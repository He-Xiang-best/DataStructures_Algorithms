#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include<stack>
#include "List.h" 

template <class elemType>								// elemTypeΪ������洢��Ԫ������
class linkList: public List<elemType>  { 
private:  
	struct Node {                                       //node�ṹ��Ķ��塣�ֽ׶Σ��ṹ���������𲻴� 
	public:  
   		elemType  data;									// ����һ������������ -data��data���ֿ����޸� 
		Node 	* next;									// ����ָ����ָ���̽�� 
		Node(const elemType value, Node* p = NULL)  {	// ���������������������ָ���������������Node���캯�� �� 
			data = value;                               //�ٸ����ӣ���������ͨ����һ�ص�Կ��p������next��ͳ���value
                                                        //������data����ſ���ͨ����һ�ء� �˴��������Ϊ����ĺ��壬ͨ����һ��һ���������� 
			next = p; 
		} 
		Node(Node* p = NULL)  { 						// ����һ��������Node���캯��-�����Ѿ������ú��ˣ�ֱ��ָ����һ��������ֱ���þͺ��� 
			next = p;                                   //�����Ѿ���ʼ�����ˣ�����������һ����㣬���ı䱾����ֵ��null����Ĭ�ϲ����� 
		}
	};
	Node*  head;								// �������ͷָ�� 
    Node*  tail;    							// �������βָ�� 
	int curLength;								// ������ĵ�ǰ����
	Node*  getPosition(int i)const;				// ����ָ�������е�i��Ԫ�ص�ָ��   

	void traverseRecursive(Node * p);
	void traverseNonRecursive1();
	void traverseNonRecursive2();
	void traverseNonRecursive3();
public:  
	linkList();								// ���캯�� 
	~linkList();								// �������� 
    void clear(); 								// ����������գ�ʹ֮��Ϊ�ձ�
	bool empty()const{return head->next==NULL;}// �п�
	int size()const{return curLength;};         // ���ص�����ĵ�ǰʵ�ʳ��� 						 
	void insert(int i,const elemType &value);	// ��λ��i�ϲ���һ��Ԫ��value����ĳ�����1 
	void remove(int i);							// ɾ��λ��i�ϵ�Ԫ��value����ɾ��λ�úϷ�����ĳ��ȼ�1 
	int search(const elemType&value)const;		// ����ֵΪvalue��Ԫ�ص�һ�γ��ֵ�λ��
	elemType visit(int i)const;					// ����λ��Ϊi��Ԫ��ֵ����λ��0��ʾ��һ��Ԫ�أ������������±�
	void traverse()const;						// ����������	
	void headCreate();							// ��ͷ�巨������������
	void tailCreate();							// ��β�巨������������
	void inverse();								// ���õ�����
	int prior(const elemType&value)const;		// ����ֵΪvalue��Ԫ�ص�ǰ��
	linkList* Union(linkList<elemType> * lb);
	void outPut();
}; 
 
template <class elemType>  
linkList<elemType>::linkList(){ 
	head = tail = new Node();				// ��������ͷ���Ŀձ�������Ҫ�ȿ�node�Ĺ��캯���������档 
	curLength=0;                            //����node���޲ε��������node���캯����ȥ�ģ�������һ���������Ǹ����캯����ȥ 
} 
 
template <class elemType> 
linkList<elemType>::~linkList(){ 
	clear();
	delete head;								// ɾ��ͷ���
} 

