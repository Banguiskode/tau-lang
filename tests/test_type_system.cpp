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

#include "../src/doctest.h"
#include "../src/defs.h"
#include "../src/formula.h"
#include "../src/bool.h"
#include "test_helpers.h"

using namespace idni::rewriter;
using namespace idni::tau;
using namespace std;

namespace testing = doctest;

TEST_SUITE("is_resolved_predicate") {

	TEST_CASE("is_resolved_predicate: true") {
		static constexpr char* sample =	"$X := { bool : src_code }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto type = lib 
			| tau_parser::library 
			| tau_parser::rules 
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::binding
			| tau_parser::source_binding
			| tau_parser::type;
		CHECK( type.has_value() );	
		CHECK( is_resolved_predicate<Bool>(type.value()) );	
	}

	TEST_CASE("is_resolved_predicate: false") {
		static constexpr char* sample =	"$X := { : src_code }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto type = lib 
			| tau_parser::library 
			| tau_parser::rules 
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::binding
			| tau_parser::source_binding
			| tau_parser::type;
		CHECK( type.has_value() );	
		CHECK( !is_resolved_predicate<Bool>(type.value()) );	
	}
}

TEST_SUITE("is_unresolved_predicate") {

	TEST_CASE("is_resolved_predicate: true") {
		static constexpr char* sample =	"$X := { : src_code }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto type = lib 
			| tau_parser::library 
			| tau_parser::rules 
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::binding
			| tau_parser::source_binding
			| tau_parser::type;
		CHECK( type.has_value() );	
		CHECK( is_unresolved_predicate<Bool>(type.value()) );	
	}

	TEST_CASE("is_unresolved_predicate: false") {
		static constexpr char* sample =	"$X := { bool : src_code }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto type = lib 
			| tau_parser::library 
			| tau_parser::rules 
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf
			| tau_parser::bf_constant
			| tau_parser::constant
			| tau_parser::binding
			| tau_parser::source_binding
			| tau_parser::type;
		CHECK( type.has_value() );	
		CHECK( !is_unresolved_predicate<Bool>(type.value()) );	
	}
}

TEST_SUITE("is_unresolved") {

	TEST_CASE("is_resolved_predicate: true") {
		static constexpr char* sample =	"$X := { : src_code }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		CHECK( is_unresolved<Bool>(lib) );	
	}

	TEST_CASE("is_unresolved_predicate: false") {
		static constexpr char* sample =	"$X := { bool : src_code }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		CHECK( !is_unresolved<Bool>(lib) );	
	}
}

TEST_SUITE("resolve_type") {

	TEST_CASE("unresolved case") {
		static constexpr char* sample =	"$X := ({ : src_code } bf_and { bool : src_code }).";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto unresolved = lib 
			| tau_parser::library 
			| tau_parser::rules 
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf;
		auto result = resolve_type<Bool>(unresolved.value());
		CHECK( result != unresolved.value() );	
	}

	TEST_CASE("resolved case") {
		static constexpr char* sample =	"$X := { bool : src_code }.";
		auto src = make_tau_source(sample);
		auto lib = make_statement(src);
		auto resolved = lib 
			| tau_parser::library 
			| tau_parser::rules 
			| tau_parser::rule
			| tau_parser::bf_rule
			| tau_parser::bf;
		auto result = resolve_type<Bool>(resolved.value());
		CHECK( result == resolved.value() );	
	}
}