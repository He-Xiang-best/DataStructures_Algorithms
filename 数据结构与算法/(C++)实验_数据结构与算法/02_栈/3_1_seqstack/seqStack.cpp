
//============================================================================
// @FileName     ��seqStack.cpp
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.10.25
// Description   ��
/*
�ֱ�ʵ��˳��ջ����ջ�ĳ����������Ͷ��壬���ջ�Ļ���������
��ʼ��ջ�����ջ�Ƿ�Ϊ�ա����ջ����ջ����ջ��ȡջ��Ԫ�ء�
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <windows.h>  
#include <string.h>
#include "seqstack.h"
using namespace std;



template<class T>
void startStack(seqstack<T> &sq) {
	int n;
	cout << "������Ҫ��ջ�д�ż���Ԫ�أ�" ;
	cin >> n;
	cout << endl;
	while (n>sq.maxLength())
	{
		sq.resize();
	}
	cout << "����������Ԫ�ص�ֵ��" << endl;
	T value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		sq.push(value);
	}
	cout << "\nջ��ʼ���ɹ���" << endl;
}

template<class T>
void clearStack(seqstack<T>& sq) {
	sq.clear();
	cout << "ջ��ճɹ���" << endl;
}

template<class T>
void getStackLength(seqstack<T>& sq) {
	
	cout << "��ǰ��ջ�ĳ���Ϊ��" << sq.size()<<endl;
}

template<class T>
void judgeIsEmpty(seqstack<T>& sq) {
	if (sq.isEmpty()) {
		cout << "��ǰջ������Ϊ�գ�" << endl;
		return;
	}
	if (sq.isFull()) {
		cout << "��ǰջ��������������ʱ����Ϊ��" << sq.maxLength() << endl;
		return;
	}
	cout << "��ǰջ��������Ϊ�գ���ʱ����Ϊ��" << sq.maxLength() << endl;
}

template<class T>
void getStacktop(seqstack<T>& sq) {
	if (sq.isEmpty()) {
		cout << "��ǰջΪ�գ���ջ��Ԫ�أ�" << endl;
	}
	else
		cout << "��ǰ��ջ��Ԫ��Ϊ��" << sq.getTop() << endl;
}

template<class T>
void inStack(seqstack<T>& sq) {
	int n;
	cout << "�������ջ����Ԫ�أ�";
	cin >> n;
	cout << endl;
	while (n > sq.maxLength())
	{
		sq.resize();
	}
	cout << "�����������ջԪ�ص�ֵ��" << endl;
	T value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		sq.push(value);
	}
	cout << "\nԪ�ؽ�ջ�ɹ���" << endl;
}

template<class T>
void popStack(seqstack<T>& sq) {
	int n;
	cout << "�����㵯ջ����Ԫ�أ�";
	cin >> n;
	cout << endl;
	while (n > sq.size()||n<0) {
		cout << "��ջԪ�ظ������󣬵�ǰջ��Ԫ������Ϊ��" << sq.size() << endl;
		cout << "\n������������Ҫ��ջ��Ԫ�ظ�����" ;
		cin >> n;
		cout << endl;	
	}
	if (n == 0) {
		cout << "û��Ԫ�ص�ջ��" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Ԫ��"<<sq.pop()<<"��ջ�ɹ���" << endl;
	}
}

//������
int scan() {
	cout << "  =================================================================\n";
	cout << " ��                                                                ��\n";
	cout << " ��                       ˳��ջ�Ļ�������                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ����ʼ������(1)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        �����ջ����(2)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ����ջ������(3)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ��ȡջ������(4)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                         ���пա� ��(5)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                         ����ջ�� ��(6)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                         ����ջ�� ��(7)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                         ���˳��� ��(0)                         ��\n";
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
		"                                ���ڳ�ʼ��˳��ջ...........";
	Sleep(1000);
	system("cls");
	seqstack<int> sq;
	for (; ;)
	{
		switch (scan()) {
		case 1:
			system("cls");
			startStack(sq);
			getchar();
			getchar();
			break;
		case 2:
			system("cls");
			clearStack(sq);
			getchar();
			getchar();
			break;
		case 3:
			system("cls");
			getStackLength(sq);
			getchar();
			getchar();
			break;
		case 4:
			system("cls");
			getStacktop(sq);
			getchar();
			getchar();
			break;
		case 5:
			system("cls");
			judgeIsEmpty(sq);
			getchar();
			getchar();
			break;
		case 6:
			system("cls");
			inStack(sq);
			getchar();
			getchar();
			break;
		case 7:
			system("cls");
			popStack(sq);
			getchar();
			getchar();
			break;
		case 0:
			system("cls");
			cout << "�������˳�!" << endl;
			exit(0);
			getchar();
			getchar();
			break;
	}
		//system("cls");
	}
    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
