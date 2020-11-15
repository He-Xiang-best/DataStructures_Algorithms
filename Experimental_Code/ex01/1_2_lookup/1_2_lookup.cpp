
//============================================================================
// @FileName     ：1_2_lookup
// @Author       ：04191315_HeXiang
// @Version      ：1.0
// @Date         ：2020.9.23
// Description   ：
/*
 在数组A[n]中查找值为k的元素，若找到则输出其位置i(1≤i≤n)，
 否则输出0作为标志。设计算法求解此问题，并分析其时间复杂度。
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <stdlib.h>
#include <time.h>
#define random(x) rand()%(x)
using namespace std;

int creatDataNum() {
	cout << "请输入创建数组数据的个数：";
	int size;
	cin >> size;
	cout << endl;
	return size;
}
int* creatArray(int size) {
	int *A = new int[size];
	srand((int)time(0));// 产生随机种子数
	cout << "数据为:  ";
	for (int i = 0; i < size; i++) {
		A[i] = random(100);//数据范围在（0~99】
		cout << A[i] << "  ";
	}
	return A;
}

int findNum(){
	cout << "\n\n请输入要查找的数k：";
	int k;
	cin >> k;
	cout << endl;
	return k;
}

void findLocation(int number, int k, int *A) {
	int step = 0;
	cout << "数据位置： ";
	for (int i = 0; i < number; ++i) {
		if (k == A[i]) {
			cout << (i + 1) << "  ";
			step++;
		}
	}
	if (step == 0) {
		//也可以设计为输出0
		cout << "No Find The Number Location!";
	}
	cout << "\n\n时间复杂度：O (n)" << endl;
	delete[] A;
}

int main()
{
	int getSize = creatDataNum();
	findLocation(getSize, findNum(), creatArray(getSize));

    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
