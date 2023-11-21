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

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define OUTPUT_APPLY_RULES

#include "../src/doctest.h"
#include "../src/defs.h"
#include "../src/formula.h"
#include "../src/bool.h"
#include "test_helpers.h"

using namespace idni::rewriter;
using namespace idni::tau;
using namespace std;

namespace testing = doctest;

// IMPORTANT: To check the parser (and the underlying grammar) we don't need
// any special boolean algebra, so we use Bool to simplify our testing.

// The following test suites represent correct sentences of a tau formula or
// library and as such must be parsed correctly and satisfy the structural checks
// we perform on the parsed formula (as the rest of the code assumes such structure).

// TODO (LOW) why "$X := { : src_code } bf_and { bool : src_code }." is parsed
//
// improperly? bf | bf_constant | ...
//
// Check if still hapopens after the latest changes to the grammar.

TEST_SUITE("parsing formula") {

	const char* sample =
		"?X := ?X."
		"?Y := ?Y."
		" ( ?Z == F ) .";
	auto src = make_tau_source(sample);
	auto frml = make_statement(src);

	TEST_CASE("formula") {
		auto formula = frml | tau_parser::formula ;
		CHECK( formula.has_value() );
	}

	TEST_CASE("rules") {
		auto rules = frml | tau_parser::formula | tau_parser::rules ;
		CHECK( rules.has_value() );
	}

	TEST_CASE("rule") {
		auto rules = frml | tau_parser::formula | tau_parser::rules || tau_parser::rule;
		CHECK( rules.size() == 2 );
	}

	TEST_CASE("main") {
		auto main = frml | tau_parser::formula | tau_parser::main;
		CHECK( main.has_value() );
	}
}


TEST_SUITE("parsing builders") {

	TEST_CASE("one capture") {
		const char* sample = "( $X ) := (?X wff_and $X).";
		auto src = make_builder<Bool>(sample);
		CHECK( is_non_terminal<tau_parser::captures, Bool>(src.first) );
		CHECK( is_non_terminal<tau_parser::wff, Bool>(src.second) );
	}

	TEST_CASE("two capture") {
		const char* sample = "( $X $Y ) := (?X wff_and $Y).";
		auto src = make_builder<Bool>(sample);
		auto left = src.first;
		auto right = src.first;
		CHECK( is_non_terminal<tau_parser::captures, Bool>(src.first) );
		CHECK( is_non_terminal<tau_parser::wff, Bool>(src.second) );
	}
}

TEST_SUITE("parsing library") {

	const char* sample =
		"?X := ?X."
		"?Y := ?Y.";
	auto src = make_tau_source(sample);
	auto lib = make_statement(src);

	TEST_CASE("library") {
		auto library = lib | tau_parser::library ;
		CHECK( library.has_value() );
	}

	TEST_CASE("rules") {
		auto rules = lib | tau_parser::library | tau_parser::rules ;
		CHECK( rules.has_value());
	}

	TEST_CASE("rule") {
		auto rules = lib | tau_parser::library | tau_parser::rules || tau_parser::rule;
		CHECK( rules.size() == 2 );
	}
}

TEST_SUITE("parsing rules") {

	TEST_CASE("wff rule") {
		// TODO (LOW) add test for wff rule parsing
	}
	TEST_CASE("cbf rule") {
		// TODO (LOW) add test for cbf rule parsing
	}
	TEST_CASE("bf rule") {
		// TODO (LOW) add test for bf rule parsing
	}
}

TEST_SUITE("parsing variables") {
	// done inderectly
}

TEST_SUITE("parsing captures") {
	// done inderectly
}

TEST_SUITE("parsing inputs") {
	// TODO (LOW) add tests for inputs parsing
}

TEST_SUITE("parsing outputs") {
	// TODO (LOW) add tests for outputs parsing
}

TEST_SUITE("parsing indexes"){
	// TODO (LOW) add tests for indexes parsing
}

