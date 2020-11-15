
//============================================================================
// @FileName     ：linkListStruct
// @Author       ：04191315_HeXiang
// @Version      ：1.0
// @Date         ：2020.10.21
// Description   ：
/*
实现单链表完成线性表的基本操作：
初始化线性表、清空线性表、求线性表长度、检查线性表是否为空、遍历线性表、从线性表中查找元素、
从线性表中查找与给定元素值相同的元素在线性表中的位置、插入元素、删除元素。
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include <iostream>
#include <windows.h>  
#include <string.h>
#include "linkList.h"
using namespace std;

//主界面
int scan() {
	cout << "  =================================================================\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        单链表的基本操作                        ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【创建数据】…(1)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【遍历数据】…(2)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【插入数据】…(3)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋               ┋—> 【按值查询元素位置】  …(4)                 ┋\n";
	cout << " ┋               ┋                                                ┋\n";
	cout << " ┋               ┋—> 【按位查询元素数值】  …(5)                 ┋\n";
	cout << " ┋【查询操作】—>┋                                                ┋\n";
	cout << " ┋               ┋—> 【查看单链表的长度】  …(6)                 ┋\n";
	cout << " ┋               ┋                                                ┋\n";
	cout << " ┋               ┋—> 【查看单链表是否为空】…(7)                 ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                    【删除给定序号的节点】…(8)                 ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                    【删除给定数据的节点】…(9)                 ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【清除数据】…(10)                      ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【逆置数据】…(11)                      ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【退出操作】…(0)                       ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << "  =================================================================\n";
	int choice;
	cout << "\n                     亲，请输入您要操作的编号：";
	cin >> choice;
	return choice;
}

//向单链表中创建数据
template<class T>
void linkListCreatData(linkList<T> &ls) {
	//int num;
	//cout << "请问你要创建几个数据？"<<endl;
	//cin >> num;
	cout << "\n请输入您要创建的数据：(输入9999表示停止)" << endl;
	T value;
	cin >> value;
	for (/*int i = 0*/; value != 9999;/*i++*/ ) {
		ls.tailCreate(value);
		cin >> value;
	}
	cout << "\n单链表的数据创建完毕！可前往查看！" << endl;
}

//遍历单链表
template<class T>
void linkListTraverse(linkList<T>& ls) {
	if (ls.isEmpty()) {
		cout << "当前的链表为空，没有数据！无需遍历！" << endl;
	}
	else
		ls.traverse();
}

//向单链表第i个位置前插入一个节点
template<class T>
void linkListInsert(linkList<T>& ls) {
	if (ls.isEmpty()) {
		cout << "当前为空表，无法进行数据的插入！";	
	}
	else {
		cout << "请输入您要插入的位置：";
		int location;
		cin >> location;
		cout << endl;
		int len = ls.size() + 1;
		while (location<1 || location>len) {
			cout << "插入的位置有误！请重新输入！（当前合法的插入位置为【1..." << len << "】" << endl;
			cin >> location;
		}
		T value;
		cout << "请输入你要插入的数据的值：";
		cin >> value;
		cout << endl;
		ls.headinsert(location, value);
		cout << "插入成功！可前往查看！" << endl;
		
	}
}

//给定索引查询对应的数值
template<class T>
void linkListFindindex(linkList<T>& ls) {
	if (ls.isEmpty()) {
		cout << "当前的链表为空，没有数据可供查询！" << endl;
		return;
	}
	cout << "请输入您要查找的数据: ";
	T value;
	cin >> value;
	cout << endl;
	int location = ls.searchinValue(value);
	if (location == -1) {
		cout << "\n当前元素不在单链表中！可返回重新输入查找！" << endl;
	}
	else {
		cout << "\n当前元素在单链表中的第 " << location << " 个位置" << endl;
	}
}

template<class T>
void linkListFindValue(linkList<T>& ls) {
	if (ls.isEmpty()) {
		cout << "当前的链表为空，没有数据可供查询！" << endl;
	}
	else {
		int len = ls.size();
		int i;
		cout << "请输入您要查找的序号:";
		cin >> i;
		cout << endl;
		while (i<1 || i>len) {
			cout << "查找失败！查询的序号有误！请返回重新输入！（当前合法的查询序号为【1..." << len << "】" << endl;
			cin >> i;
			cout << endl;
		}
			ls.searchinNum(i);

	}
}

template<class T>
void remove(linkList<T> &ls) {
	if (ls.isEmpty()) {
		cout << "当前的链表为空，没有数据！无法删除！" << endl;
	}
	else {
		int location;
		cout << "请输入您要删除的节点序号：";
		cin >> location;
		cout << endl;
		int len = ls.size();
		while (location<1 || location>len) {
			cout << "删除失败！删除的序号有误！请重新输入！（当前合法的删除序号为【1..." << len << "】" << endl;
			cin >> location;
			cout << endl;
		}
			ls.removeinNum(location);
			cout << "删除成功！" << endl;
	}
}

template<class T>
void remove2(linkList<T>&ls) {
	if (ls.isEmpty()) {
		cout << "当前的链表为空，没有数据！无法删除！" << endl;
		return;
	}
	T value;
	cout << "请输入你要删除的值：";
	cin >> value;
	int location = ls.searchinValue(value);
	if(location == -1) {
		cout << "\n删除失败！当前元素不在单链表中！可返回重新输入查找！" << endl;
	}
	else {
		ls.removeinNum(location);
		cout << "\n删除成功！" << endl;
	}
}

int main()
{
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl <<
		"                                正在初始化单链表...........";
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
			cout << "单链表的长度为：" << ls.size() << endl;
			getchar();
			getchar();
			break;
		case 7:
			system("cls");
			if (ls.isEmpty()) {
				cout << "当前的单链表为空表！可前往创建数据！" << endl;
			}
			else
				cout << "当前的单链表不为空，长度为：" << ls.size() << endl;
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
				cout << "当前的链表为空，没有数据！无需清除！" << endl;
			}
			else {
				ls.clear();
				cout << "数据全部清除成功！" << endl;
			}
			getchar();
			getchar();
			break;
		case 11:
			system("cls");
			if (ls.isEmpty()) {
				cout << "当前的链表为空，没有数据！不可逆置！" << endl;
			}
			else {
				ls.inverse();
				cout << "数据逆置成功！" << endl;
			}
			getchar();
			getchar();
			break;
		case 0:
			system("cls");
			cout << "程序已退出!" << endl;
			exit(0);
			break;
		}
		system("cls");
	}
    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
