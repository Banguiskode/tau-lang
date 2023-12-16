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

#include <iostream>

#include "normalizer2.h"

using namespace std;
using namespace idni::tau;

// Trought all the code we would use the following tags to denote different
// types of tasks or notes.
// We could use TODO, DOING, IDEA, FIXME, REVIEW, DOCUMENTATION and MARK. Also,
// we could give a priority to each task by adding HIGH, LOW or MEDIUM between
// parenthesis.
//
// We use the subtags as follows:
// - (IMPORTANT) for main tasks of the project,
// - (HIGH) for tasks that should be done asap as they are important missing
//   functionallity or important improvements,
// - (MEDIUM) for tasks that should be done soon as they are but they are not
//   missing functionallity or important improvements, mostly related to code
//   quality and testing,
// - (LOW) for tasks that should be done at some point but they are not
//   important, mostly related to code quality and testing but not as important as
//   MEDIUM tasks,
// - (VERY LOW) for tasks that should be done at some point but they are not
//   important, mostly related to code quality and testing but not as important as
//   LOW tasks,

//
// Global tasks
//

// TODO (IMPORTANT) normalizer

// TODO (IMPORTANT) satisfability

// TODO (IMPORTANT) execution

// TODO (IMPORTANT) basic UI and I/O api

// TODO (IMPORTANT) basic documentation

// TODO (IMPORTANT) error and runtime error handling

// TODO (IMPORTANT) basic logics (implementation, splitter,...)
// TODO (IMPORTANT) propositional logic
// TODO (IMPORTANT) tau BA

// TODO (IMPORTANT) semantic checks

// TODO (IMPORTANT) cryptographic support

// TODO (IMPORTANT) finite boolean algebras and arithmetic
// - Check SMT coompetition (best seems to be CVC5)
// - SMT-Lib format allow us to interact with several solvers, using the best
//   one for each task.
// - We would use them bit vectors and integer arithmetic (possibly Z3 for bit vectors for finite BA)
// - We could also use them for quantifier free formulas.
//
// Further info in https://en.wikipedia.org/wiki/Satisfiability_modulo_theories#Standardization_and_the_SMT-COMP_solver_competition

// TODO (IMPORTANT) blockchain support
// - acceptance conditions
// - selfamending network
// - user consensus

//
// General tasks that are not related to any specific file.
//


// TODO (MEDIUM) declare a static const lambda instead of a predicates if possible

// TODO (MEDIUM) declare a static const lambda instead of stateless struct possible

// TODO (LOW) split code into h/cpp files

// TODO (MEDIUM) final features should be cotrolled by a command line flag
//
// toggles for debugging, comment properly to enable/disable each feature/debug helper.

// TODO (LOW) review proper use of bf_subs_cb in code

// DOCUMENTATION (LOW) add documentation to the public parts of the code
//
// Just convert the current comments into proper doxygen description.

int main(int /*argc*/, char** /*argv*/) {
	// TODO (MEDIUM) tau main method, parse command line arguments, read input file,...
	// normalize, print output, etc.
	return 0;
}
