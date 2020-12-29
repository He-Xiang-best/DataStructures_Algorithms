#pragma once
using namespace std;
//ֱ�Ӳ�������
template <class Type>
void straightInsertSort(Type R[], int size) {
    int pos, j;		// posΪ�������¼λ�� 
    Type tmp;
    for (pos = 1; pos < size; pos++) {
        tmp = R[pos]; 	// ���������¼�Ž���ʱ����
        // �Ӻ���ǰ���Ҳ���λ��
        for (j = pos - 1; tmp < R[j] && j >= 0; j--)
            R[j + 1] = R[j]; // �����ڴ������¼�ļ�¼����ƶ�
        R[j + 1] = tmp; 	// ���������¼�ŵ�����λ��
    }
}

//�۰��������Binary Insertion Sort��������i����¼Ҫ����ǰi��1�������¼����ʱ��
//�������۰���ҷ�ʽȷ������λ�ã��Լ��ٱȽϴ������Ӷ��ﵽ���ٱȽϴ�����Ŀ�� 
template <class Type>
void  binaryInsertSort(Type R[], int size) {
    int pos, j, low, high, mid;
    Type tmp;
    for (pos = 1; pos < size; pos++) {// �ٶ���һ����¼���� 
        tmp = R[pos];	// �����ż�¼R[pos]�ݴ浽tmp
        low = 0; high = pos - 1;// �����۰���ҵķ�Χ
        while (low <= high) {	// �۰���Ҳ���λ��
            mid = (low + high) / 2;	// �����м�λ��
            if (tmp < R[mid]) high = mid - 1;
            else low = mid + 1;
        }
        for (j = pos - 1; j >= low; j--)
            R[j + 1] = R[j];	// ��¼����
        R[low] = tmp;		// ����������¼
    }
}
