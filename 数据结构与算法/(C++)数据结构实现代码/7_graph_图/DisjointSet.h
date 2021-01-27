/*--------------------------------------------------------------------*/
#ifndef _UNION_FIND_SET_
#define _UNION_FIND_SET_
#include<cstdlib>
#include <cstring>
class unionFindSet {
	int size;
	int *parent;
public:
	unionFindSet(int s) ;
	~unionFindSet() { if(parent != NULL) delete [] parent;}
	void merge(int root1, int root2);
	int find(int x);
}; 
unionFindSet::unionFindSet(int n){ 
	size = n;
	parent = new int [size];
	memset(parent, -1, sizeof(int)*size); // ���н���˫�׳�ʼ��-1
}
int unionFindSet::find(int x){ 
	if (parent[x] < 0) return x;		// ��parent[x] < 0ʱ��x�������
	return parent[x] = find(parent[x]);	// ·��ѹ��
}
void unionFindSet::merge(int root1, int root2){ 
	root1 = find(root1);				// ����root1������
    root2 = find(root2);				// ����root2������
	if (root1 == root2) return;			// ����ͬһ����������ϲ�
  	if (parent[root1] > parent[root2])	// �����Ƚϴ�С��root2��ģ����
	{ 	parent[root2] += parent[root1];	// root1�鲢��root2��root2��ģ����  
		parent[root1] = root2;			// root1��˫����Ϊroot2
	}
  	else  
	{ 	parent[root1] += parent[root2];  
		parent[root2] = root1;
	}
 } 
#endif
