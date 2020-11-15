#pragma once
#include<iostream> 
using namespace std;

template<class T>
class seqstack {
private:
	T* data;
	int top;
	int maxSize;
	int curLength;
public:
	seqstack();
	~seqstack() { delete[]data; }
	void clear() { top = -1; }
	bool isEmpty()const { return top == -1; }
	bool isFull()const { return top == maxSize - 1; }
	int size()const { return top + 1; }
	int maxLength()const { return maxSize; }
	void push(const T& value);
	T pop();
	T getTop();
	void resize();
};

//构造函数初始化栈
template<class T>
inline seqstack<T>::seqstack()
{
	this->curLength = 0;
	this->maxSize = 10;
	this->data = new int[maxSize];
	top = -1;
}

template<class T>
inline void seqstack<T>::push(const T& value)
{
	if (isFull()) resize();
	data[++top] = value;
	curLength++;
}

template<class T>
inline T seqstack<T>::pop()
{
	return data[top--];
	curLength--;
}

template<class T>
inline T seqstack<T>::getTop()
{
	return data[top];
}

template<class T>
inline void seqstack<T>::resize()
{
	T* tem = data;
	this->data = new int[maxSize * 2];
	for (int i = 0; i < maxSize; i++)
	{
		data[i] = tem[i];
	}
	maxSize = maxSize * 2;
	delete[]tem;
}
