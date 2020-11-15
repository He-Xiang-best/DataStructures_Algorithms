//============================================================================
// @FileName     ��LinkQueue.cpp
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.11.15
// Description   ��
/*
�ֱ�ʵ��ѭ�����к������еĳ����������Ͷ��壬��ɶ��еĻ���������
��ʼ�����С��������Ƿ�Ϊ�ա���ն��С���ӡ����ӡ�ȡ����Ԫ�ء�
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include <windows.h>  
#include <string.h>
#include "linkQueue.h"
using namespace std;

template<class T>
void startQueue(linkQueue<T>& lq) {

	cout << "�������������Ԫ�ص�ֵ��(����9999��ʾ����)" << endl;
	T value;
	cin >> value;
	for (int i = 0;value!=9999; i++)
	{
		lq.enQueue(value);
		cin >> value;
	}
	cout << "\n���г�ʼ���ɹ���" << endl;
}

template<class T>
void clearQueue(linkQueue<T>& lq) {
	lq.clear();
	cout << "������ճɹ���" << endl;
}

template<class T>
void getQueueLength(linkQueue<T>& lq) {

	cout << "��ǰ�Ķ��еĳ���Ϊ��" << lq.size() << endl;
}

template<class T>
void judgeIsEmpty(linkQueue<T>& lq) {
	if (lq.empty()) {
		cout << "��ǰ���е�����Ϊ�գ�" << endl;
		return;
	}

	cout << "��ǰ���е�������Ϊ�գ���ʱ����Ϊ��" << lq.size() << endl;
}

template<class T>
void getQueuetop(linkQueue<T>& lq) {
	if (lq.empty()) {
		cout << "��ǰ����Ϊ�գ��޶���Ԫ�أ�" << endl;
	}
	else
		cout << "��ǰ�Ķ���Ԫ��Ϊ��" << lq.getHead() << endl;
}

template<class T>
void getQueuerear(linkQueue<T>& lq) {
	if (lq.empty()) {
		cout << "��ǰ����Ϊ�գ��޶�βԪ�أ�" << endl;
	}
	else
		cout << "��ǰ�Ķ�βԪ��Ϊ��" << lq.getRear() << endl;
}


template<class T>
void insertQueue(linkQueue<T>& lq) {

	cout << "�������������Ԫ�ص�ֵ��������9999��ʾ������" << endl;
	T value;
	cin >> value;
	for (int i = 0; value != 9999; i++)
	{
		lq.enQueue(value);
		cin >> value;
	}
	cout << "\nԪ����ӳɹ���" << endl;
}

template<class T>
void outQueue(linkQueue<T>& lq) {
	int n;
	cout << "������Ҫ���Ӽ���Ԫ�أ�";
	cin >> n;
	cout << endl;
	while (n > lq.size() || n < 0) {
		cout << "����Ԫ�ظ������󣬵�ǰ���е�Ԫ������Ϊ��" << lq.size() << endl;
		cout << "\n������������Ҫ���ӵ�Ԫ�ظ�����";
		cin >> n;
		cout << endl;
	}
	if (n == 0) {
		cout << "û��Ԫ�ؿɳ��ӣ�" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Ԫ��" << lq.deQueue() << "���ӳɹ���" << endl;
	}
}

//������
int scan() {
	cout << "  =================================================================\n";
	cout << " ��                                                                ��\n";
	cout << " ��                       �����еĻ�������                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ����ʼ������(1)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                       ����ն��С���(2)                        ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ����ӳ�����(3)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ��ȡ���ס���(4)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ��ȡ��β����(5)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                         ���пա� ��(6)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                         ����ӡ� ��(7)                         ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                         �����ӡ� ��(8)                         ��\n";
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
		"                                ���ڳ�ʼ��������...........";
	Sleep(1000);
	system("cls");
	linkQueue<int> lq;
	for (; ;)
	{
		switch (scan()) {
		case 1:
			system("cls");
			startQueue(lq);
			getchar();
			getchar();
			break;
		case 2:
			system("cls");
			clearQueue(lq);
			getchar();
			getchar();
			break;
		case 3:
			system("cls");
			getQueueLength(lq);
			getchar();
			getchar();
			break;
		case 4:
			system("cls");
			getQueuetop(lq);
			getchar();
			getchar();
			break;
		case 5:
			system("cls");
			getQueuerear(lq);
			getchar();
			getchar();
			break;
		case 6:
			system("cls");
			judgeIsEmpty(lq);
			getchar();
			getchar();
			break;
		case 7:
			system("cls");
			insertQueue(lq);
			getchar();
			getchar();
			break;
		case 8:
			system("cls");
			outQueue(lq);
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

