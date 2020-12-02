
//============================================================================
// @FileName     ：1_4_ Josephlink
// @Author       ：04191315_HeXiang
// @Version      ：1.0
// @Date         ：2020.9.23
// Description   ：
/*
 任给正整数n和k，按下述方法可以得到1,2, …,n的一个置换：
 将数字1,2,…,n环形排列，按顺时针方向自1开始报数，报到K时输出该位置上的数字，并使其出列。
 然后从他在顺时针方向的下一个数字继续报数，如此下去，直到所有的数字全部出列为止。
 例如N=10，K=3，则正确的出列顺序应为3，6，9，2，7，1，8，5，10，4。
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int getNum() {
	int n;
	cout << "请输入队列的元素个数n的值：";
	cin >> n;
	cout << endl;
	return n;
}

int getStep() {
	int k;
	cout << "请输入踢出数据的步长k的值：";
	cin >> k;
	cout << endl;
	return k;
}
int *Array(int n){
	//构建一个数组，并赋值得到一个约瑟夫环数
	int *A=new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = i + 1;
	}
	return A;
}

void procession(int n, int k, int *A) {
	cout << "约瑟夫环 ： \n" << endl;
	//设置判断行走的步长
	int step = k;
	//设置打印个数，当全部数字打印完后结束输出
	int printCount = 0;
	//循环进行约瑟夫环数出列
	for (int i = k - 1; printCount < n; i++) {
		//如果数组元素==0，证明此元素已被踢除出列，此时这一步相当于没有行走
		if (A[i % n] == 0) {
			continue;
		}
		//若元素没有出列，则判断步长是否走到了规定步长，走到了则使其出列（打印），随后将其剔除（赋值为0）
		if (step % k == 0) {
			cout << A[i % n] << " ";
			A[i % n] = 0;
			//出列一个，打印一个，等到所有元素出列完后，结束循环
			printCount++;
			//行走步数+1
			step++;
		}
		else
			//没有走到规定步长，则不踢出元素，则步数+1，继续前进
			step++;
	}
	  delete[] A;
}

int main()
{
	int arrayLen = getNum();
	
	//调用函数procession，实现出列操作
	procession(arrayLen, getStep(), Array(arrayLen));

    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