template <class elemType>  
void linkList<elemType>::clear(){ 
	Node *p,*tmp; 
	p = head->next;								// pΪ����ָ��(ע�ⲻҪ�����޸�ͷָ��)��ָ����Ԫ���
	while (p != NULL) {							// ��Чwhile(p)
		tmp = p; 
		p= p->next;								// ָ�����
		delete tmp;										
	} 
	head->next=NULL;							// ͷ����ָ�����ÿ�
	tail = head;								// ͷβָ���ָ��ͷ���
	curLength=0;
}
/*
template <class elemType>  
int linkList<elemType>::size()const{ 
	//return curLength;							// ��linkList����û�����ݳ�ԱcurLength
	Node *p =head->next;						// ��Ҫ��ͷ��β��������					
	int count=0;
	while(p){ count++; p=p->next;}
	return count;
} 
*/
template <class elemType>  						
typename linkList<elemType> :: Node* linkList<elemType> :: getPosition(int i)const { 
	Node *p =head;      
	int count = 0; 

	if (i < -1 || i > curLength-1)				// // getPosition�ɲ���λ��Ϊ[-1..n-1],��iΪ-1��λ��ͷ���,��iΪ0��λ����Ԫ��� 
		return NULL;							// ��i�Ƿ�ʱ����NULL

	while (count <= i) { 
		p = p-> next; 
		count++; 
	} 

	return p;									// ����ָ��� i ����ָ�� 
} 
      
 
template  <class elemType>  			 		
void linkList<elemType> :: insert(int i,const elemType &value)  { 
	Node *p, *q; 
					 
	if (i < 0 || i > curLength)					// �Ϸ��Ĳ���λ��Ϊ[0..n]
		 throw outOfRange();					// ����λ�÷Ƿ����׳��쳣

	p = getPosition(i-1);						// p��λ��Ϊi�Ľ���ǰ�� 
    q = new Node(value, p->next); 
    p->next = q; 

    if (p == tail)tail = q;						// ������ڱ�β���������Ϊ�µ�β���   

	curLength++;
} 
 
template  <class elemType>  							
void  linkList<elemType>::remove(int i){ 
	Node *pre, *p;  
	if (i < 0 || i > curLength-1) 				// �Ϸ���ɾ��λ��Ϊ[0..n-1] 
		 throw outOfRange();					// ����ɾ��㲻����ʱ���׳��쳣

	pre = getPosition(i-1);
    p = pre->next;								// p��������ɾ��� 
	if (p == tail) {							// ��ɾ���Ϊβ��㣬���޸�βָ�� 
		  tail = pre; 
		  pre->next=NULL;
		  delete p; 
    } 
    else {										// ɾ�����p ���޸�ָ�� 
    	pre->next = p->next; 
	    delete p; 
     } 
	curLength--;
} 
  
template <class elemType>  						
void  linkList<elemType> ::traverse()const{ 
	Node *p = head->next; 
	cout << "traverse:" ; 
	while (p != NULL) {  
		cout << p->data <<"  "; 
		p = p->next; 
	} 
	cout << endl; 
} 

template <class elemType>  							
int linkList<elemType> ::search(const elemType&value)const{ 
	Node *p = head->next; 
	int count=0;								// ��Ԫ����λ��Ϊ0
	while (p != NULL && p->data!=value) {   
		p = p->next; 
		count++;
	} 
	if(p == NULL)return -1;						// ����ʧ�ܷ���-1������-1����ͷ�ڵ�
	else return count;
} 

template <class elemType>  						// ����λ��Ϊi��Ԫ�ط�����������
elemType linkList<elemType> ::visit(int i)const{ 
	Node *p = head->next; 
	int count=0;								// ��Ԫ���λ��Ϊ0

	if (i < 0 || i > curLength-1) 				// �Ϸ��ķ���λ��Ϊ[0..n-1] 
		throw outOfRange();						// ����㲻����ʱ���׳��쳣

	while ( count<i ) {   
		p = p->next; 
		count++;
	} 
	return p->data;
} 

template <class elemType>  						// ͷ�巨�������� 
void linkList<elemType> :: headCreate(){ 
	Node *p; 
	elemType value,flag;
	cout<<"input elements,ended with:";
	cin>>flag;									// ���������־

	while(cin>>value,value!=flag)
	{
		p=new Node(value,head->next);
		head->next=p;							// ���p���뵽ͷ���ĺ���
		if(head==tail)tail=p;					// ԭ����Ϊ�գ�����p��β���
		curLength++;
	}
} 

template <class elemType>  						// β�巨��������
void linkList<elemType> ::tailCreate(){ 
	Node *p; 
	elemType value,flag;
	cout<<"input elements,ended with:";
	cin>>flag;									// ���������־

	while(cin>>value,value!=flag)
	{
		p=new Node(value,NULL);
		tail->next=p;							// ���p���뵽β���ĺ���
		tail=p;									// ���p��Ϊ�µı�β
		curLength++;
	}
} 
template <class elemType>  						// ͷ�巨���� 
void linkList<elemType> :: inverse(){ 
	Node *p,*tmp;
	p=head->next;								// pΪ����ָ��ָ����Ԫ���
	head->next=NULL;							// ����ֻ��һ��ͷ���Ŀ�����							
	if(p)tail=p;								// ԭ��Ԫ��㽫��ɱ�β
	while(p)
	{
		tmp=p->next;							// ���浱ǰ������p�ĺ��
		p->next=head->next;						
		head->next=p;							// ���p���뵽ͷ���ĺ���
		p=tmp;
	}
} 

