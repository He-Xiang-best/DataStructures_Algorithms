
//============================================================================
// @FileName     ：seqStack.cpp
// @Author       ：04191315_HeXiang
// @Version      ：1.0
// @Date         ：2020.10.25
// Description   ：
/*
分别实现顺序栈和链栈的抽象数据类型定义，完成栈的基本操作：
初始化栈、检查栈是否为空、清空栈、入栈、退栈、取栈顶元素。
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
	cout << "请问你要往栈中存放几个元素？" ;
	cin >> n;
	cout << endl;
	while (n>sq.maxLength())
	{
		sq.resize();
	}
	cout << "请依次输入元素的值：" << endl;
	T value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		sq.push(value);
	}
	cout << "\n栈初始化成功！" << endl;
}

template<class T>
void clearStack(seqstack<T>& sq) {
	sq.clear();
	cout << "栈清空成功！" << endl;
}

template<class T>
void getStackLength(seqstack<T>& sq) {
	
	cout << "当前的栈的长度为：" << sq.size()<<endl;
}

template<class T>
void judgeIsEmpty(seqstack<T>& sq) {
	if (sq.isEmpty()) {
		cout << "当前栈的容量为空！" << endl;
		return;
	}
	if (sq.isFull()) {
		cout << "当前栈的容量已满，此时容量为：" << sq.maxLength() << endl;
		return;
	}
	cout << "当前栈的容量不为空，此时容量为：" << sq.maxLength() << endl;
}

template<class T>
void getStacktop(seqstack<T>& sq) {
	if (sq.isEmpty()) {
		cout << "当前栈为空，无栈顶元素！" << endl;
	}
	else
		cout << "当前的栈顶元素为：" << sq.getTop() << endl;
}

template<class T>
void inStack(seqstack<T>& sq) {
	int n;
	cout << "请问你进栈几个元素？";
	cin >> n;
	cout << endl;
	while (n > sq.maxLength())
	{
		sq.resize();
	}
	cout << "请依次输入进栈元素的值：" << endl;
	T value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		sq.push(value);
	}
	cout << "\n元素进栈成功！" << endl;
}

template<class T>
void popStack(seqstack<T>& sq) {
	int n;
	cout << "请问你弹栈几个元素？";
	cin >> n;
	cout << endl;
	while (n > sq.size()||n<0) {
		cout << "弹栈元素个数有误，当前栈的元数个数为：" << sq.size() << endl;
		cout << "\n请重新输入需要弹栈的元素个数：" ;
		cin >> n;
		cout << endl;	
	}
	if (n == 0) {
		cout << "没有元素弹栈！" << endl;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "元素"<<sq.pop()<<"弹栈成功！" << endl;
	}
}

//主界面
int scan() {
	cout << "  =================================================================\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                       顺序栈的基本操作                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【初始化】…(1)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【清空栈】…(2)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【求栈长】…(3)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【取栈顶】…(4)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                         【判空】 …(5)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                         【进栈】 …(6)                         ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                         【弹栈】 …(7)                         ┋\n";
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
		"                                正在初始化顺序栈...........";
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
