//============================================================================
// @FileName     ：LinkQueue.cpp
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
#include "linkQueue.h"
using namespace std;

template<class T>
void startQueue(linkQueue<T>& lq) {

	cout << "请依次输入入队元素的值：(输入9999表示结束)" << endl;
	T value;
	cin >> value;
	for (int i = 0;value!=9999; i++)
	{
		lq.enQueue(value);
		cin >> value;
	}
	cout << "\n队列初始化成功！" << endl;
}

template<class T>
void clearQueue(linkQueue<T>& lq) {
	lq.clear();
	cout << "队列清空成功！" << endl;
}

template<class T>
void getQueueLength(linkQueue<T>& lq) {

	cout << "当前的队列的长度为：" << lq.size() << endl;
}

template<class T>
void judgeIsEmpty(linkQueue<T>& lq) {
	if (lq.empty()) {
		cout << "当前队列的容量为空！" << endl;
		return;
	}

	cout << "当前队列的容量不为空，此时容量为：" << lq.size() << endl;
}

template<class T>
void getQueuetop(linkQueue<T>& lq) {
	if (lq.empty()) {
		cout << "当前队列为空，无队首元素！" << endl;
	}
	else
		cout << "当前的队首元素为：" << lq.getHead() << endl;
}

template<class T>
void getQueuerear(linkQueue<T>& lq) {
	if (lq.empty()) {
		cout << "当前队列为空，无队尾元素！" << endl;
	}
	else
		cout << "当前的队尾元素为：" << lq.getRear() << endl;
}


template<class T>
void insertQueue(linkQueue<T>& lq) {

	cout << "请依次输入入队元素的值：（输入9999表示结束）" << endl;
	T value;
	cin >> value;
	for (int i = 0; value != 9999; i++)
	{
		lq.enQueue(value);
		cin >> value;
	}
	cout << "\n元素入队成功！" << endl;
}

template<class T>
void outQueue(linkQueue<T>& lq) {
	int n;
	cout << "请问你要出队几个元素？";
	cin >> n;
	cout << endl;
	while (n > lq.size() || n < 0) {
		cout << "出队元素个数有误，当前队列的元数个数为：" << lq.size() << endl;
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
		cout << "元素" << lq.deQueue() << "出队成功！" << endl;
	}
}

//主界面
int scan() {
	cout << "  =================================================================\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                       链队列的基本操作                         ┋\n";
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
		"                                正在初始化链队列...........";
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

