#ifndef SJTU_DEQUE_HPP
#define SJTU_DEQUE_HPP

#include "exceptions.hpp"

#include <cstddef>

namespace sjtu { 

template<class T>
class deque {
public:
	struct node {
		node *prev, *next;
		T *value[1010];
		size_t Size;
		node() {
			prev = NULL;
			next = NULL;
			Size = 0;
			for (size_t i = 0; i <= 1009; i++) value[i] = NULL;
		}
		node(node * pre, node * nxt, size_t S) : Size(S), prev(pre), next(nxt) {}
		node(const node *p): Size(p -> Size) {
			prev = p -> prev;
			next = p -> next;
			for (size_t i = 1; i <= p -> Size; i++) value[i] = new T(*(p -> value[i]));
		}
		~node() {
			size_t i = 1;
			while (i <= 1009 && i <= Size) {
				if (value[i] != NULL) 
					delete value[i];
				value[i] = NULL;
				i++;
			}
		}
	} *head, *tail;
	
	size_t totalsize;
	
	node * Insert(node * p, size_t pos, T value, bool f) {
		if (p == head) {
			node *tmp;
			tmp = new node;
			head -> next = tmp;
			tmp -> next = tail;
			tail -> prev = tmp;
			tmp -> prev = head;
			tmp -> Size = 1;
			pos = 1;
			//p = tmp;
			tmp -> value[1] = new T(value); 
			//*(p->value[1]) = value;
			totalsize++;
			if (f) return p; else return p->prev;
		}
		else if (p -> Size < 1000) {
			p -> Size++;totalsize++;
			p -> value[p->Size] = new T(*(p -> value[p->Size - 1]));
			for (size_t i = p -> Size - 1; i >= pos + 1; i--) 
				(p -> value[i]) = (p -> value[i - 1]);
			*(p -> value[pos]) = value;
			if (f) return p; else return p->prev;
		}
		else {
			//totalsize++;
			node *tmp;
			tmp = new node;
			tmp -> next = p -> next;
			tmp -> prev = p;
			(p -> next) -> prev = tmp;
			p -> next = tmp;
			p -> Size = tmp -> Size = 500;
			for (size_t i = 1; i <= 500; i++) {
				tmp->value[i] = new T(*(p -> value[i + 500]));
			//	*(tmp -> value[i]) = *(p -> value[i + 500]);
				delete p->value[i + 500];
				p->value[i + 500] = NULL;
			}
			if (pos > 500) return Insert(tmp, pos - 500, value, 0);
			else return Insert(p, pos, value, 1);
		}
		
	}
/*	void Erase(node* p, size_t pos) {
		if (p -> Size == 1) {
			p -> prev -> next = p -> next;
			p -> next -> prev = p -> prev;
			delete p;
		}
		else {
			for (size_t i = pos; i <= p -> Size - 1; i++)	(p -> value[i]) = (p -> value[i + 1]);
			p -> Size--;
		}
		totalsize--;
	}*/

	void Clear(node *cur) {
		if (cur == NULL) return;
		Clear(cur -> next);
		//for (size_t i = 1; i <= cur -> Size; i++) delete v[i];
		delete cur;
	}
	
