#include <cstdlib>    
  
#include <iostream>    
#include "String.h"    
#include <cstring>   
using namespace std;  
/* 
int index(seqString &T,seqString &P);   
int main(int argc, char *argv[])   
{  
	char *s = "how are you ?";   
      
	seqString*t1 = new seqString(s); 
	seqString*t2 = new seqString("friend");
	//cout<<(*t1)<<"��ǰ������"<<t1->length()<<endl;   
	t1->replace(13,1,*t2);
	cout<<(*t1)<<"��ǰ������"<<t1->length()<<endl;   

	//cout <<t1->subStr(0,6)<< endl;   // ȡ�Ӵ�

	seqString t3("how");
	seqString t4="abc";
	seqString t5("");
	cout << t3<< endl;  
	
	//t3.strCpy(t5.strCpy("how r u ?"));
	//t3.strCat(t4);  

	//cout<<"t3:"<<t3<<",t4:"<<t4<<t3.length()+t4.length()<<endl;
										
	//cout << strcmp(t1,t2)<<"  "<<t1->compare(*t2)<<endl;	// �ַ����Ƚ�
	
	cout <<index(t3, *t2)<<endl;					// �Ӵ���λ

    system("PAUSE");   
    return EXIT_SUCCESS;   
}   

// �����Ӵ�T������S�е�λ�ã���T����S���Ӵ��򷵻�0��index������ĳ�Ա������
	int index(seqString &S,seqString &T) {			// ���ص�ģʽƥ���㷨
    int i = 0;							// Ŀ�괮�����������±���� 
    int j = 0;							// ģʽ�����Ӵ������±���� 
    int sLen = S.length();				// �������� 
    int tLen = T.length();				// �Ӵ����� 
    if  (sLen < tLen) 					// ���Ŀ���ģʽ�̣�ƥ���޷��ɹ� 
        return 0;          			 
    while (i < sLen && j < tLen)  {		// �����Ƚ϶�Ӧ�ַ�����ʼƥ�� 
        if (S[i] ==T[j])  
            i++,  j++; 
        else  	{   						// ��Ӧ�ַ������ʱ������ָ����ݣ��Ӵ���ͷ��ʼ
            i = i - j + 1;  
            j = 0; 
        } 
    } 
    if ( j >= tLen) 
        return (i - tLen+1); 				// �����Ӵ��������е�λ��
    else return 0; 
}
*/
int main(int argc, char *argv[])   
{  
	const char *s = "how are you ?";   
      
	String*t1 = new String(s); 
	String*t2 = new String("friend");

	cout<<(*t1)<<"��ǰ������"<<t1->size()<<",capacity="<<t1->capacity()<<endl; 
	
	String ss = t1->subStr(0,5);
	cout <<"substr=";
	cout<<ss;
	cout<< endl;   // ȡ�Ӵ�

	String t3("");
	String t4=" you!";

	cout << t3<<"��t1�е�һ�γ��ֵ�λ���ǣ�"<<t1->bfFind(t3)<<endl;
	cout << t3<<"��t1�е�һ�γ��ֵ�λ���ǣ�"<<t1->kmpFind(t3)<<endl;

	cout<<*t1<<"��"<<*t2<<t1->compare(*t2)<<endl;//�Ƚϵ�ǰ�ַ�����s�Ĵ�С,compare������>ʱ����1��<ʱ����-1��==ʱ����0 
	cout<<t4<<"��"<<t3<<t4.compare(t3)<<endl;//�Ƚϵ�ǰ�ַ�����s�Ĵ�С,compare������>ʱ����1��<ʱ����-1��==ʱ����0 
	cout<<t3<<"��"<<t3<<t3.compare(t3)<<endl;//�Ƚϵ�ǰ�ַ�����s�Ĵ�С,compare������>ʱ����1��<ʱ����-1��==ʱ����0 

	cout<<t3.insert(0,*t1);
	cout<<"��ǰ������"<<t3.size()<<",capacity="<<t3.capacity()<<endl; 	//  ��posλ�ò����ַ���s
	cout<<t1->erase(3,0)<<endl;//ɾ��pos��ʼ��num���ַ��������޸ĺ���ַ���
	t3=t3+t4;

	cout<<t3[0]<<endl;

    system("PAUSE");   
    return EXIT_SUCCESS;   
}
