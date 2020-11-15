#pragma once
//#include"List.h"
#include<iostream>
using namespace std;

template<class elemType>
class seqList                                          //:public List<elemType>
{
public:
	seqList();                                         //默认初始化
	seqList(seqList &sl);                              //定义拷贝构造函数
	~seqList() { delete[] array; };                    //销毁顺序表
	void insert(int i, const elemType& value);         //在顺序表中插入一个数据
	void push_Back(elemType& value);                   //初始化顺序表
	void remove(int i);                                //按照所给的下标删除对应元素
	//void remove(elemType& value);                    //按照所给的值删除对应元素
	void traverse();                                   //遍历顺序表
	void inverse();                                    //逆置顺序表
	int search(const elemType& value)const;            //按值查询序号
	int size()const { return this->curLength; }        //查看当前顺序表的长度
	int getMaxSize()const { return this->maxSize; }    //查看当前顺序表的长度
	int isOutOfRange(const int inputSize)const {       //判断自定义创建的数据是否越界
		return this->maxSize - inputSize; 
	}
	bool isEmpty()const { return curLength == 0; }     //判断顺序表是否为空
	bool isFull()const { return curLength == maxSize;} //判断顺序表的容器是否已满
	void clear() { curLength = 0; }                    //清空顺序表的数据
	void resize();                                     //扩充顺序表容量
	void getUnionAndSort(seqList<elemType>& B);        //合并两个顺序表并排序
	void sortBuf();                                    //对顺序表中的元素排序
	elemType visit(int i);                             //按序号(位置)查询对应的值

private:
	elemType* array; //定义顺序表——存储数据的数组
	int curLength;   //顺序表的长度
	int maxSize;     //顺序表的最大容量
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

//前插法对顺序表内插入新的元素
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

//初始化顺序表
template<class elemType>
void seqList<elemType>::push_Back(elemType& value)
{   
	this->array[curLength] = value;
	curLength++;
}

//删除给定序号的元素数据
template<class elemType>
void seqList<elemType>::remove(int i)
{
	for (int k = i-1; k < this->curLength; k++)
	{
		this->array[k] = this->array[k + 1];
	}
	this->curLength--;
}

//遍历顺序表中元素的数据
template<class elemType>
void seqList<elemType>::traverse()
{
		for (int i = 0; i < curLength; i++) {
			cout << array[i] <<"  ";
		}
		cout << endl;
}

//逆置顺序表中元素的数据
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

//返回按值查找所在序号下标第一次出现的位置
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

//按照序号的下标查找元素的值
template<class elemType>
elemType seqList<elemType>::visit(int i)
{
	elemType getValue = this->array[i - 1];
	return getValue;
}

//合并顺序表并排序
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

//扩充顺序表的容量
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
