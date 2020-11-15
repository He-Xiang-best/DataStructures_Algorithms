#pragma once
#include"Queue.h"
using namespace std;

template <class T>
class seqQueue /*: public Queue<T>*/ {
private:
	T* data;
	int maxsize;
	int front, rear;
public:
	seqQueue(int initsize = 100);
	~seqQueue() { delete[] data; }
	void clear() { front = rear = -1; }
	void resize();
	int maxLen()const { return maxsize; }
	bool empty()const { return front == rear; }
	bool full()const { return (rear + 1) % maxsize == front; }
	int size()const{ return (rear - front + maxsize) % maxsize; }
	void enQueue(const T& x);
	T deQueue();
	T getHead()const;
	T getRear()const;

};

template<class T>
void seqQueue<T>::resize()
{
	T* p = data;
	data = new T[2 * maxsize];
	for (int i = 1; i < maxsize; ++i)
		data[i] = p[(front + i) % maxsize];
	front = 0; rear = maxsize - 1;
	maxsize *= 2;
	delete p;
}

template <class T>
seqQueue<T>::seqQueue(int initsize) {
	if (initsize <= 0)throw badsize(); 
	data = new T[initsize];
	maxsize = initsize;
	front = rear = -1;
}

template <class T>
void seqQueue<T>::enQueue(const T& x) {
	if ((rear + 1) % maxsize == front) resize(); 
	rear = (rear + 1) % maxsize;
	data[rear] = x;
}
		
template <class T>
T seqQueue<T> ::deQueue() {
	if (empty()) throw outOfRange();
		front = (front + 1) % maxsize;
		return data[front];
}
		
template <class T>
T seqQueue<T>::getHead()const{
	if (empty()) 
		throw outOfRange();
	return data[(front + 1) % maxsize];
}

template<class T>
T seqQueue<T>::getRear() const
{   
	if (empty())
		throw outOfRange();
	return data[rear];
}