TEST_SUITE("parsing wwf formulas ") {

	TEST_CASE("wff_neg") {
		const char* sample = "wff_neg ( ?Z == F ).";
		auto src = make_tau_source(sample);
		auto frml = make_statement(src);
		auto neg_formula = frml
			| tau_parser::formula
			| tau_parser::main
			| tau_parser::wff
			| tau_parser::wff_neg;
		CHECK( neg_formula.has_value() );
	}

	TEST_CASE("wff_and") {
		const char* sample = "(( ?Z == F ) wff_and ( ?X == F )).";
		auto src = make_tau_source(sample);
		auto frml = make_statement(src);
		auto and_formula = frml
			| tau_parser::formula
			| tau_parser::main
			| tau_parser::wff
			| tau_parser::wff_and;
		CHECK( and_formula.has_value() );
	}

	TEST_CASE("wff_or") {
		const char* sample = "(( ?Z == F ) wff_or ( ?X == F )).";
		auto src = make_tau_source(sample);
		auto frml = make_statement(src);
		auto or_formula = frml
			| tau_parser::formula
			| tau_parser::main
			| tau_parser::wff
			| tau_parser::wff_or;
		CHECK( or_formula.has_value() );
	}

	TEST_CASE("wff_xor") {
		const char* sample = "(( ?Z == F ) wff_xor ( ?X == F )).";
		auto src = make_tau_source(sample);
		auto frml = make_statement(src);
		auto xor_formula = frml
			| tau_parser::formula
			| tau_parser::main
			| tau_parser::wff
			| tau_parser::wff_xor;
		CHECK( xor_formula.has_value() );
	}

	TEST_CASE("wff_eq") {
		const char* sample = "( ?Z == F ).";
		auto src = make_tau_source(sample);
		auto frml = make_statement(src);
		auto eq_formula = frml
			| tau_parser::formula
			| tau_parser::main
			| tau_parser::wff
			| tau_parser::wff_eq;
		CHECK( eq_formula.has_value() );
	}

	TEST_CASE("wff_imply") {
		const char* sample = "(?Z wff_imply ?Z) := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto imply_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::wff_rule
			| tau_parser::wff_matcher
			| tau_parser::wff
			| tau_parser::wff_imply;
		CHECK( imply_rule.has_value() );
	}

	TEST_CASE("wff_coimply") {
		const char* sample = "(?Z wff_coimply ?Z) := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto coimply_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::wff_rule
			| tau_parser::wff_matcher
			| tau_parser::wff
			| tau_parser::wff_coimply;
		CHECK( coimply_rule.has_value() );
	}

	TEST_CASE("wff_equiv") {
		const char* sample = "(?Z wff_equiv ?Z) := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto equiv_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::wff_rule
			| tau_parser::wff_matcher
			| tau_parser::wff
			| tau_parser::wff_equiv;
		CHECK( equiv_rule.has_value() );
	}

	TEST_CASE("wff_all") {
		const char* sample = "wff_all ?Z ( ?Z == F ) .";
		auto src = make_tau_source(sample);
		auto frml = make_statement(src);
		auto all_formula = frml
			| tau_parser::formula
			| tau_parser::main
			| tau_parser::wff
			| tau_parser::wff_all;
		CHECK( all_formula.has_value() );
	}

	TEST_CASE("wff_ex") {
		const char* sample = "wff_ex ?Z ( ?Z == F ) .";
		auto src = make_tau_source(sample);
		auto frml = make_statement(src);
		auto ex_formula = frml
			| tau_parser::formula
			| tau_parser::main
			| tau_parser::wff
			| tau_parser::wff_ex;
		CHECK( ex_formula.has_value() );
	}

	// TODO (HIGH) test wwf refs
	TEST_CASE("wff_ref") {
		//CHECK( false );
	}
}

