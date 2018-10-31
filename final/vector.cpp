#ifndef SJTU_VECTOR_HPP
#define SJTU_VECTOR_HPP

#include "exceptions.hpp"

#include <climits>
#include <cstddef>

namespace sjtu {
/**
 * a data container like std::vector
 * store data in a successive memory and support random access.
 */
template<typename T>
class vector {
public:
	/**
	 * TODO
	 * a type for actions of the elements of a vector, and you should write
	 *   a class named const_iterator with same interfaces.
	 */
	/**
	 * you can see RandomAccessIterator at CppReference for help.
	 */
private:
	T *data;
	int currentlength;
	int maxsize; 
	
	void resize(){
		if (maxsize == 0) maxsize = 1;
		else maxsize *= 2;
		T *tmp = data;
		data = reinterpret_cast<T*>(operator new(sizeof(T) * maxsize)); 
		for (int i = 0; i < currentlength; ++i) {
			new (static_cast<void*>(&data[i])) T(tmp[i]);
			tmp[i].~T();
		}
		operator delete(tmp);
	}
	
public:
	class const_iterator;
	class iterator {
	friend class vector<T>;
	friend class const_iterator;
	private:
		/**
		 * TODO add data members
		 *   just add whatever you want.
		 */
		 T *it;
		 T **which;
	public:
		/**
		 * return a new iterator which pointer n-next elements
		 *   even if there are not enough elements, just return the answer.
		 * as well as operator-
		 */
		iterator (T *_it, T **_which):it(_it), which(_which){}
		iterator operator+(const int &n) const {
			//TODO
			return iterator(it + n, which);
		}
		iterator operator-(const int &n) const {
			//TODO
			return (it - n, which);
		}
		// return th distance between two iterator,
		// if these two iterators points to different vectors, throw invaild_iterator.
		int operator-(const iterator &rhs) const {
			//TODO
			if (which != rhs.which) throw invalid_iterator();
			return it - rhs.it;
		}
		iterator operator+=(const int &n) {
			//TODO
			it = it + n;
			return *this;
		}
		iterator operator-=(const int &n) {
			//TODO
			it = it - n;
			return *this;
		}
		/**
		 * TODO iter++
		 */
		iterator operator++(int) {
			iterator tmp = *this;
			it += 1;
			return tmp;
		}
		/**
		 * TODO ++iter
		 */
		iterator& operator++() {
			it += 1;
			return *this; 
		}
		/**
		 * TODO iter--
		 */
		iterator operator--(int) {
			iterator tmp = *this;
			it -= 1;
			return tmp;
		}
		/**
		 * TODO --iter
		 */
		iterator& operator--() {
			it -= 1;
			return *this;
		}
		/**
		 * TODO *it
		 */
		T& operator*() const{
			return *it;
		}
		/**
		 * a operator to check whether two iterators are same (pointing to the same memory).
		 */
		bool operator==(const iterator &rhs) const {return (it == rhs.it);}
		bool operator==(const const_iterator &rhs) const {return (it == rhs.it);}
		/**
		 * some other operator for iterator.
		 */
		bool operator!=(const iterator &rhs) const {return (it != rhs.it);}
		bool operator!=(const const_iterator &rhs) const {return (it != rhs.it);}
	};
	/**
	 * TODO
	 * has same function as iterator, just for a const object.
	 */
	class const_iterator {
	friend class vector<T>;
	friend class iterator;
	private:
		T *it;
		T*const* which;
	public:
		const_iterator (T *_it, T *const*_which):it(_it), which(_which){};
		const_iterator operator+(const int &n) const{
			return const_iterator(it + n, which);
		}
		const_iterator operator-(const int &n) const{
			return const_iterator(it - n, which);
		}
		int operator-(const const_iterator &rhs) const{
			if (which != rhs.which) throw invalid_iterator();
			return it - rhs.it;
		}
		const_iterator operator+=(const int &n){
			it += n;
			return *this;
		}
		const_iterator operator-=(const int &n){
			it -= n;
			return *this;
		}
		const_iterator operator++(int n){
			const_iterator tmp = *this;
			it += 1;
			return tmp;
		}
		const_iterator operator++(){
			it += 1;
			return *this;
		}
		const_iterator operator--(int n){
			const_iterator tmp = *this;
			it -= 1;
			return tmp;
		}
		const_iterator operator--(){
			it -= 1;
			return *this;
		}
		T& operator*() const{
			return *it;
		}
		bool operator==(const iterator &rhs) const {return (it == rhs.it);}
		bool operator==(const const_iterator &rhs) const{return (it == rhs.it);}
		bool operator!=(const iterator &rhs) const {return (it != rhs.it);}
		bool operator!=(const const_iterator &rhs) const {return (it != rhs.it);}	
	};
	/**
	 * TODO Constructs
	 * Atleast three: default constructor, copy constructor and a constructor for std::vector
	 */
	vector() {maxsize = 0; data = NULL; currentlength = 0;}
	vector(const vector &other) {
		maxsize = other.maxsize; 
		currentlength = other.currentlength;
		data = reinterpret_cast<T*>(operator new(sizeof(T)*maxsize));
		for (int i = 0; i < maxsize; ++i) new (static_cast<void*>(&data[i])) T(other.data[i]);
	}
	
