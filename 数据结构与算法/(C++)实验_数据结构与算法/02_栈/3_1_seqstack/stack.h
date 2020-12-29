#pragma once
template<class T>
class stack 
{
public:
	virtual void clear() = 0;
	virtual bool isEmpty()const = 0;
	virtual bool isFull()const = 0;
	virtual int size()const = 0;
	virtual void push(const T& value) = 0;
	virtual T pop() = 0;
	virtual T getTop() = 0;
	virtual void resize() = 0;
	virtual ~stack() {}
};