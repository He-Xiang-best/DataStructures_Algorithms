#pragma once
#include "Stack.h"
using namespace std;

//��ջ�����Ͷ��� 
template<class T>
class linkStack {
private:
	struct Node {
		T data;//������ 
		Node* next;//ָ����
		Node() { next = NULL; }
		Node(const T& value, Node* p = NULL) { data = value; next = p; }
	};
	Node* top;//ջ��ָ�� 
	int curLength;
public:
	linkStack() { top = NULL; curLength = 0; }//�����ջ
	~linkStack() { clear(); }
	void clear(); //���
	bool empty()const { return top == NULL; }//�п�
	int size()const { return curLength; };//�󳤶�
	void push(const T& value);//ѹջ 
	T pop();//��ջ 
	T getTop()const;//ȡջ��Ԫ�� 
};

//���ջ
template<class T>
void linkStack<T>::clear() {
	Node* p;
	while (top != NULL) {
		p = top;//pָ��ǰջ��Ԫ�� 
		top = top->next;//topָ�������ջ��Ԫ�� 
		curLength = 0;
		delete p;//�ͷ�Pָ��ĵ�ǰջ��Ԫ�� 
	}
}

//��ջ�е�Ԫ�ظ�������size�滻
// template<class T>
// int linkStack<T>::size()const {
// 	Node* p = top;//topʼ��ָ��ͷ����Ҫ�����м����
// 	int count = 0;//������
// 	while (p) {//����ջ��ͳ��Ԫ������ 
// 		count++;
// 		p = p->next;
// 	}
// 	return count;
// }

//��ջ
template <class T>
void linkStack<T>::push(const T& value) {
	Node* p = new Node(value, top);//��ջ������Ԫ�� 
	top = p;//p��Ϊ�µ�ջ��Ԫ�� 
	curLength++;
}

//��ջ
template<class T>
T linkStack<T>::pop() {
	if (empty()) throw outOfRange();
	Node* p = top;
	T value = p->data;//value ����ջ��Ԫ�ص�ֵ
	top = top->next;//topָ������ƶ�
	delete p;
	curLength--;
	return value;
}

//ȡ��ջ��Ԫ��
template<class T>
T linkStack<T>::getTop()const {
	if (empty()) throw outOfRange();
	return top->data;
}
