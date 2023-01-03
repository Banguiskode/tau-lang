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
#ifndef __OUT_H__
#define __OUT_H__
#include "nso.h"
#include "dict.h"
#include "bool.h"
#include "anf.h"
#include <ostream>
#include <sstream>

ostream& operator<<(ostream& os, const Bool& b) { return os << (b.b ? 1 : 0); }

template<typename B> ostream& operator<<(ostream& os, const hbdd<B>& f) {
	set<pair<B, vector<int_t>>> dnf = f->dnf();
	size_t n = dnf.size();
	set<string> ss;
	for (auto& c : dnf) {
		set<string> s;
		assert(!(c.first == false));
		stringstream t;
		if (!(c.first == true)) t << '{' << c.first << '}';
		for (int_t v : c.second)
			if (v < 0) s.insert(string(dict(-v)) + "'"s);
			else s.insert(dict(v));
		for (auto& x : s) t << x;
		ss.insert(t.str());
	}
	for (auto& s : ss) {
		os << s;
		if (--n) os << " | ";
	}
	return os;
}

template<typename B> ostream& operator<<(ostream& os, const clause<B>& c) {
	if (c.first) os << c.first << " = 0" << endl;
	for (const hbdd<B>& f : c.second) os << f << " != 0" << endl;
	return os;
}

template<typename... Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>& t) {
	auto f = [&os](auto x) { os << x; };
	(f(get<Ts>(t)), ...);
	return os;
}

template<typename... BAs>
ostream& operator<<(ostream& os, const nso<BAs...>& t) {
	if (t == false) return os << 'F';
	if (t == true) return os << 'T';
	DBG(assert(!t.empty());)
	size_t n = t.size();
	for (auto& c : t) if (os << c; --n) os << " || " << endl;
	return os;
}

ostream& operator<<(ostream& os, const anf& a) {
	size_t n = a.size();
	set<string> ss;
	for (auto& x : a) {
		set<string> s;
		for (auto y : x) s.insert(dict(y));
		string t;
		for (const string& y : s) t += y;
		ss.insert(t);
	}
	for (const string& s : ss) {
		os << s;
		if (--n) os << " + ";
	}
	return os;
}
#endif
