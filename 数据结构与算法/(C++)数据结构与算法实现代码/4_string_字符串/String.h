#ifndef _SEQ_STRING_H_
#define _SEQ_STRING_H_
#include<iostream>
#include <cstring> 
using namespace std;

class outOfRange:public exception {    				// ���ڼ�鷶Χ����Ч��
public:    
   const char* what()const throw()    
   {    return "ERROR! OUT OF RANGE.\n";    } 
};  
class badSize:public exception {    				// ���ڼ�鳤�ȵ���Ч��
public:    
   const char* what()const throw()    
   {    return "ERROR! BAD SIZE.\n";    }  
};

class String
{
public:
	String(const char *str = NULL);					// ���캯��
	String(const String &str);						// �������캯��
	~String(){delete []data;}						// ��������

	int capacity()const{return maxSize;}			// ���洢����
	int size()const{return curLength;}				// ���ַ�������
	bool empty()const{return curLength==0;}			// �п�

	String subStr(int pos,int num)const;			// ��posλ�ÿ�ʼȡ����Ϊn���Ӵ�
	int compare(const String &s) const;				// �Ƚϵ�ǰ�ַ�����s�Ĵ�С,����ֵ����strcmp���
	int bfFind(const String &s, int pos = 0) const;	// ���ص�ģʽƥ���㷨����pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
	String &insert(int pos,const String &s);		// ��posλ�ò����ַ���s
	String &erase(int pos, int num);				// ɾ����pos��ʼ��num���ַ��������޸ĺ���ַ���
	const char* toCharStr() const{ return data; }	// ��ȡ�ַ�����data
	int  kmpFind(const String &t, int pos = 0);			// kmpģʽƥ��
	void  getNext(const String &t,int *next);				// ��ȡnext����
	void  getNextVal(const String&t,int *nextVal);		// ��ȡnextVal����

	bool operator==(const String &str) const;		// ����==���ж������ַ����Ƿ����
	String& operator+(const String &str) ;			// ����+
	String& operator=(const String &str);			// ����=
	char& operator[](int n) const;					// ����[]

	friend istream& operator>>(istream &cin, String &str);	// ���봮
	friend ostream& operator<<(ostream &cout, String &str);	// �����
private:
	char *data;										// �ַ���
	int maxSize;									// ���洢����
	int curLength;									// ���ĳ���
	void resize(int len);							// ��������ռ�
};
int String:: kmpFind(const String &t,int pos){ 
    if(t.curLength == 0)return 0;					// ע�⣺c++�����������С��0������
    if(curLength < t.curLength)return -1;			// ����������Ӵ��̣�ƥ��ʧ��
    int i = 0,j = 0;							// Ŀ�괮��ģʽ����ָ��
    int *next=new int[t.curLength];				// next����
    getNextVal(t,next); 							// Ϊnext���鸳ֵ
    while ( i < curLength  &&  j < t.curLength) {	// �Ƚ϶�Ӧ�ַ�
        if( j == -1 || data[i] == t.data[j])		// ���1��2
            i++,  j++;
        else j = next[j];						// ���3
    }
    delete []next;
    if ( j >= t.curLength)  return (i - t.curLength);
    else  return -1;
}

void  String::getNext(const String &t,int *next){ 
    int i=0,j=-1;
    next[0]=-1; 
    while(i<t.curLength-1){ 
        if((j==-1)||(t[i]==t[j])) {
            ++i, ++j; 
            next[i]=j;
        }
        else  j=next[j];
    }
}

void  String::getNextVal(const String&t,int *nextVal){ 	// ��ģʽ��T��next��������ֵ��������next
    int i=0,j=-1;
    nextVal[0]=-1; 
    while(i<t.curLength-1){ 
        if((j==-1)||(t[i]==t[j])){
            ++i,++j;
            if(t[i]!=t[j]) nextVal[i]=j;		
            else  nextVal[i]=nextVal[j];
        }
        else  j=nextVal[j];
    }
}


/*ע�⣬��ĳ�Ա�����У���һЩ�Ǽ���const���εģ���ʾ��������������ĳ�Ա�����κ��޸ġ�һЩ�������������Ҳ����const���Σ���ʾ�ú�������Ըı����������ֵ��

�� ����ʵ��
����������г�Ա������ʵ�֡�

ͬ�����캯������һ���ַ����������String�ĳ�ʼ����Ĭ�ϵ��ַ�������Ϊ�ա�����ĺ��������в���Ҫ�ٶ��������Ĭ��ֵ����Ϊ�������Ѿ��������ˡ�

���⣬����C����strlen��ʱ����Ҫע���ַ��������Ƿ�Ϊ�գ��Կ�ָ�����strlen�������ڴ����
*/
int String::compare(const String &s) const		// ����ĳ�Ա����ʵ�ֱȽϵ�ǰ�ַ�����s�Ĵ�С������������
{
	int i = 0;   
	while (s.data[i] != '\0'  ||  this->data[i] != '\0' ) 
	{   
		if (this->data[i] > s.data[i])			// this����s
			return 1;  
		else if (this->data[i] < s.data[i])		// thisС��s
			return -1;   
		i++;   
	}   
	if (this->data[i] == '\0' && s.data[i] != '\0')   
		return -1;								// s��ʣ��Ԫ�أ�����this
	else if (s.data[i] == '\0' && this->data[i] != '\0')   
		return 1;								// this��ʣ��Ԫ�أ�����s
	return 0;									// ����ʣ��Ԫ�أ����

	// ����������滻�ɵ���strcmp����������return strcmp(data,s.toCharStr());
}

