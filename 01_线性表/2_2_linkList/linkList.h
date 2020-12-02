#pragma once
#include<iostream> 
using namespace std;
//============================================================================
// @FileName     ��linkList
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.10.21
// Description   ��
/*
ʵ�ֵ�����������Ա�Ļ���������
��ʼ�����Ա�������Ա������Ա��ȡ�������Ա��Ƿ�Ϊ�ա�
�������Ա������Ա��в���Ԫ�ء������Ա��в��������Ԫ��ֵ��ͬ��Ԫ�������Ա��е�λ�á�
����Ԫ�ء�ɾ��Ԫ�ء�
 */
 //============================================================================
 
template <class elemType>								// elemTypeΪ������洢��Ԫ������
class linkList {
private:
	struct Node {
	public:
		elemType  data;									// ����������
		Node* next;									    // ����ָ����ָ���̽��
		// ���ڳ�ʼ��һ�������ݵĽڵ�
		Node(const elemType value, Node* p = NULL) {
			data = value;
			next = p;
		}
		//���ڳ�ʼ��ͷ����û�����ݵĽڵ�
		Node(Node* p = NULL) {
			next = p;
		}
	};
	Node* head;								           // �������ͷָ��
	Node* tail;    							           // �������βָ��
	int curLength;								       // ������ĳ���
public:
	linkList();								           // ���캯��
	~linkList();								       // ��������
	void clear(); 								       // ����������գ�ʹ֮��Ϊ�ձ�ͷ��㻹�ڣ�
	bool isEmpty()const {
		return head->next == NULL;                     // �жϵ������Ƿ�Ϊ��(�ж�curLength==0Ҳ����)
	}
	int  size()const;                   		       // ���ص�����ĵ�ǰʵ�ʳ���
	void headinsert(int i, elemType &value);	       // ��λ��iǰ����һ��Ԫ��value����ĳ�����1
	void removeinNum(int i);					       // ɾ��λ��i�ϵ�Ԫ��value����ɾ��λ�úϷ�����ĳ��ȼ�1
//	bool removeinValue(elemType &value);               //ɾ���洢ֵΪvalue�Ľڵ�
	int  searchinValue(elemType &value);               // ����ֵΪvalue��Ԫ�ص�һ�γ��ֵ�λ��
	void searchinNum(int i);		                   // �������Ϊnum��Ԫ�ص���ֵ
	void traverse()const;						       // ����������
	void inverse();
//	void headCreate(elemType &value);			       // �ձ�ʱ����ͷ�巨��������
	void tailCreate(elemType &value);		           // ��β�巨������������
};

/*****************���캯������������ͷ���Ŀձ�(��ʼ��)**********************/
template <class elemType>
linkList<elemType>::linkList() {
	head = tail = new Node();
	curLength = 0;
}

/***************������������������ݣ���ɾ��ͷ��㣬�����ͷſռ�**************/
template <class elemType>
linkList<elemType>::~linkList() {
	clear();
	delete head;
}

/***************************ɾ��ȫ���Ľ�㣬�ͷſռ�**************************/
template <class elemType>
void linkList<elemType>::clear() {
	Node* p, * tmp;
	p = head->next;								    // pΪ����ָ�룬ָ����Ԫ���
	while (p != NULL) {
		tmp = p;
		p = p->next;								// ָ�����
		delete tmp;
	}
	head->next = NULL;							    // ͷ����ָ�����ÿ�
	tail = head;								    // ͷβָ���ָ��ͷ���
	curLength = 0;
}

/*******************************��õ�����ĳ���******************************/
template <class elemType>
int linkList<elemType>::size()const {
	//��ͷ��β����������ó��ȱȽ��鷳��ֱ����һ�����ݼ�¼�ͺ�
	//	Node *p =head->next;
	//	int count=0;
	//	while(p) {
	//		count++;
	//		p=p->next;
	//	}
	//	return count;
	return curLength;
}

/****************************��ֵ���������ڱ��е�λ��************************/
template <class elemType>
int linkList<elemType> ::searchinValue(elemType &value) {
	Node* p = head->next;
	int i = 1;//����ϲ������Ϊ��ŵ�˳��
	while (p != NULL && p->data != value) {
		p = p->next;
		i++;
	}
	if (p == NULL) return -1;
	else return i;

}

/****************************����Ų��������ڱ��е���ֵ*****************************/
template <class elemType>
void linkList<elemType> ::searchinNum(int i) {
	Node* p = head->next;
	int j = 1;
		while (j < i) {
			p = p->next;
			j++;
		}
		cout << "\n��" << i << "��Ԫ�ض�Ӧ����ֵΪ: " << p->data << endl;
	
}

/****************************ʹ��ǰ�巨��������********************************/
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

/*****************************�����ɾ���ڵ�******************************/
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

//�ɽ�������ɾ�����
/***************************��ֵɾ���ڵ�***********************************/
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

/**************************����������***************************************/
template <class elemType>
void  linkList<elemType> ::traverse()const {
	Node* p = head->next;
	cout << "��������������£�\n" << endl;
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

////ʵ����һ��
///**************ͷ�巨�������ݣ��ձ�ʱ����ͷ�巨�������ݣ�*******************/
//template <class elemType>
//void linkList<elemType> ::headCreate(elemType &value) {
//	Node* p;
//	p = new Node(value, head->next);
//	head->next = p;
//	if (head == tail)
//		tail = p;
//	curLength++;
//}

/**************************ʹ��β�巨��������*******************************/
template <class elemType>
void linkList<elemType> ::tailCreate(elemType &value) {
	Node* p;
	p = new Node(value, NULL);
	tail->next = p;							    // ���p���뵽β���ĺ���
	tail = p;									// ���p��Ϊ�µı�β
	curLength++;
}