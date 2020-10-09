
//============================================================================
// @FileName     ��1_4_ Josephlink
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.9.23
// Description   ��
/*
 �θ�������n��k���������������Եõ�1,2, ��,n��һ���û���
 ������1,2,��,n�������У���˳ʱ�뷽����1��ʼ����������Kʱ�����λ���ϵ����֣���ʹ����С�
 Ȼ�������˳ʱ�뷽�����һ�����ּ��������������ȥ��ֱ�����е�����ȫ������Ϊֹ��
 ����N=10��K=3������ȷ�ĳ���˳��ӦΪ3��6��9��2��7��1��8��5��10��4��
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int getNum() {
	int n;
	cout << "��������е�Ԫ�ظ���n��ֵ��";
	cin >> n;
	cout << endl;
	return n;
}

int getStep() {
	int k;
	cout << "�������߳����ݵĲ���k��ֵ��";
	cin >> k;
	cout << endl;
	return k;
}
int *Array(int n){
	//����һ�����飬����ֵ�õ�һ��Լɪ����
	int *A=new int[n];
	for (int i = 0; i < n; i++) {
		A[i] = i + 1;
	}
	return A;
}

void procession(int n, int k, int *A) {
	cout << "Լɪ�� �� \n" << endl;
	//�����ж����ߵĲ���
	int step = k;
	//���ô�ӡ��������ȫ�����ִ�ӡ���������
	int printCount = 0;
	//ѭ������Լɪ��������
	for (int i = k - 1; printCount < n; i++) {
		//�������Ԫ��==0��֤����Ԫ���ѱ��߳����У���ʱ��һ���൱��û������
		if (A[i % n] == 0) {
			continue;
		}
		//��Ԫ��û�г��У����жϲ����Ƿ��ߵ��˹涨�������ߵ�����ʹ����У���ӡ����������޳�����ֵΪ0��
		if (step % k == 0) {
			cout << A[i % n] << " ";
			A[i % n] = 0;
			//����һ������ӡһ�����ȵ�����Ԫ�س�����󣬽���ѭ��
			printCount++;
			//���߲���+1
			step++;
		}
		else
			//û���ߵ��涨���������߳�Ԫ�أ�����+1������ǰ��
			step++;
	}
	  delete[] A;
}

int main()
{
	int arrayLen = getNum();
	
	//���ú���procession��ʵ�ֳ��в���
	procession(arrayLen, getStep(), Array(arrayLen));

    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
