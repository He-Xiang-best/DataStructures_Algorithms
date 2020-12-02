
//============================================================================
// @FileName     ：1_1_sort3
// @Author       ：04191315_HeXiang
// @Version      ：1.0
// @Date         ：2020.9.23
// Description   ：
/*
 已知输入x，y，z三个不相等的整数，设计一个“高效”算法，使得这三个数按从小到大输出。
 “高效”的含义是用最少的元素比较次数、元素移动次数和输出次数。
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;
//设置两个全局变量，分别用于存放调用getMin函数比较第一次和第二次后的较大值
static int maxValue1, maxValue2;
//用于判断比较最小值函数的调用次数，控制较大值的存放位置，比较两次为一次轮
static bool isCompare = false;

//用于返回两数比较中的较小数，并把较大值存放到全局变量中
int getMin(int x, int y) {
	if (x > y) {
		if (isCompare) {
			maxValue2 = x;
			isCompare = false;
		}
		else {
			maxValue1 = x;
			isCompare = true;
		}
		return y;
	}
	else {
		if (isCompare) {
			maxValue2 = y;
			isCompare = false;
		}
		else {
			maxValue1 = y;
			isCompare = true;
		}
		return x;
	}
}

//用于统计移动的次数，这里我理解为原有顺序变换到输出顺序后,前移所需的次数
int moveTimes(int num1, int num2, int num3, int min1) {
	switch ((num1 == min1) ? 1 : ((num2 == min1) ? 2 : 3)) {
	case 1:
		if (num2 < num3)
			return 0;
		else
			return 1;
		break;
	case 2:
		if (num1 < num3)
			return 1;
		else
			return 2;
		break;
	case 3:
		if (num1 < num2)
			return 2;
		else
			return 1;
		break;
	}
	return 0;
}

void compareResult(int num1, int num2, int num3) {
	//比较两次即可获得最小值
	int minValue = getMin(getMin(num1, num2), num3);
	//比较较大的两个数，返回的为中间大的数，最后比较完的全局变量maxValue1保存到了最大值
	int middleValue = getMin(maxValue1, maxValue2);
	cout << "排序结果为：" << minValue << "  " << middleValue << "  " << maxValue1
		<< endl;
	cout << "比较次数： 3" << endl;
	cout << "移动次数为： " << moveTimes(num1, num2, num3, minValue) << endl;
}

void sendData() {
	int num1, num2, num3;
	cout << "请输入三个不相等的整数：" << endl;
	cin >> num1 >> num2 >> num3;
	//判断输入数据的正确性
	while (num1 == num2 || num2 == num3 || num3 == num1)
	{
		cout << "数据的输入有误!请重新输入：" << endl;
		cin >> num1 >> num2 >> num3;
	}
	compareResult(num1, num2, num3);
}

int main()
{
	sendData();
    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
