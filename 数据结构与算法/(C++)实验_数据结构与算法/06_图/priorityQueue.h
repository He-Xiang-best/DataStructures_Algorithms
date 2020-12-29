#pragma once
#include<iostream>
using namespace std;

template <class elemType>
class priorityQueue {
private:
    int curLength;  	                        // ������Ԫ�ظ���
    elemType* data;                             // ָ����Ԫ�ص�����
    int  maxSize; 	                            // ���еĴ�С
    void resize();		                        // ������пռ�
    void siftDown(int parent);					// ��parentλ�����µ������ȼ�����
    void siftUp(int position);					// ��positionλ�����ϵ������ȼ�����
public:
    priorityQueue();
    priorityQueue(const elemType *data, int size);
    ~priorityQueue() { delete[] data; }
    bool empty()const { return curLength == 0; }// �п�
    int size()const { return curLength; }	    // �󳤶�
    void buildHeap();				            // ����
    void enQueue(const elemType& x);		    // ���
    elemType deQueue();				            // ����
    elemType getHead()const {			        // ȡ����Ԫ��
        if (empty())  cout << "\n���������������" << endl;
        return  data[1];
    }
};

//���
template <class elemType>
void priorityQueue<elemType>::enQueue(const elemType& x) {
    if (curLength == maxSize - 1)  resize();
    data[++curLength] = x;	// �±��1��ʼ
    siftUp(curLength);		// �����Ԫ�������ϵ���
}

//���ϵ����ѣ�Ϊ���Ч�ʣ���˫�׵ļ�ֵ��ʱ�����������ƶ�˫�����ݵĲ��ԣ������ǽ������ݡ�
template <class elemType>
void priorityQueue<elemType>::siftUp(int position) {					// ��position��ʼ���ϵ���
    elemType temp = data[position];								        // ����positionλ��Ԫ��
    for (; position > 1 && temp < data[position / 2]; position = 2)
        data[position] = data[position / 2];							// positionλ��Ԫ�ر�˫��С��˫������
    data[position] = temp;
}

//����
template <class elemType>
elemType priorityQueue<elemType>::deQueue() {
    if (empty()) cout<<"��Χ���󣡲���ʧ�ܣ�";
    elemType min;
    min = data[1];	                                            // ������СԪ��
    data[1] = data[curLength--];								// ��βԪ�ش����±�1λ�ã��Ѷ���
    siftDown(1);		                                        // �Ӷ��ף��Ѷ������µ���
    return  min; 		                                        // ���ض���Ԫ��
}

//Ϊ���Ч�ʣ����������ƶ����ݵĲ��ԣ������ǽ�������
template <class elemType>
void priorityQueue<elemType>::siftDown(int parent) {
    // ��parent��ʼ���µ���
    int child;
    elemType tmp = data[parent];// ����parent�����
    for (; parent * 2 <= curLength; parent = child) {
        child = parent * 2;		// child���ڼ�¼��С���ӽ��
        if (child != curLength && data[child + 1] < data[child])
            child++;			// �Һ��Ӹ�С
        if (data[child] < tmp)  data[parent] = data[child];
        else  break;
    }
    data[parent] = tmp;
}

//���ѷ�������ʵ�֡�
template <class elemType>
void priorityQueue<elemType>::buildHeap() {
    for (int i = curLength / 2; i > 0; i--)
        siftDown(i);
    // [curLength/2..1]���±����ķ��ն˽�㿪ʼ����
}

//��������ѣ��г�ʼ��С�ͳ�ʼ���У�����buildHeap( )���ѡ�
template <class elemType>
priorityQueue<elemType>::priorityQueue(const elemType* items, int size) :
    maxSize(size + 10), curLength(size) {
    data = new elemType[maxSize];
    for (int i = 0; i < size; i++)
        data[i + 1] = items[i];	// ����Ԫ��
}

//��������ѣ�ֻ�г�ʼ��С���޳�ʼ���У�����ʱ��Ҫ������Ӳ���
template <class elemType>
priorityQueue<elemType>::priorityQueue(){
    int initSize = 100;
    if (initSize <= 0)
        cout << "��ʼ�����ѷ�Χ����" << endl;
    data = new elemType[initSize];
    maxSize = initSize;
    curLength = 0;
}

//����ѿռ�
template <class elemType>
void priorityQueue<elemType>::resize() {
    elemType* tmp = data; // tmp ָ��ԭ�ѿռ�
    maxSize *= 2; //�ѿռ�����2��
    data = new elemType[maxSize]; // dataָ���µĶѿռ�
    for (int i = 0; i < curLength; ++i)
        data[i] = tmp[i]; // ����Ԫ��
        delete[]tmp;
}



