#pragma once
#include<queue>
#include<stack>
#include"BinaryTree.h"
using namespace std;
template <class elemType>
class BinaryLinkList :public binaryTree<elemType> {
private:
    struct Node {  			// ����������
        Node* left, * right;// ָ�����Һ��ӵ�ָ��
        elemType data;		// ����������
        Node() : left(NULL), right(NULL) { }// �޲ι���
        Node(elemType value, Node* l = NULL, Node* r = NULL)
        {
            data = value; left = l; right = r;
        }
        ~Node() {}
    };
    enum ChildType { Left, Right };
    struct StackElem
    {
        Node* pointer;
        ChildType flag;

    };
    Node* root;				        // ָ��������ĸ���� 
// ����˽�к������β�����ΪNode��ָ��
    void clear(Node* t);			// ˽�У����
    int size(Node* t) const; 		// ˽�У��������Ľ������
    int height(Node* t) const; 		// ˽�У��������ĸ߶�
    int leafNum(Node* t)const; 		// ˽�У���������Ҷ����
    void preOrder(Node* t) const;	// ˽�У��ݹ�ǰ�����
    void inOrder(Node* t) const;	// ˽�У��ݹ��������
    void postOrder(Node* t) const;	// ˽�У��ݹ�������
    void preOrderCreate(elemType flag, Node*& t);// ˽�У����������� 
public:
    BinaryLinkList() : root(NULL) {}	// ����ն�����
    ~BinaryLinkList() { clear(); }
    bool empty() const { return root == NULL; }	// �п�
    // ���е���ա���������߶ȡ�Ҷ�����������˽����ա���������߶ȡ�Ҷ�����
    void clear() { if (root) clear(root); root = NULL; }	// ���У����
    int size() const { return size(root); }	// ���У���������
    int height() const { return height(root); }	// ���У��������ĸ߶�
    int leafNum()const { return leafNum(root); }// ���У���������Ҷ����
     // ���У�ǰ�����򡢺������������˽��ǰ�����򡢺������
    void preOrderTraverse() const { if (root) preOrder(root); }
    void inOrderTraverse() const { if (root) inOrder(root); }
    void postOrderTraverse() const { if (root) postOrder(root); }
    void levelOrderTraverse() const;	// ��α���
    void preOrderWithStack()const;		// �ǵݹ�ǰ�����
    void inOrderWithStack()const;		// �ǵݹ�������� 
    void postOrderWithStack()const;		// �ǵݹ�������
    // ���ô��ⲿ���Ĳ�����д���������
    void levelOrderCreate(elemType flag);
    // ���У����ô��ⲿ����ǰ�����д���������	
    void preOrderCreate(elemType flag) {
        preOrderCreate(flag, root);
    }
};

//�������ĵݹ�ǰ�����
template <class elemType>
void BinaryLinkList<elemType>::preOrder(Node* t) const {
    if (t) {
        cout << t->data << ' ';	// ���ʵ�ǰ���
        preOrder(t->left);		// ǰ�����������
        preOrder(t->right);		// ǰ�����������
    }
}

//������������ݹ����
template <class elemType>
void BinaryLinkList<elemType>::inOrder(Node* t) const {
    if (t) {
        inOrder(t->left); 		// �������������
        cout << t->data << ' '; // ���ʵ�ǰ���
        inOrder(t->right);	  	// �������������
    }
}

//�������ĵݹ�������
template <class elemType>
void BinaryLinkList<elemType>::postOrder(Node* t) const {
    if (t) {
        postOrder(t->left); 		// �������������
        postOrder(t->right); 		// �������������
        cout << t->data << ' '; 	// ���ʵ�ǰ���
    }
}

//�������Ĳ�α�����
template <class elemType>
void BinaryLinkList<elemType>::levelOrderTraverse() const {
    queue<Node*> que;		// STL�еĶ���
    Node* p = root;
    if (p) que.push(p);		// ����������
    while (!que.empty()) {	// ���зǿ�
        p = que.front(); 	 // ȡ����Ԫ��
        que.pop();			// ����
        cout << p->data << ' ';	// ���ʵ�ǰ���	
        if (p->left != NULL)que.push(p->left);	// ������������
        if (p->right != NULL)que.push(p->right);// ������������
    }
}

