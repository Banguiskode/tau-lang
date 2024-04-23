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

#ifndef __FIND_SOLUTION_H__
#define __FIND_SOLUTION_H__

#include "tau.h"
#include "satisfiability.h"
#include "normal_forms.h"

// In what follows we use the algorithms and notations of Section 3.2 of the
// TABA book (https://github.com/IDNI/tau-lang/blob/main/docs/taba.pdf)

using namespace idni::rewriter;
using namespace idni::tau;

namespace idni::tau {

template<typename...BAs>
using clause = nso<BAs...>;

template<typename...BAs>
using bound = std::variant<BAs...>;

template<typename...BAs>
struct onf_clause {
	std::vector<bound<BAs...>> lowers; // c's in the book
	std::vector<bound<BAs...>> uppers; // d's in the book
	std::pair<bound<BAs...>, bound<BAs...>> interval;
};

template<typename...BAs>
struct nlgeqs_clause {
	std::vector<bound<BAs...>> lowers; // c's in the book
	std::vector<bound<BAs...>> uppers; // d's in the book
};

template<typename...BAs>
using splitter_set = std::set<std::variant<BAs...>>;

template<typename...BAs>
onf_clause<BAs...> to_onf_clause(clause<BAs...> clause) {
	return {};
}

template<typename...BAs>
static constexpr auto _leq = overloaded([]<typename T>(const T& l, const T& r) -> bool {
		return (~l & r = false);
	}, [](const auto&, const auto&) -> sp_tau_node<BAs...> { throw std::logic_error("wrong types"); });

template<typename...BAs>
static constexpr auto _eq = overloaded([]<typename T>(const T& l, const T& r) -> bool {
		// TODO (HIGH) fix this
		return (~l & r = false);
	}, [](const auto&, const auto&) -> sp_tau_node<BAs...> { throw std::logic_error("wrong types"); });

template<typename...BAs>
static constexpr auto _and = overloaded([]<typename T>(const T& l, const T& r) -> bool {
			return l & r;
	}, [](const auto&, const auto&) -> sp_tau_node<BAs...> { throw std::logic_error("wrong types"); });

template<typename...BAs>
static constexpr auto _or = overloaded([]<typename T>(const T& l, const T& r) -> bool {
			return l | r;
	}, [](const auto&, const auto&) -> sp_tau_node<BAs...> { throw std::logic_error("wrong types"); });

static constexpr auto _is_zero = [](const auto& l) -> bool { return l == false; };
static constexpr auto _is_geq_zero = [](const auto& l) -> bool { return l == false; };
static constexpr auto _is_leq_one = [](const auto& l) -> bool { return l == false; };

template<typename...BAs>
static constexpr auto _neg = [](const auto& l) -> std::variant<BAs...> { return ~l; };

// template<typename...BAs>
// bool has_clause_maximal_solution(nlgeqs_clause<BAs...> clause) {
// 	auto b = clause.interval.second; // always 1, makes no sense to check
// 	for (auto& c_i: clause.lowers) if (std::visit(_leq<BAs...>, c_i, b)) return false;
// 	return true;
// }
//
// template<typename...BAs>
// bool has_clause_minimal_solution(nlgeqs_clause<BAs...> clause) {
// 	auto a = clause.interval.first; // always 0, make no sense to check
// 	for (auto& d_i: clause.uppers) if (std::visit(_leq<BAs...>, a, d_i)) return false;
// 	return true;
// }

template<typename...BAs>
splitter_set<BAs...> compute_splitter_set(const nlgeqs_clause<BAs...>& clause) {
	splitter_set<BAs...> ss;
	for (size_t i = 0; i < clause.lowers.size(); ++i) {
		for (size_t j = 0; j < clause.uppers.size(); ++j) {
			std::variant<BAs...> result = clause.lowers[i];
			for (size_t ii = 0; ii < clause.lowers.size(); ++ii)
				// (result <= c_ii) <-> (result c_ii' =0)
				if (std::visit(_leq<BAs...>, result, clause.lowers[ii]))
					result = std::visit(_and<BAs...>, result, clause.lowers[ii]);
				else result = std::visit(_and<BAs...>, result, std::visit(_neg<BAs...>, clause.lowers[ii]));

			result = std::visit(_and<BAs...>, result, clause.uppers[j]);
			if (!std::visit(_is_zero, result)) continue;

			for (size_t jj = 0; jj < clause.uppers.size(); ++jj)
				// (result <= d_jj) <-> (result d_jj' =0)
				if (std::visit(_leq<BAs...>, clause.uppers[j], clause.uppers[jj]))
					result = std::visit(_and<BAs...>, result, clause.uppers[jj]);
				else result = std::visit(_and<BAs...>, result, std::visit(_neg<BAs...>, clause.uppers[jj]));

			if (!std::visit(_is_zero, result)) ss.insert(result);
		}
	}
	return ss;
}

template<typename splitter_t, typename...BAs>
std::optional<std::variant<BAs...>> solve_clause_using_splitter(nlgeqs_clause<BAs...> clause, splitter_t splitter) {
	// Following Lemma 3.4 of TABA book we could compute maximal and minilmal solutions.
	// However, in our case, as we have use the LGRS to remove the equality from
	// our initial system, we have a=0 and b=1. Thus, there are no maximal or minimal
	// solutions. We can directly compute the solution using the splitters.

	// if (has_clause_maximal_solution(clause)) return ...;
	// if (has_clause_minimal_solution(clause)) return ...;

	std::variant<BAs...> result;
	for (auto& split: compute_splitter_set(clause)) {
		if (auto splitted = splitter(split); splitted.has_value())
			result = std::visit(_or<BAs...>, result, splitted.value());
		else return {};
	}
	return result;
}

template<typename splitter_t, typename...BAs>
std::optional<std::variant<BAs...>> solve_clause_using_splitter(clause<BAs...> clause, splitter_t splitter) {
	auto var = find_top(clause, is_non_terminal<tau_parser::var, BAs...>)
		|optional_value_extractor<sp_tau_node<BAs...>>;
	auto f = find_top(clause, is_non_terminal<tau_parser::bf_eq, BAs...>)
		| tau_parser::bf
		| optional_value_extractor<sp_tau_node<BAs...>>;
	auto x_plus_fx = trim(build_bf_xor<BAs...>(wrap(tau_parser::bf, var), f));
	auto lgrs = replace(clause, {{var, x_plus_fx}});
	auto simplified = lgrs
		| repeat_each<step<BAs...>, BAs...>(
			to_dnf_bf<BAs...>
			| simplify_bf<BAs...>
			| apply_cb<BAs...>)
		| to_mnf_bf<BAs...>();

	nlgeqs_clause<BAs...> nlg_eqs;

	auto f_0 = replace(simplified,  {{var, _0<BAs...>}})
		| repeat_each<step<BAs...>, BAs...>(
			simplify_bf<BAs...>
			| apply_cb<BAs...>)
		| to_mnf_bf<BAs...>();
	auto f_1 = replace(simplified, {{var, _1<BAs...>}})
		| repeat_each<step<BAs...>, BAs...>(
			simplify_bf<BAs...>
			| apply_cb<BAs...>)
		| to_mnf_bf<BAs...>();

	for (auto& neq: select_all(f_0, is_non_terminal<tau_parser::bf_neq, BAs...>)) {
		auto c_i = neq | tau_parser::bf | only_child_extractor<sp_tau_node<BAs...>>
			| ba_extractor<BAs...> | optional_value_extractor<sp_tau_node<BAs...>>;
		nlg_eqs.lowers.push_back(c_i);
	}

	for (auto& neq: select_all(f_1, is_non_terminal<tau_parser::bf_neq, BAs...>)) {
		auto neg_d_i = neq | tau_parser::bf | only_child_extractor<sp_tau_node<BAs...>>
			| ba_extractor<BAs...> | optional_value_extractor<sp_tau_node<BAs...>>;
		auto d_i = std::visit(_neg<BAs...>, neg_d_i);
		nlg_eqs.uppers.push_back(d_i);
	}

	return solve_clause_using_splitter(nlg_eqs, splitter);
}

// Solves an univariate equation using splitters
template<typename splitter_t, typename...BAs>
std::optional<std::variant<BAs...>> solve_using_splitter(nso<BAs...> nso, splitter_t splitter) {
	// convert to DNF
	// squeeze positives
	auto nso_with_defs = apply_definitions(nso);
	auto form = nso_with_defs
		| repeat_all<step<BAs...>, BAs...>(
			step<BAs...>(apply_defs<BAs...>))
		| repeat_each<step<BAs...>, BAs...>(
			to_dnf_wff<BAs...>
			| simplify_wff<BAs...>)
		| to_mnf_wff<BAs...>()
		| repeat_all<step<BAs...>, BAs...>(
			bf_positives_upwards<BAs...>
			| squeeze_positives<BAs...>)
		| repeat_all<step<BAs...>, BAs...>(
			to_dnf_bf<BAs...>
			| simplify_bf<BAs...>
			| apply_cb<BAs...>)
		| to_mnf_bf<BAs...>()
		| repeat_all<step<BAs...>, BAs...>(
			trivialities<BAs...>
			| simplify_bf<BAs...>
			| simplify_wff<BAs...>);

	for (auto& clause: get_dnf_clauses<tau_parser::wff>(form)) {
		if (auto onf_clause = to_onf_clause(clause); is_clause_consistent(onf_clause)) {
			return solve_clause_using_splitter(onf_clause, splitter);
		}
	}
	return {};
}

} // idni::tau namespace
#endif // __FIND_SOLUTION_H__