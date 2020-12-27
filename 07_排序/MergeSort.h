#pragma once
using namespace std;
    template <class Type>
    void  merge(Type R[], Type tmp[], int low, int mid, int high) {
        int i = low, j = mid, k = 0;
        while (i < mid && j <= high)// R�м�¼��С����ز���tmp
            if (R[i] < R[j])
                tmp[k++] = R[i++]; // ��R[i]��R[j]��С�߿�����tmp[k]
            else tmp[k++] = R[j++];
        while (i < mid) 		// ǰ��ʣ��R[i.. mid-1]���Ƶ�tmp
            tmp[k++] = R[i++];
        while (j <= high) 	// ���ʣ��R[j..high]���Ƶ�tmp
            tmp[k++] = R[j++];
        for (i = 0, k = low; k <= high; )
            R[k++] = tmp[i++];	// �ź���ļ�¼��tmp����R
    }

    //�ݹ�2-·�鲢����ͨ���ݹ����ʵ�ֶ�������R[low.. high]��������̣�����鲢Ϊ����Ρ�
    template <class Type>
    void  mergeSort(Type R[], Type tmp[], int low, int high) {
        if (low == high) return;
        int mid = (low + high) / 2; 	// ���м仮��Ϊ����������
        mergeSort(R, tmp, low, mid);// �ݹ�鲢������R[low.. mid] 
        mergeSort(R, tmp, mid + 1, high);// �ݹ�鲢������R[mid+1.. high]  
        merge(R, tmp, low, mid + 1, high);	// �鲢����������
    }

    //2-·�鲢����Ľӿں���������Ϊ����������R���Լ����д�Сsize��
    template <class Type>
    void mergeSort(Type R[], int size) {
        Type* tmp = new Type[size];	// ��������
        mergeSort(R, tmp, 0, size - 1);
        delete[] tmp;
    }

