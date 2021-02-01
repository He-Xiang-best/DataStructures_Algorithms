// abstract data type for stack 
#ifndef _STACK_H_
#define _STACK_H_
/*
class outOfRange:public exception {    	// ���ڼ�鷶Χ����Ч��
public:    
outOfRange():exception("ERROR!OUT OF RANGE.\n")  
{}
};  
class badSize:public exception {    		// ���ڼ�鳤�ȵ���Ч��
public:    
badSize():exception("ERROR!BAD SIZE.\n")  
{}
};
*/
class outOfRange:public exception {    	// ���ڼ�鷶Χ����Ч��
public:    
   const char* what()const throw()    
   {    return "ERROR! OUT OF RANGE.\n";    } 
};  
class badSize:public exception {    		// ���ڼ�鳤�ȵ���Ч��
public:    
   const char* what()const throw()    
   {    return "ERROR! BAD SIZE.\n";    }  
};

template <class T> 					// ջ��Ԫ������Ϊ T 
class Stack 
{ public: 
	virtual bool empty() const = 0; 
	virtual int size() const = 0; 
	virtual void push(const T &x) = 0; 
	virtual T  pop() = 0;              
	virtual T getTop() const = 0;  
	virtual void clear() =0;
	virtual ~Stack() {}
};
#endif