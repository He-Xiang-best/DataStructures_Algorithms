#ifndef _CAL_H_
#define _CAL_H_
#include "linkStack.h"  
#include <iostream> 
#include <cmath>
#include <cstring> 
using namespace std;  
class calculator{
private:
    linkStack<char> optr;				// �����ջ
    linkStack<double> opnd;				// ������ջ
    char* infix;						// �洢��׺���ʽ���ַ�����
    char* postfix;						// �洢��׺���ʽ���ַ����飬������3.4 
    int  size;							// ��׺���ʽ�ַ����ĳ���
public:	
    calculator(const char *s);					// ���캯��    	
    ~calculator();						// ��������
    double spellNum(char* fix,int& i);		// ƴ�����������ַ�ת����double���͵�����
    int priorInStack(char item);			// ����ջ����������ȼ�
    int priorOutStack(char ch);			// ����ջ����������ȼ�
    int precede(char item,char ch);		// �Ƚ�ջ������������ȴ���
    double operate(double a,char theta,double b);	// a��b����theta����
    double calculateInfix();				// ��׺���ʽ��ֵ
    double calculatePostfix();			// ��׺���ʽ��ֵ��������3.4
    void infixToPostfix () ;				// ��׺���ʽת��׺���ʽ��������3.4
    void printInfix ();					// �����׺���ʽ
    void printPostfix();					// �����׺���ʽ��������3.4
};
//���У�precede�Ǽ�����������ȼ��ĺ���������������ȽϿ��д��ڡ����ڡ�С�����ֽ������������ȣ�������һ������'('')'��'='��operate�����㺯�������ݵ���ջ�������(+��-��*��/)������������������Ӧ���㡣
//�����쳣�����ڳ���Ϊ0�쳣��
class divideByZero:public exception {    	
public:    
   const char* what()const throw()    
   {    return "ERROR! DIVIDE BY ZERO.\n";    } 
};
//�����쳣�����ڱ��ʽ����
class wrongExpression:public exception {    
public:    
   const char* what()const throw()    
   {    return "ERROR! BAD EXPRESSION.\n";    } 
};
//��׺���ʽ��ֵ�Ļ����������£�
//[�㷨3.13]	���캯��
calculator::calculator(const char *s) { 	 
    size = strlen(s) ;   
    infix = new char [size +1]; // infix�洢��׺���ʽ
    postfix = new char [2*size]; // postfix�洢��׺���ʽ
    strcpy(infix,s); 			
}

//[�㷨3.14]	��������
calculator::~calculator() { 			 
    delete []infix;
    delete []postfix;
} 

