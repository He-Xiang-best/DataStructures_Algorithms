
//============================================================================
// @FileName     ��seqQueue.cpp
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
#include "seqQueue.h"
using namespace std;

template<class T>
void startQueue(seqQueue<T>& sq) {
	int n;
	cout << "������Ҫ�������д��뼸��Ԫ�أ�";
	cin >> n;
	cout << endl;
	while (n > sq.maxLen())
	{
		sq.resize();
	}
	cout << "����������Ԫ�ص�ֵ��" << endl;
	T value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		sq.enQueue(value);
	}
	cout << "\n���г�ʼ���ɹ���" << endl;
}

template<class T>
void clearQueue(seqQueue<T>& sq) {
	sq.clear();
	cout << "������ճɹ���" << endl;
}

template<class T>
void getQueueLength(seqQueue<T>& sq) {

	cout << "��ǰ�Ķ��еĳ���Ϊ��" << sq.size() << endl;
}

template<class T>
void judgeIsEmpty(seqQueue<T>& sq) {
	if (sq.empty()) {
		cout << "��ǰ���е�����Ϊ�գ�" << endl;
		return;
	}
	if (sq.full()) {
		cout << "��ǰ���е�������������ʱ����Ϊ��" << sq.maxLen() << endl;
		return;
	}
	cout << "��ǰ���е�������Ϊ�գ���ʱ����Ϊ��" << sq.maxLen() << endl;
}

template<class T>
void getQueuetop(seqQueue<T>& sq) {
	if (sq.empty()) {
		cout << "��ǰ����Ϊ�գ��޶���Ԫ�أ�" << endl;
	}
	else
		cout << "��ǰ�Ķ���Ԫ��Ϊ��" << sq.getHead() << endl;
}

template<class T>
void getQueuerear(seqQueue<T>& sq) {
	if (sq.empty()) {
		cout << "��ǰ����Ϊ�գ��޶�βԪ�أ�" << endl;
	}
	else
		cout << "��ǰ�Ķ�βԪ��Ϊ��" << sq.getRear() << endl;
}


template<class T>
void insertQueue(seqQueue<T>& sq) {
	int n;
	cout << "��������Ӽ���Ԫ�أ�";
	cin >> n;
	cout << endl;
	while (n > sq.maxLen())
	{
		sq.resize();
	}
	cout << "�������������Ԫ�ص�ֵ��" << endl;
	T value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		sq.enQueue(value);
	}
	cout << "\nԪ����ӳɹ���" << endl;
}

template<class T>
void outQueue(seqQueue<T>& sq) {
	int n;
	cout << "������Ҫ���Ӽ���Ԫ�أ�";
	cin >> n;
	cout << endl;
	while (n > sq.size() || n < 0) {
		cout << "����Ԫ�ظ������󣬵�ǰ���е�Ԫ������Ϊ��" << sq.size() << endl;
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
		cout << "Ԫ��" << sq.deQueue() << "���ӳɹ���" << endl;
	}
}

//������
int scan() {
	cout << "  =================================================================\n";
	cout << " ��                                                                ��\n";
	cout << " ��                       ˳����еĻ�������                       ��\n";
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
		"                                ���ڳ�ʼ��˳�����...........";
	Sleep(1000);
	system("cls");
	seqQueue<int> sq;
	for (; ;)
	{
		switch (scan()) {
		case 1:
			system("cls");
			startQueue(sq);
			getchar();
			getchar();
			break;
		case 2:
			system("cls");
			clearQueue(sq);
			getchar();
			getchar();
			break;
		case 3:
			system("cls");
			getQueueLength(sq);
			getchar();
			getchar();
			break;
		case 4:
			system("cls");
			getQueuetop(sq);
			getchar();
			getchar();
			break;
		case 5:
			system("cls");
			getQueuerear(sq);
			getchar();
			getchar();
			break;
		case 6:
			system("cls");
			judgeIsEmpty(sq);
			getchar();
			getchar();
			break;
		case 7:
			system("cls");
			insertQueue(sq);
			getchar();
			getchar();
			break;
		case 8:
			system("cls");
			outQueue(sq);
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

