
//============================================================================
// @FileName     ��1_2_lookup
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.9.23
// Description   ��
/*
 ������A[n]�в���ֵΪk��Ԫ�أ����ҵ��������λ��i(1��i��n)��
 �������0��Ϊ��־������㷨�������⣬��������ʱ�临�Ӷȡ�
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <stdlib.h>
#include <time.h>
#define random(x) rand()%(x)
using namespace std;

int creatDataNum() {
	cout << "�����봴���������ݵĸ�����";
	int size;
	cin >> size;
	cout << endl;
	return size;
}
int* creatArray(int size) {
	int *A = new int[size];
	srand((int)time(0));// �������������
	cout << "����Ϊ:  ";
	for (int i = 0; i < size; i++) {
		A[i] = random(100);//���ݷ�Χ�ڣ�0~99��
		cout << A[i] << "  ";
	}
	return A;
}

int findNum(){
	cout << "\n\n������Ҫ���ҵ���k��";
	int k;
	cin >> k;
	cout << endl;
	return k;
}

void findLocation(int number, int k, int *A) {
	int step = 0;
	cout << "����λ�ã� ";
	for (int i = 0; i < number; ++i) {
		if (k == A[i]) {
			cout << (i + 1) << "  ";
			step++;
		}
	}
	if (step == 0) {
		//Ҳ�������Ϊ���0
		cout << "No Find The Number Location!";
	}
	cout << "\n\nʱ�临�Ӷȣ�O (n)" << endl;
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