	class const_iterator;
	class iterator {
		friend class deque;
	private:
		size_t k;
		deque *d;
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
	public:
		iterator() {
				// TODO
			}
		iterator(const iterator &other) :k(other.k), d(other.d) {
			// TODO
		}
		iterator(size_t p, deque * l) :k(p), d(l) {}
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, the behaviour is **undefined**.
		 * as well as operator-
		 */
		iterator operator+(const int &n)  {
			k += n;
			return *this;
			//TODO
		}
		iterator operator-(const int &n)  {
			k -= n;
			return *this;
			//TODO
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invaild_iterator.
		int operator-(const iterator &rhs) const {
			if (d == rhs.d) return k - rhs.k;
			else throw invalid_iterator();
			//TODO
		}
		iterator operator+=(const int &n) {
			iterator tmp(*this);
			k += n;
			return tmp;
			//TODO
		}
		iterator operator-=(const int &n) {
			iterator tmp(*this);
			k -= n;
			return tmp;
			//TODO
		}
		/**
		 * TODO iter++
		 */
		iterator operator++(int) {
			iterator tmp(*this);
			++k;
			return tmp;
		}
		/**
		 * TODO ++iter
		 */
		iterator& operator++() {
			++k;
			return *this;
		}
		/**
		 * TODO iter--
		 */
		iterator operator--(int) {
			iterator tmp(*this);
			--k;
			return tmp;
		}
		/**
		 * TODO --iter
		 */
		iterator& operator--() {
			--k;
			return *this;
		}
		/**
		 * TODO *it
		 */
		T& operator*() const {
			if (k >= 1 && k <= d -> totalsize) {
				node *p(d -> head);
				size_t tmp = k;
				p = p -> next;
				while (p != d -> tail && tmp >= p -> Size) {
						tmp -= p -> Size;
						p = p -> next;
					}
				if (tmp == 0) return *(p -> prev -> value[p -> prev -> Size]);
				else return *(p -> value[tmp]);
				
			}
			else throw index_out_of_bound();
		}
		/**
		 * TODO it->field
		 */
		T* operator->() const noexcept {
			if (k >= 1 && k <= d -> totalsize) {
				node *p(d -> head);
				size_t tmp = k;
				p = p -> next;
				while (p != d -> tail && tmp >= p -> Size) {
						tmp -= p -> Size;
						p = p -> next;
					}
				if (tmp == 0) return (p -> prev -> value[p -> prev -> Size]);
				else return (p -> value[tmp]);
				
			}
			else throw index_out_of_bound();
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const {
			return k == rhs.k;
		}
		bool operator==(const const_iterator &rhs) const {
			return k == rhs.k;
		}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const {
			return k != rhs.k;
		}
		bool operator!=(const const_iterator &rhs) const {
			return k != rhs.k;
		}
	};
	class const_iterator {
		// it should has similar member method as iterator.
		//  and it should be able to construct from an iterator.
		friend class deque;
		
		private:
			size_t k;
			deque *d;
			// data members.
		public:
			const_iterator() {
				// TODO
			}
			const_iterator(const const_iterator &other):k(other.k), d(other.d) {
				// TODO
			}
			const_iterator(const iterator &other):k(other.k), d(other.d) {
				// TODO
			}
			const_iterator(size_t p, deque * l) : k(p) , d(l) {}
			const_iterator operator+(const int &n) const {
				k += n;
				return *this;
				//TODO
			}
			const_iterator operator-(const int &n) const {
				k -= n;
				return *this;
				//TODO
			}
			const int operator-(const iterator &rhs) const {
				if (d == rhs.d) return k - rhs.k;
				else throw invalid_iterator();
				//TODO
			}
			const_iterator operator+=(const int &n) {
				iterator tmp(*this);
				k += n;
				return tmp;
				//TODO
			}
			const_iterator operator-=(const int &n) {
				iterator tmp(*this);
				k -= n;
				return tmp;
				//TODO
			}
			const_iterator operator++(int) {
				iterator tmp(*this);
				++k;
				return tmp;
			}
			const_iterator& operator++() {
				++k;
				return *this;
			}
			const_iterator operator--(int) {
				iterator tmp(*this);
				--k;
				return tmp;
			}
			const_iterator& operator--() {
				--k;
				return *this;
			}
			const T& operator*() const {
				if (k >= 1 && k <= d -> totalsize) {
				node *p(d -> head);
				size_t tmp = k;
				p = p -> next;
				while (p != d -> tail && tmp >= p -> Size) {
						tmp -= p -> Size;
						p = p -> next;
					}
				if (tmp == 0) return *(p -> prev -> value[p -> prev -> Size]);
				else return *(p -> value[tmp]);
				}
				else throw index_out_of_bound();
			}
			const T* operator->() const noexcept {
				if (k >= 1 && k <= d -> totalsize) {
				node *p(d -> head);
				size_t tmp = k;
				p = p -> next;
				while (p != d -> tail && tmp >= p -> Size) {
						tmp -= p -> Size;
						p = p -> next;
					}
				if (tmp == 0) return (p -> prev -> value[p -> prev -> Size]);
				else return (p -> value[tmp]);
				}
				else throw index_out_of_bound();
			}
			bool operator==(const iterator &rhs) const {
				return k == rhs.k;
			}
			bool operator==(const const_iterator &rhs) const {
				return k == rhs.k;
			}
			bool operator!=(const iterator &rhs) const {
				return k != rhs.k;
			}
			bool operator!=(const const_iterator &rhs) const {
				return k != rhs.k;
			}
			// And other methods in iterator.
			// And other methods in iterator.
			// And other methods in iterator.
	};
	/**
	 * TODO Constructors
	 */
	deque() {
		head = new node;
		tail = new node;
		head -> next = tail;
		tail -> prev = head;
		totalsize = 0;
	}
	deque(const deque &other) : totalsize(other.totalsize){
		head = new node;
		tail = new node;
		head -> next = tail;
		tail -> prev = head;
		node *p(other.head), *q(head);
		p = p -> next;
		int i = 1;
		while (p != other.tail) {
			//cout << i << endl;
			i++;
			//	cout << 1;
			node *tmp;
			tmp = new node(p);
			q -> next = tmp;
			tmp -> next = tail;
			tail -> prev = tmp;
			tmp -> prev = q;
			q = q -> next;
			p = p -> next;
		}
		//cout <<endl;
	}
	/**
	 * TODO Deconstructor
	 */
	~deque() {
		Clear(head);
		//delete head;
		//delete tail;
		head = NULL;
		tail = NULL;
	}
	/**
	 * TODO assignment operator
	 */
	deque &operator=(const deque &other) {
		if (this == &other) return *this;
		
		totalsize = other.totalsize;
		Clear(head);
		head = new node;
		tail = new node;
		head -> next = tail;
		tail -> prev = head;
		node *p(other.head), *q(head);
		p = p -> next;
		int i = 1;
		while (p != other.tail) {
			//cout << i << endl;
			i++;
			node *tmp;
			tmp = new node(p);
			q -> next = tmp;
			tmp -> next = tail;
			tail -> prev = tmp;
			tmp -> prev = q;
			q = q -> next;
			p = p -> next;
		}
	}
	/**
	 * access specified element with bounds checking
	 * throw index_out_of_bound if out of bound.
	 */
	T & at(const size_t &pos) {
		if (pos + 1 <= 0) throw index_out_of_bound();
		node *q(head);
		size_t tmp = pos + 1;
		q = q->next;
		while (q != tail && tmp >= q->Size) {
			tmp -= q->Size;
			q = q->next;
		}
		if (q == tail && tmp > 0) throw index_out_of_bound();
		else {
			if (tmp == 0) return *(q->prev->value[q->prev->Size]);
			else return *(q->value[tmp]);
		}
	}
	const T & at(const size_t &pos) const {
		if (pos + 1 <= 0) throw index_out_of_bound();
		node *q(head);
		size_t tmp = pos + 1;
		q = q->next;
		while (q != tail && tmp >= q->Size) {
			tmp -= q->Size;
			q = q->next;
		}
		if (q == tail && tmp > 0) throw index_out_of_bound();
		else {
			if (tmp == 0) return *(q->prev->value[q->prev->Size]);
			else return *(q->value[tmp]);
		}
	}
	T & operator[](const size_t &pos) {
		if (pos + 1 <= 0) throw index_out_of_bound();
		node *q(head);
		size_t tmp = pos + 1;
		q = q -> next;
		while (q != tail && tmp >= q -> Size) {
			tmp -= q -> Size;
			q = q -> next;
		}
		if (q == tail && tmp > 0) throw index_out_of_bound();
		else {
			if (tmp == 0) return *(q -> prev -> value[q -> prev -> Size]);
			else return *(q -> value[tmp]);
		}
	}
	const T & operator[](const size_t &pos) const {
		if (pos + 1 <= 0) throw index_out_of_bound();
		node *q(head);
		size_t tmp = pos + 1;
		q = q->next;
		while (q != tail && tmp >= q->Size) {
			tmp -= q->Size;
			q = q->next;
		}
		if (q == tail && tmp > 0) throw index_out_of_bound();
		else {
			if (tmp == 0) return *(q->prev->value[q->prev->Size]);
			else return *(q->value[tmp]);
		}
	}
	/**
	 * access the first element
	 * throw container_is_empty when the container is empty.
	 */
	const T & front() const {
		if (totalsize == 0) throw container_is_empty();
		else return(*(head -> next -> value[1]));
	}
	/**
	 * access the last element
	 * throw container_is_empty when the container is empty.
	 */
	const T & back() const {
		if (totalsize == 0) throw container_is_empty();
		else return(*(tail -> prev -> value[tail -> prev -> Size]));
	}
	/**
	 * returns an iterator to the beginning.
	 */
	iterator begin() {
		return iterator(1, this);	
	}
	const_iterator cbegin() const {
		return const_iterator(1, this);
	}
	/**
	 * returns an iterator to the end.
	 */
	iterator end() {
		return iterator(totalsize + 1, this);
	}
	const_iterator cend() const {
		return iterator(totalsize + 1, this);
	}
	/**
	 * checks whether the container is empty.
	 */
	bool empty() const {
		return totalsize == 0;
	}
	/**
	 * returns the number of elements
	 */
	size_t size() const {
		return totalsize;
	}
	/**
	 * clears the contents
	 */
	void clear() {
		Clear(head);
		head = NULL;
		tail = NULL;
		head -> next = tail;
		tail -> prev = head;
		totalsize = 0;
	}
	/**
	 * inserts elements at the specified locat on in the container.
	 * inserts value before pos
	 * returns an iterator pointing to the inserted value
	 *     throw if the iterator is invalid or it point to a wrong place.
	 */
	iterator insert(iterator pos, const T &value) {
		if (pos.k <= 0) throw invalid_iterator();
		node *q(head);
		size_t tmp = pos.k;
		q = q -> next;
		if (totalsize == 0) head = Insert(head, 0, value, 1);
		else {
			while (q != tail && tmp >= q -> Size) {
				tmp -= q -> Size;
				q = q -> next;
			}
			if (q == tail && tmp > 0) throw invalid_iterator();
			else {
				if (tmp == 0) q = Insert(q -> prev, q -> prev -> Size, value, 1);
				else q = Insert(q, tmp, value, 1);
				return pos;
			}
		}
	}
	/**
	 * removes specified element at pos.
	 * removes the element at pos.
	 * returns an iterator pointing to the following element, if pos pointing to the last element, end() will be returned.
	 * throw if the container is empty, the iterator is invalid or it points to a wrong place.
	 */
	iterator erase(iterator pos) {
		if (pos.k <= 0) throw invalid_iterator();
		if (totalsize == 0) throw container_is_empty();
		node *q(head);
		size_t tmp = pos.k;
		q = q -> next;
		while (q != tail && tmp >= q -> Size) {
			tmp -= q -> Size;
			q = q -> next;
		}
		if (q == tail && tmp > 0) throw invalid_iterator();
		else {
			if (tmp == 0) {
				if (q->prev -> Size == 1) {
					q -> prev -> prev -> next = q;
					q -> prev = q -> prev -> prev;
					delete q -> prev;
				}
				else {
					delete q -> prev -> value[q -> prev -> Size];
					q -> prev -> Size--;
				}
				totalsize--;
			}//Erase(q->prev, q->prev->Size);
			else {
				if (q -> Size == 1) {
					q -> prev -> next = q -> next;
					q -> next -> prev = q -> prev;
					delete q;
				}
				else {
					delete q -> value[tmp];
					for (size_t i = tmp; i <= q -> Size - 1; i++)
						(q -> value[i]) = (q -> value[i + 1]);
					q -> Size--;
				}
				totalsize--;
			}//Erase(q, tmp);
			if (totalsize) return pos; else return end();
		}
	}
	/**
	 * adds an element to the end
	 */
	void push_back(const T &value) {
		node *t(tail->prev);
		t = Insert(t, tail -> prev -> Size, value, 1);
		if (totalsize > 1) {
			T * tmp;
			tmp = tail->prev->value[tail->prev->Size];
			tail->prev->value[tail->prev->Size] = tail->prev->value[tail->prev->Size - 1];
			tail->prev->value[tail->prev->Size - 1] = tmp;
		}
	}
	/**
	 * removes the last element
	 *     throw when the container is empty.
	 */
	void pop_back() {
		if (totalsize == 0) throw container_is_empty();
		else {
			if (tail->prev->Size == 1) {
				tail->prev->prev->next = tail;
				tail->prev = tail->prev->prev;
				delete tail->prev;
			}
			else {
				delete (tail->prev->value[tail->prev->Size]);
				//tail->prev->value[tail->prev->Size] = NULL;
				tail->prev->Size--;
			}
			totalsize--;
		}
	}
	/**
	 * inserts an element to the beginning.
	 */
	void push_front(const T &value) {
		if (totalsize == 0) head = Insert(head, 0, value, 1);
		else head -> next = Insert(head -> next, 1, value, 1);
	}
	/**
	 * removes the first element.
	 *     throw when the container is empty.
	 */
	void pop_front() {
		if (totalsize == 0) throw container_is_empty();
		else {
			if (head->next->Size == 1) {
				head->next->next->prev = head;
				head->next = head->next->next;
				delete head->next;
			}
			else {
				delete head->next->value[1];
				for (size_t i = 1; i <= head->next->Size - 1; i++)	
					(head->next->value[i]) = (head->next->value[i + 1]);
				head->next->Size--;
			}
			totalsize--;
		}
	}
};

}

#endif
