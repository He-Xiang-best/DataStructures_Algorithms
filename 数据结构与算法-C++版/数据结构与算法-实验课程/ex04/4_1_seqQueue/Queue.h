#pragma once
#include<exception>
using namespace std;

class outOfRange :public exception {
	// 用于检查范围的有效性public:
	const char* what()const throw()
	{
		return "ERROR! oUT OF RANGE.\n";
	}
};

class badsize : public exception {
// 用于检查初始长度的有效性
public:
	const char* what()const throw()
	{
		return "ERROR! BAD SIZE.\n";
	}
};


template <class T>
class Queue{
public:
	virtual bool empty()const =0 ;
	virtual int size()const = 0;
	virtual void clear() = 0;
	virtual void enQueue(const T & x) = 0;
	virtual T deQueue() =0;
	virtual T getHead()const = 0;
    virtual ~Queue() {  }
};
