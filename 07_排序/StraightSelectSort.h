#pragma once
using namespace std;
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