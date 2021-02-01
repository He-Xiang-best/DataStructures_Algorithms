#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_
#include"queue.h"
template <class elemType>
class priorityQueue:public Queue<elemType>
{private:
	int curLength;  
	elemType *data;   
	int maxSize;
	void resize();
	void buildHeap();							// ����
	void siftDown(int parent );					// ��parentλ�����µ������ȼ����У��ѣ�
	void siftUp(int position);					// ��positionλ�����ϵ������ȼ����У��ѣ�
public:
	priorityQueue( int initSize = 100 );
    priorityQueue( const elemType data[], int size );
	~priorityQueue() { delete [] data; }
    bool empty()const { return curLength == 0; }// �п�
	int size()const { return curLength; }		// �󳤶�
    void enQueue( const elemType & x );			// ���
    elemType deQueue();							// ����
    elemType getHead()const {					// ȡ����Ԫ��
		if( empty()) throw outOfRange();
		return data[1]; 
	}	
};
template <class elemType>
priorityQueue<elemType>::priorityQueue( int initSize ) 
{	if(initSize<=0)throw badSize();
	data = new elemType[initSize];
	maxSize = initSize;   
	curLength = 0;
}
template <class elemType>
priorityQueue<elemType>::priorityQueue( const elemType *items, int size ): maxSize(size + 10 ),  curLength(size)
{	data = new elemType[maxSize];
	for( int i = 0; i < size; i++ )   
		data[ i + 1 ] = items[ i ];						// ����Ԫ��
	buildHeap();										// ���ý���
} 
template <class elemType>
void priorityQueue<elemType>::buildHeap( )
{	for( int i = curLength / 2; i > 0; i-- )
		siftDown( i );									// [curLength/2..1]���±����ķ��ն˽�㿪ʼ����
} 
template <class elemType>
void priorityQueue<elemType>::enQueue( const elemType & x )
{	if( curLength == maxSize - 1 )  resize();	
	data[++curLength ] = x;								// �±��1��ʼ
	siftUp( curLength );								// �����Ԫ�������ϵ���
} 
template <class elemType>
void priorityQueue<elemType>::siftUp( int position )	// ��position��ʼ���ϵ���
{		
	elemType temp=data[ position];						// ����positionλ��Ԫ��
	for( ; position> 1 && temp< data[ position/ 2 ]; position/= 2 )
		data[ position] = data[ position/ 2 ];			// positionλ��Ԫ�ر�˫��С��˫������
	data[ position] =temp ;
}
template <class elemType>
elemType priorityQueue<elemType>::deQueue()
{	if( empty()) throw outOfRange();
	elemType min;
	min = data[ 1 ];									// ������СԪ��
	data[ 1 ] = data[ curLength-- ];					// ��βԪ�ش����±�1λ�ã��Ѷ���
	siftDown( 1 );										// ���ף��Ѷ������µ���
	return min;
} 
template <class elemType>
void priorityQueue<elemType>::siftDown( int parent )	// ��parent��ʼ���µ���
{	int child;
	elemType tmp = data[ parent ];						// ����parent�����
 
	for( ; parent * 2 <= curLength; parent = child )	
	{	child = parent * 2;								// child���ڼ�¼��С���ӽ��
		if( child != curLength && data[ child + 1 ] < data[ child ] )
			child++;									// �Һ��Ӹ�С
		if( data[ child ] < tmp )   data[ parent ] = data[ child ];
		else    break;
	}
	data[ parent ] = tmp;
}
template <class elemType>
void priorityQueue<elemType>::resize()
{ 
	elemType *tmp = data;								// tmpָ��ԭ��ռ�
	maxSize *= 2;										// ��ռ�����2��
	data = new elemType[maxSize];						// dataָ���µı�ռ�
	for (int i = 0; i < curLength; ++i)				
		data[i] = tmp[i];								// ����Ԫ��
	delete [] tmp;
} 
#endif
