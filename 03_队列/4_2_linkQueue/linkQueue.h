#pragma once
#include"Queue.h"
using namespace std;

template <class T>
class linkQueue /*: public Queue<T>*/{
private:
	struct node {
		T data;
		node* next;
		node(const T& x, node* N = NULL) {
			data = x; next = N;
		}
		node() :next(NULL) {}
		~node() {}
	};
	int length;
	node* front,*rear;
public:
		linkQueue() { front = rear = NULL; }
		~linkQueue() { clear(); };
		void clear();
		bool empty()const { return front == NULL; }
		int size()const { return length; };
		void enQueue(const T & x);
		T deQueue();
		T getHead()const;
		T getRear()const;
};


template <class T>
void linkQueue<T>::clear() {
	node* p;
	while (front != NULL) {
		p = front;
		front = front->next;
		delete p;
	}
	rear = NULL;
	length = 0;
}

template <class T>
void linkQueue<T>::enQueue(const T& x) {
	if (rear == NULL)
	front = rear = new node(x);
	else {
		rear->next = new node(x);
		rear = rear->next;
	}
	length++;
}

template <class T>
T linkQueue<T>::deQueue() {
	if (empty()) throw outOfRange();
	node* p = front;
	T value = front->data;
	front = front-> next;
	if (front == NULL) rear = NULL;
	delete p;
	length--;
	return value;
}

template <class T>
T linkQueue<T>::getHead()const {
	if (empty())throw outOfRange();
	return front->data;
}

template <class T>
T linkQueue<T>::getRear()const {
	if (empty())throw outOfRange();
	return rear->data;
}