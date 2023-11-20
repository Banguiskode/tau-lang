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

// We could use TODO (HIGH|MEDIUM|LOW|nothing), DOING, IDEA, FIXME, REVIEW and MARK.

// TODO (IMPORTANT) deal with runtime errors in the code. 
// For example, if the user provides a formula with errors, we should not continue
// and print garbage. Instead, we should print an error message and exit.

// TODO (MEDIUM) declare a static const lambda instead of a predicates if possible
//
// This could be done in all the code. 

int main(int argc, char** argv) {
	// TODO (LOW) tau main method, parse command line arguments, read input file,...
	// normalize, print output, etc.
	return 0;
}

// TODO (LOW) move to unit tests or delete it
//#include "barr.h"
//#include "out.h"
//#include "anf.h"
//#include "ba.h"

//template<typename B> vector<bdd<B>> bdd<B>::V;
//template<typename B> unordered_map<bdd_node, size_t> bdd<B>::Mn;
//template<typename B> map<B, size_t> bdd<B>::Mb;
//template<typename B> int_t bdd<B>::T;
//template<typename B> int_t bdd<B>::F;
//template<typename B>
//unordered_map<bdd_node, std::shared_ptr<bdd_handle<B>>> bdd_handle<B>::Mn;
//template<typename B>
//map<B, std::shared_ptr<bdd_handle<B>>> bdd_handle<B>::Mb;
//template<typename B> hbdd<B> bdd_handle<B>::htrue;
//template<typename B> hbdd<B> bdd_handle<B>::hfalse;

// all this and init is still not called...
//template<typename B, auto o>
//bool bdd_handle<B, o>::dummy = (bdd_init<B, o>(), true);
//template<typename... BAs, typename... aux>
//bool msba<tuple<BAs...>, aux...>::dummy =
//	(msba<tuple<BAs...>, aux...>::init(), true);


	//typedef msba<tuple<sbf>> fof;
	// typedef barr<sbf> fof;
	//typedef barr<Bool> fof;
	// fof::init();
/*	fof x(true, sbf_T), y(false, sbf_F);
	fof a(true, sbf_F), b(false, sbf_T);
	out(out(cout, x), y);
	out(out(cout, a), b);
	x.normalize();
	y.normalize();
	a.normalize();
	b.normalize();
	out(out(cout, x), y);
	out(out(cout, a), b);
	fof z = (x&y);
	z.normalize();
	out<sbf>(cout, z);*/

/*	sbf f = ("a"s & "x"s) | ("b"s & "x'"s);
	sbf g = ("c"s & "x"s) | ("d"s & "x'"s);
	fof t(true);
	t = (t & fof(true, f));
	t = (t & fof(false, g));
	fof tt(true);*/
//	cout << bdd_handle<fof>::get(t) << endl;
//	tt = (t & fof(true, bdd_handle<fof>::bit(true, 1) & bdd_handle<fof>::get(t)));
/*	out(cout, t);
	cout << t.b << endl;
	t.normalize();
	cout << t.b << endl;
	out(cout, t);*/
//	return 0;
/*	t += bdd_handle<fof>::get(t);
	cout << t << endl;
	cout << (~t) << endl;
	return 0;
	cout << ~(fof(true)+=f) << endl << g << endl << g->subst(dict("x"), f) << endl;
//	cout << anf(f) << endl << anf(g) << endl;
	anf(g).subst(dict("x"), anf(f));
	g = g->subst(dict("x"), f);
//	cout << anf(g) << endl;
//	anf(g).verify();
//	return 0;
	int_t x = dict("x");
	cout << anf(f | g) << endl;
	cout << (anf(f) | anf(g)) << endl;
	assert(anf(f | g) == (anf(f) | anf(g)));
	cout << anf(g->subst(x, f)->sub0(x)) << endl;
	cout << (anf(g).subst(x, anf(f)).subst(x, anf(false)) ) << endl;
	cout << anf(g->subst(x, ~f)->sub1(x)) << endl;
	cout << (anf(g).subst(x, ~anf(f)).subst(x, anf(true))) << endl;

	cout << anf(g->subst(x, f)) << endl;
	cout << (anf(g).subst(x, anf(f))) << endl;
	cout << anf(g->subst(x, ~f)) << endl;
	cout << (anf(g).subst(x, ~anf(f))) << endl;

	cout << anf(g->subst(x, f)->sub0(x) | g->subst(x, ~f)->sub1(x)) << endl;
	cout << (anf(g).subst(x, anf(f)).subst(x, anf(false)) | anf(g).subst(x, ~anf(f)).subst(x, anf(true))) << endl;
	assert(anf((g->subst(x, f))->sub0(x) | (g->subst(x, ~f))->sub1(x)) ==
		((anf(g).subst(x, anf(f))).subst(x, anf(false)) | (anf(g).subst(x, ~anf(f))).subst(x, anf(true))));
	return 0;
	cout << g->sub0(dict("x")) << endl << g->sub1(dict("x")) << endl;*/
/*	int_t x = dict("x");
	cout << anf(g = (g->subst(x, f)->sub0(x) | g->subst(x, ~f)->sub1(x)))
		<< endl << g << endl;
//	cout << anf(g) << endl;
	anf(g).verify();
//	return 0;
	cout << (fof(true) += f).ex(dict("x")) << endl;
	cout << ((fof(true) += f) -= g).ex(dict("x")) << endl;
	return 0;
	tau<Bool, hbdd<Bool>> t(true);
	hbdd<Bool> f = "x"s & "y"s;
//	cout << f << endl;
//	cout << (f | "y'"s )<< endl;
	t += f;
//	cout << t;
	t -= "x"s & "y'"s;
	cout << t;
	cout << t.ex(dict("x"));*/