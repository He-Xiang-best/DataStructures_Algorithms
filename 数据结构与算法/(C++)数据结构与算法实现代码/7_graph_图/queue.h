#ifndef _QUEUE_H_
#define _QUEUE_H_

class outOfRange:public exception {    	// ���ڼ�鷶Χ����Ч��
public:    
   const char* what()const throw(){  return "ERROR! OUT OF RANGE.\n";  } 
}; 
class badSize{};

template <class T>
class Queue
{
public:
	virtual bool empty()const = 0;		//�жӿ�
	virtual int size()const=0 ;
	virtual void enQueue(const T &x) = 0;	//���
	virtual T  deQueue() = 0;				//����
	virtual T  getHead()const = 0; 			//����ͷԪ��[��ȡ����Ԫ�أ��ҿ����޸Ķ���Ԫ�أ�������������]
	virtual ~Queue() {}         			//����������
};

#endif
