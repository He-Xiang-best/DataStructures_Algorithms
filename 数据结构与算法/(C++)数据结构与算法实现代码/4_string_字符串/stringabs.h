#ifndef _STRING_ABSTRACT_TYPE_H_
#define _STRING_ABSTRACT_TYPE_H_
class stringAbstractType
{
public:
	virtual int capacity()const=0;			// ���洢����
	virtual int size()const=0;				// ���ַ�������
	virtual bool empty()const=0;		// �п�
	virtual stringAbstractType subStr(int pos,int num)const=0;			// ��posλ�ÿ�ʼȡ����Ϊn���Ӵ�
	virtual int compare(const stringAbstractType &s) const=0;				// �Ƚϵ�ǰ�ַ�����s�Ĵ�С
	virtual int bfFind(const stringAbstractType &s, int pos = 0) const=0;	// BF��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
	virtual stringAbstractType &insert(int pos,const stringAbstractType &s)=0;		// ��posλ�ò����ַ���s
	virtual stringAbstractType &erase(int pos, int num)=0;				// ɾ����pos��ʼ��num���ַ��������޸ĺ���ַ���
	virtual ~stringAbstractType(){};									// ��������
};
#endif