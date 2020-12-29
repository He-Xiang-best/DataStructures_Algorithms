#pragma once
using namespace std;
//����Shell����ķ��鷽������Shell������㷨����
template <class Type>
void shellSort(Type R[], int size) {
    int gap, pos, j;	// gapΪϣ��������posΪ�������¼λ��
    Type tmp;
    for (gap = size / 2; gap > 0; gap /= 2) {
        for (pos = gap; pos < size; pos++) {
            tmp = R[pos];
            for (j = pos - gap; j >= 0 && R[j] > tmp; j -= gap)
                R[j + gap] = R[j];	// ��¼���� 
            R[j + gap] = tmp;		// ���������¼�ŵ�����λ��
        }
    }
}
