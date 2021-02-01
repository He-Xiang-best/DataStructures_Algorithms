#include <cstdlib>    
#include <iostream>     
#include<stack>
#include<string>
using namespace std;   
#include "linkStack.h"  
#include "seqStack.h" 
#include "CAL.h"

template <class T> 	 
void testStack(Stack<T> &s)
{
	for (int i=0; i<10; ++i) s.push(2*i);
	cout<<"curLength="<<s.size()<<endl;
	while (!s.empty())  cout << s.pop() << ' ';
	cout<<"\ncurLength="<<s.size()<<endl;

	try{
		cout <<s.getTop();
	}
	catch(outOfRange& me){
		cout<<me.what();
	}
}
// ��׳�
template <class T> 	   
long factorial(Stack<T> &s,long n) {   
     long result = 1;   
     while (n > 0)                  // ������ݹ����          
        s.push(n--);                // ���ݹ�������Ӧ����ѹջ    
     while (!s.empty()) {         // �ݹ�������㣬��ʼ���з��ش���    
        result *= s.pop();  
     }    
     return result;   
}
// ����ת��
void convert(){
    linkStack<int> S;   		// ջS
    int N,e;   
    cin>>N;						// ����ʮ������
    while(N!=0) {
        S.push(N%16);			// ���õ��İ˽�����λ��ջ
        N=N/16;					// ��N����8���µı�����
    }
    while(!S.empty()){
        e=S.pop(); 
		if(e > 9)  
	          cout<<char(e-10+'a');
		else  cout<<e<<" ";			// ����˽�����
    }
    cout<<endl;
}
// ����ƥ��1
bool match(){
    linkStack<char> S;   							// ʹ��3.1.3��ʵ�ֵ���ջ
    char item;
    int i=0;
    string expression;
    getline(cin,expression);							// �����ַ���
    while(i < expression.size()){  					// ɨ���ַ���
        switch (expression[i]){
            case '(':S.push(expression[i]);    break;	// ������ ( ѹջ
            case ')':								// ������ ) ����ջ��Ԫ��ƥ��
                if(S.empty()||(item=S.getTop())!='('){	// ʧ��
                    cout<<"mismatched\n";    return false;
                } 
                else   S.pop();     break; 			// ƥ��
            case '[':S.push(expression[i]);    break; 	// ������ [ ѹջ
            case ']':				 				// ������ ] ����ջ��Ԫ��ƥ��
                if(S.empty()||(item=S.getTop())!='['){ 	// ʧ��
                    cout<<"mismatched\n";    return false;
                } 
                else   S.pop();     break; 			// ƥ��
            case '{':S.push(expression[i]);    break; 	// ������ { ѹջ
            case '}': 								// ������ } ����ջ��Ԫ��ƥ��
                if(S.empty()||(item=S.getTop())!='{'){ 	// ʧ��
                    cout<<"mismatched\n";    return false;
                } 
                else   S.pop();    break; 				// ƥ��
        };
        i++;
    }
    if(S.empty()) {  cout<<"matched\n";    return true;  } 
    else{  cout<<"mismatched\n";    return false; }		// ջ�ǿգ�ʧ��
}
// ����ƥ��2
bool match2(){
    stack<char> S;   // ջS
	string expression;
    getline(cin,expression);
	char item;
	int i=0;
    while(i< expression.size()){  				// '\0'��ʾ�ַ������� 
        switch (expression[i]){
            case '(':S.push(expression[i]);    break;		// ������ ( ѹջ
            case ')':							// ������ ) ����ջ��Ԫ��ƥ��
                if(S.empty()||(item=S.top())!='('){
                    cout<<") mismatched\n";    return false;
                } 
                else   S.pop();     break;
            case '[':S.push(expression[i]);    break; 		// ������ [ ѹջ
            case ']':				 			// ������ ] ����ջ��Ԫ��ƥ��
                if(S.empty()||(item=S.top())!='['){
                    cout<<"] mismatched\n";    return false;
                } 
                else   S.pop();     break;
            case '{':S.push(expression[i]);    break; 		// ������ { ѹջ
            case '}': 							// ������ } ����ջ��Ԫ��ƥ��
                if(S.empty()||(item=S.top())!='{'){
                    cout<<"} mismatched\n";    return false;
                } 
                else   S.pop();    break;
        };
		i++;
    }
    if(S.empty()) {
        cout<<"matched\n";    return true;
    } 
    else{
    	while(!S.empty())
        {
        	cout<<S.top()<<" ";
        	S.pop();
	}	
		cout<<" mismatched\n";    return false;
    }
}

 
// ���Ա��ʽ��ֵ
/*
int main()   
{   char x;
	calculator C("12*(6-3.5)/8=");
//	cout<<"input a string:\n";
//	cout<<"��׺���ʽ������"<<C.calculateInfix()<<endl;
	try{

	cout<<"�����׺���ʽ";
	C.printInfix();

	cout<<"������׺���ʽ�Ľ��";
	cout<<C.calculateInfix()<<endl;

	C.infixToPostfix();

	cout<<"�����׺���ʽ";
	C.printPostfix();

	cout<<"�����׺���ʽ�Ľ��";	
	cout<<C.calculatePostfix()<<endl;
	}
	catch(exception &me)
	{
		cout<<me.what();
	}

	cin>>x;
	return 0;
} 
*/

// ����ջ
int main( )   
{	
	linkStack<int> ls;
	seqStack<int> ss;
	testStack(ss);
	testStack(ls);

    long x;  
	cout<<"input a number:\n";
    cin >> x;   
    cout<< "the factioral of "<< x
		<< " is: " << factorial(ls,x)<<endl;  

	match();
	cin>>x;
	return 0;
}  