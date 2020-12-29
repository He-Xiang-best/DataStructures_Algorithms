#pragma once
#include<typeinfo>
using namespace std;
    //���µ����ɶ�,����Ϊ����������R��Ҫ�����Ľ����pos�Լ����д�Сsize��
    template <class Type>
    void siftDown(Type R[], int pos, int size) {
        int child;
        Type tmp = R[pos]; 		// �ݴ桰������¼R[pos]
        for (; pos * 2 + 1 < size; pos = child) {
            child = pos * 2 + 1;
            if (child != size - 1 && R[child + 1] > R[child])
                child++;			// ѡȡ�������ӵĴ���		
            if (R[child] > tmp) 	// �ϴ�ĺ��ӱ�˫�״�
                R[pos] = R[child];
            else  break;
        }
        R[pos] = tmp; 			// ��������������ȷλ��
    }

    //������,����Ϊ����������S���Լ����д�Сsize��
    template <class Type>
    void heapSort(Type R[], int size) {
        int  i;
        // ��ʼ���ѣ������һ����Ҷ��㿪ʼ����
        for (i = size / 2 - 1; i >= 0; i--)
            siftDown(R, i, size);
        // ��n-1������ɾ���Ѷ�Ԫ�غ󷴸������ѣ�			
        for (i = size - 1; i > 0; i--) {
            swap(R[0], R[i]);	// �����Ѷ�Ԫ���������������һ��Ԫ��
            siftDown(R, 0, i);	// ��R[0..i]���µ���Ϊ�󶥶�
        }
    }
