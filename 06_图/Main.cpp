
//============================================================================
// @FileName     ��Main.cpp
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.12.1
// Description   ��
/*

 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include<cmath>
#include"Graph.h"
#include"adjMatrixGraph.h"
#include"adjListGraph.h"
#include"priorityQueue.h"
#include"disJionSet.h"
using namespace std;

const char* d1[] = { "A","B","C","D","E" };
int A[5][5] = {
    0,0,1,1,0,
    0,0,0,1,1,
    1,0,0,1,1,
    1,1,1,0,0,
    0,1,1,0,0,
};

char * creatGraphV(int n){
    char* v = new char[n];
    char temp;
    cout << "����������" << n << "���㣨�õ������ű�ʾ��" << endl;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v[i] = temp;
    }
    return v;
}

int** creatGraphE(int n)
{
    int VE_num=n;
    cout << "���濪ʼ����ͼ�ıߵĹ�ϵ:" << endl;
    int ** E ;
    int temp;
    cout << "���������붥������ޱߵĹ�ϵ(0-�ޣ�1-��)����������" << endl;
    E = new int* [VE_num];
    for (int i = 0; i < VE_num; i++) {
        E[i] = new int[VE_num];
        for (int j = 0; j < VE_num; j++) {
        cin >> temp;
        E[i][j] = temp;
        }
    }

    return E;
}

template<class VertexType,class EdgeType>
void testGraph(graph< VertexType, EdgeType>& g) {
    cout << "dfs:     "; g.dfsTraverse();
    cout << "bfs:     "; g.bfsTraverse();
    g.printGraph();
}

int main()
{
    /*int n; 
    cout << "�����ȿ�ʼ����ͼ�Ķ��㣬�����м������㣿" << endl;
    cin >> n;
    char* d2=creatGraphV(n);
    int** B = creatGraphE(n);
    */
    cout << "-----------------�����ڽӾ���-----------------"<<endl;
    adjMatrix<char*, int> mg(5, 0);
    //adjMatrix<char*, int> mg2(n, 0);
    mg.createGraph((char* const*)d1, (int*)A);
    //mg2.createGraph((char* const*)d2, (int*)B);
    testGraph(mg);
    cout << "------------------�����ڽӱ�------------------"<< endl;
    adjList<char*, int> lg(5);
    //adjList<char*, int> lg2(n);
    lg.createGraph((char* const*)d1, (int*)A);
    //lg2.createGraph((char* const*)d2, (int*)B);
    testGraph(lg);

    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
