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
		T *value[3010];
		size_t Size;
		int beg = 1505; 
		node() {
			prev = NULL;
			next = NULL;
			Size = 0;
			//for (size_t i = 0; i <= 1009; i++) value[i] = NULL;
		}
		node(node * pre, node * nxt, size_t S) : Size(S), prev(pre), next(nxt) {}
		node(const node *p): Size(p -> Size),beg(p->beg) {
			prev = p -> prev;
			next = p -> next;
			for (size_t i = beg + 1; i <= beg + Size; i++) value[i] = new T(*(p -> value[i]));
		}
		~node() {
			for (size_t i = beg + 1; i <= beg + Size; i++) {
				if (value[i]) 
					delete value[i];
				value[i] = NULL;
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
			tmp -> beg = 1505;
			tmp -> Size = 1;
			pos = 1;
			//p = tmp;
			tmp -> value[tmp -> beg + 1] = new T(value); 
			//*(p->value[1]) = value;
			totalsize++;
			if (f) return p; else return p->prev;
		}
		else if (p -> Size < 1500) {
			p -> Size++;totalsize++;
			if (pos == 1) {
				p->beg--;
				p -> value[p->beg + 1] = new T(value);
				return p;
			}
			else {
			
			p -> value[p->Size + p->beg] = new T(*(p -> value[p->Size + p->beg - 1]));
			for (size_t i = p -> Size - 1; i >= pos + 1; i--) 
				*(p -> value[i + p->beg]) = *(p -> value[i + p->beg - 1]);
			*(p -> value[pos + p->beg]) = value;
			if (f) return p; else return p->prev;}
		}
		else {
			//totalsize++;
			node *tmp;
			tmp = new node;
			tmp -> next = p -> next;
			tmp -> prev = p;
			(p -> next) -> prev = tmp;
			p -> next = tmp;
			p -> Size = tmp -> Size = 750;
			for (size_t i = 1; i <= 750; i++) {
				tmp->value[i + 1505] = (p -> value[p->beg + i + 750]);
			//	*(tmp -> value[i]) = *(p -> value[i + 500]);
			//	delete p->value[p->beg + i + 500];
			//	p->value[p->beg + i + 500] = NULL;//?
			}
			if (p -> beg < 1505) {
				for (size_t i = 750; i >= 1; i--)
					p -> value[1505 + i] = p -> value[p->beg + i];
			}
			else if (p -> beg > 1505) {
				for (size_t i = 1; i <= 750; i++)
					p -> value[1505 + i] = p -> value[p -> beg + i];
			}
			p -> beg = tmp -> beg = 1505;
			if (pos > 750) return Insert(tmp, pos - 750, value, 0);
			else return Insert(p, pos, value, 1);
		}
		
	}
	void Erase(node* &p, size_t pos) {
		if (p -> Size == 1) {
			node *q(p);
			p -> prev -> next = q -> next;
			p -> next -> prev = q -> prev;
			delete p;
		}
		else {
			if (p -> value[p->beg + pos] != NULL) delete p->value[p->beg + pos];
			for (size_t i = pos; i <= p -> Size - 1; i++)	(p -> value[p->beg +i]) = (p -> value[p->beg + i + 1]);
			p -> Size--;
		}
		totalsize--;
	}

	void Clear(node *cur) {
		if (cur == tail) return;
		Clear(cur -> next);
		//for (size_t i = 1; i <= cur -> Size; i++) delete v[i];
		delete cur;
	}
	
	class const_iterator;
	class iterator {
		friend class deque;
	private:
		size_t k;
		const deque *d;
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
		iterator(size_t p, const deque * l) :k(p), d(l) {}
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
			k += n;
			return *this;
			//TODO
		}
		iterator operator-=(const int &n) {
			k -= n;
			return *this;
			//TODO
		}
		/**
		 * TODO iter++
		 */
		iterator operator++(int) {
			iterator tmp(*this);
			tmp.k = k; 
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
			tmp.k = k; 
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
				if (tmp == 0) return *(p -> prev -> value[p->prev->beg + p -> prev -> Size]);
				else return *(p -> value[p->beg + tmp]);
				
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
				if (tmp == 0) return (p -> prev -> value[p->prev->beg + p -> prev -> Size]);
				else return (p -> value[p->beg + tmp]);
				
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
			const deque *d;
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
			const_iterator(size_t p, const deque * l) : k(p) , d(l) {}
			const_iterator operator+(const int &n) {
				k += n;
				return *this;
				//TODO
			}
			const_iterator operator-(const int &n) {
				k -= n;
				return *this;
				//TODO
			}
			const int operator-(const const_iterator &rhs) const {
				if (d == rhs.d) return k - rhs.k;
				else throw invalid_iterator();
				//TODO
			}
			const_iterator operator+=(const int &n) {
				k += n;
				return *this;
				//TODO
			}
			const_iterator operator-=(const int &n) {
				k -= n;
				return *this;
				//TODO
			}
			const_iterator operator++(int) {
				const_iterator tmp(*this);
				tmp.k = k; 
				++k;
				return tmp;
			}
			const_iterator& operator++() {
				++k;
				return *this;
			}
			const_iterator operator--(int) {
				const_iterator tmp(*this);
				tmp.k = k; 
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
				if (tmp == 0) return *(p -> prev -> value[p->prev->beg + p -> prev -> Size]);
				else return *(p -> value[p->beg + tmp]);
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
				if (tmp == 0) return (p -> prev -> value[p->prev->beg + p -> prev -> Size]);
				else return (p -> value[p->beg + tmp]);
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
		if (other.head == NULL && other.tail == NULL) {}
		else {
		node *p(other.head), *q(head);
		p = p -> next;
		int i = 1;
		while (p != other.tail) {
			//cout << i << endl;
			i++;
			//	cout << 1;
			node *tmp;
			tmp = new node(p);
			q->next = tmp;
			tmp->next = tail;
			tail->prev = tmp;
			tmp->prev = q;
			q = q->next;
			p = p->next;
		}
		}
		//cout <<endl;
	}
	/**
	 * TODO Deconstructor
	 */
	~deque() {
		Clear(head -> next);
		if (head) delete head;
		if (tail) delete tail;
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
		delete tail;
		head = new node;
		tail = new node;
		head -> next = tail;
		tail -> prev = head;
		if (other.head == NULL && other.tail == NULL) return *this;
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
		return *this;
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
			if (tmp == 0) return *(q->prev->value[q->prev->beg + q->prev->Size]);
			else return *(q->value[q->beg + tmp]);
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
			if (tmp == 0) return *(q->prev->value[q->prev->beg + q->prev->Size]);
			else return *(q->value[q->beg + tmp]);
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
			if (tmp == 0) return *(q -> prev -> value[q->prev->beg + q -> prev -> Size]);
			else return *(q -> value[q->beg + tmp]);
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
			if (tmp == 0) return *(q->prev->value[q->prev->beg + q->prev->Size]);
			else return *(q->value[q->beg + tmp]);
		}
	}
	/**
	 * access the first element
	 * throw container_is_empty when the container is empty.
	 */
	const T & front() const {
		if (totalsize == 0) throw container_is_empty();
		else return(*(head -> next -> value[head -> next ->beg + 1]));
	}
	/**
	 * access the last element
	 * throw container_is_empty when the container is empty.
	 */
	const T & back() const {
		if (totalsize == 0) throw container_is_empty();
		else return(*(tail -> prev -> value[tail -> prev ->beg + tail -> prev -> Size]));
	}
	/**
	 * returns an iterator to the beginning.
	 */
	iterator begin() {
		const deque * now(this);
		return iterator(1, now);	
	}
	const_iterator cbegin() const {
		const deque * now(this);
		return const_iterator(1, now);
	}
	/**
	 * returns an iterator to the end.
	 */
	iterator end() {
		const deque * now(this);
		return iterator(totalsize + 1, now);
	}
	const_iterator cend() const {
		const deque * now(this);
		return iterator(totalsize + 1, now);
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
		Clear(head -> next);
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
		if (this != pos.d) throw invalid_iterator();
		if (pos.k == totalsize + 1) {
			push_back(value); return pos;
		}
		if (pos.k <= 0) throw invalid_iterator();
		if (pos.k > totalsize + 1)  throw invalid_iterator();
		node *q(head);
		size_t tmp = pos.k;
		q = q -> next;
		if (totalsize == 0) head = Insert(head, 0, value, 1);
		else {
			while (q != tail && tmp >= q -> Size) {
				tmp -= q -> Size;
				q = q -> next;
			}
			if (tmp == 0) q = Insert(q -> prev, q -> prev -> Size, value, 1);
			else q = Insert(q, tmp, value, 1);
			return pos;
		}
	}
	/**
	 * removes specified element at pos.
	 * removes the element at pos.
	 * returns an iterator pointing to the following element, if pos pointing to the last element, end() will be returned.
	 * throw if the container is empty, the iterator is invalid or it points to a wrong place.
	 */
	iterator erase(iterator pos) {
		if (pos.d != this) throw invalid_iterator();
		if (totalsize < pos.k) throw invalid_iterator();
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
				if (q->prev->Size == 1) {
					node *r(q->prev);
					q->prev->prev->next = r->next;
					q->prev->next->prev = r->prev;
					delete r;
				}
				else {
					if (q->prev->value[q->prev->beg + q->prev->Size] != NULL) delete q->prev->value[q->prev->beg+q->prev->Size];
					q->prev->Size--;
				}
				totalsize--;
				
			}//Erase(q->prev, q->prev->Size);
			else {
				if (q->Size == 1) {
					node *r(q);
					q->prev->next = r->next;
					q->next->prev = r->prev;
					delete r;
				}
				else {
					if (q->value[q->beg + tmp] != NULL) delete q->value[q -> beg+tmp];
					for (size_t i = tmp; i <= q->Size - 1; i++)	(q->value[q -> beg + i]) = (q->value[q -> beg + i + 1]);
					q->Size--;
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
			tmp = tail->prev->value[tail->prev->beg + tail->prev->Size];
			tail->prev->value[tail->prev->beg + tail->prev->Size] = tail->prev->value[tail->prev->beg + tail->prev->Size - 1];
			tail->prev->value[tail->prev->beg + tail->prev->Size - 1] = tmp;
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
				node *q(tail->prev);
				tail->prev->prev->next = q->next;
				tail->prev = q->prev;
				delete q;
			}
			else {
				//(tail->prev->value[tail->prev->Size - 1]) = (tail->prev->value[tail->prev->Size]);
				delete tail->prev->value[tail->prev->beg + tail->prev->Size];
				tail->prev->value[tail->prev->beg + tail->prev->Size] = NULL;
				tail->prev->Size--;
			}
			totalsize--;
		}
		//Erase(tail -> prev, tail -> prev -> Size);
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
			if (head -> next -> Size == 1) {
				node *q(head -> next);
				head->next->next->prev = q->prev;
				head -> next = q -> next;
				delete q;
				}
			else {
				delete head->next->value[head->next->beg + 1];
				head->next->beg++;
				//for (size_t i = 1; i <= head->next-> Size - 1; i++)	(head->next-> value[head->next->beg + i]) = (head->next-> value[head->next->beg + 1]);
				head -> next -> Size--;
			}
			totalsize--;
			
		}
		//Erase(head -> next, 1);
	}
};

}

#endif
