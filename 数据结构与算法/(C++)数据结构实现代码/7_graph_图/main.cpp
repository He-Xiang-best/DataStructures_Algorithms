#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
#include"graph.h"
#include"adjListGraph.h"
#include"adjMatrixGraph.h"
#include"DisjointSet.h"
#include"priorityQueue.h"
// �������Ϊ�ޱ߱�־���ɸ���ʵ��������ã�����ͼA,B����0���ޱ߱�־
#define INFINITE 0X7FFFFFFF		
#define N 5 // ����Aͼ�Ķ�����
#define M 9 // ����Bͼ�Ķ�����

const char * d1[] = { "A", "B", "C", "D", "E" };
int A[N][N] = {
	//        A  B  C  D  E
	/*A*/     0, 0, 1, 1, 0,
	/*B*/     0, 0, 0, 1, 1,
	/*C*/     1, 0, 0, 1, 1,
	/*D*/     1, 1, 1, 0, 0,
	/*E*/     0, 1, 1, 0, 0, };			// ����ͼ,��ͼ�л����޷���������

const char * d2[] = { "C0", "C1", "C2", "C3","C4","C5","C6","C7","C8" };
int B[M][M] = {
	//C0  C1  C2  C3  C4  C5  C6  C7  C8	
	0, 0, 1, 0, 0, 0, 0, 1, 0,
	0, 0, 1, 1, 1, 0, 0, 0, 0,
	0, 0, 0, 1, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 1, 1, 0, 0,
	0, 0, 0, 0, 0, 1, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 1,
	0, 0, 0, 0, 0, 0, 1, 0, 0 };		// ��ͼΪ��ʾ�γ����ȹ�ϵ�������޻�ͼ�����ڲ�����������	

const char *d3[] = { "V0", "V1", "V2", "V3","V4","V5" };
int C[M][M] = {	
	0, 6, 1, 5, 0, 0,
	6, 0, 5, 0, 3, 0,
	1, 5, 0, 5, 6, 4,
	5, 0, 5, 0, 0, 2,
	0, 3, 6, 0, 0, 6,
	0, 0, 4, 2, 6, 0, };				// ��ͼ���ڲ�����С������	


template <class VertexType, class EdgeType>
void testGraph(graph<VertexType,EdgeType>& g)
{
	cout<<"dfs:    "; g.dfsTraverse();
	cout<<"bfs:    "; g.bfsTraverse();	
	g.printGraph();
}
int main()
{ 
	cout<<"----------------------�����ڽӾ���--------------------\n";
	adjMatrix<char*, int> mg(5,0);		// ʹ��Aͼ,0���ޱ߱�� 
	mg.createGraph((char* const*)d1,(int*)A);
	//adjMatrix<char*, int> mg(9,0);	// ʹ��Bͼ
	//mg.createGraph((char* const*)d2,(int*)B);	// ����Bͼ
	testGraph(mg);

	cout<<"\n----------------------�����ڽӱ�----------------------\n";
	adjList<char*, int> lg(5);			// ʹ��Aͼ,0���ޱ߱��
	lg.createGraph((char* const*)d1,(int*)A);
	//adjList<char*, int> lg(9);		// ʹ��Bͼ
	//lg.createGraph((char* const*)d2,(int*)B);	// ����Bͼ
	testGraph(lg);

	system("pause");
}
