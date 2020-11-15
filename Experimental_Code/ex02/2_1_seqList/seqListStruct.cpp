
//============================================================================
// @FileName     ：
// @Author       ：04191315_HeXiang
// @Version      ：1.0
// @Date         ：2020.10.21
// Description   ：
/*
实现顺序表完成线性表的基本操作：
初始化线性表、清空线性表、求线性表长度、检查线性表是否为空、遍历线性表、
从线性表中查找元素、从线性表中查找与给定元素值相同的元素在线性表中的位置、插入元素、删除元素。
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include"seqList.h"
#include<iostream>  
//#include<stdlib.h>
//#include<time.h>
#include<windows.h>
#define random(x) rand()%(x)
using namespace std;

//遍历顺序表的数据
template <class T>
void seqListTraverse(seqList<T>& sq) {
    if (sq.isEmpty())
    {
        cout << "当前的顺序表为空表！可前往创建！" << endl;
    }
    else {
        cout << "当前顺序表的元素数据如下:\n" << endl;
        sq.traverse();
    }

}

//按值查询数据
template <class T>
void FindNumInValue(seqList<T>& sq) {
	if (sq.size() == 0) {
		cout << "当前为空表！没有数据可供查询！" << endl;
	}
	else {
		cout << "请给定查询数值，返回其所在位置的序号：";
		T value; cin >> value; cout << endl;
		int location = sq.search(value);
		if (location == 0) {
			cout << "顺序表中不存在此数据！" << endl;
		}
		else
			cout << "此数据所在的位置为：" << location << endl;
	}
}

//按序号查询数据
template <class T>
void FindNumInOrder(seqList<T>& sq) {
	if (sq.size() == 0) {
		cout << "当前为空表！没有数据可供查询！" << endl;
	}
	else {
		cout << "请输入您要查询数据的序号： ";
		int i; cin >> i; cout << endl;
		while (i<1 || i>sq.size()) {
			cout << "(当前合法的查询位置为：【1......" << sq.size() << "】)\n" << endl;
			cout << "查询的数据范围有误!请重新输入： ";
			cin >> i;
			cout << endl;
		}
		cout << "第" << i << "个数据对应的数值为 —— " << sq.visit(i) << endl;
	}
}


//按序号删除
template <class T>
void seqListRemoveInOrder(seqList<T>& sq) {
	if (sq.size() == 0) {
		cout << "当前为空表！没有数据可供删除！" << endl;
	}
	else {
		cout << "请输入您要删除数据的序号： ";
		int i; cin >> i; cout << endl;
		while (i<1 || i>sq.size()) {
			cout << "(当前合法的删除位置为：【1......" << sq.size() << "】)\n" << endl;
			cout << "删除的数据范围有误!请重新输入： ";
			cin >> i;
			cout << endl;
		}
		sq.remove(i);
		cout << "\n数据删除成功！" << endl;
	}
}

//按区间删除
template <class T>
void seqListRemoveRange(seqList<T>& sq) {
	if (sq.size() == 0) {
		cout << "当前为空表！没有数据可供删除！" << endl;
	}
	else {
		cout << "请输入您要删除数据的区间：【括号两边都取得到】 ";
		int i,j; cin >> i>>j; cout << endl;
		while (i<1 || i>sq.size()||j<1 || j>sq.size()||j<=i) {
			cout << "(当前合法的删除区间为：【1......" << sq.size() << "】的子集)\n" << endl;
			cout << "您此时删除的数据区间有误!请重新输入： ";
			cin >> i>>j;
			cout << endl;
		}
		for (int k=i;k<=j;k++) {
			sq.remove(i);
		}
		
		cout << "\n数据删除成功！" << endl;
	}
}

//按值删除数据
template <class T>
void seqListRemoveInValue(seqList<T>& sq) {
	if (sq.size() == 0) {
		cout << "当前为空表！没有数据可供删除！" << endl;
	}
	else {
		cout << "请输入您要删除数据的值： ";
		T value; cin >> value; cout << endl;
		int i = sq.search(value);
		if (i == 0) {
			cout << "当前数值不存在！删除失败！" << endl;
		}
		else {
			sq.remove(i);
			cout << "数据删除成功！" << endl;
		}
	}
}

//往顺序表中插入数值
template <class T>
void seqListInsert(seqList<T>& sq) {
	if (sq.size() == 0) {
		cout << "当前为空表！没有数据可供插入！" << endl;
	}
	else {
		cout << "请依次输入您要插入数据的位置以及数值：\n" << endl;
		int location;
		T value;
		cin >> location >> value;
		if (sq.isFull()) sq.resize();//如果插入时容量已满，则扩容
		while (location > sq.size() + 1 || location < 1)
		{
			cout << "(当前合法的插入位置为：【1......" << sq.size() + 1 << "】)\n" << endl;
			cout << "您此时插入的数据位置有误！请重新输入：";
			cin >> location;
			cout << endl;
		}
		sq.insert(location, value);
		cout << "\n数据插入成功！" << endl;
	}
}


//初始化创建数据
template <class T>
void seqListCreat(seqList<T> &sq) {
    cout << "请问你要创建几个数据： ";
    int n;
    cin >> n;
    //如果插入的数据量大于起始初始化给的容量，则扩容
    while(sq.isOutOfRange(n) < 0)
        sq.resize();
    //srand((int)time(0));
	cout << "\n请输入数据：\n" << endl;
	T value;
    for (int i = 0; i < n; i++) {
		cin >> value;
            sq.push_Back(value);
        }
        cout << "\n数据创建成功！" << endl;
}

template <class T>
void seqListUnionAndSort(seqList<T>& sq) {
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl <<
		"                                   正在初始化合并表B...........";
	Sleep(1000);//页面休眠1秒
	system("cls");//实现清屏操作
	seqList<int> B;
	cout << "合并表B————";
	seqListCreat(B);
	cout << "\n正在合并顺序表，并将新表进行排序..........." << endl;
	Sleep(1000);//页面休眠1秒
	sq.getUnionAndSort(B);
	cout << "\n合并顺序表并排序成功！" << endl;
}


//主界面
int scan() {
    cout << "  =================================================================\n";
    cout << " ┋                                                                ┋\n";
    cout << " ┋                        顺序表的基本操作                        ┋\n";
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
    cout << " ┋               ┋                                                ┋\n";
    cout << " ┋【查询操作】—>┋—> 【查看顺序表的容量】  …(6)                 ┋\n";
    cout << " ┋               ┋                                                ┋\n";
    cout << " ┋               ┋—> 【查看元素的存储量】  …(7)                 ┋\n";
    cout << " ┋               ┋                                                ┋\n";
    cout << " ┋               ┋—> 【查看顺序表是否为空】…(8)                 ┋\n";
    cout << " ┋                                                                ┋\n";
    cout << " ┋                      【按序号删除数据】   …(9)                ┋\n";
    cout << " ┋                                                                ┋\n";
    cout << " ┋                      【按数值删除数据】   …(10)               ┋\n";
    cout << " ┋                                                                ┋\n";
	cout << " ┋                      【按区间删除数据】   …(11)               ┋\n";
	cout << " ┋                                                                ┋\n";
    cout << " ┋                        【逆置数据】…(12)                      ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【合并数据】…(13)                      ┋\n";
	cout << " ┋                                                                ┋\n";
	cout << " ┋                        【清除数据】…(14)                      ┋\n";
    cout << " ┋                                                                ┋\n";
    cout << " ┋                                                                ┋\n";
    cout << " ┋                        【退出操作】…(0)                       ┋\n";
    cout << " ┋                                                                ┋\n";
    cout << "  =================================================================\n";
    int choice;
    cout << "\n                     亲，请输入您要操作的编号：";
    cin >> choice;
    return choice;
}


int main()
{
	seqList<int> sq;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl <<
        "                                   正在初始化顺序表...........";
    Sleep(1000);//页面休眠1秒
    system("cls");//实现清屏操作

    for (;;) {
		switch (scan()) {
		case 1:
			system("cls");
			seqListCreat(sq);
			getchar();
			getchar();
			break;
		case 2:
			system("cls");
			seqListTraverse(sq);
			getchar();
			getchar();
			break;
		case 3:
			system("cls");
			seqListInsert(sq);
			getchar();
			getchar();
			break;
		case 4:
			system("cls");
			FindNumInValue(sq);
			getchar();
			getchar();
			break;
		case 5:
			system("cls");
			FindNumInOrder(sq);
			getchar();
			getchar();
			break;
		case 6:
			system("cls");
			cout << "当前顺序表的容量为： " << sq.getMaxSize() << endl;
			getchar();
			getchar();
			break;
		case 7:
			system("cls");
			cout << "当前元素的存储量为： " << sq.size() << endl;
			getchar();
			getchar();
			break;
		case 8:
			system("cls");
			if (sq.isEmpty()) cout << "当前顺序表为空表！" << endl;
			else cout << "此时顺序表不为空！有 "<<sq.size()<<" 个元素数据" << endl;
			getchar();
			getchar();
			break;
		case 9:
			system("cls");
			seqListRemoveInOrder(sq);
			getchar();
			getchar();
			break;
		case 10:
			system("cls");
			seqListRemoveInValue(sq);
			getchar();
			getchar();
			break;
		case 11:
			system("cls");
			seqListRemoveRange(sq);
			getchar();
			getchar();
			break;
		case 12:
			system("cls");
			if (sq.isEmpty()) cout << "当前顺序表为空表！没有数据可供逆置！" << endl;
			else {
				sq.inverse();
				cout << "数据逆置成功！" << endl;
			}
			getchar();
			getchar();
			break;
		case 13:
			system("cls");
			seqListUnionAndSort(sq);
			getchar();
			getchar();
			break;
		case 14:
			system("cls");
			sq.clear();
			cout << "所有数据已清空！" << endl;
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
