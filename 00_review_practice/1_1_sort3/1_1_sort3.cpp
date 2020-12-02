
//============================================================================
// @FileName     ��1_1_sort3
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.9.23
// Description   ��
/*
 ��֪����x��y��z��������ȵ����������һ������Ч���㷨��ʹ��������������С���������
 ����Ч���ĺ����������ٵ�Ԫ�رȽϴ�����Ԫ���ƶ����������������
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;
//��������ȫ�ֱ������ֱ����ڴ�ŵ���getMin�����Ƚϵ�һ�κ͵ڶ��κ�Ľϴ�ֵ
static int maxValue1, maxValue2;
//�����жϱȽ���Сֵ�����ĵ��ô��������ƽϴ�ֵ�Ĵ��λ�ã��Ƚ�����Ϊһ����
static bool isCompare = false;

//���ڷ��������Ƚ��еĽ�С�������ѽϴ�ֵ��ŵ�ȫ�ֱ�����
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

//����ͳ���ƶ��Ĵ��������������Ϊԭ��˳��任�����˳���,ǰ������Ĵ���
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
	//�Ƚ����μ��ɻ����Сֵ
	int minValue = getMin(getMin(num1, num2), num3);
	//�ȽϽϴ�������������ص�Ϊ�м����������Ƚ����ȫ�ֱ���maxValue1���浽�����ֵ
	int middleValue = getMin(maxValue1, maxValue2);
	cout << "������Ϊ��" << minValue << "  " << middleValue << "  " << maxValue1
		<< endl;
	cout << "�Ƚϴ����� 3" << endl;
	cout << "�ƶ�����Ϊ�� " << moveTimes(num1, num2, num3, minValue) << endl;
}

void sendData() {
	int num1, num2, num3;
	cout << "��������������ȵ�������" << endl;
	cin >> num1 >> num2 >> num3;
	//�ж��������ݵ���ȷ��
	while (num1 == num2 || num2 == num3 || num3 == num1)
	{
		cout << "���ݵ���������!���������룺" << endl;
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
