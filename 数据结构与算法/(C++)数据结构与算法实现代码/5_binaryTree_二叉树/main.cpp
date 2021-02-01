#include<queue>
#include<stack>
#include<iostream>
#include <cstdlib>    
using namespace std;
#include"BinaryLinkedList.h"

//����һ��������ʾ�Ķ����� (��ͼ��ʾ)   
//                A   
//              /   \   
//             B      C   
//           /   \     \
//          D     E      F
//               /      / \
//              G      H   I
// 
//�ٶ�data��Ϊ�ַ��ͣ�����ǰ������(*��ʾNULLΪ�ⲿ���)��ABD**EG***C*FH**I**
//��ʱ�����ݸ������ܹ�Ψһȷ��һ�ö�����
//�������ͬ����������ⲿ���Ĳ������ABCDE*F**G*HI******

template <class T> 
void testBinaryTree(BinaryLinkList<T> &tree)
{  	
	cout<<"������ⲿ����ǰ���������(*��ʾNULLΪ�ⲿ���)��"; tree.preOrderCreate('*');
	cout << "�߶�Ϊ��" << tree.height() << endl;
	cout << "��ģΪ��" << tree.size() << endl;
	cout << "Ҷ������" << tree.leafNum() << endl;
	cout << "ǰ�������";  tree.preOrderWithStack();
	cout << "\n���������";  tree.inOrderWithStack();
	cout << "\n���������";  tree.postOrderWithStack();  
	cout << "\n����������"; tree.levelOrderTraverse();
	cout <<endl;
}

int main()
{
	BinaryLinkList<char> tree;
	testBinaryTree(tree);
	system("pause");
	return 0;
}
