#pragma once
#include<exception>
using namespace std;

//栈的抽象数据类型定义
template<class T>//栈的元素类型为T 
class Stack {
public:
	virtual bool empty()const = 0;//判空 
	virtual int size() const = 0;//求栈中的元素个数
	virtual void push(const T& x) = 0;//压栈，插入元素为x的新的栈顶元素
	virtual T pop() = 0;//弹栈，若栈非空，则删除栈顶元素
	virtual T getTop() const = 0;//取栈顶元素，返回栈顶元素但不弹出
	virtual void clear() = 0;//清空栈
	virtual ~Stack() {}

};
//自定义异常处理类：
class outOfRange :public exception {   //用于检查范围的有效性
public:
	const char* what()const throw() {
		return "ERROR!OUT OF RANGE.\n";
	}
};
class badSize :public exception {//用于检查初始长度的有效性
public:
	const char* what()const throw() {
		return "ERROR!BAD SIZE.\n";
	}
};