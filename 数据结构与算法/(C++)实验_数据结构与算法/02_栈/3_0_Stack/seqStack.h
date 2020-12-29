#pragma once
#pragma once
#include"Stack.h"
using namespace std;
//˳��ջ���������� 
template<class T >
class seqStack :public Stack<T> {
private:
	T* data;//���ջ��Ԫ�ص�����
	int top;//ջ��ָ��ָ��ջ��Ԫ��
	int maxSize;
	void resize();//����ջ������
public:
	seqStack(int initSize = 100);
	~seqStack() { delete[] data; }
	void clear() { top = -1; }   //���ջ
	bool empty()const { return top == -1; } //�п� 
	int size()const { return top + 1; }//�󳤶�
	void push(const T& value);//��ջ
	T pop();//��ջ
	T getTop()const;//ȡ��ջ����Ԫ��    	
};

//���캯��,��ʼ��һ���յ�˳��ջ����ջ��ָ��topΪ-1 
template<class T>
seqStack<T>::seqStack(int initSize) {
	if (initSize <= 0)throw badSize();
	data = new T[initSize];
	maxSize = initSize;
	top = -1;
}
//��ջ
template<class T>
void seqStack<T>::push(const T& value) {
	if (top == maxSize - 1) resize();//�ж�˳���Ƿ������������Ļ���������
	data[++top] = value;//�޸�ջ��ָ�룬��Ԫ����ջ 	
}
//��ջ 
template<class T>
T seqStack<T>::pop() {
	if (empty()) throw outOfRange();//��ջ�޷���ջ 
	return data[top--]; //�޸�ջ��ָ�룬����ջ��Ԫ�� 
}
//ȡ��ջ��Ԫ��
template<class T>
T seqStack<T>::getTop()const {
	if (empty()) throw outOfRange();
	return data[top];
}
//����ջ�ռ�
template<class T>
void seqStack<T>::resize() {
	T* tmp = data;
	data = new T[2 * maxSize];
	for (int i = 0; i < maxSize; ++i)
		data[i] = tmp[i];
	maxSize *= 2;
	delete[] tmp;
}