template <class elemType>  
int linkList<elemType> ::prior(const elemType&value)const{
    Node *p=head->next; 					// p�ǹ���ָ��ָ����Ԫ���
    Node *pre=NULL; 						// preָ��p��ǰ�����
    int count=-1;							// -1��ʾ��Ԫ�����ǰ��
    while(p &&p->data!=value){
        pre=p; 								// ǰ��ָ�����
        p=p->next; 							// ָ���¸���������
        count++;
    }
    if(p == NULL)return -1;					// ����ʧ�ܷ���-1������-1����ͷ���
    else return count; 						// ���ҳɹ���countΪԪ�ص�λ��
}        
template <class elemType> 
linkList<elemType> * linkList<elemType> ::Union(linkList<elemType> * lb){
    Node *pa,*pb,*pc;						// �ֱ�������la��lb��lc�Ĺ���ָ��
    linkList<elemType>* lc = this;			// lc����la�ռ䣬��lb�ϲ�����
    pa=head->next;  head->next=NULL;			// la��ͷ����ָ������ΪNULL�����ɿ�����
    pb=(lb->head)->next;  (lb->head)->next=NULL;// lb��ͷ����ָ������ΪNULL�����ɿ�����
    pc=lc->head;							// Ϊ��Լ�ռ�lc��ֱ������la��ͷ���
    while(pa && pb){						// la��lb���ǿ�
        if(pa->data<=pb->data) {				// pa��ָ���β�巨����lc��
            pc->next=pa;  pc=pa;  pa=pa->next;    
        }
        else	{							// pb��ָ���β�巨����lc��
            pc->next=pb;  pc=pb;  pb=pb->next;   
        }
    }
    if(pa){ 								// ��paδ��β����pcָ��pa
        pc->next=pa;						
        lc->tail=tail;						// �޸�βָ��
    }
    else{
        pc->next=pb;						// ��pbδ��β����pcָ��pb
        lc->tail=lb->tail;					// �޸�βָ��
    }
    lc->curLength = curLength+lb->curLength;
    delete lb;	
    return lc;
}

template <class elemType> 
void linkList<elemType> :: outPut() {        
	cout<<"�ݹ�:";
	traverseRecursive(head->next);	cout<<endl;
	cout<<"�ǵݹ�1:";
	traverseNonRecursive1();	cout<<endl;
	cout<<"�ǵݹ�2:";
	traverseNonRecursive2();	cout<<endl;
	cout<<"�ǵݹ�3:";
	traverseNonRecursive3();	cout<<endl;
}
template <class elemType> 
void linkList<elemType> :: traverseRecursive(Node * p) {        
    if(p) {
        cout<<p->data<<"  ";				// �������ֵ
        traverseRecursive(p->next);       			// β�ݹ����	
    }									
}
//˳����������������ݵķǵݹ��㷨һ��	
template <class elemType> 		 
void linkList<elemType> :: traverseNonRecursive1()  {    
	Node *p=head->next;
    Lb1:                      				// �ڵ�һ����ִ�����ǰ����
    if(p){
        cout<<p->data<<"  ";				// �������ֵ
        p=p->next;    
        goto Lb1;               			// ת����һ����ִ�����
    }
}
//˳����������������ݵķǵݹ��㷨����
template <class elemType> 			
void linkList<elemType> :: traverseNonRecursive2() { 
    Node *tmp = head->next; 	
    while (tmp != NULL) {  
        cout << tmp->data <<"  ";			// �������ֵ
        tmp = tmp->next; 				// ����һ���޸ı���ֵ 
    } 
    cout <<endl; 
}
//˳����������������ݵķǵݹ��㷨����
template <class elemType> 				
void linkList<elemType> :: traverseNonRecursive3() { 
    stack<Node*> S; 
	Node* tmp=head->next;
    while (tmp != NULL) {  
        S.push(tmp);			
        tmp = tmp->next; 				
    }
	while(!S.empty()){
		tmp=S.top();
		S.pop();
		cout << tmp->data <<"  ";	
	}
    cout <<endl; 
}          

#endif
