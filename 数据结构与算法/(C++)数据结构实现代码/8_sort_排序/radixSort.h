

int getDigit(int key,int i) { 
	for(int j=1;j<i;j++)
		key = key/10;  
	key = key%10; 
	return key; 
}

const int radix = 10;
template <class Type>
void LSD(Type R[],int size,int i)  { 
    Type* bucket = new Type[size];  
    int *count = new int[radix];			// ������  
    int j,k;
    for(j = 0; j < radix; j++)				// ��������0
        count[j] = 0;					 
    for(j = 0; j < size; j++) { 
        k = getDigit(R[j],i);				// ����ÿ��Ͱ������
        count[k]++; ;
    }  
    for(j = 1; j < radix; j++)  
        count[j] = count[j - 1] + count[j]; 	// ��ÿ��Ͱ������������bucket�����λ��  
    for(j = size - 1; j >= 0; j--){			// һ�˷��䣺���ؼ��ֵ�iλ����bucket��  
        k = getDigit(R[j],i);
        bucket[--count[k]] = R[j];    
    }  
    for(j = 0; j < size; j++)				// һ���ռ�����Ͱ�����ݸ��Ƶ�R  
        R[j] = bucket[j];  
    delete []bucket;
    delete []count;
}

template <class Type>
void radixSort(Type R[],int size){		// ��������    
    int i,d=1,max = R[0];
	for(i=1;i<size;i++)
		if(R[i] > max)max = R[i];		// �����Ԫ�ص�����m��  
	while(max = max/10)d++;             // ��ؼ��ֵ������d
    for(i = 1; i <= d; i++)				// ����d�˻������� 
		LSD(R,size,i);					// ���ؼ��ֵĵ�iλ���л������� 
}  