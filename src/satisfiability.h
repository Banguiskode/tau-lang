// LICENSE
// This software is free for use and redistribution while including this
// license notice, unless:
// 1. is used for commercial or non-personal purposes, or
// 2. used for a product which includes or associated with a blockchain or other
// decentralized database technology, or
// 3. used for a product which includes or associated with the issuance or use
// of cryptographic or electronic currencies/coins/tokens.
// On all of the mentioned cases, an explicit and written permission is required
// from the Author (Ohad Asor).
// Contact ohad@idni.org for requesting a permission. This license may be
// modified over time by the Author.

#ifndef __SATISFIABILITY_H__
#define __SATISFIABILITY_H__

#include <iostream>

#include "tau.h"

using namespace std;
using namespace idni::tau;

namespace idni::tau {

template<typename... BAs>
void get_gssotc_clauses(const gssotc<BAs...>& n, std::vector<gssotc<BAs...>>& clauses) {
	if (auto check = n | tau_parser::tau_or; check.has_value()) {
		for (auto& c: check || tau_parser::tau) get_gssotc_clauses(c , clauses);
	} else {
		clauses.push_back(n);
		DBG(std::cout << "(I) found get_gssotc_clause: " << n << std::endl;)
	}
}

template<typename... BAs>
std::vector<gssotc<BAs...>> get_gssotc_clauses(const gssotc<BAs...>& n) {
	std::vector<gssotc<BAs...>> clauses;
	get_gssotc_clauses(n, clauses);
	return clauses;
}

template<typename... BAs>
void get_gssotc_literals(const gssotc<BAs...>& clause, std::vector<gssotc<BAs...>>& literals) {
	if (auto check = clause | tau_parser::tau_and; check.has_value())
		for (auto& c: check || tau_parser::tau) get_gssotc_literals(c , literals);
	else {
		literals.push_back(clause);
		DBG(std::cout << "(I) found get_gssotc_clause: " << clause << std::endl;)
	}
}

template<typename... BAs>
std::vector<gssotc<BAs...>> get_gssotc_literals(const gssotc<BAs...>& clause) {
	std::vector<gssotc<BAs...>> literals;
	get_gssotc_literals(clause, literals);
	return literals;
}

template<typename... BAs>
static const auto is_gssotc_positive_literal = [] (const gssotc<BAs...>& n) {
	auto check = n | tau_parser::tau_wff;
	return check.has_value();
};
template<typename... BAs>
using is_gssotc_positive_literal_t = decltype(is_gssotc_positive_literal<BAs...>);

template<typename... BAs>
static const auto is_gssotc_negative_literal = [] (const gssotc<BAs...>& n) {
	auto check = n | tau_parser::tau_neg | tau_parser::wff;
	return check.has_value();
};

template<typename... BAs>
using is_gssotc_negative_literal_t = decltype(is_gssotc_negative_literal<BAs...>);

template<typename... BAs>
std::pair<std::optional<gssotc<BAs...>>, std::vector<gssotc<BAs...>>> get_gssotc_positive_negative_literals(const gssotc<BAs...> clause) {
	std::optional<gssotc<BAs...>> positive;
	std::vector<gssotc<BAs...>> negatives;

	for(auto& l: get_gssotc_literals(clause)) {
		if (is_gssotc_positive_literal<BAs...>(l)) positive = {l};
		else negatives.push_back(l);
	}

	#ifdef DEBUG
	if (positive.has_value()) std::cout << "(I) positive: " << positive.value() << std::endl;
	if (!negatives.empty()) {
		for (auto& n: negatives) std::cout << "(I) negative: " << n << std::endl;
	}
	#endif // DEBUG

	return {positive, negatives};
}

template<typename...BAs>
struct tau_spec_vars {

