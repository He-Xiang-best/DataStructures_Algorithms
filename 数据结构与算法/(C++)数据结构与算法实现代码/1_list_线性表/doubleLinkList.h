#ifndef _DOUBLELINKLIST_H_
#define _DOUBLELINKLIST_H_
#include "List.h" 

template <class elemType>
class doubleLinkList: public List<elemType>
{
 private:
	struct Node {
		elemType  data;
		Node *prior, *next;
		Node(const elemType &value, Node *p = NULL, Node *n = NULL)
		{ 	data = value; next = n; prior = p;		}
		Node( ):next(NULL), prior(NULL) {}
		~Node() {}
	};
	Node  *head, *tail;
	int curLength;
	Node *getPosition(int i)const; 
public:
	doubleLinkList() ;
	~doubleLinkList();
	void clear() ;
	bool empty()const{ return head->next == tail; }
	int size() const{ return curLength; }
	void insert(int i, const elemType &value); 
	void remove(int i);  
	int search(const elemType &value) const  ;
	elemType visit(int i) const;
	void traverse() const ;  
	void inverse();
};
template <class elemType>
doubleLinkList<elemType>::doubleLinkList() 
{   
	head = new Node;					// ͷָ��ָ��ͷ���
	tail = new Node;
    head->next = tail;		// βָ��ָ��β��㣬�˴�β�����������ͷ���
    tail->prior = head;
    curLength = 0;
} 

template <class elemType>
void doubleLinkList<elemType>::clear() 
{ 
	Node  *p = head->next, *tmp;
	head->next = tail;
	tail->prior = head;
	while (p != tail) { 
		tmp = p->next;
		delete p;   
		p=tmp; 	 
	}
	curLength = 0;
}
template <class elemType>
doubleLinkList<elemType>::~doubleLinkList(){
	clear(); 
	delete head; 
	delete tail;
}
template <class elemType>
typename doubleLinkList<elemType>::Node *doubleLinkList<elemType>::getPosition(int i) const
{ 
	Node *p =head;      
	int count = 0; 
	// getPosition�ɲ���λ��Ϊ[-1..n],��iΪ-1��λ��ͷ���,��iΪn��λ��tailָ���β���
	if (i < -1 || i > curLength )return NULL;	// ��i�Ƿ�ʱ����NULL 								
	while (count <= i) { 
		p = p-> next; 
		count++; 
	} 
	return p;									// ����ָ��� i ����ָ�� 
} 

template <class elemType>
void doubleLinkList<elemType>::insert(int i,const elemType &value)
{
	Node *p, *tmp;
	if (i < 0 || i > curLength)					// �Ϸ��Ĳ���λ��Ϊ[0..n]
		 throw outOfRange();					// ����λ�÷Ƿ����׳��쳣
	p = getPosition(i);						// ��i==n��λ��tailָ���β���
	tmp = new Node(value, p->prior, p);		// tmp���뵽p֮ǰ
	p->prior->next = tmp;
	p->prior = tmp;
	++curLength;
}
template <class elemType>
void doubleLinkList<elemType>::remove(int i)
{
	Node *p;
	if (i < 0 || i > curLength-1) 				// �Ϸ���ɾ��λ��Ϊ[0..n-1] 
		 throw outOfRange();					// ����ɾ��㲻����ʱ���׳��쳣
	p = getPosition(i);
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	--curLength;
}
template <class elemType>
int doubleLinkList<elemType>::search(const elemType &value) const  
{ 
	Node *p = head->next;
	int i = 0;
	while (p != tail && p->data != value) { p = p->next; ++i; }
	if (p == tail) return -1; else return i;
} 
template <class elemType>
elemType doubleLinkList<elemType>::visit(int i) const
{ 
	if (i < 0 || i > curLength-1) 			// �Ϸ��ķ���λ��Ϊ[0..n-1] 
		throw outOfRange();					// ����㲻����ʱ���׳��쳣
	Node *p = getPosition(i);				// getPosition��λ��Χ[-1..n]����˲���ֱ������getPosition�жϷ�Χ�Ƿ�Ϸ�
	return p->data;
} 
template <class elemType>
void doubleLinkList<elemType>::traverse() const
{
	Node *p = head->next;
	cout << "traverse:" ; 
	while (p != tail) {
		cout << p->data << "  ";
		p=p->next;
	}
	cout << endl;
}
template <class elemType>
void doubleLinkList<elemType>::inverse()
{
	Node *tmp,*p = head->next;
	head->next = tail;
	tail->prior = head;
	while (p != tail) { 
		tmp= p->next;
		p->next=head->next;  p->prior=head;
		head->next->prior=p;	head->next=p;
		p=tmp; 	 
	}
}

#endif