	template <class TT>
	vector(const TT &other){
		maxsize = other.capacity();
		currentlength = other.size();
		data = reinterpret_cast<T*>(operator new(sizeof(T)*maxsize));
		for (int i = 0; i < maxsize; ++i) new (static_cast<void*>(&data[i])) T(other.data[i]);
	}
	/**
	 * TODO Destructor
	 */
	~vector() {
		for (int i = 0; i < currentlength; ++i) data[i].~T();
		operator delete(data);	
	}
	/**
	 * TODO Assignment operator
	 */
	vector &operator=(const vector &other) {
		if (this == &other) return *this;
		for (int i = 0; i < maxsize; ++i) data[i].~T();
		operator delete(data);
		maxsize = other.maxsize;
		currentlength = other.currentlength;
		data = reinterpret_cast<T*>(operator new(sizeof(T)*maxsize));
		for (int i = 0; i < maxsize; ++i) new(static_cast<void*>(&data[i])) T(other.data[i]);
		return *this;
	}
	/**
	 * assigns specified element with bounds checking
	 * throw index_out_of_bound if pos is not in [0, size)
	 */
	T & at(const size_t &pos) {
		if (pos < 0 || pos >= currentlength) throw index_out_of_bound();
		else return data[pos];
	}
	const T & at(const size_t &pos) const {
		if (pos < 0 || pos >= size) throw index_out_of_bound();
		else return data[pos];
	}
	/**
	 * assigns specified element with bounds checking
	 * throw index_out_of_bound if pos is not in [0, size)
	 * !!! Pay attentions
	 *   In STL this operator does not check the boundary but I want you to do.
	 */
	T & operator[](const size_t &pos) {
		if (pos < 0 || pos >= currentlength)  throw index_out_of_bound();
		else return data[pos];
	}
	const T & operator[](const size_t &pos) const {
		if (pos < 0 || pos >= currentlength)  throw index_out_of_bound();
		else return data[pos];
	}
	/**
	 * access the first element.
	 * throw container_is_empty if size == 0
	 */
	const T & front() const {
		if (currentlength == 0) throw container_is_empty();
		else return data[0];
	}
	/**
	 * access the last element.
	 * throw container_is_empty if size == 0
	 */
	const T & back() const {
		if (currentlength == 0) throw container_is_empty();
		else return data[currentlength-1];
	}
	/**
	 * returns an iterator to the beginning.
	 */
	iterator begin() {
		iterator tmp(&data[0],&data);
		return tmp;
	}
	const_iterator cbegin() const {
		const_iterator tmp(&data[0],&data);
		return tmp;
	}
	/**
	 * returns an iterator to the end.
	 */
	iterator end() {
		iterator tmp(&data[currentlength],&data);
		return tmp;
	}
	const_iterator cend() const {
		const_iterator tmp(&data[currentlength],&data);
		return tmp;
	}
	/**
	 * checks whether the container is empty
	 */
	bool empty() const {return currentlength == 0;}
	/**
	 * returns the number of elements
	 */
	size_t size() const {return currentlength;}
	/**
	 * returns the number of elements that can be held in currently allocated storage.
	 */
	size_t capacity() const {return maxsize;}
	/**
	 * clears the contents
	 */
	void clear() {currentlength = 0;}
	/**
	 * inserts value before pos
	 * returns an iterator pointing to the inserted value.
	 */
	iterator insert(iterator pos, const T &value) {
		iterator tmp(&data[0], &data);
		int x;
		x = pos - tmp;
		if (currentlength == maxsize) resize();
		currentlength++;
		for (int j = currentlength - 2; j >= x ; --j) {
			new (static_cast<void*> (&data[j+1])) T(data[j]);
			data[j].~T();
		}
		new (static_cast<void*>(&data[x])) T(value);
		tmp.it = &data[x];
		return tmp;
	}
	/** 
	 * inserts value at index ind.
	 * after inserting, this->at(ind) == value is true
	 * returns an iterator pointing to the inserted value.
	 * throw index_out_of_bound if ind > size (in this situation ind can be size because after inserting the size will increase 1.)
	 */
	iterator insert(const size_t &ind, const T &value) {
		if (ind > currentlength) throw index_out_of_bound();
		return insert(iterator(&data[ind],&data), value);
	}
	/**
	 * removes the element at pos.
	 * return an iterator pointing to the following element.
	 * If the iterator pos refers the last element, the end() iterator is returned.
	 */
	iterator erase(iterator pos) {
		iterator tmp(&data[0], &data);
		int x;
		x = pos - tmp; 
		currentlength--;
		data[x].~T();
		for (int j = x; j < currentlength; ++j) {
			new (static_cast<void*> (&data[j])) T(data[j+1]);
			data[j+1].~T();
		}
		tmp.it = &data[x];
		return tmp;
	}
	/**
	 * removes the element with index ind.
	 * return an iterator pointing to the following element.
	 * throw index_out_of_bound if ind >= size
	 */
	iterator erase(const size_t &ind) {
		if (ind >= currentlength|| ind < 0) throw index_out_of_bound();
		return erase(iterator(&data[ind],&data));
	}
	/**
	 * adds an element to the end.
	 */
	void push_back(const T &value) {
		if (currentlength == maxsize) resize();
		new (static_cast<void*> (&data[currentlength])) T(value);
		currentlength += 1;
	}
	/**
	 * remove the last element from the end.
	 * throw container_is_empty if size() == 0
	 */
	void pop_back() {
		if (currentlength == 0) throw container_is_empty();
		data[currentlength-1].~T();
		currentlength -= 1;
	}
		
};


}

#endif
