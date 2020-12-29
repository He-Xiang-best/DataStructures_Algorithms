#pragma once
template <class Type>
class Sort {
public:
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
//�������۰���ң��ڲ����½��ѽ��ܣ���ʽȷ������λ�ã��Լ��ٱȽϴ������Ӷ��ﵽ���ٱȽϴ�����Ŀ�� 
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

//ð�������㷨
template <class Type>
void bubbleSort(Type R[], int size) {
    int i, j;
    bool flag = true;		// ��¼һ��������Ƿ���������
    for (i = 1; i < size && flag; ++i) {
        flag = false;		// �ٶ���������û�н���
        for (j = 0; j < size - i; ++j)
            if (R[j + 1] < R[j]) {	// ����		
                swap(R[j], R[j + 1]);	// ����STL�е�swap���н���
                flag = true;
            }
    }
}

//�ݹ�������򡣲���Ϊ����������S���Լ�����������½�low���Ͻ�high��
template <class Type>
void quickSort(Type S[], int low, int high) {
    int pivot;
    if (low >= high) return;
    pivot = partition(S, low, high); // һ�λ��֣���������λ��
    quickSort(S, low, pivot - 1);	// ���������һ���������
    quickSort(S, pivot + 1, high);	// �������ұ�һ���������
}

//һ�˿������򣨻�һ�λ��֣�������Ϊ����������S���Լ�����������½�low���Ͻ�high��
template <class Type>
int partition(Type S[], int low, int high) {
    Type  tmp = S[low];		    // �ݴ���ֵ
    while (low != high) {		// ��ʼ���зָ�
        while (low < high && S[high] >= tmp)high--;	// ��<��ֵ�ļ�¼
        if (low < high) { S[low] = S[high]; low++; }
        // �ü�¼�ƶ���С�±��
        while (low < high && S[low] <= tmp) low++;	// ��>��ֵ�ļ�¼
        if (low < high) { S[high] = S[low]; high--; }
        // �ü�¼�ƶ������±��
    }
    S[low] = tmp;		// ����ֵ����ֽ�λ����
    return low;			// ��������λ��
}

//��������Ľӿں���������Ϊ����������S���Լ����д�Сsize��
template <class Type>
void quickSort(Type S[], int size) {
    quickSort(S, 0, size - 1);
}

//ֱ��ѡ������
template <class Type>
void straightSelectSort(Type R[], int size) {
    int  pos, min, j;// minΪһ����������С��¼�±�
    // posΪ����ŵ�ǰ��С��¼��λ��
    for (pos = 0; pos < size - 1; pos++) {
        min = pos;
        for (j = pos + 1; j < size; ++j)
            if (R[j] < R[min]) min = j;// ������С��¼
        // ����STL�е�swap��ͷ�ļ�algorithm	    
        if (pos != min) swap(R[pos], R[min]);
    }
}

//�����򡣲���Ϊ����������S���Լ����д�Сsize��
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

//���µ����ɶѡ�����Ϊ����������R��Ҫ�����Ľ����pos�Լ����д�Сsize��
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


//�鲢���ڵ��������������С�����������R[low..mid-1]��R[mid..high]�鲢Ϊ��������R[low..high]��
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

//ȡ�ؼ���key�ĵ�iλ������Ϊ�ؼ���key�Լ���ǰλi��
int getDigit(int key, int i) {
    for (int j = 1; j < i; j++)
        key = key / 10;
    key = key % 10;
    return key;
}

};