	void add(const gssotc<BAs...>& io) {
		auto offset = io
			| only_child_extractor<tau_ba<BAs...>, BAs...>
			| tau_parser::offset
			| optional_value_extractor<gssotc<BAs...>>;
		auto pos = offset
			| only_child_extractor<tau_ba<BAs...>, BAs...>
			| non_terminal_extractor<tau_ba<BAs...>, BAs...>
			| optional_value_extractor<size_t>;
		auto var_name = (io
			| only_child_extractor<tau_ba<BAs...>, BAs...>
			| optional_value_extractor<gssotc<BAs...>>)->child[0];
		name.emplace(var_name);
		switch (pos) {
			case tau_parser::num:
				loopback = max(loopback,
					offset | tau_parser::num
					| only_child_extractor<tau_ba<BAs...>, BAs...>
					| offset_extractor<tau_ba<BAs...>, BAs...>
					| optional_value_extractor<size_t>);
				break;
			case tau_parser::shift:
				loopback = max(loopback,
					offset | tau_parser::shift
					| tau_parser::num
					| only_child_extractor<tau_ba<BAs...>, BAs...>
					| offset_extractor<tau_ba<BAs...>, BAs...>
					| optional_value_extractor<size_t>);
				break;
			default:
				break;
		}
	}

	std::set<gssotc<BAs...>> name;
	size_t loopback = 0;
};

template<typename... BAs>
std::pair<tau_spec_vars<BAs...>, tau_spec_vars<BAs...>> get_gssotc_io_vars(const gssotc<BAs...> collapsed) {
	tau_spec_vars<BAs...> inputs;
	tau_spec_vars<BAs...> outputs;
	for (const auto& variable: select_top(collapsed, is_non_terminal<tau_parser::io_var, tau_ba<BAs...>, BAs...>)) {
		auto type = variable
			| only_child_extractor<tau_ba<BAs...>, BAs...>
			| non_terminal_extractor<tau_ba<BAs...>, BAs...>
			| optional_value_extractor<size_t>;
		(type == tau_parser::in ? inputs : outputs).add(variable);
	}

	DBG(std::cout << "(I) inputs: " ; for (auto& i: inputs.name) std::cout << i << ", "; std::cout << std::endl;)
	DBG(std::cout << "(I) outputs: " ; for (auto& o: outputs.name) std::cout << o << ", "; std::cout << std::endl;)

	return {inputs, outputs};
}

template<typename... BAs>
std::string build_string_from_clause(const gssotc<BAs...>& clause, bindings<tau_ba<BAs...>, BAs...> bindings, size_t binding_seed = 0) {

	std::basic_stringstream<char> str;
	std::map<std::variant<tau_ba<BAs...>, BAs...>, std::string> extracted_bindings;

	auto visitor = overloaded(
		[&str] (const tau_source_sym& l) {
			if (!l.nt() && !l.is_null()) str << l.t(); },
		[&str, &extracted_bindings, &binding_seed] (const std::variant<tau_ba<BAs...>, BAs...>& bae) {
			if (extracted_bindings.contains(bae)) str << extracted_bindings[bae];
			else {
				auto binding = "taubinding" + std::to_string(binding_seed++);
				extracted_bindings[bae] = binding;
				str << binding;
			}},
		[&str] (const size_t& n) { str << n; });

	auto print = [&str, &visitor] (const auto& e) {
		std::visit(visitor, e->value);
		return e;
	};
	using print_t = decltype(print);

	post_order_tree_traverser<print_t, all_t<gssotc<BAs...>>, gssotc<BAs...>>(print, all<gssotc<BAs...>>)(clause);
	for (auto& [k, v]: extracted_bindings) { bindings.insert({v, k}); }
	return str.str();
}

template<typename... BAs>
std::string build_args_from_vars(const tau_spec_vars<BAs...>& vars, size_t index) {
	std::basic_stringstream<char> str;
	for (const auto& var: vars.name) {
		str << var << "[" << index << "]";
		if (var != *vars.name.rbegin()) str << ", ";
	}
	return str.str();
}

template<typename... BAs>
std::string build_args_from_vars(const tau_spec_vars<BAs...>& vars) {
	std::basic_stringstream<char> str;
	for (const auto& var: vars.name) {
		str << var;
		if (var != *vars.name.rbegin()) str << ", ";
	}
	return str.str();
}

template<typename... BAs>
std::string build_universal_quantifiers(const tau_spec_vars<BAs...>& vars, size_t index) {
	std::basic_stringstream<char> str;
	for (const auto& var: vars.name) {
		str << "all " << var << "[" << index << "] ";
	}
	return str.str();
}

template<typename... BAs>
std::string build_existential_quantifiers(const tau_spec_vars<BAs...>& vars, size_t index) {
	std::basic_stringstream<char> str;
	for (const auto& var: vars.name) {
		str << "ex " << var << "[" << index << "] ";
	}
	return str.str();
}

template<typename... BAs>
std::string build_boolean_existential_quantifiers(size_t size) {
	std::basic_stringstream<char> str;
	for (size_t i = 1; i <= size; ++i) {
		str << "bex $nn" << i;
		if (i < size) str << ",";
	}
	return str.str();
}

template<typename... BAs>
std::pair<std::string, bindings<tau_ba<BAs...>, BAs...>>  build_eta_nso_rr(
		const std::optional<gssotc<BAs...>>& positive,
		const std::vector<gssotc<BAs...>>& negatives,
		const tau_spec_vars<BAs...>& inputs,
		const tau_spec_vars<BAs...>& outputs) {
	auto print_t = [] (size_t negatives) {
		std::basic_stringstream<char> str;
		for (size_t i = 1; i <= negatives; ++i) {
			str << "t";
			if (i < negatives) str << ",";
		}
		return str.str();
	};
	auto print_negative_vars = [] (size_t negatives) {
		std::basic_stringstream<char> str;
		for (size_t i = 1; i <= negatives; ++i) {
			str << "$n" << i;
			if (i < negatives) str << ",";
		}
		return str.str();
	};
	auto print_new_negative_vars = [] (size_t negatives) {
		std::basic_stringstream<char> str;
		for (size_t i = 1; i <= negatives; ++i) {
			str << "$nn" << i;
			if (i < negatives) str << ",";
		}
		return str.str();
	};

	bindings<tau_ba<BAs...>, BAs...> bindings;
	size_t binding_seed = 0;
	size_t loopback = max(inputs.loopback, outputs.loopback);
	std::basic_stringstream<char> nsorr;
	nsorr << "eta[t](" << build_args_from_vars(outputs) << ") := ";
		// add call to etas
		if (negatives.size() > 0) {
			nsorr << "etas[t](" << build_args_from_vars(outputs) << print_t(outputs.name.size()) << ").\n";
		}
	nsorr << "etas[t](" << build_args_from_vars(outputs) << print_negative_vars(outputs.name.size()) <<") := ";
		// quantify input and output variables
		for (size_t i = 1; i <= loopback; ++i) {
			nsorr << build_universal_quantifiers(inputs, i);
			nsorr << build_existential_quantifiers(outputs, i);
		}
		// boolean quantify new negative vars
		nsorr << build_boolean_existential_quantifiers(outputs.name.size());
		// add positive literal if it exists
		if (positive.has_value()) {
			nsorr << build_string_from_clause(positive.value(), bindings, binding_seed);
			if (negatives.size() > 0) nsorr << " && ";
		}
		// generate a disjunction of all negations conjucted with the max_loopback variables and
		if (negatives.size() > 0) {
			for (size_t i = 0; i < negatives.size(); ++i) {
				nsorr << "(( $n" << i << " && " << "$nn" << i << " ) &&& " << build_string_from_clause(negatives[i], bindings, binding_seed) << ") &&& ";
			}
			// add recursive call with t-1
			nsorr << "etas[t-1](" << build_args_from_vars(outputs) << print_new_negative_vars(outputs.name.size()) << ").\n";
		}
	// add main

	DBG(std::cout << "(I) build_eta_nso_rr: " << nsorr.str() << std::endl;)

	return {nsorr.str(), bindings};
}


template<typename... BAs>
std::string build_check_nso_rr(const tau_spec_vars<BAs...>& outputs, size_t loopback, size_t current) {
	std::basic_stringstream<char> check;
	check << build_existential_quantifiers(outputs, loopback) <<
		" (eta[" << current << "](" << build_args_from_vars(outputs) << ").\n";

	DBG(std::cout << "(I) build_check_nso_rr: " << check.str() << std::endl;)

	return check.str();
}

template<typename... BAs>
std::string build_main_nso_rr(const tau_spec_vars<BAs...>& outputs, size_t loopback, size_t current, size_t previous) {
	std::basic_stringstream<char> main;
	main << build_universal_quantifiers(outputs, loopback) <<
		" (eta[" << current << "](" << build_args_from_vars(outputs) << ") <-> eta[" << previous << "]).\n";

	DBG(std::cout << "(I) build_main_nso_rr: " << main.str() << std::endl;)

	return main.str();
}


template<typename... BAs>
std::pair<std::string, bindings<tau_ba<BAs...>, BAs...>> build_main_nso_rr_wff(const std::optional<gssotc<BAs...>>& positive, const tau_spec_vars<BAs...>& inputs, const tau_spec_vars<BAs...>& outputs, size_t loopback) {
	std::basic_stringstream<char> main;
	bindings<tau_ba<BAs...>, BAs...> bindings;

	if (positive.has_value()) {
		auto wff = positive | tau_parser::tau_wff | tau_parser::wff| optional_value_extractor<gssotc<BAs...>>;

		// print quantifiers related to free variables
		for (size_t i = 1; i <= loopback; ++i) {
			main << build_universal_quantifiers(inputs, i);
			main << build_existential_quantifiers(outputs, i);
		}
		// print the main wff
		main << build_string_from_clause(wff, bindings)	<< ".";
	} else main << "T.";

	DBG(std::cout << "(I) get_main_nso_wo_rr: " << main.str() << std::endl;)

	return {main.str(), bindings};
}

template<typename... BAs>
bool is_gssotc_clause_satisfiable_no_vars(const gssotc<BAs...>& collapsed) {
	auto check = collapsed | tau_parser::tau_wff | tau_parser::wff | tau_parser::wff_t;
	if (check.has_value()) {
		DBG(std::cout << "(I) -- Check is_gssotc_clause_satisfiable: true" << std::endl;)
		return true;
	} else {
		DBG(std::cout << "(I) -- Check is_gssotc_clause_satisfiable: false" << std::endl;)
		return false;
	}
	return check.has_value() ? true : false;
}

template<typename... BAs>
bool is_gssotc_clause_satisfiable_no_negatives(const std::optional<gssotc<BAs...>>& positive,  const tau_spec_vars<BAs...>& inputs, const tau_spec_vars<BAs...>& outputs, size_t loopback) {

	// TODO (HIGH) fix formula to be normalized, must include a phi call and a phi definition
	auto [main_wo_rr, bindings] = build_main_nso_rr_wff<BAs...>(positive, inputs, outputs, loopback);
	DBG(std::cout << "(I) -- Check normalizer" << std::endl;)
	DBG(std::cout << main_wo_rr << std::endl;)
	auto normalize = normalizer<tau_ba<BAs...>, BAs...>(main_wo_rr, bindings).main;

	if ((normalize | tau_parser::wff_f).has_value()) {
		DBG(std::cout << "(I) -- Check is_gssotc_clause_satisfiable: false" << std::endl;)
		return false;
	}

	DBG(std::cout << "(I) -- Check is_gssotc_clause_satisfiable: true" << std::endl;)
	return true;
}

template<typename... BAs>
bool is_gssotc_clause_satisfiable_general(const std::optional<gssotc<BAs...>>& positive, const std::vector<gssotc<BAs...>> negatives,  const tau_spec_vars<BAs...>& inputs, const tau_spec_vars<BAs...>& outputs, size_t loopback) {
	auto etas = build_eta_nso_rr<BAs...>(positive, negatives, inputs, outputs);
	for (size_t current = 1; /* until return statement */ ; ++current) {
		auto [eta, extracted_bindings] = build_eta_nso_rr<BAs...>(positive, negatives, inputs, outputs);
		bindings<tau_ba<BAs...>, BAs...> reversed_bindings;
		auto check = build_check_nso_rr(outputs, loopback, current);
		auto normalize = normalizer<tau_ba<BAs...>, BAs...>(eta.append(check), reversed_bindings).main;
		if ((normalize | tau_parser::wff_f).has_value()) {
			DBG(std::cout << "(I) --Check is_gssotc_clause_satisfiable: false" << std::endl);
			return false;
		}
		for (size_t previous = 1; previous < current; ++previous) {
			auto main = build_main_nso_rr(outputs, loopback, current, previous);
			auto normalize = normalizer<tau_ba<BAs...>, BAs...>(eta.append(main), reversed_bindings).main;
			if ((normalize | tau_parser::wff_t).has_value()) return true;
		}
	}
}

template<typename... BAs>
bool is_gssotc_clause_satisfiable(const gssotc<BAs...>& clause) {

	DBG(std::cout << "(I) -- Checking is_gssotc_clause_satisfiable"; std::cout << std::endl;)
	DBG(std::cout << clause << std::endl;)

	auto collapsed = clause |
		repeat_all<step<tau_ba<BAs...>, BAs...>, tau_ba<BAs...>, BAs...>(
			simplify_tau<tau_ba<BAs...>, BAs...>
			| collapse_positives_tau<tau_ba<BAs...>, BAs...>);

	auto [positive, negatives] = get_gssotc_positive_negative_literals(collapsed);
	auto [inputs, outputs] = get_gssotc_io_vars(collapsed);
	size_t loopback = max(inputs.loopback, outputs.loopback);

	if (inputs.name.empty() && outputs.name.empty()) {

		DBG(std::cout << "(I) -- No variables case" << std::endl;)
		DBG(std::cout << "(F) " << collapsed << std::endl;)

		return is_gssotc_clause_satisfiable_no_vars(collapsed);
	} else if (negatives.empty() && positive.has_value()) {

		DBG(std::cout << "(I) -- No negatives case" << std::endl;)
		DBG(std::cout << clause << std::endl;)

		return is_gssotc_clause_satisfiable_no_negatives(positive, inputs, outputs, loopback);
	}

	DBG(std::cout << "(I) -- General case" << std::endl;)
	DBG(std::cout << clause << std::endl;)

	return is_gssotc_clause_satisfiable_general(positive, negatives, inputs, outputs, loopback);
}

template<typename... BAs>
bool is_gssotc_satisfiable(const gssotc<BAs...>& form) {
	auto dnf = form
		| repeat_all<step<tau_ba<BAs...>, BAs...>, tau_ba<BAs...>, BAs...>(
			to_dnf_tau<tau_ba<BAs...>, BAs...>
			| simplify_tau<tau_ba<BAs...>, BAs...>);

	DBG(std::cout << "(I) -- Converting to dnf and simplifying" << std::endl;)
	DBG(std::cout << dnf << std::endl;)

	auto clauses = get_gssotc_clauses(dnf);
	for (auto& clause: clauses) {
		if (is_gssotc_clause_satisfiable(clause)) return true;
	}
	return false;
}

template <typename... BAs>
bool is_gssotc_equivalent_to(gssotc<BAs...> n1, gssotc<BAs...> n2) {
	return !is_gssotc_satisfiable(build_tau_neg(build_tau_equiv(n1, n2)));
}

template <typename... BAs>
auto is_gssotc_equivalent_to_any_of(const gssotc<BAs...>& n, std::vector<gssotc<BAs...>>& previous) {
	return std::any_of(previous.begin(), previous.end(), [n] (const gssotc<BAs...>& p) {
		return is_gssotc_equivalent_to<BAs...>(n, p);
	});
}

// check satisfability of a tau_spec (boolean combination case)
template<typename...BAs>
bool is_tau_spec_satisfiable(const tau_spec<BAs...>& tau_spec) {
	DBG(std::cout << "(I) -- Begin is_tau_spec_satisfiable tau_spec " << std::endl;)
	DBG(std::cout << tau_spec << std::endl;)

	auto loopback = get_max_loopback_in_rr(tau_spec.main);
	DBG(std::cout << "(I) Max loopback: " << loopback << std::endl;)

	std::vector<gssotc<BAs...>> previous;

	for (int i = loopback; ; i++) {
		auto current = build_main_step<tau_ba<BAs...>, BAs...>(tau_spec.main, i)
			| repeat_all<step<tau_ba<BAs...>, BAs...>, tau_ba<BAs...>, BAs...>(step<tau_ba<BAs...>, BAs...>(tau_spec.rec_relations));

		DBG(std::cout << "(I) -- Begin is_tau_spec_satisfiable step" << std::endl;)
		DBG(std::cout << current << std::endl;)

		if (!is_gssotc_satisfiable(current)) {
			DBG(std::cout << "(I) -- End is_tau_spec_satisfiable: false" << std::endl);
			return false;
		}
		if (is_gssotc_equivalent_to_any_of(current, previous)) {
			DBG(std::cout << "(I) -- End is_tau_spec_satisfiable: true" << std::endl);
			return true;
		} else previous.push_back(current);
	}
}

} // namespace idni::tau

#endif // __SATISFIABILITY_H__