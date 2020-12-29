
//============================================================================
// @FileName     ��linkStack.cpp
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.11.4
// Description   ��
/*
�ֱ�ʵ��˳��ջ����ջ�ĳ����������Ͷ��壬���ջ�Ļ���������
��ʼ��ջ�����ջ�Ƿ�Ϊ�ա����ջ����ջ����ջ��ȡջ��Ԫ�ء�
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include<Windows.h>
#include"linkStack.h"
using namespace std;

template<class T>
void startStack(linkStack<T>& ls) {

	cout << "�����������ջԪ�ص�ֵ��(����9999�������)" << endl;
	T value;
	cin >> value;
	for (int i = 0; value!=9999; i++)
	{
		ls.push(value);
		cin >> value;
	}
	cout << "\nջ��ʼ���ɹ���" << endl;
}

template<class T>
void clearStack(linkStack<T>& ls) {
	ls.clear();
	cout << "ջ��ճɹ���" << endl;
}

template<class T>
void getStackLength(linkStack<T>& ls) {

	cout << "��ǰ��ջ�ĳ���Ϊ��" << ls.size() << endl;
}

template<class T>
void judgeIsEmpty(linkStack<T>& ls) {
	if (ls.empty()) {
		cout << "��ǰջ������Ϊ�գ�" << endl;
		return;
	}
	cout << "��ǰջ��������Ϊ�գ���ʱ����Ϊ��" << ls.size() << endl;
}

template<class T>
void getStacktop(linkStack<T>& ls) {
	if (ls.empty()) {
		cout << "��ǰջΪ�գ���ջ��Ԫ�أ�" << endl;
	}
	else
		cout << "��ǰ��ջ��Ԫ��Ϊ��" << ls.getTop() << endl;
}

template<class T>
void inStack(linkStack<T>& ls) {

	cout << "�����������ջԪ�ص�ֵ��(����9999�������)" << endl;
	T value;
	cin >> value;
	for (int i = 0; value != 9999; i++)
	{
		ls.push(value);
		cin >> value;
	}
	cout << "\nԪ�ؽ�ջ�ɹ���" << endl;
}

template<class T>
void popStack(linkStack<T>& ls) {
	int n;
	cout << "�����㵯ջ����Ԫ�أ�";
	cin >> n;
	cout << endl;
	while (n > ls.size() || n < 0) {
		cout << "��ջԪ�ظ������󣬵�ǰջ��Ԫ������Ϊ��" << ls.size() << endl;
		cout << "\n������������Ҫ��ջ��Ԫ�ظ�����";
		cin >> n;
		cout << endl;
	}
	if (n == 0) {
		cout << "û��Ԫ�ص�ջ��" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Ԫ��" << ls.pop() << "��ջ�ɹ���" << endl;
	}
}

//������
int scan() {
	cout << "  =================================================================\n";
	cout << " ��                                                                ��\n";
	cout << " ��                       ��ջ�Ļ�������                           ��\n";
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
		"                                ���ڳ�ʼ����ջ...........";
	Sleep(1000);
	system("cls");
	linkStack<int> ls;
	for (; ;)
	{
		switch (scan()) {
		case 1:
			system("cls");
			startStack(ls);
			getchar();
			getchar();
			break;
		case 2:
			system("cls");
			clearStack(ls);
			getchar();
			getchar();
			break;
		case 3:
			system("cls");
			getStackLength(ls);
			getchar();
			getchar();
			break;
		case 4:
			system("cls");
			getStacktop(ls);
			getchar();
			getchar();
			break;
		case 5:
			system("cls");
			judgeIsEmpty(ls);
			getchar();
			getchar();
			break;
		case 6:
			system("cls");
			inStack(ls);
			getchar();
			getchar();
			break;
		case 7:
			system("cls");
			popStack(ls);
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
