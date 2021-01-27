//#include <string.h>  
#include <assert.h>
#include "String.h"
//using namespace std;
 
class seqString {  
private: 
	char *str;								// ��̬���䴮������ռ�
	int curLen;								// curLen�Ǵ��ĵ�ǰ����
	friend std::ostream& operator <<(std::ostream &out,seqString &s);
	friend int strcmp(seqString *s1, seqString *s2);
public: 
	seqString(char *s);						// ���캯��
	seqString(const seqString & t);				// �������캯��
	~seqString();								// ��������
	int length()const;						// �󴮳���
	seqString& strCpy(const seqString &s);			// ����s���Ƶ�����
	seqString subStr(int pos,int n );			// ȡ�Ӵ�
	seqString& strCat(const seqString &s);		// �ַ�������
	int compare(const seqString &s);			// �ַ����Ƚ�
	seqString& operator=(const seqString &s);		// ���ظ�ֵ����=������ͬcopy
	char& operator[](int n);				// �����±�����[]
	seqString& replace(int i,int j,const seqString &t); // �����дӵ�i���ַ���ʼ��j���ַ���t���滻
};

seqString::seqString(char *s="") {// ���캯��
    int i=0;
    curLen=0;
    while(s[curLen]!='\0') curLen++;		// curLen = strlen(s) ;  
    str = new char [curLen+1]; 
    assert(str != '\0');					// �����ٶ�̬���򲻳ɹ�ʱ�������쳣�˳� 
    while(s[i]!='\0') {					// ��s��ֵ��str
        str[i]=s[i];
        i++;
    }									// strcpy(str, s);
    str[i]='\0';
}


seqString::seqString(const seqString & s) {		// �������캯��
    int i=0;
    curLen=s.curLen; 
    str = new char [curLen+1]; 
    assert(str != '\0');					// �����ٶ�̬���򲻳ɹ�ʱ�������쳣�˳� 
    while(s.str[i]!='\0') {
        str[i]=s.str[i];
        i++;
    }
    str[i]='\0';
} 

	seqString & seqString::strCat(const seqString & s){		
		int i=0,j=0;
		seqString temp(*this);
		curLen+=s.curLen; 
		delete []str;
		str = new char[curLen+1]; 
		assert(str != '\0');	// �����ٶ�̬���򲻳ɹ�ʱ�������쳣�˳� 
		while(temp.str[i]!='\0')
			str[i]=temp.str[i++];		
		while(s.str[j]!='\0')
			str[i++]=s.str[j++];
		str[i]='\0';
		return *this;
	} 



	seqString& seqString::replace(int pos,int num,const seqString &t){
	seqString temp(*this);
	int i=0,j=0;
	if(pos<1 || num<0){
	//	cout<<"��������"<<endl;	//���������û���ĳ��ȵĺϷ���
		return *this;
	} 
	curLen+=t.curLen-j; 
	delete []str;
	str = new char[curLen+1]; 
	assert(str != '\0');	// �����ٶ�̬���򲻳ɹ�ʱ�������쳣�˳� 

	while(i<pos-1)
		str[i]=temp.str[i++];
	
	while(j<t.curLen)
		str[i++]=t.str[j++];
	
	j=pos+num-1;
	while(temp.str[j]!='\0')
		str[i++]=temp.str[j++];
	str[i]='\0';
	return *this;
}

	seqString::~seqString() 
	{	
		delete []str;
		curLen=0;
	} 

	int seqString::length()const						//��Ҫ��const������operater=�е�const����
	{
		return  curLen-1;
	}


	seqString & seqString::operator=(const seqString &s)	{	//����=
	int i=0;
		delete []str;
		curLen=s.length();
		str=new char[curLen+1];
		while(s.str[i]!='\0'){
		str[i]=s.str[i];
			i++;
		}
		str[i]='\0';
		return *this;
	}

	seqString& seqString::strCpy(const seqString &s)	{		// ����s���Ƶ�����
	int i=0;
		delete []str;
		curLen=s.curLen;
		str=new char[curLen+1];
		assert(str != '\0');					// �����ٶ�̬���򲻳ɹ�ʱ�������쳣�˳� 
		while(s.str[i]!='\0'){
			str[i]=s.str[i];
			i++;
		}
		str[i]='\0';
		return *this;
	}

	char& seqString::operator[](int n)					//����[]
	{
		return str[n];
	}

	std::ostream& operator <<(std::ostream &out,seqString &s) //����<<   ��using namespace std;���ȥ��std
	{
		out<<s.str;							
		return out;
	}

seqString seqString::subStr(int pos,int n){ 	// ���±�Ϊpos��λ�ÿ�ʼ����ȡ����Ϊn���Ӵ�
    int i;  
    seqString tmp(""); 												
    if (pos >= curLen||pos < 0)			// ��ʼ�±�pos����
        return tmp;						// ���ؿմ�		
    if(n > curLen - pos)					// n���ڴ�pos��ʼ����βԪ�ظ���
        n=curLen-pos;					// �޸�n��ֵ

    delete []tmp.str; 					// �ͷ�ԭ���Ĵ洢�ռ� 
    tmp.curLen= n; 
    tmp.str = new char[n+1]; 
    assert(tmp.str != NULL) ;				// �����ٶ�̬���򲻳ɹ�ʱ�������쳣�˳�
    for (i =0; i < n; i++)
        tmp.str[i] = str[pos+i];  		// pos��ʼ����Ϊn���Ӵ���ֵ��tmp	
    tmp.str[i] = '\0';  					
    return tmp; 
	}


	int seqString::compare(const seqString &s)			// ����ĳ�Ա����ʵ�ֱȽϵ�ǰ�ַ�����s�Ĵ�С������������
	{	int i = 0;   
		while (s.str[i] != '\0'  &&  this->str[i] != '\0' ) 
		{   
			if (this->str[i] > s.str[i])			// this����s
				return 1;  
			else if (this->str[i] < s.str[i])		// thisС��s
				return -1;   
			i++;   
		}   
		if (this->str[i] == '\0' && s.str[i] != '\0')   
			return -1;								// s��ʣ��Ԫ�أ�����this
		else if (s.str[i] == '\0' && this->str[i] != '\0')   
			return 1;								// this��ʣ��Ԫ�أ�����s
		return 0;									// ����ʣ��Ԫ�أ����

	}
	  
	int strcmp(seqString *s1, seqString *s2)				// ����Ԫ����ʵ���ַ����Ƚϣ�ָ��������
	{   
		int i = 0;   
		while (s2->str[i] != '\0'  ||  s1->str[i] != '\0' ) 
		{   
			if (s1->str[i] > s2->str[i])			// s1����s2
				return 1;   
			else if (s1->str[i] < s2->str[i])		// s1С��s2
				return -1;   
			i++;   
		}   
		if (s1->str[i] == '\0' && s2->str[i] != '\0')   
			return -1;								// s2��ʣ��Ԫ�أ�����s1
		else if (s2->str[i] == '\0' && s1->str[i] != '\0')   
			return 1;								// s1��ʣ��Ԫ�أ�����s2
		return 0;									// ����ʣ��Ԫ�أ����
	} 
 
