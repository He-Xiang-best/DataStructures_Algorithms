
//============================================================================
// @FileName     ：seqQueue.cpp
// @Author       ：04191315_HeXiang
// @Version      ：1.0
// @Date         ：2020.11.15
// Description   ：
/*
分别实现循环队列和链队列的抽象数据类型定义，完成队列的基本操作：
初始化队列、检查队列是否为空、清空队列、入队、出队、取队首元素。
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
	cout << "请问你要往队列中存入几个元素？";
	cin >> n;
	cout << endl;
	while (n > sq.maxLen())
	{
		sq.resize();
	}
	cout << "请依次输入元素的值：" << endl;
	T value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		sq.enQueue(value);
	}
	cout << "\n队列初始化成功！" << endl;
}

template<class T>
void clearQueue(seqQueue<T>& sq) {
	sq.clear();
	cout << "队列清空成功！" << endl;
}

template<class T>
void getQueueLength(seqQueue<T>& sq) {

	cout << "当前的队列的长度为：" << sq.size() << endl;
}

template<class T>
void judgeIsEmpty(seqQueue<T>& sq) {
	if (sq.empty()) {
		cout << "当前队列的容量为空！" << endl;
		return;
	}
	if (sq.full()) {
		cout << "当前队列的容量已满，此时容量为：" << sq.maxLen() << endl;
		return;
	}
	cout << "当前队列的容量不为空，此时容量为：" << sq.maxLen() << endl;
}

template<class T>
void getQueuetop(seqQueue<T>& sq) {
	if (sq.empty()) {
		cout << "当前队列为空，无队首元素！" << endl;
	}
	else
		cout << "当前的队首元素为：" << sq.getHead() << endl;
}

template<class T>
void getQueuerear(seqQueue<T>& sq) {
	if (sq.empty()) {
		cout << "当前队列为空，无队尾元素！" << endl;
	}
	else
		cout << "当前的队尾元素为：" << sq.getRear() << endl;
}


template<class T>
void insertQueue(seqQueue<T>& sq) {
	int n;
	cout << "请问你入队几个元素？";
	cin >> n;
	cout << endl;
	while (n > sq.maxLen())
	{
		sq.resize();
	}
	cout << "请依次输入入队元素的值：" << endl;
	T value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		sq.enQueue(value);
	}
	cout << "\n元素入队成功！" << endl;
}

template<class T>
void outQueue(seqQueue<T>& sq) {
	int n;
	cout << "请问你要出队几个元素？";
	cin >> n;
	cout << endl;
	while (n > sq.size() || n < 0) {
		cout << "出队元素个数有误，当前队列的元数个数为：" << sq.size() << endl;
		cout << "\n请重新输入需要出队的元素个数：";
		cin >> n;
		cout << endl;
	}
	if (n == 0) {
		cout << "没有元素可出队！" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "元素" << sq.deQueue() << "出队成功！" << endl;
	}
}

//主界面
int scan() {
	cout << "  =================================================================\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                       顺序队列的基本操作                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【初始化】…(1)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                       【清空队列】…(2)                        ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【求队长】…(3)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【取队首】…(4)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【取队尾】…(5)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                         【判空】 …(6)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                         【入队】 …(7)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                         【出队】 …(8)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                         【退出】 …(0)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << "  =================================================================\n";
	int choice;
	cout << "\n                     亲，请输入您要操作的编号：";
	cin >> choice;
	return choice;
}


int main()
{
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl <<
		"                                正在初始化顺序队列...........";
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
			cout << "程序已退出!" << endl;
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

