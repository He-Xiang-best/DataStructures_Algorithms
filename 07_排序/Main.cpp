
//============================================================================
// @FileName     ��Main.cpp
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.12.3
// Description   ��
/*
��������Զ������������
��ֱ�Ӳ�������ϣ������ð������ֱ��ѡ�����򡢿������򡢶����򡢹鲢����ķ�����������ͳ�Ƹ����򷽷���ʱ��
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include"BubbleSort.h"
#include"HeapSort.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"RadixSort.h"
#include"ShellSort.h"
#include"StraightInsertSort.h"
#include"StraightSelectSort.h"
#include<iostream> 
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int sortSize;
int* sortArray;

void setArray() {
    int size;
    cout << "���Զ�������Ĺ�ģ��";
    cin >> size; cout << endl;
    sortSize = size;
    srand(0);
    sortArray = new int[sortSize];
    cout << "��������������£�" << endl;
    for (int i = 0; i < sortSize; i++)
    {   
        sortArray[i] = rand() % 101;
        cout << sortArray[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << "\n-----------------------------------" << endl;
}

template <class Type>
void testSort(void(*sort)(Type R[] ,int size)){
    clock_t start, finish;
    double duration;
    cout << "��ǰ����Ĺ�ģΪ��"<<sortSize<<endl;
    cout << "��ǰ������Ϊ��" << endl;
    int* array = new int[sortSize];
    for (int i = 0; i < sortSize; i++)
    {  
        cout << (array[i]=sortArray[i]) << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    start = clock();
    sort(array, sortSize);
    finish = clock();
    duration = (double)(finish - start);
    cout << "\n����������Ϊ��" << endl;
    for (int i = 0; i < sortSize; i++)
    {
        cout << array[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << "\n�����ʱΪ��" << duration << " ms\n";
    cout << "\n-----------------------------------" << endl;
}



int main()
{
    setArray();
    cout << "ֱ�Ӳ�������" << endl;
    testSort(straightInsertSort<int>);
    cout << "�۰��������" << endl;
    testSort(binaryInsertSort<int>);
    cout << "ϣ������" << endl;
    testSort(shellSort<int>);
    cout << "ֱ��ѡ������" << endl;
    testSort(straightSelectSort<int>);
    cout << "������" << endl;
    testSort(heapSort<int>);
    cout << "ð������" << endl;
    testSort(bubbleSort<int>);
    cout << "��������" << endl;
    testSort(quickSort<int>);
    cout << "�鲢����" << endl;
    testSort(mergeSort<int>);
    cout << "��������" << endl;
    testSort(radixSort<int>);
    cout << "������������ɣ�" << endl;
    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
