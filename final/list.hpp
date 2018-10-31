#pragma once
#include <utility>
#include <cstddef>
#include "exceptions.hpp"

namespace sjtu
{
	template<class T>
	class list
	{
		struct node
		{
			T *data;
			node *pre, *next;
			node() :data(NULL), pre(NULL), next(NULL) {}
			node(const T &_data, node *_pre = NULL, node *_next = NULL) :data(new T(_data)), pre(_pre), next(_next) {}
			node(T &&_data, node *_pre = NULL, node *_next = NULL) :data(new T(std::move(_data))), pre(_pre), next(_next) {}
			~node() { if (data) delete data; }
		}*tail = new node, *head = tail;
		size_t n = 0;
	public:
		list() {}
		list(const list &x) :n(x.n)
		{
			for (node *t = x.tail->pre; t; t = t->pre)
			{
				node *a = new node(*(t->data));
				a->next = head;
				head = head->pre = a;
			}
		}
		list(list &&x) : head(x.head), tail(x.tail), n(x.n)
		{
			x.head = x.tail = NULL;
		}
		~list()
		{
			clear(); 
			if (tail) delete tail;
		}
		list &operator= (const list &x)
		{
			if (this->tail == x.tail) return *this;
			clear(); n = x.n;
			for (node *t = x.tail->pre; t; t = t->pre)
			{
				node *a = new node(*(t->data));
				a->next = head;
				head = head->pre = a;
			}
			return *this;
		}
		list &operator= (list &&x)
		{
			~list();
			head = x.head, tail = x.tail, n = x.n;
			x.head = x.tail = NULL;
		}

		//iterator:
		class iterator;
		class const_iterator;
		class iterator
		{
		private:
			node *block;
			list<T> *context;
		public:
			friend class const_iterator;
			//constructor:
			iterator() :block(NULL), context(NULL) {}
			iterator(list<T> *other, node *_block) :context(other), block(_block) {}
			iterator(const iterator &other) :context(other.context), block(other.block) {}
			iterator(const const_iterator &other) :context(other.context), block(other.block) {}

			//operator:
			iterator operator++(int)
			{
				iterator last(*this);
				if ((block = block->next) == NULL) throw invalid_iterator();
				return last;
			}
			iterator& operator++()
			{
				if ((block = block->next) == NULL) throw invalid_iterator();
				return *this;
			}
			iterator operator--(int)
			{
				iterator last(*this);
				if ((block = block->pre) == NULL) throw invalid_iterator();
				return last;
			}
			iterator& operator--()
			{
				if ((block = block->pre) == NULL) throw invalid_iterator();
				return *this;
			}
			iterator& operator = (const iterator &other)
			{
				block = other.block, context = other.context;
				return *this;
			}
			inline T& operator*() const  
			{ 
				if (block->data == NULL) throw invalid_iterator();
				return *(block->data); 
			}
			inline T* operator->() const { return &(*(*this)); }
			inline bool operator==(const iterator &other) const
			{
				return context == other.context && block == other.block;
			}
			inline bool operator!=(const iterator &other) const
			{
				return !(*this == other);
			}
			inline node *data() const
			{
				return block;
			}
			list<T>* container() const { return context; }
		};
		class const_iterator
		{
		private:
			node *block;
			list<T> *context;
		public:
			friend class iterator;
			//constructor:
			const_iterator() :block(NULL), context(NULL) {}
			const_iterator(const list<T> *other, node *_block) :context((list<T>*)other), block(_block) {}
			const_iterator(const iterator &other) :context(other.context), block(other.block) {}
			const_iterator(const const_iterator &other) :context(other.context), block(other.block) {}

