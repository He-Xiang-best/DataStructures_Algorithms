#pragma once
#include<iostream> 
using namespace std;
//============================================================================
// @FileName     ：linkList
// @Author       ：04191315_HeXiang
// @Version      ：1.0
// @Date         ：2020.10.21
// Description   ：
/*
实现单链表完成线性表的基本操作：
初始化线性表、清空线性表、求线性表长度、检查线性表是否为空、
遍历线性表、从线性表中查找元素、从线性表中查找与给定元素值相同的元素在线性表中的位置、
插入元素、删除元素。
 */
 //============================================================================
 
template <class elemType>								// elemType为单链表存储的元素类型
class linkList {
private:
	struct Node {
	public:
		elemType  data;									// 结点的数据域
		Node* next;									    // 结点的指针域，指向后继结点
		// 用于初始化一个有数据的节点
		Node(const elemType value, Node* p = NULL) {
			data = value;
			next = p;
		}
		//用于初始化头结点或没有数据的节点
		Node(Node* p = NULL) {
			next = p;
		}
	};
	Node* head;								           // 单链表的头指针
	Node* tail;    							           // 单链表的尾指针
	int curLength;								       // 单链表的长度
public:
	linkList();								           // 构造函数
	~linkList();								       // 析构函数
	void clear(); 								       // 将单链表清空，使之成为空表（头结点还在）
	bool isEmpty()const {
		return head->next == NULL;                     // 判断单链表是否为空(判断curLength==0也可以)
	}
	int  size()const;                   		       // 返回单链表的当前实际长度
	void headinsert(int i, elemType &value);	       // 在位置i前插入一个元素value，表的长度增1
	void removeinNum(int i);					       // 删除位置i上的元素value，若删除位置合法，表的长度减1
//	bool removeinValue(elemType &value);               //删除存储值为value的节点
	int  searchinValue(elemType &value);               // 查找值为value的元素第一次出现的位序
	void searchinNum(int i);		                   // 查找序号为num的元素的数值
	void traverse()const;						       // 遍历单链表
	void inverse();
//	void headCreate(elemType &value);			       // 空表时可用头插法插入数据
	void tailCreate(elemType &value);		           // “尾插法”创建单链表
};

/*****************构造函数：创建带有头结点的空表(初始化)**********************/
template <class elemType>
linkList<elemType>::linkList() {
	head = tail = new Node();
	curLength = 0;
}

/***************析构函数：先清除数据，再删除头结点，彻底释放空间**************/
template <class elemType>
linkList<elemType>::~linkList() {
	clear();
	delete head;
}

/***************************删除全部的结点，释放空间**************************/
template <class elemType>
void linkList<elemType>::clear() {
	Node* p, * tmp;
	p = head->next;								    // p为工作指针，指向首元结点
	while (p != NULL) {
		tmp = p;
		p = p->next;								// 指针后移
		delete tmp;
	}
	head->next = NULL;							    // 头结点的指针域置空
	tail = head;								    // 头尾指针均指向头结点
	curLength = 0;
}

/*******************************获得单链表的长度******************************/
template <class elemType>
int linkList<elemType>::size()const {
	//从头到尾遍历链表，获得长度比较麻烦，直接用一个数据记录就好
	//	Node *p =head->next;
	//	int count=0;
	//	while(p) {
	//		count++;
	//		p=p->next;
	//	}
	//	return count;
	return curLength;
}

/****************************按值查找数据在表中的位置************************/
template <class elemType>
int linkList<elemType> ::searchinValue(elemType &value) {
	Node* p = head->next;
	int i = 1;//个人喜欢按人为序号的顺序
	while (p != NULL && p->data != value) {
		p = p->next;
		i++;
	}
	if (p == NULL) return -1;
	else return i;

}

/****************************按序号查找数据在表中的数值*****************************/
template <class elemType>
void linkList<elemType> ::searchinNum(int i) {
	Node* p = head->next;
	int j = 1;
		while (j < i) {
			p = p->next;
			j++;
		}
		cout << "\n第" << i << "个元素对应的数值为: " << p->data << endl;
	
}

/****************************使用前插法插入数据********************************/
template  <class elemType>
void linkList<elemType> ::headinsert(int i, elemType &value) { 
	Node* p = head;
	int j = 0;
	while (j < i - 1) {
		p = p->next;
		j++;
	}
	p->next = new Node(value, p->next);
	curLength++;

}

/*****************************按序号删除节点******************************/
template  <class elemType>
void  linkList<elemType>::removeinNum(int i) {
	Node* p = head, * del;
	for (int j = 1; j < i; j++) {
		p = p->next;
	}
	del = p->next;
	p->next = del->next;
	delete del;
	curLength--;
}

//可借助索引删除完成
/***************************按值删除节点***********************************/
//template  <class elemType>
//bool linkList<elemType>::removeinValue(elemType &value) {
//	Node* p = head, * del;
//	while (p->next != NULL && p->next->data != value) {
//		p = p->next;
//	}
//	if (p->next != NULL) {
//		del = p->next;
//		p->next = p->next->next;
//		delete del;
//		curLength--;
//		return true;
//
//	}
//	else
//		return false;
//}

/**************************遍历单链表***************************************/
template <class elemType>
void  linkList<elemType> ::traverse()const {
	Node* p = head->next;
	cout << "单链表的数据如下：\n" << endl;
	while (p != NULL) {
		cout << p->data << "   ";
		p = p->next;
	}
	cout << endl;
}

template<class elemType>
void linkList<elemType>::inverse()
{
	Node* p, * temp;
	p = head->next;
	head->next = NULL;
	if (p) tail = p;
	while (p) {
		temp = p->next;
		p->next = head->next;
		head->next = p;
		p = temp;
	}
 

}

////实操玩一玩
///**************头插法插入数据（空表时可用头插法插入数据）*******************/
//template <class elemType>
//void linkList<elemType> ::headCreate(elemType &value) {
//	Node* p;
//	p = new Node(value, head->next);
//	head->next = p;
//	if (head == tail)
//		tail = p;
//	curLength++;
//}

/**************************使用尾插法创建链表*******************************/
template <class elemType>
void linkList<elemType> ::tailCreate(elemType &value) {
	Node* p;
	p = new Node(value, NULL);
	tail->next = p;							    // 结点p插入到尾结点的后面
	tail = p;									// 结点p成为新的表尾
	curLength++;
}