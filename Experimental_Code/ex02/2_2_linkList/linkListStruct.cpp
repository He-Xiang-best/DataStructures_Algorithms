
//============================================================================
// @FileName     ��linkListStruct
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.10.21
// Description   ��
/*
ʵ�ֵ�����������Ա�Ļ���������
��ʼ�����Ա�������Ա������Ա��ȡ�������Ա��Ƿ�Ϊ�ա��������Ա������Ա��в���Ԫ�ء�
�����Ա��в��������Ԫ��ֵ��ͬ��Ԫ�������Ա��е�λ�á�����Ԫ�ء�ɾ��Ԫ�ء�
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include <iostream>
#include <windows.h>  
#include <string.h>
#include "linkList.h"
using namespace std;

//������
int scan() {
	cout << "  =================================================================\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ������Ļ�������                        ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ���������ݡ���(1)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ���������ݡ���(2)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ���������ݡ���(3)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��               ����> ����ֵ��ѯԪ��λ�á�  ��(4)                 ��\n";
	cout << " ��               ��                                                ��\n";
	cout << " ��               ����> ����λ��ѯԪ����ֵ��  ��(5)                 ��\n";
	cout << " ������ѯ��������>��                                                ��\n";
	cout << " ��               ����> ���鿴������ĳ��ȡ�  ��(6)                 ��\n";
	cout << " ��               ��                                                ��\n";
	cout << " ��               ����> ���鿴�������Ƿ�Ϊ�ա���(7)                 ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                    ��ɾ��������ŵĽڵ㡿��(8)                 ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                    ��ɾ���������ݵĽڵ㡿��(9)                 ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ��������ݡ���(10)                      ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ���������ݡ���(11)                      ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ���˳���������(0)                       ��\n";
	cout << " ��                                                                ��\n";
	cout << "  =================================================================\n";
	int choice;
	cout << "\n                     �ף���������Ҫ�����ı�ţ�";
	cin >> choice;
	return choice;
}

//�������д�������
template<class T>
void linkListCreatData(linkList<T> &ls) {
	//int num;
	//cout << "������Ҫ�����������ݣ�"<<endl;
	//cin >> num;
	cout << "\n��������Ҫ���������ݣ�(����9999��ʾֹͣ)" << endl;
	T value;
	cin >> value;
	for (/*int i = 0*/; value != 9999;/*i++*/ ) {
		ls.tailCreate(value);
		cin >> value;
	}
	cout << "\n����������ݴ�����ϣ���ǰ���鿴��" << endl;
}

//����������
template<class T>
void linkListTraverse(linkList<T>& ls) {
	if (ls.isEmpty()) {
		cout << "��ǰ������Ϊ�գ�û�����ݣ����������" << endl;
	}
	else
		ls.traverse();
}

//�������i��λ��ǰ����һ���ڵ�
template<class T>
void linkListInsert(linkList<T>& ls) {
	if (ls.isEmpty()) {
		cout << "��ǰΪ�ձ��޷��������ݵĲ��룡";	
	}
	else {
		cout << "��������Ҫ�����λ�ã�";
		int location;
		cin >> location;
		cout << endl;
		int len = ls.size() + 1;
		while (location<1 || location>len) {
			cout << "�����λ���������������룡����ǰ�Ϸ��Ĳ���λ��Ϊ��1..." << len << "��" << endl;
			cin >> location;
		}
		T value;
		cout << "��������Ҫ��������ݵ�ֵ��";
		cin >> value;
		cout << endl;
		ls.headinsert(location, value);
		cout << "����ɹ�����ǰ���鿴��" << endl;
		
	}
}

//����������ѯ��Ӧ����ֵ
template<class T>
void linkListFindindex(linkList<T>& ls) {
	if (ls.isEmpty()) {
		cout << "��ǰ������Ϊ�գ�û�����ݿɹ���ѯ��" << endl;
		return;
	}
	cout << "��������Ҫ���ҵ�����: ";
	T value;
	cin >> value;
	cout << endl;
	int location = ls.searchinValue(value);
	if (location == -1) {
		cout << "\n��ǰԪ�ز��ڵ������У��ɷ�������������ң�" << endl;
	}
	else {
		cout << "\n��ǰԪ���ڵ������еĵ� " << location << " ��λ��" << endl;
	}
}