			//operator:
			const_iterator operator++(int)
			{
				const_iterator last(*this);
				if ((block = block->next) == NULL) throw invalid_iterator();
				return last;
			}
			const_iterator& operator++()
			{
				if ((block = block->next) == NULL) throw invalid_iterator();
				return *this;
			}
			const_iterator operator--(int)
			{
				const_iterator last(*this);
				if ((block = block->pre) == NULL) throw invalid_iterator();
				return last;
			}
			const_iterator& operator--()
			{
				if ((block = block->pre) == NULL) throw invalid_iterator();
				return *this;
			}
			const_iterator& operator = (const const_iterator &other)
			{
				block = other.block, context = other.context;
				return *this;
			}
			const T& operator*() const
			{
				if (block->data == NULL) throw invalid_iterator();
				return *(block->data);
			}
			const T* operator->() const { return &(*(*this)); }
			bool operator==(const const_iterator &other) const
			{
				return context == other.context && block == other.block;
			}
			bool operator!=(const const_iterator &other) const
			{
				return !(*this == other);
			}
			node *data() { return block; }
			list<T>* container() const { return context; }
		};

		iterator begin() { return iterator(this, head); }
		const_iterator begin() const { return const_iterator(this, head); }
		const_iterator cbegin() const { return const_iterator(this, head); }
		iterator end() { return iterator(this, tail); }
		const_iterator end() const { return const_iterator(this, tail); }
		const_iterator cend() const { return const_iterator(this, tail); }

		// Element access:
		T& front()
		{
			if (empty()) throw container_is_empty();
			return *(head->data);
		}
		const T& front() const
		{
			if (empty()) throw container_is_empty();
			return *(head->data);
		}
		T& back()
		{
			if (empty()) throw container_is_empty();
			return *(tail->pre->data);
		}
		const T& back() const
		{
			if (empty()) throw container_is_empty();
			return *(tail->pre->data);
		}
		T& operator[] (size_t index)
		{
			if (index >= size()) throw index_out_of_bound();
			for (node *t = head;; index--, t = t->next)
				if (index == 0) return *(t->data);
		}
		const T& operator[] (size_t index) const
		{
			if (index >= size()) throw index_out_of_bound();
			for (node *t = head;; index--) if (index == 0) return *(t->data);
		}

		//Capacity:
		bool empty() const { return n == 0; }
		size_t size() const { return n; }

		//Modifiers:
		iterator insert(iterator pos, const T& val)
		{
			n++;
			node *p = pos.data(), *t = new node(val, NULL, p);
			if (t->pre = p->pre) p->pre->next = t;
			else head = t;
			p->pre = t;
			return iterator(this, t);
		}
		iterator insert(iterator pos, T&& val)
		{
			n++;
			node *p = pos.data(), *t = new node(std::move(val), NULL, p);
			if (t->pre = p->pre) p->pre->next = t;
			else head = t;
			p->pre = t;
			return iterator(this, t);
		}
		iterator erase(iterator pos)
		{
			n--;
			node *p = pos.data();
			if (p->pre) p->pre->next = p->next;
			else head = p->next;
			p->next->pre = p->pre;
			iterator ans(this, p->next);
			delete p;
			return ans;
		}
		void push_front(const T& val) { insert(begin(), val); }
		void pop_front()
		{
			if (empty()) throw container_is_empty();
			erase(begin());
		}
		void push_back(const T& val) { insert(end(), val); }
		void pop_back()
		{
			if (empty()) throw container_is_empty();
			erase(--end());
		}
		void clear()
		{
			if (head == NULL && tail == NULL) return;
			node *next;
			for (node *t = head; t != tail; t = next)
			{
				next = t->next; delete t;
			}
			head = tail, tail->pre = NULL, n = 0;
		}
		list divide(iterator it)
		{
			int num = 0; 
			for (iterator t = begin(); t != it; t++, num++);
			list ans; node *t = ans.tail;
			ans.head = it.data(), ans.tail = tail;
			node *p = ans.head->pre;
			ans.n = n - num, n = num;
			ans.head->pre = NULL;
			tail = p->next = t;
			tail->pre = p;
			return ans;
		}
		list& merge(list &x)
		{
			node *t = tail->pre;
			delete tail;
			t->next = x.head, x.head->pre = t;
			tail = x.tail; n += x.n;
			x.head = NULL, x.tail = NULL;
			return *this;
		}
		void setend(const T &x)
		{
			iterator pos = end();
			if (pos.data()->data) delete pos.data()->data;
			pos.data()->data = new T(x);
		}
		void delend(){ if (end().data()->data) delete end().data()->data; }
	};
}