#pragma once
//#include"List.h"
#include<iostream>
using namespace std;

template<class elemType>
class seqList                                          //:public List<elemType>
{
public:
	seqList();                                         //Ĭ�ϳ�ʼ��
	seqList(seqList &sl);                              //���忽�����캯��
	~seqList() { delete[] array; };                    //����˳���
	void insert(int i, const elemType& value);         //��˳����в���һ������
	void push_Back(elemType& value);                   //��ʼ��˳���
	void remove(int i);                                //�����������±�ɾ����ӦԪ��
	//void remove(elemType& value);                    //����������ֵɾ����ӦԪ��
	void traverse();                                   //����˳���
	void inverse();                                    //����˳���
	int search(const elemType& value)const;            //��ֵ��ѯ���
	int size()const { return this->curLength; }        //�鿴��ǰ˳���ĳ���
	int getMaxSize()const { return this->maxSize; }    //�鿴��ǰ˳���ĳ���
	int isOutOfRange(const int inputSize)const {       //�ж��Զ��崴���������Ƿ�Խ��
		return this->maxSize - inputSize; 
	}
	bool isEmpty()const { return curLength == 0; }     //�ж�˳����Ƿ�Ϊ��
	bool isFull()const { return curLength == maxSize;} //�ж�˳���������Ƿ�����
	void clear() { curLength = 0; }                    //���˳��������
	void resize();                                     //����˳�������
	void getUnionAndSort(seqList<elemType>& B);        //�ϲ�����˳�������
	void sortBuf();                                    //��˳����е�Ԫ������
	elemType visit(int i);                             //�����(λ��)��ѯ��Ӧ��ֵ

private:
	elemType* array; //����˳������洢���ݵ�����
	int curLength;   //˳���ĳ���
	int maxSize;     //˳�����������
};


template<class elemType>
seqList<elemType>::seqList()
{
	curLength = 0;
	maxSize = 10;
	this->array = new elemType[this->maxSize];
}

template<class elemType>
inline seqList<elemType>::seqList(seqList &sl)
{
	
	this->maxSize = sl.maxSize;
	this->curLength = sl.curLength;
	this->array = new elemType[this->maxSize];
	for (int i = 0; i < this->curLength;i++) {
		this->array[i] = sl.array[i];
	}
}

//ǰ�巨��˳����ڲ����µ�Ԫ��
template<class elemType>
void seqList<elemType>::insert(int i, const elemType& value)
{
	int k = i - 1;
	for (int j = this->curLength; j>k ; j--){
		this->array[j] = this->array[j - 1];
	}
	this->array[k] = value;
	this->curLength++;
}

//��ʼ��˳���
template<class elemType>
void seqList<elemType>::push_Back(elemType& value)
{   
	this->array[curLength] = value;
	curLength++;
}

//ɾ��������ŵ�Ԫ������
template<class elemType>
void seqList<elemType>::remove(int i)
{
	for (int k = i-1; k < this->curLength; k++)
	{
		this->array[k] = this->array[k + 1];
	}
	this->curLength--;
}

//����˳�����Ԫ�ص�����
template<class elemType>
void seqList<elemType>::traverse()
{
		for (int i = 0; i < curLength; i++) {
			cout << array[i] <<"  ";
		}
		cout << endl;
}

//����˳�����Ԫ�ص�����
template<class elemType>
void seqList<elemType>::inverse()
{
	elemType temp;
	for (int i = 0; i < this->curLength/2; i++)
	{
		temp = this->array[i];
		this->array[i] = this->array[curLength - i - 1];
		this->array[curLength - i - 1] = temp;
	}
}

//���ذ�ֵ������������±��һ�γ��ֵ�λ��
template<class elemType>
int seqList<elemType>::search(const elemType& value) const
{
	for (int i = 0; i < this->curLength; i++)
	{
		if (this->array[i]==value)
		{
			return i + 1;
			break;
		}
	}
	return 0;
}

//������ŵ��±����Ԫ�ص�ֵ
template<class elemType>
elemType seqList<elemType>::visit(int i)
{
	elemType getValue = this->array[i - 1];
	return getValue;
}

//�ϲ�˳�������
template<class elemType>
void seqList<elemType>::getUnionAndSort(seqList<elemType>& B)
{
	int m, n, i;
	m = this->curLength; n = B.curLength;
	while (m + n > this->maxSize) resize();
	for (i=0; i<n; i++) {
		push_Back(B.array[i]);
	}
	sortBuf();
	
}

template<class elemType>
inline void seqList<elemType>::sortBuf()
{
	for (int i = 0; i < this->curLength; i++)
	{
		for (int j = 0; j < this->curLength - i - 1; j++)
		{
			if (this->array[j] > this->array[j + 1])
			{
				elemType temp = this->array[j];
				this->array[j] = this->array[j + 1];
				this->array[j + 1] = temp;
			}
		}
	}
}

//����˳��������
template<class elemType>
void seqList<elemType>::resize()
{
	elemType* temp = array;
	this->maxSize *= 2;
	array = new elemType[this->maxSize];
	for (int i = 0; i < this->curLength; i++) {
		array[i] = temp[i];
	}
	delete[] temp;
}
