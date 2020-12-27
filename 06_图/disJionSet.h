#pragma once
#include<iostream>
using namespace std;

class unionFindSet {
	int size;
	int* parent;
public:
	unionFindSet(int s);
	~unionFindSet(){ if(parent != NULL) delete[] parent;}
	void merge(int rootl, int root2);
	int find(int x);
};

//���캯������ʼ�����鼯��
unionFindSet::unionFindSet(int n) {
	size = n;
	parent = new int[size];
	memset(parent, -1, sizeof(int) * size); //���н���˫�׳�ʼ��Ϊ��1
}

//���ҽ���������ϲ�ѹ��·�����ݹ���÷���ʱ˳�㽫·���Ͻ���˫����Ϊ����㡣
int unionFindSet::find(int x) {
	if (parent[x] < 0) return x;//��parent[x] < 0ʱ��x�������
	return parent[x] = find(parent[x]);//·��ѹ��
}

//���ݹ�ģ�ϲ��������ϡ�
void unionFindSet::merge(int root1, int root2) {
	root1 = find(root1);//����root1 ������
	root2 = find(root2);//����root2������
	if (root1 == root2) return;//����ͬһ����������ϲ�
	if (parent[root1] > parent[root2]) // �����Ƚϴ�С��root2��ģ����
	{
		parent[root2] += parent[root1];//root1�鲢��root2, root2��ģ����
		parent[root1] = root2;//root1��˫����Ϊroot2
	}
	else {
		parent[root1] += parent[root2];
		parent[root2] = root1;
	}
}
