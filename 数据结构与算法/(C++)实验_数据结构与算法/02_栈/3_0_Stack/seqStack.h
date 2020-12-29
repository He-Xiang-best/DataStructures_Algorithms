#pragma once
#pragma once
#include"Stack.h"
using namespace std;
//顺序栈的类型描述 
template<class T >
class seqStack :public Stack<T> {
private:
	T* data;//存放栈中元素的数组
	int top;//栈顶指针指向栈顶元素
	int maxSize;
	void resize();//扩大栈的容量
public:
	seqStack(int initSize = 100);
	~seqStack() { delete[] data; }
	void clear() { top = -1; }   //清空栈
	bool empty()const { return top == -1; } //判空 
	int size()const { return top + 1; }//求长度
	void push(const T& value);//进栈
	T pop();//出栈
	T getTop()const;//取出栈顶的元素    	
};

//构造函数,初始化一个空的顺序栈，置栈顶指针top为-1 
template<class T>
seqStack<T>::seqStack(int initSize) {
	if (initSize <= 0)throw badSize();
	data = new T[initSize];
	maxSize = initSize;
	top = -1;
}
//进栈
template<class T>
void seqStack<T>::push(const T& value) {
	if (top == maxSize - 1) resize();//判断顺序是否已满，已满的话扩大容量
	data[++top] = value;//修改栈顶指针，新元素入栈 	
}
//出栈 
template<class T>
T seqStack<T>::pop() {
	if (empty()) throw outOfRange();//空栈无法弹栈 
	return data[top--]; //修改栈顶指针，返回栈顶元素 
}
//取出栈顶元素
template<class T>
T seqStack<T>::getTop()const {
	if (empty()) throw outOfRange();
	return data[top];
}
//扩大栈空间
template<class T>
void seqStack<T>::resize() {
	T* tmp = data;
	data = new T[2 * maxSize];
	for (int i = 0; i < maxSize; ++i)
		data[i] = tmp[i];
	maxSize *= 2;
	delete[] tmp;
}