TEST_SUITE("parsing cbf formulas ") {

	TEST_CASE("cbf_neg") {
		const char* sample = "?Z := cbf_neg ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto neg_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::cbf_rule
			| tau_parser::cbf_body
			| tau_parser::cbf
			| tau_parser::cbf_neg;
		CHECK( neg_rule.has_value() );
	}

	TEST_CASE("cbf_and") {
		const char* sample = "?Z := ( ?Z cbf_and ?Z ).";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto and_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::cbf_rule
			| tau_parser::cbf_body
			| tau_parser::cbf
			| tau_parser::cbf_and;
		CHECK( and_rule.has_value() );
	}

	TEST_CASE("cbf_or") {
		const char* sample = "?Z := ( ?Z cbf_or ?Z ).";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto or_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::cbf_rule
			| tau_parser::cbf_body
			| tau_parser::cbf
			| tau_parser::cbf_or;
		CHECK( or_rule.has_value() );
	}

	TEST_CASE("cbf_xor") {
		const char* sample = "?Z := ( ?Z cbf_xor ?Z ).";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto xor_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::cbf_rule
			| tau_parser::cbf_body
			| tau_parser::cbf
			| tau_parser::cbf_xor;
		CHECK( xor_rule.has_value() );
	}

	TEST_CASE("cbf_imply") {
		const char* sample = "(?Z cbf_imply ?Z) := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto imply_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::cbf_rule
			| tau_parser::cbf_matcher
			| tau_parser::cbf
			| tau_parser::cbf_imply;
		CHECK( imply_rule.has_value() );
	}

	TEST_CASE("cbf_coimply") {
		const char* sample = "(?Z cbf_coimply ?Z) := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto coimply_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::cbf_rule
			| tau_parser::cbf_matcher
			| tau_parser::cbf
			| tau_parser::cbf_coimply;
		CHECK( coimply_rule.has_value() );
	}

	TEST_CASE("cbf_equiv") {
		const char* sample = "(?Z cbf_equiv ?Z) := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto equiv_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::cbf_rule
			| tau_parser::cbf_matcher
			| tau_parser::cbf
			| tau_parser::cbf_equiv;
		CHECK( equiv_rule.has_value() );
	}

	TEST_CASE("cbf_if") {
		const char* sample = "(if $Y then $Z  else $Z) := $X.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto if_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::wff_rule
			| tau_parser::wff_matcher
			| tau_parser::wff
			| tau_parser::cbf_if;
		CHECK( if_rule.has_value() );
	}

	// TODO (HIGH) test cbf refs
	TEST_CASE("cbf_ref") {
		// CHECK( false );
	}
}

TEST_SUITE("parsing bf formulas ") {

	TEST_CASE("bf_neg") {
		const char* sample = "bf_neg ?Z := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto neg_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_matcher
			| tau_parser::bf
			| tau_parser::bf_neg;
		CHECK( neg_rule.has_value() );
	}

	TEST_CASE("bf_and") {
		const char* sample = "(?Z bf_and ?Z) := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto and_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_matcher
			| tau_parser::bf
			| tau_parser::bf_and;
		CHECK( and_rule.has_value() );
	}

	TEST_CASE("bf_or") {
		const char* sample = "(?Z bf_or ?Z) := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto or_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_matcher
			| tau_parser::bf
			| tau_parser::bf_or;
		CHECK( or_rule.has_value() );
	}

	TEST_CASE("bf_xor") {
		const char* sample = "(?Z bf_xor ?Z) := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto xor_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_matcher
			| tau_parser::bf
			| tau_parser::bf_xor;
		CHECK( xor_rule.has_value() );
	}

	TEST_CASE("bf_less") {
		const char* sample = "(?Z bf_less ?Z) := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto less_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_matcher
			| tau_parser::bf
			| tau_parser::bf_less;
		CHECK( less_rule.has_value() );
	}

	TEST_CASE("bf_less_equal") {
		const char* sample = "(?Z bf_less_equal ?Z) := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto less_equal_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_matcher
			| tau_parser::bf
			| tau_parser::bf_less_equal;
		CHECK( less_equal_rule.has_value() );
	}

	TEST_CASE("bf_greater") {
		const char* sample = "(?Z bf_greater ?Z) := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto greater_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_matcher
			| tau_parser::bf
			| tau_parser::bf_greater;
		CHECK( greater_rule.has_value() );
	}

	TEST_CASE("bf_all") {
		const char* sample = "bf_all ?Z $Z := ?Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto all_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_matcher
			| tau_parser::bf
			| tau_parser::bf_all;
		CHECK( all_rule.has_value() );
	}

	TEST_CASE("bf_ex") {
		const char* sample = "bf_ex ?Z $Z := $Z.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto ex_rule = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_matcher
			| tau_parser::bf
			| tau_parser::bf_ex;
		CHECK( ex_rule.has_value() );
	}
}

