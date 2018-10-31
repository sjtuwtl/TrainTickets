#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "RB_Tree.hpp"
#include <fstream>
using std::fstream;
using std::pair;

template<
	class Key,
	class T,
	class Compare = std::less<Key>
> class map: public RB_Tree<Key, T, Compare> {

private:
	typedef pair<const Key, T> value_type;
	typedef typename RB_Tree<Key, T, Compare>::node node;

public:

	T &operator [] (const Key &x) {
		T tmp;
		auto cur = this -> insert({x, tmp});
		return cur.first -> second;
	}
	
	const T & operator [] (const Key &key) const {
		auto res = this -> _find(key);
		node *x = this -> _checkFindRes(res);
		if (!x) throw index_out_of_bound{};
		return x -> value -> second;
	}
	
	T & at(const Key &key) {
		auto res = this -> _find(key);
		node *x = this -> _checkFindRes(res);
		if (!x) throw index_out_of_bound{};
		return x -> value -> second;
	}
	
	const T & at(const Key &key) const {
		auto res = this -> _find(key);
		node *x = this -> _checkFindRes(res);
		if (!x) throw index_out_of_bound{};
		return x -> value -> second;
	}
	
	bool empty() const { return this -> root == NULL; }
	
	size_t count(const Key &key) const { return this ->_checkFindRes(this -> _find(key)) ? 1 : 0; }
	
};

template<
	class Key,
	class Compare = std::less<Key>
> class MyMap: public map<Key, int, Compare> {
private:

	typedef typename RB_Tree<Key, int, Compare>::node node;
	typedef pair< pair<Key, int>, int> pir;

	void _inTree(fstream &fin, node *(&p), node *pnt) {
		pir nod;
		nod.first.first.read(fin);
        fin >> nod.first.second >> nod.second;
		if (nod.first.second == -1) {
			p = NULL;
		}
		else {
            ++this -> curSize;
			p = new node(nod.first);
			_inTree(fin, p -> ch[0], p);
			this -> _updateLink(p, this -> tail -> prev, this -> tail);
			_inTree(fin, p -> ch[1], p);
			p -> pnt = pnt;
			p -> color = nod.second;
		}
	}
	
	void _outTree(fstream &fout, node *p) const {
		pir nod;
		if (p == NULL) {
			nod.first.second = -1;
			nod.first.first.write(fout);
            fout << nod.first.second << ' ';
            fout << nod.second << ' ';
			return;
		}
		nod.first = *(p -> value); nod.second = p -> color;
		nod.first.first.write(fout);
        fout << nod.first.second << ' ';
        fout << nod.second << ' ';
		_outTree(fout, p -> ch[0]);
		_outTree(fout, p -> ch[1]);
	}

public:
	
	void read(fstream &fin) {
		this -> clear();
		_inTree(fin, this -> root, NULL);
	}
	
	void write(fstream &fout) const {
		_outTree(fout, this -> root);
	}
};



#endif