template<class T>
void linkListFindValue(linkList<T>& ls) {
	if (ls.isEmpty()) {
		cout << "��ǰ������Ϊ�գ�û�����ݿɹ���ѯ��" << endl;
	}
	else {
		int len = ls.size();
		int i;
		cout << "��������Ҫ���ҵ����:";
		cin >> i;
		cout << endl;
		while (i<1 || i>len) {
			cout << "����ʧ�ܣ���ѯ����������뷵���������룡����ǰ�Ϸ��Ĳ�ѯ���Ϊ��1..." << len << "��" << endl;
			cin >> i;
			cout << endl;
		}
			ls.searchinNum(i);

	}
}

template<class T>
void remove(linkList<T> &ls) {
	if (ls.isEmpty()) {
		cout << "��ǰ������Ϊ�գ�û�����ݣ��޷�ɾ����" << endl;
	}
	else {
		int location;
		cout << "��������Ҫɾ���Ľڵ���ţ�";
		cin >> location;
		cout << endl;
		int len = ls.size();
		while (location<1 || location>len) {
			cout << "ɾ��ʧ�ܣ�ɾ��������������������룡����ǰ�Ϸ���ɾ�����Ϊ��1..." << len << "��" << endl;
			cin >> location;
			cout << endl;
		}
			ls.removeinNum(location);
			cout << "ɾ���ɹ���" << endl;
	}
}

template<class T>
void remove2(linkList<T>&ls) {
	if (ls.isEmpty()) {
		cout << "��ǰ������Ϊ�գ�û�����ݣ��޷�ɾ����" << endl;
		return;
	}
	T value;
	cout << "��������Ҫɾ����ֵ��";
	cin >> value;
	int location = ls.searchinValue(value);
	if(location == -1) {
		cout << "\nɾ��ʧ�ܣ���ǰԪ�ز��ڵ������У��ɷ�������������ң�" << endl;
	}
	else {
		ls.removeinNum(location);
		cout << "\nɾ���ɹ���" << endl;
	}
}

int main()
{
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl <<
		"                                ���ڳ�ʼ��������...........";
	Sleep(1000);
	system("cls");
	linkList<int> ls;
	for (;;) {
		switch (scan()) {
		case 1:
			system("cls");
			linkListCreatData(ls);
			getchar();
			getchar();
			break;
		case 2:
			system("cls");
			linkListTraverse(ls);
			getchar();
			getchar();
			break;
		case 3:
			system("cls");
			linkListInsert(ls);
			getchar();
			getchar();
			break;
		case 4:
			system("cls");
			linkListFindindex(ls);
			getchar();
			getchar();
			break;
		case 5:
			system("cls");
			linkListFindValue(ls);
			getchar();
			getchar();
			break;
		case 6:
			system("cls");
			cout << "������ĳ���Ϊ��" << ls.size() << endl;
			getchar();
			getchar();
			break;
		case 7:
			system("cls");
			if (ls.isEmpty()) {
				cout << "��ǰ�ĵ�����Ϊ�ձ���ǰ���������ݣ�" << endl;
			}
			else
				cout << "��ǰ�ĵ�����Ϊ�գ�����Ϊ��" << ls.size() << endl;
			getchar();
			getchar();
			break;
		case 8:
			system("cls");
			remove(ls);
			getchar();
			getchar();
			break;
		case 9:
			system("cls");
			remove2(ls);
			getchar();
			getchar();
			break;
		case 10:
			system("cls");
			if (ls.isEmpty()) {
				cout << "��ǰ������Ϊ�գ�û�����ݣ����������" << endl;
			}
			else {
				ls.clear();
				cout << "����ȫ������ɹ���" << endl;
			}
			getchar();
			getchar();
			break;
		case 11:
			system("cls");
			if (ls.isEmpty()) {
				cout << "��ǰ������Ϊ�գ�û�����ݣ��������ã�" << endl;
			}
			else {
				ls.inverse();
				cout << "�������óɹ���" << endl;
			}
			getchar();
			getchar();
			break;
		case 0:
			system("cls");
			cout << "�������˳�!" << endl;
			exit(0);
			break;
		}
		system("cls");
	}
    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