//ǰ�����н���������
template <class elemType>
void BinaryLinkList<elemType>::preOrderCreate(elemType flag, Node*& t) {
    // ��ע�⣬��ΪҪ�޸�tָ�룬����tָ��ʹ�����ô���
    elemType value;
    cin >> value;
    if (value != flag) {		// �ݹ����value==flag
        t = new Node(value);	// ���ɸ����
        preOrderCreate(flag, t->left);	// �ݹ鴴��������
        preOrderCreate(flag, t->right);	// �ݹ鴴��������
    }
}

//��������
template <class elemType>
int BinaryLinkList<elemType>::size(Node* t) const {
    if (t == NULL) return 0;// ���(1)��������
    return 1 + size(t->left) + size(t->right);// ���(2)�������ǿ�
}

//�������ĸ߶�
template <class elemType>
int BinaryLinkList<elemType>::height(Node* t) const {
    if (t == NULL) return 0;	        // ���(1)��������	
    else {				                // ���(2)�������ǿ�
        int lh = height(t->left), rh = height(t->right);
        return 1 + ((lh > rh) ? lh : rh);// ���ĸ߶�Ϊ���������߶ȴ���+1
    }
}

//��Ҷ����
template <class elemType>
int BinaryLinkList<elemType>::leafNum(Node* t)const {
    if (t == NULL)return 0;	// ���(1)��������	
    else if ((t->left == NULL) && (t->right == NULL))
        return 1;	// ���(2)��Ҷ���
    else 			// ���(3)������������Ҷ����֮��
        return leafNum(t->left) + leafNum(t->right);
}

//��ն�����
//ɾ������������֮����ɾ�����������
template <class elemType>
void BinaryLinkList<elemType>::clear(Node* t) {
    if (t->left) clear(t->left);
    if (t->right) clear(t->right);
    delete t;
}

//���ô��ⲿ���Ĳ�����д���������
template <class elemType>
void BinaryLinkList<elemType>::levelOrderCreate(elemType flag) {
    queue<Node*> que; // STL�еĶ���
    Node* p;
    elemType value, ldata, rdata;
    cin >> value;
    if (value != flag) root = new Node(value); //���������
        que.push(root); //���
    while (!que.empty()) {// ���зǿ�
        p = que.front(); que.pop(); // ȡ����Ԫ��
        cin >> ldata >> rdata; // �������Һ���
        if (ldata != flag) que.push(p->left = new Node(ldata));
        if (rdata != flag)que.push(p->right = new Node(rdata));
    }
}

//�ǵݹ�ǰ�����
template <class elemType>
void BinaryLinkList<elemType>::preOrderWithStack()const {
    stack<Node*> s; //STL�е�ջ
    Node* p = root; // ����ָ��
    while (!s.empty() || p) {// ջ�ǿջ���p�ǿ�
        if (p) {
            cout << p->data << " "; //���ʵ�ǰ���
            s.push(p); // ָ����ջ
            p = p->left; //����ָ��ָ��������
        }
        else { //������������ϣ�ת�����������
            p = s.top(); // ��ȡջ��Ԫ��
            s.pop(); // ��ջ
            p = p->right; //����ָ��ָ��������
        }
    }
}

//�ǵݹ��������
template <class elemType>
void BinaryLinkList<elemType>::inOrderWithStack()const {
    stack<Node*> s; //STL�е�ջ
    Node* p = root; // ����ָ��
    while (!s.empty() || p) {// ջ�ǿջ���p�ǿ�
        if (p) {
            s.push(p); // ָ����ջ
            p = p->left; //����ָ��ָ��������
        }
        else { //������������ϣ�ת�����������
            p = s.top(); // ��ȡջ��Ԫ��
            s.pop(); // ��ջ
            cout << p->data << " "; //���ʵ�ǰ���
            p = p->right; //����ָ��ָ��������
        }
    }
}

//�ǵݹ�������
template <class elemType>
void BinaryLinkList<elemType>::postOrderWithStack()const {
    
    StackElem elem;
    stack<StackElem> s;
    Node* p = root; // ����ָ��
    while (!s.empty() || p) {// ջ�ǿջ���p�ǿ�
        while (p != NULL) {
            elem.pointer = p;
            elem.flag = Left;
            s.push(elem);
            p = p->left;
        }
        elem = s.top();
        s.pop();
        p = elem.pointer;
        if (elem.flag == Left) {
            elem.flag = Right;
            s.push(elem);
            p = p->right;
        }
        else {
            cout << p->data << " ";
            p = NULL;
        }
    }
}


