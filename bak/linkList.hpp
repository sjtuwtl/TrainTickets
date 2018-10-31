#ifndef __list__
#define __list__

#include "classSet.hpp"
#include "toolSet.hpp"
#include <string>

template <class T>
class list {
private:
	struct node {
		T data;
		node *prev, *next;
		
		node(const T &_data, node *p = NULL, node *n = NULL): data(_data), prev(p), next(n) {}
		node():prev(NULL), next(NULL){}
		~node() {};
	};
	
	node *head, *tail;
	size_t curSize;
	
	node *move(int x) const {
		if (x < 0 || x > curSize) throw outOfBound{};
	
		node *p;
		p = head;
		for (int i = 0; i < x; ++i) p = p -> next;
	
		return p;
	}
	
public:
	
	class const_iterator;
	class iterator {
		friend class list;
	private:
		 node *p;
	public:
		iterator() {
			p = NULL;
		}
		iterator(node *_p): p(_p) {}
		iterator(const iterator &other): p(other.p) {}
		iterator operator ++ (int) {
			if (p -> next == NULL) throw invalid_iterator{};
			iterator tmp(*this);
			p = p -> next;
			return tmp;
		}
		iterator & operator ++ () {
			if (p -> next == NULL) throw invalid_iterator{};
			p = p -> next;
			return *this;
		}
		iterator operator -- (int) {
			if (p -> prev -> prev == NULL) throw invalid_iterator{};
			iterator tmp(*this);
			p = p -> prev;
			return *this;
		}
		iterator &operator -- () {
			if (p -> prev -> prev == NULL) throw invalid_iterator{};
			p = p -> prev;
			return *this;
		}
		T &operator * () const {
			return p -> data;
		}
		bool operator == (const iterator &rhs) const {
			return p == rhs.p;
		}
		bool operator == (const const_iterator &rhs) const {
			return p == rhs.p;
		}
		bool operator != (const iterator &rhs) const {
			return p != rhs.p;
		}
		bool operator != (const const_iterator &rhs) const {
			return p != rhs.p;
		}

		T *operator -> () const noexcept {
			return &(p -> data);
		}
	};
	class const_iterator {
		friend class list;
	private:
		const node *p;
	public:
		const_iterator(): p(NULL) {}
		const_iterator(const const_iterator &other): p(other.p) {}
		const_iterator(const iterator &other): p(other.p) {}
		
		const_iterator(node *_p): p(_p) {}
		
		const T &operator * () const {
			return p -> data;
		}
		
		const_iterator operator ++ (int) {
			if (p -> next == NULL) throw invalid_iterator{};
			iterator tmp(*this);
			p = p -> next;
			return tmp;
		}
		const_iterator & operator ++ () {
			if (p -> next == NULL) throw invalid_iterator{};
			p = p -> next;
			return *this;
		}
		const_iterator operator -- (int) {
			if (p -> prev -> prev == NULL) throw invalid_iterator{};
			iterator tmp(*this);
			p = p -> prev;
			return *this;
		}
		const_iterator &operator -- () {
			if (p -> prev -> prev == NULL) throw invalid_iterator{};
			p = p -> prev;
			return *this;
		}
		
		bool operator == (const iterator &rhs) const {
			return p == rhs.p;
		}
		bool operator == (const const_iterator &rhs) const {
			return p == rhs.p;
		}
		bool operator != (const iterator &rhs) const {
			return p != rhs.p;
		}
		bool operator != (const const_iterator &rhs) const {
			return p != rhs.p;
		}
		const T * operator -> () const {
			return &(p -> data);
		}
	};
	
	list() {
		head = new node;
		head -> next = tail = new node;
		tail -> prev = head;
		curSize = 0;
	}

	~list(){clear(); delete head; delete tail;}

	void clear() {
		for (node *p = head -> next, *q; p != tail; p = q) {
			q = p -> next;
			delete p;
		}
		head -> next = tail;
		tail -> prev = head;
		curSize = 0;
	}

	iterator insert(int x, const T &a) {
		if (x < 0 || x > curSize) throw outOfBound{};
		node *p = move(x), *q = p -> next;
		p -> next = q -> prev = new node (a, p, q);
		++curSize; 
		return iterator(p -> next);
	}

	iterator preInsert(iterator pre, const T &a) {
		node *p = pre.p;
		if (p == NULL) throw invalid_iterator{};
		p -> prev = new node(a, p -> prev, p);
		p -> prev -> prev -> next = p -> prev;
		++curSize;
		return iterator(p -> prev);
	}

	iterator sufInsert(iterator suf, const T &a) {
		node *p = suf.p;
		if (p == NULL) throw invalid_iterator{};
		p -> next = new node(a, p, p -> next);
		p -> next -> next -> prev = p -> next;
		++curSize;
		return iterator(p -> next);
	}

	void remove(int x) {
		if (x < 0 || x >= curSize) throw outOfBound{};
		node *cur = move(x), *p = cur -> prev, *q = cur -> next;
		p -> next = q;
		q -> prev = p;
		delete cur;
		--curSize;
	}

	void remove(iterator it) {
		node *cur = it.p;
		if (cur == NULL || cur -> prev == NULL || cur -> next == NULL) throw invalid_iterator{};
		node *p = cur -> prev, *q = cur -> next;
		p -> next = q;
		q -> prev = p;
		delete cur;
		--curSize;
	}

	iterator search(const T &a) {
		for (node *p = head -> next; p != tail; p = p -> next) {
			if (p -> data == a) return iterator(p);
		}
		return end();
	}	

	const_iterator search(const T &a) const {
		for (node *p = head -> next; p != tail; p = p -> next) {
			if (p -> data == a) return const_iterator(p);
		}
		return cend();
	}	

	void sufRemove(iterator it) {
		node *p = it.p;
		if (p -> next == NULL || p -> next == tail) throw invalid_iterator{};
		node * tmp = p -> next;
		p -> next = tmp -> next;
		tmp -> next -> prev = p;
		--curSize;
		delete tmp;
	}

	void preRemove(iterator it) {
		node *p = it.p;
		if (p == head || p == head -> next) throw invalid_iterator{};
		node *tmp = p -> prev;
		p -> prev = tmp -> prev;
		tmp -> prev -> next = p;
		--curSize;
		delete tmp;
	}

	void read(fstream &fin) {
		clear();
		size_t tmpLen;
		fin.read(reinterpret_cast<char *> (&tmpLen), sizeof tmpLen);
		T tmp;
		while (curSize < tmpLen) {
			tmp.read(fin);
			insert(0, tmp);
		}
	}

	void write(fstream &fout) {
		fout.write(reinterpret_cast<const char *> (&curSize), sizeof curSize);
		for (node *p = tail -> prev; p != head; p = p -> prev) {
			p -> data.write(fout);	
		}
	}
	size_t length() const { return curSize; }
	
	iterator begin() const { return iterator(head -> next); }
	iterator end() const { return iterator(tail); }
	const_iterator cbegin() const { return const_iterator(head -> next); }
	const_iterator cend() const { return const_iterator(tail); }
};

#endif
