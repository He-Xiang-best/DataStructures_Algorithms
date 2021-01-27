#include<iostream>
#include <ctime>
#include <algorithm>
using namespace std;
#include"heapSort.h"
#include"shellSort.h"
#include"straightInsertSort.h"
#include"straightSelectSort.h"
#include"bubbleSort.h"
#include"quickSort.h"
#include"mergeSort.h"
#include"radixSort.h"
#define N 8
int  A[N] ={236,180,366,145,22,9,416,636};
//int  A[N] ={9,16,22,36,36,45,66,80};
//���������е�������¼
/*
template <class Type>
void Swap(Type &a,Type &b){
	Type tmp = a;
	a = b;
	b = tmp;	
}
*/
// ���Ը���������				
template <class Type>
void testSort(void (*sort)( Type R[],int size ))
{
	clock_t start, finish;
	double duration;
	
	srand(1);								// �趨�������������						
	cout<<"�����ģ��"<<N<<endl;
	int * array =new int[N];				// �����������,����ΪN
	//for(int i=0;i<N;i++)
	//	cout<<(array[i]=rand() % (N*8))<<"\t";	// 0��N-1֮��������

	for(int i=0;i<N;i++)
		cout<<(array[i]=A[i])<<"\t";		
	cout<<endl;

	start = clock();
	sort(array,N);							// ����
	finish = clock();
	duration = (double)(finish - start);	// û/ CLOCKS_PER_SEC;

	for(int i=0;i<N;i++)
		cout<<array[i]<<"\t";
	cout<<"�����ʱ"<<duration<<"ms\n";
	cout<<"--------------------------------------------------------------------------\n";
}
int main()
{
	cout<<"ֱ�Ӳ�������,"; 
	testSort(straightInsertSort<int>);	
	cout<<"�۰��������,"; 
	testSort(binaryInsertSort<int>);	
	cout<<"ϣ������,"; 
	testSort(shellSort<int>);	
	cout<<"ֱ��ѡ������,"; 
	testSort(straightSelectSort<int>);	
	cout<<"������,"; 
	testSort(heapSort<int>);
	cout<<"ð������,"; 
	testSort(bubbleSort<int>);
	cout<<"��������,"; 
	testSort(quickSort<int>);
	cout<<"�鲢����,"; 
	testSort(mergeSort<int>);
	cout<<"��������,"; 
	testSort(radixSort<int>);
	char x;
	cin>>x;
}
