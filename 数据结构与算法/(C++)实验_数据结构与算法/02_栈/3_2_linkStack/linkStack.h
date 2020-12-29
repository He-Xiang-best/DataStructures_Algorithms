#pragma once
#include "Stack.h"
using namespace std;

//链栈的类型定义 
template<class T>
class linkStack {
private:
	struct Node {
		T data;//数据域 
		Node* next;//指针域
		Node() { next = NULL; }
		Node(const T& value, Node* p = NULL) { data = value; next = p; }
	};
	Node* top;//栈顶指针 
	int curLength;
public:
	linkStack() { top = NULL; curLength = 0; }//构造空栈
	~linkStack() { clear(); }
	void clear(); //清空
	bool empty()const { return top == NULL; }//判空
	int size()const { return curLength; };//求长度
	void push(const T& value);//压栈 
	T pop();//弹栈 
	T getTop()const;//取栈顶元素 
};

//清空栈
template<class T>
void linkStack<T>::clear() {
	Node* p;
	while (top != NULL) {
		p = top;//p指向当前栈顶元素 
		top = top->next;//top指针移向次栈顶元素 
		curLength = 0;
		delete p;//释放P指向的当前栈顶元素 
	}
}

//求栈中的元素个数——size替换
// template<class T>
// int linkStack<T>::size()const {
// 	Node* p = top;//top始终指向头所以要设置中间变量
// 	int count = 0;//计数器
// 	while (p) {//遍历栈，统计元素总数 
// 		count++;
// 		p = p->next;
// 	}
// 	return count;
// }

//进栈
template <class T>
void linkStack<T>::push(const T& value) {
	Node* p = new Node(value, top);//在栈顶插入元素 
	top = p;//p成为新的栈顶元素 
	curLength++;
}

//出栈
template<class T>
T linkStack<T>::pop() {
	if (empty()) throw outOfRange();
	Node* p = top;
	T value = p->data;//value 保存栈顶元素的值
	top = top->next;//top指针向后移动
	delete p;
	curLength--;
	return value;
}

//取出栈顶元素
template<class T>
T linkStack<T>::getTop()const {
	if (empty()) throw outOfRange();
	return top->data;
}