TEST_SUITE("parsing bindings ") {

	TEST_CASE("named binding") {
		const char* sample = "{ binding } := { binding }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto named = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_body
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::binding
			| tau_parser::named_binding;
		CHECK( named.has_value() );
	}

	TEST_CASE("source binding") {
		const char* sample = "{ type : binding } := { type : binding }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto source = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_body
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::binding
			| tau_parser::source_binding;
		CHECK( source.has_value() );
	}

	TEST_CASE("source binding type") {
		const char* sample = "{ type : binding } := { type : binding }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto type = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_body
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::binding
			| tau_parser::source_binding
			| tau_parser::type;
		CHECK( type.has_value() );
	}

	TEST_CASE("source binding source") {
		const char* sample = "{ type : binding } := { type : binding }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto source = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_body
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::binding
			| tau_parser::source_binding
			| tau_parser::source;
		CHECK( source.has_value() );
	}

	TEST_CASE("unresolved source binding") {
		const char* sample = "{  : binding } := {  : binding }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto type = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_body
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::binding
			| tau_parser::source_binding
			| tau_parser::type
			| tau_parser::chars;
		CHECK( !type.has_value() );
	}

	TEST_CASE("resolved source binding") {
		const char* sample = "{ type : binding } := { type : binding }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto type = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_body
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::binding
			| tau_parser::source_binding
			| tau_parser::type
			| tau_parser::chars;
		CHECK( type.has_value() );
	}
}

TEST_SUITE("parsing callbacks ") {

	TEST_CASE("bf_and_cb") {
		const char* sample = "$X := { $X bf_and_cb $X }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto and_cb = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_body
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::bf_and_cb;
		CHECK( and_cb.has_value() );
	}

	TEST_CASE("bf_or_cb") {
		const char* sample = "$X := { $X bf_or_cb $X }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto or_cb = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_body
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::bf_or_cb;
		CHECK( or_cb.has_value() );
	}

	TEST_CASE("bf_xor_cb") {
		const char* sample = "$X := { $X bf_xor_cb $X }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto xor_cb = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_body
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::bf_xor_cb;
		CHECK( xor_cb.has_value() );
	}

	TEST_CASE("bf_neg_cb") {
		const char* sample = "$X := { bf_neg_cb $X }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto neg_cb = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_body
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::bf_neg_cb;
		CHECK( neg_cb.has_value() );
	}

	TEST_CASE("bf_subs_cb") {
		const char* sample = "$X := bf_subs_cb $X $X $X.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto subs_cb = lib
			| tau_parser::library
			| tau_parser::rules
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf_body
			| tau_parser::bf
			| tau_parser::bf_subs_cb;
		CHECK( subs_cb.has_value() );
	}

	// The following todos are classified as LOW because they are tested inderectly
	// in other unit/integration tests. However, it is better to have explicit tests.
	//
	// TODO (MEDIUM) add bf_less_cb test
	// TODO (MEDIUM) add bf_less_equal_cb test
	// TODO (MEDIUM) add bf_greater_cb test
	// TODO (MEDIUM) add bf_eq_cb test
	// TODO (MEDIUM) add bf_neq_cb test
	// TODO (MEDIUM) add bf_is_zero_cb test
	// TODO (MEDIUM) add bf_is_one_cb test
	// TODO (MEDIUM) add bf_has_clashing_subformulas_cb test
	// TODO (MEDIUM) add bf_has_subformula_cb test
	// TODO (MEDIUM) add wff_has_clashing_subformulas_cb test
	// TODO (MEDIUM) add wfff_has_subformula_cb test

}
