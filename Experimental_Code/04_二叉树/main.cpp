
//============================================================================
// @FileName     ��main.cpp
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��
// Description   ��
/*

 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include"BinaryLinkedList.h"
using namespace std;

//������
int scan() {
	cout << "  =================================================================\n";
	cout << " ��                                                                ��\n";
	cout << " ��                      �������Ļ�������                          ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ����������     ��(1)                    ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        �������ߡ�     ��(2)                    ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                      �������Ĺ�ģ��   ��(3)                    ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                      ������Ҷ������   ��(4)                    ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                     ������ǰ�������  ��(5)                    ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                     ���������������  ��(6)                    ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                     �����ĺ��������  ��(7)                    ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                     �����Ĳ�α�����  ��(8)                    ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                      ����ն�������   ��(9)                    ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                       ���˳�������    ��(0)                    ��\n";
	cout << " ��                                                                ��\n";
	cout << "  =================================================================\n";
	int choice;
	cout << "\n                     �ף���������Ҫ�����ı�ţ�";
	cin >> choice;
	return choice;
}


int main()
{
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl <<
		"                                ���ڳ�ʼ��������...........";
	Sleep(1000);
	system("cls");
	BinaryLinkList<char> tree;
	for (;;) {
		switch (scan()) {
		case 1:
			system("cls");
			//*��ʾNULLΪ�ⲿ�ڵ�
			cout << "�����ⲿ�ڵ��ǰ�����������(*��ʾNULLΪ�ⲿ�ڵ�)" << endl;
			tree.preOrderCreate('*');
			cout <<"�����ɳɹ���"<< endl;
			getchar();
			getchar();
			break;
		case 2:
			system("cls");
			cout << "���ĸ߶�Ϊ��" << tree.height() << endl;
			getchar();
			getchar();
			break;
		case 3:
			system("cls");
			cout << "���Ĺ�ģΪ��" << tree.size() << endl;
			getchar();
			getchar();
			break;
		case 4:
			system("cls");
			cout << "����Ҷ����Ϊ��" << tree.leafNum() << endl;
			getchar();
			getchar();
			break;
		case 5:
			system("cls");
			cout << "����ǰ�����Ϊ��" << endl;
			tree.preOrderWithStack();
			getchar();
			getchar();
			break;
		case 6:
			system("cls");
			cout << "�����������Ϊ��" << endl; 
			tree.inOrderWithStack();
			getchar();
			getchar();
			break;
		case 7:
			system("cls");
			cout << "���ĺ������Ϊ��" << endl;
			tree.postOrderWithStack();
			getchar();
			getchar();
			break;
		case 8:
			system("cls");
			cout << "���Ĳ�α���Ϊ��" << endl;
			tree.levelOrderTraverse();
			getchar();
			getchar();
			break;
		case 9:
			system("cls");
			tree.clear();
			cout << "������գ�" << endl;
			getchar();
			getchar();
			break;
		case 0:
			system("cls");
			cout << "�������˳�!" << endl;
			exit(0);
			break;
		}
		//system("cls");
	}

    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