//[�㷨3.15]	ƴ��
double calculator::spellNum(char* fix,int& i) {	// �������ַ�תƴ��double���͵�����
    double num1=0,num2=0,num;
    int j=0;
    while(fix[i] >= '0' && fix[i] <= '9') 		// ����С������ǰ����
        num1 = num1*10 +fix[i++]-'0';  
    if(fix[i]=='.') {						// ����С�����Ժ󲿷�
        i++; 
        while(fix[i] >= '0' && fix[i] <= '9')
            num2 += (fix[i++]- '0')*1.0/pow(10.0,++j); 			
    }  
    return num=num1+num2;
}
//[�㷨3.16]	����ջ����������ȼ�
int calculator::priorInStack(char item) {	 	// �μ���3.1
    int in;
    switch(item) {
        case '=':in=0;break;
        case '(':in=1;break;
        case '*':
        case '/':in=5;break;
        case '+':
        case '-':in=3;break;
        case ')':in=6;break;
    }
    return in;
}
//[�㷨3.17]	����ջ����������ȼ�
int calculator::priorOutStack(char ch)	{		// �μ���3.1
    int out;
    switch(ch) {
        case '=':out=0;break;
        case '(':out=6;break;
        case '*':
        case '/':out=4;break;
        case '+':
        case '-':out=2;break;
        case ')':out=1;break;
        default: throw wrongExpression();
    }
    return out;
}
//[�㷨3.18]	�Ƚ�ջ������������ȴ���
int calculator::precede(char item,char ch){ 		
    if(priorInStack(item) < priorOutStack(ch))  return -1;
    else if(priorInStack(item) == priorOutStack(ch))  return 0;
    else return 1;
}
//[�㷨3.19]	���һ����������
double calculator::operate(double a,char theta,double b)  { 
    double result;
    switch(theta) {
        case '+' : 	result=a+b;break;
        case '-' : 	result=a-b;break;
        case '*' : 	result=a*b;break;
        case '/' :
            if ( fabs(b) <= 1e-6 )  throw divideByZero(); 
            else {
                result=a/b;
                break;
            }
    }
    return result;
}
//[�㷨3.20]	��׺���ʽ��ֵ
double  calculator::calculateInfix(){	
    optr.clear();
    opnd.clear();
    int i=0;
    char item,theta;
    double num,a,b;
    optr.push('=');							// '='����ջ�ף��������
    while(!optr.empty()){
        if((infix[i]>='0'&& infix[i]<='9')||infix[i]=='.'){
            num=spellNum(infix,i);
            opnd.push(num);					// �����ַ�����ջ
        }   
        else {
            item = optr.getTop();
            switch(precede(item,infix[i])){ 	// infix[i]��ջ��������Ƚ�
                case -1:optr.push(infix[i]);	// infix[i]����ߣ���ջ
                        i++;					// iָ����һ�ַ�
                        break;
                case 0: item = optr.pop();		// ɾ�����Ż�'='
                        if(item != '=')i++;		// iָ����һ�ַ�
                        break;
                case 1: theta = optr.pop();   	// infix[i]����ͣ�����һ�������
                        b = opnd.pop(); a = opnd.pop();  	// ��������������
                        opnd.push(operate(a,theta,b));	// ������Ӧ���㣬�����ջ
            }  
        }
    }
    num=opnd.pop();
    if(!opnd.empty())throw wrongExpression();
    return num;
}
//˵�������������С�b = opnd.pop(); a = opnd.pop();�������������������˴�û���ж�ջ�Ƿ�Ϊ�գ���Ϊ��ջΪ��ʱ��linkList��pop()�������׳�outOfRange�쳣��
//[�㷨3.21]	������ʽ
void  calculator::printInfix(){
    int i=0;
    while(infix[i]!='\0')
        cout<<infix[i++];
    cout<<endl;
}
void  calculator::infixToPostfix(){
    int i=0,j=0;							// i��j�ֱ�����׺���ʽ�ͺ�׺���ʽ���±�
    char item;
    optr.clear();
    optr.push('=');							// '='����ջ�ף����ȼ����
    while(!optr.empty()){	
        if((infix[i]>='0'&& infix[i]<='9')||infix[i]=='.')
            postfix[j++]=infix[i++];			// �����ַ�ֱ�Ӵ洢����׺���ʽ�� 
        else {
            postfix[j++]=' ';					// �ո��������ֺ�׺���ʽ�и���ɲ���
            item=optr.getTop();
            switch(precede(item,infix[i])){		// infix[i]��ջ��������Ƚ�
                case -1:optr.push(infix[i]);	// infix[i]����ߣ���ջ
                        i++;   break;			// iָ����һ�ַ�
                case 0: item=optr.pop();		// ɾ�����Ż�'='
                        if(item != '=')i++;	    // iָ����һ�ַ�
                        break;
                case 1: item=optr.pop();		// item����ߣ���ջ
                        postfix[j++]=item;		// item�洢����׺���ʽ��
            }  
        }
    }
    postfix[j]='\0';						// �ַ���������־
}
//[�㷨3.23]	��׺���ʽ��ֵ
double calculator::calculatePostfix(){			// �Ժ�׺���ʽ��ֵ
    opnd.clear();
    int i=0;
    double num,a,b;
    while (postfix[i]!='\0'){					// '\0'�Ǻ�׺���ʽ������־
        if((postfix[i]>='0'&&postfix[i]<='9')||postfix[i]=='.') {
            num=spellNum(postfix,i);			// ���������ַ���С���㣬ƴ��
            opnd.push(num);					// numѹ������ջ
        }
        else if(postfix[i]==' ')i++;			// �ո�����
        else {
            b=opnd.pop();  a=opnd.pop(); 		// ��������������					
            if(postfix[i]=='+')  num=a+b;
            if(postfix[i]=='-')  num=a-b;
            if(postfix[i]=='*')  num=a*b;
            if(postfix[i]=='/'){
                if( fabs(b) <= 1e-6 ) throw divideByZero();
                else num=a/b;
            }
            opnd.push(num);					// ������ѹջ
            i++;	
        }
    }
    num=opnd.pop();
    if(!opnd.empty()) throw wrongExpression();
    return num;
}
//[�㷨3.24]	�����׺���ʽ
void  calculator::printPostfix(){
    int i=0;
    while(postfix[i]!='\0')
        cout<<postfix[i++];
    cout<<endl;
}


#endif