int String::bfFind(const String &s, int pos) const{
    int i = 0, j = 0;						// Ŀ�괮��ģʽ����ָ��
    if (curLength < s.curLength) 				// �������Ӵ��̣�ƥ��ʧ�� 
        return -1;          			 
    while (i < curLength && j < s.curLength){	
        if (data[i] ==s.data[j])  			// ��Ӧ�ַ����ָ�����
            i++,  j++; 
        else  	{   							// ��Ӧ�ַ������ʱ
            i = i - j + 1;					// ����ָ�����
            j = 0;							// �Ӵ���ͷ��ʼ
        } 
    } 
    if ( j >= s.curLength) 
        return (i - s.curLength); 			// �����Ӵ��������е�λ��
    else return -1; 
}



String & String::insert(int pos,const String &s){
	if (pos > curLength||pos < 0)			// ����λ��pos����
		throw outOfRange();					// ���ؿմ�		

	if(curLength+s.curLength > maxSize)		// �ռ䲻��
		resize(2*(curLength+s.curLength));

	for (int i = curLength; i >= pos; i--)	// �±�i��[curLength..pos]��Χ
		data[i+s.curLength] = data[i];		// ��Ԫ�������ƶ�s.curLength��,����'\0'

	for(int j=0 ;j < s.curLength; j++)		// �洢s���ַ�
		data[pos+j] = s.data[j];

	curLength += s.curLength;				// �޸Ĵ��ĳ���
	return *this;
}

String & String::erase(int pos, int num){
	if (pos < 0 || pos > curLength-1)			// �Ϸ���ɾ��λ��Ϊ[0..curLengt-1] 
		throw outOfRange();		

	if(num < 0)throw badSize();	

	if(num > curLength - pos)					// num���ڴ�pos��ʼ����βԪ�ظ���
        num = curLength-pos;					// �޸�num��ֵ

    for (int j = pos+num; j <=curLength ; j++)	// �±�j+1��[pos+num..curLength]��Χ
        data[j-num] = data[j] ;					// ��Ԫ����ǰ�ƶ�num��,����'\0'

    curLength -= num; 							// �޸Ĵ��ĳ���
	return *this;
}

String String::subStr(int pos,int num)const{	
    int i;  
    String tmp(""); 												
    if (pos > curLength||pos < 0)				// pos�ĺϷ���Χ��[0.. curLength]
        throw outOfRange();					// �׳��쳣

	if(num < 0)throw badSize();	

    if(num > curLength - pos)					// num���ڴ�pos��ʼ����βԪ�ظ���
        num = curLength-pos;					// �޸�num��ֵ

    delete []tmp.data; 						// �ͷ�tmpԭ���Ĵ洢�ռ� 
    tmp.maxSize = tmp.curLength = num; 	
    tmp.data = new char[num+1]; 				// �����СΪnum+1�Ĵ洢�ռ�

    for (i =0; i < num; i++)					// ����Ϊnum���Ӵ���ֵ��tmp
        tmp.data[i] = data[pos+i];  
    tmp.data[i] = '\0';  					
    return tmp; 
}


 String::String(const char *str)				// ���캯��
{
	maxSize = 2*strlen(str);
	data = new char[maxSize + 1];
	strcpy(data,str);
	curLength = strlen(data);	 
}

String::String(const String &str)				// �������캯��
{
	maxSize = str.maxSize;
	data = new char[maxSize + 1];
	strcpy(data, str.toCharStr());
	curLength = str.curLength;	 
}

//�����ַ����������㣬�������᷵��һ���µ��ַ�����

String& String::operator+(const String &str)	// ����+
{
	if( maxSize < curLength+str.size() )
		resize(2*(curLength+str.size()));	

	strcat(data,str.data);
	curLength += str.curLength;	 
	return *this;
}

void String::resize(int len)
{
		maxSize = len;
		char *temp = new char[maxSize + 1];
		strcpy(temp,data);
		delete []data;
		data=temp;
}
//�����ַ�����ֵ���㣬��������ı�ԭ���ַ�����ֵ��Ϊ�˱����ڴ�й¶�������ͷ���ԭ��������ڴ�����������һ���ʵ���С���ڴ����µ��ַ�����

String& String::operator=(const String &str)	// ����=
{
	if (this == &str)	return *this;

	delete []data;
	maxSize = str.maxSize;
	data = new char[maxSize + 1];
	strcpy(data, str.toCharStr());
	curLength = str.curLength;	 
	return *this;
}

bool String::operator==(const String &str) const// ����==
{
	if (curLength!= str.curLength)	return false;
	return strcmp(data, str.data) ? false : true;
}
//�����ַ��������������������һ���򵥵Ĵ�����������̫���׳��쳣��

inline char& String::operator[](int n) const	// ����[]
{
	if (n >= curLength) throw outOfRange();		// ������
	else return data[n];
}

//���������������������һ���㹻����ڴ�������������ַ������ٽ������ַ��������ɡ�����һ���Ƚϼ����ص�ʵ�֣����Ϻܶ�ֱ��is>>str.data�ķ����Ǵ���ģ���Ϊ����ȷ��str.data�Ĵ�С�ͼ���������ַ����Ĵ�С��ϵ��

istream& operator>>(istream &cin, String &str)	// ����
{
	char *temp=new char[1000];					// ����һ���ڴ�
	cin >> temp;
	str.maxSize = 2*strlen(temp);
	str.data = new char[str.maxSize + 1];
	strcpy(str.data,temp);
	str.curLength=strlen(temp);
	delete []temp;
	return cin;
}
//��������������ֻ��򵥵�����ַ��������ݼ��ɡ�ע��Ϊ��ʵ������cout<<a<<b�����������������Ҫ��������������������Ҳ�����ơ�

ostream& operator<<(ostream &cout, String &str)	// ���
{
	cout << str.data;
	return cout;
}

#endif
