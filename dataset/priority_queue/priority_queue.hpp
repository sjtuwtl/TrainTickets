#ifndef SJTU_PRIORITY_QUEUE_HPP
#define SJTU_PRIORITY_QUEUE_HPP

#include <cstddef>
#include <functional>
#include "exceptions.hpp"

namespace sjtu {

/**
 * a container like std::priority_queue which is a heap internal.
 * it should be based on the vector written by yourself.
 */
template<typename T, class Compare = std::less<T> >
class priority_queue {
private:
	struct node{
		T value;
		node *left, *right;
		int dis;
		
		node(T value, int dis) : value(value), dis(dis) {
			left = right = NULL;
		}
		
		node(const node *a ) :node(a -> value, a -> dis) {
			if (a -> left != NULL) left = new node(a -> left);
			if (a -> right != NULL) right = new node(a -> right);
		}
	};
	
	node *root;
	int size1;
	
	Compare cmp;
	
	void swap(node * &a, node * &b) {
		node * c = a;
		a = b;
		b = c;
	}
	
	node * merge(node * &a, node * &b) {
		if (a == NULL) return b;
		if (b == NULL) return a;
		if (cmp(a -> value, b -> value)) swap(a, b);
		a -> right = merge(a -> right, b);
		if (!a -> left || a -> left -> dis < a -> right -> dis) swap(a -> left, a -> right);
		a -> dis = a -> right ? a -> right -> dis + 1 : 1;
		return a;
	}
	
	void removetree(node * &x) {
		if (x == NULL) return;
		if (x -> left != NULL) removetree(x -> left);
		if (x -> right != NULL) removetree(x -> right);
		delete x;
//		x = NULL;
	}
public:
	/**
	 * TODO constructors
	 */
	
	priority_queue():size1(0), root(NULL) {
	}
	
	priority_queue(const priority_queue &other): size1(other.size1) {
		root = new node(other.root);
	}
	/**
	 * TODO deconstructor
	 */
	~priority_queue() {
		removetree(root);	
	}
	/**
	 * TODO Assignment operator
	 */
	priority_queue &operator=(const priority_queue &other) {
		if (root == other.root) return *this;
		size1 = other.size1;
		removetree(root);
		root = new node(other.root);
		return *this;
	}
	/**
	 * get the top of the queue.
	 * @return a reference of the top element.
	 * throw container_is_empty if empty() returns true;
	 */
	const T & top() const {
		if (!size1) throw(container_is_empty());
		return root -> value;
	}
	/**
	 * TODO
	 * push new element to the priority queue.
	 */
	void push(const T &e) {
		node * a = new node(e, 0);
		root = merge(root, a);
		size1++;
	}
	/**
	 * TODO
	 * delete the top element.
	 * throw container_is_empty if empty() returns true;
	 */
	void pop() {
		if (!size1) throw(container_is_empty());
		node * l = root -> left;
		node * r = root -> right;
		delete root;
		root = merge(l, r);
		size1--;
	}
	/**
	 * return the number of the elements.
	 */
	size_t size() const {
		return size1;
	}
	/**
	 * check if the container has at least an element.
	 * @return true if it is empty, false if it has at least an element.
	 */
	bool empty() const {
		return size1 == 0;
	}
	/**
	 * return a merged priority_queue with at least O(logn) complexity.
	 */
	void merge(priority_queue & other) {
		size1 += other.size1;
		root = merge(root, other.root);
		other.root = NULL;
		other.size1 = 0;
	}
};

}

#endif
