// �������R[low..mid-1]��R[mid..high]�鲢Ϊ�����R[low..high]
template <class Type>
void merge(Type R[],Type tmp[],int low, int mid, int high){	
 	int i=low, j=mid, k=0;
	//Type *tmp = new Type[high-low+1];
 	while (i<mid && j <= high)							// R�м�¼��С����ز���tmp
		if (R[i] < R[j])  tmp[k++] = R[i++];			// ��R[i]��R[j]��С�߿�����tmp[k]
		else tmp[k++] = R[j++]; 
 	while ( i<mid )  tmp[k++] = R[i++];					// ��ʣ���R[low.. mid]���Ƶ�tmp
 	while ( j<=high )  tmp[k++] = R[j++];				// ��ʣ���R[j..high]���Ƶ�tmp
 	for (i=0, k = low; k<=high; ) R[k++] = tmp[i++];	// �ź����tmp[low..high]������R[low..high]
 	//delete [] tmp;
} 
template <class Type>
void mergeSort(Type R[],Type tmp[], int low, int high){ 
	if (low == high) return;
	int mid = (low+high)/2;
	mergeSort(R,tmp,low, mid);					// �ݹ�ؽ�R[low.. mid]�鲢Ϊ�����R[low.. mid]
	mergeSort(R,tmp,mid+1, high);				// �ݹ�ؽ�R[mid+1.. high]�鲢Ϊ�����R[mid+1.. high]
	merge(R,tmp,low,mid+1,high);				// ��R[low.. mid]��R[mid+1.. high]�鲢��R[low.. high]
} 
template <class Type>
void mergeSort(Type R[], int size)
{ 
	Type *tmp = new Type[size];
	mergeSort(R,tmp,0, size-1); 
	delete [] tmp;
}
