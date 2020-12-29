#pragma once
using namespace std;
    //ȡ�ؼ���key�ĵ�iλ������Ϊ�ؼ���key�Լ���ǰλi��
    int getDigit(int key, int i) {
        for (int j = 1; j < i; j++)
            key = key / 10;
        key = key % 10;
        return key;
    }

    //���ؼ��ֵĵ�iλ����һ�˻������򡣲���Ϊ����������R�����д�Сsize�Լ���ǰλi��
    const int radix = 10; 		// ����Ϊ10
    template <class Type>
    void LSD(Type R[], int size, int i) {
        Type* bucket = new Type[size];
        int* position = new int[radix];	// ������  
        int j, k;
        for (j = 0; j < radix; j++)	// ��������0
            position[j] = 0;
        for (j = 0; j < size; j++) {
            k = getDigit(R[j], i);	// ����ÿ��Ͱ������
            position[k]++; ;
        }
        // ��ÿ��Ͱ������������bucket�����λ��  
        for (j = 1; j < radix; j++)
            position[j] = position[j - 1] + position[j];
        for (j = size - 1; j >= 0; j--) {	// ����һ�˷���
            k = getDigit(R[j], i); 				  // ���ؼ��ֵ�iλ����ֵ����bucket��  
            bucket[--position[k]] = R[j];
        }
        for (j = 0; j < size; j++)	// ˳��һ���ռ� 
            R[j] = bucket[j];  	// ��Ͱ�м�¼�ռ�������R  
        delete[]bucket;
        delete[]position;
    }

    //�������򡣲���Ϊ����������R���Լ����д�Сsize��
    template <class Type>
    void radixSort(Type R[], int size) {
        int i, d = 1, max = R[0];
        for (i = 1; i < size; i++)
            if (R[i] > max) max = R[i];	// �����ؼ���  
        while (max = max / 10) d++;  // ��ؼ��ֵ������d
        for (i = 1; i <= d; i++)	// �ӵ�λ��ʼ��������d�˻������� 
            LSD(R, size, i);
    }

