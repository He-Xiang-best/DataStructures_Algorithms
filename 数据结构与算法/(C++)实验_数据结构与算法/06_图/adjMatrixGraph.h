#pragma once
#include<queue>
#include<iostream>
#include"priorityQueue.h"
#include"disJionSet.h"
#include"Graph.h"
using namespace std;

template <class VertexType, class EdgeType>                         // VertexType��������ͣ�EdgeType�ߣ��򻡣�������
class adjMatrix :public graph<VertexType, EdgeType> {
private:
    VertexType* vertexs;  	                                        // ��������
    EdgeType** edges; 		                                        // �ڽӾ���
    EdgeType  noEdge; 		                                        // �ޱ߱�־
    void  dfs(int start) const;                                     // ��start�������������ȱ���ͼ
public:
    adjMatrix(int size, EdgeType noEdgeFlag);
    ~adjMatrix();
    void createGraph(const VertexType V[], const EdgeType E[]);
    void printGraph()const; 		                                // ���ͼ
    bool searchEdge(int from, int to) const; 		                // ���ұ�
    bool insertEdge(int from, int to, EdgeType w); 	                // ����һ����
    bool removeEdge(int from, int to); 	                            // ɾ��һ����
    void dfsTraverse() const; 		                                // ����˽��dfs������ȱ���ͼ
    void bfsTraverse() const; 		                                // ������ȱ���ͼ
    bool topSort() const;		                                    // ��������
    void prim(EdgeType noEdge) const; 	                            // prim�㷨����С������
    void kruskal() const; 		                                    // kruskal�㷨����С������
    void printMst()const; 		                                    // �����С������
    void floyd() const;			                                    // �����������·��
    void printFloyed(EdgeType** D, int** pre)const;                 // ��������������·��
};

//���캯��
template <class VertexType, class EdgeType>
adjMatrix<VertexType, EdgeType>::adjMatrix(int size, EdgeType noEdgeFlag) {
    this->verNum = size;  this->edgeNum = 0;  noEdge = noEdgeFlag;
    this->vertexs = new VertexType[this->verNum]; 	                            // ��������
    edges = new EdgeType * [this->verNum]; 		                        // �ڽӾ���
    for (int i = 0; i < this->verNum; i++) {
        edges[i] = new EdgeType[this->verNum];
        for (int j = 0; j < this->verNum; ++j)
            edges[i][j] = noEdge; 		                            // �ڽӾ����ó�ֵ
    }
    this->visited = new bool[this->verNum];		                                // ���ʱ�־����
    this->TE = new typename graph<VertexType,EdgeType>::mstEdge[this->verNum - 1];// ��С�������ı߼�
}

//��������
template <class VertexType, class EdgeType>
adjMatrix<VertexType, EdgeType>::~adjMatrix() {
    delete[] vertexs;
    for (int i = 0; i < this->verNum; i++)
        delete[] edges[i];
    delete[] edges;
    delete[] this->visited;
    delete[] this->TE;
}

//����ͼ���Ƿ���ڴ�from��to�ıߣ�����from��to�Ƕ�����vertexs�����е��±ꡣ
template <class VertexType, class EdgeType>
bool adjMatrix<VertexType, EdgeType>::searchEdge(int from, int to) const {
    if (from < 0 || from > this->verNum - 1 || to < 0 || to > this->verNum - 1) // �±�Խ��
        return false;
    if (edges[from][to] == noEdge)                                  // �����ڸñ�
        return false;
    else  return true;
}

/*
��ͼ�в����from��to�ıߣ�����from��to�Ƕ�����vertexs�����е��±ꡣ
�㷨������
(1) ���ñ��Ѿ�������ȨֵΪwʱ������false��
(2) ���ñ߲�����ʱ���øñ�Ϊw���������������󣬷���true��
(3) ���ñ��Ѿ�������Ȩֵ������wʱ�����±���ȨֵΪw������true��
*/
template <class VertexType, class EdgeType>
bool adjMatrix<VertexType, EdgeType>::insertEdge(int from, int to, EdgeType w) {
    if (from < 0 || from > this->verNum - 1 || to < 0 || to > this->verNum - 1)
        return false; 		        // �±�Խ��
    if (edges[from][to] == w)	    // �Ѿ����ڴ�from��toȨֵΪw�ı�
        return false;
    if (edges[from][to] == noEdge)	// ��from��toԭ��û�б�
        ++this->edgeNum;			        // ��������
    edges[from][to] = w;		    // �ñ���ȨֵΪw
    return true;
}

//ɾ����from��to�ıߣ�����from��to�Ƕ�����vertexs�����е��±ꡣ
template <class VertexType, class EdgeType>
bool adjMatrix<VertexType, EdgeType>::removeEdge(int from, int to) {
    if (from < 0 || from > this->verNum - 1 || to < 0 || to >this->verNum - 1)
        return false; 			        // �±�Խ��
    if (edges[from][to] == noEdge) 		// �ñ߲�����
        return false;
    edges[from][to] = noEdge; 		    // ��Ϊ�ޱ߱�־
    --this->edgeNum; 				            // ��������
    return true;
}

//����ͼ������VΪ�������飬EΪ������ά���ڽӾ���
template <class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::createGraph(const VertexType V[], const EdgeType E[]) {
    int i, j;
    for (i = 0; i < this->verNum; i++)
        this->vertexs[i] = V[i];
    for (i = 0; i < this->verNum; i++) {
        for (j = 0; j < this->verNum; j++) {
            if (E[i * this->verNum + j] > 0)
                insertEdge(i, j, E[i * this->verNum + j]);
        }
    }
}

//���ͼ
template <class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::printGraph()const {
    int i, j;
    for (i = 0; i < this->verNum; i++) {
        cout << this->vertexs[i] << ":";
        for (j = 0; j < this->verNum; j++) {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}

//˽�еݹ麯��dfs�����ʴӶ���start�����ܹ�������ȱ����������ж��㡣
template <class VertexType, class EdgeType>
void  adjMatrix<VertexType, EdgeType>::dfs(int start) const {
    int i;
    cout << this->vertexs[start] << " "; 		// ���ʶ���v
    this->visited[start] = true; 			    // �÷��ʱ�־Ϊtrue
    for (i = 0; i < this->verNum; i++) {	    // ѡȡstart��δ�����ʵ��ڽӵ�
        if (edges[start][i] != noEdge && this->visited[i] == false)
            dfs(i); 			        // ��i��������������ȱ���ͼ
    }
}

//������ȱ���ͼ�Ĺ����ӿں�����
template <class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::dfsTraverse() const {
    int i, count = 0;			        // count����ͳ������ͼ��ͨ�����ĸ���
    for (i = 0; i < this->verNum; i++)
        this->visited[i] = false;		        // �÷��ʱ�־Ϊfalse
    for (i = 0; i < this->verNum; i++) {
        if (!this->visited[i]) { 		        // ѡȡһ��δ���ʹ��Ľ�����dfs
            dfs(i);			            // ����ͼ����ͨͼ��ֻ����dfsһ��
            count++;
        }
    }
    cout << endl;
    cout << "����ͼ��ͨ��������Ϊ��" << count << endl;
}

template <class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::bfsTraverse()const {
    int v, i, j, count = 0;		        // count��ͳ����ͨ��������
    queue<int> Q;
    for (i = 0; i < this->verNum; i++) 	    // �÷��ʱ�־Ϊfalse
        this->visited[i] = false;
    for (i = 0; i < this->verNum; i++) {
        if (this->visited[i] == true) continue;
        cout << this->vertexs[i] << ' ';  	// ���ʶ���i
        this->visited[i] = true; 		        // �÷��ʱ�־Ϊtrue
        Q.push(i);	count++;
        while (!Q.empty()) {
            v = Q.front();  Q.pop();	// ����v����
            if (this->visited[v] == false) {
                for (j = 0; j < this->verNum; ++j) {
                                        // ���Ҷ���vδ�����ʵ��ٽӵ�
                    if (edges[v][j] != noEdge && this->visited[j] == false) {
                        cout << this->vertexs[j] << ' '; // ���ʶ���j
                        this->visited[j] = true; // �÷��ʱ�־Ϊtrue
                        Q.push(j);
                    }
                }
            }
        }
    }
    cout << endl;
}

//prim�㷨�����·��
template <class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::prim(EdgeType noEdge) const {
    struct Dist {
        int  adjVex;			                // ��С���۱������Ķ�����
        EdgeType  lowCost;		                // ��С����
    } *D = new Dist[this->verNum];
    EdgeType minCost;
    int u, i, j, count = 0;
    for (i = 0; i < this->verNum; ++i) {
        this->visited[i] = false;  D[i].lowCost = noEdge;
    }
    u = 0;  this->visited[u] = true;
    for (i = 1; i < this->verNum; ++i) {		        // ѡ��һ����u��U���Ϻ�
        for (j = 0; j < this->verNum; ++j) 	        // ����u�����Ķ����Dֵ
            if (!this->visited[j] && edges[u][j] != noEdge) {
                if (edges[u][j] < D[j].lowCost) {
                    D[j].lowCost = edges[u][j];	// ����lowcost
                    D[j].adjVex = u; 		    // ����adjVex 
                }
            }
        minCost = noEdge;
        for (j = 0; j < this->verNum; ++j)		    // ��V-U����lowCost��С����u
            if (D[j].lowCost < minCost) {
                minCost = D[j].lowCost; u = j;
            }
        this->TE[count].vex1 = D[u].adjVex; 		    // ������С��������һ����
        this->TE[count].vex2 = u;
        this->TE[count++].weight = D[u].lowCost;
        D[u].lowCost = noEdge;			        // ����u�Ѳ���U����
        this->visited[u] = true;
    }
    delete[] D;
}

//kruskal�㷨����С������
template <class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::kruskal() const {
    typename graph<VertexType, EdgeType>::mstEdge e{};
    int count = 0;
    unionFindSet S(this->verNum);
    priorityQueue< typename graph<VertexType, EdgeType>::mstEdge> Q;
    for (int i = 0; i < this->verNum; ++i) {          // ��ͼ�еı��������ȼ�����
        for (int j = i + 1; j < this->verNum; j++)	//j=i+1��ʼ����ֹ�ظ����
            if (edges[i][j] != noEdge) {
                e.vex1 = i;  e.vex2 = j;  e.weight = edges[i][j];
                Q.enQueue(e);
            }
    }
    while (count < this->verNum - 1) {	            // ѡ��verNum-1����
        e = Q.deQueue();		                // �����ȼ����г���һ����
        int u = S.find(e.vex1); 	            // ���Ҷ���vex1�����Ӽ�
        int v = S.find(e.vex2); 	            // ���Ҷ���vex2�����Ӽ�
        if (u != v) {							// ���ϵ��������㲻����ͬһ��ͨ����
            S.merge(u, v); 	                    // �ϲ�u��v�����Ӽ�����ͨ������
            this->TE[count++] = e;		            // ������С�������ϵ�һ����
        }
    }
}

//��������
template <class VertexType, class EdgeType>
bool adjMatrix<VertexType, EdgeType>::topSort() const {
    queue<int> Q;
    int i, j, curNode, count = 0, * inDegree = new int[this->verNum];
    for (i = 0; i < this->verNum; i++)
        inDegree[i] = 0;
    for (i = 0; i < this->verNum; i++)
        for (j = 0; j < this->verNum; j++)        // �����ڽӾ����󶥵����
            if (edges[i][j] != noEdge)  ++inDegree[j];
    for (i = 0; i < this->verNum; i++)
        if (inDegree[i] == 0)
            Q.push(i);
    while (!Q.empty()) {
        curNode = Q.front();  Q.pop();      // ����һ�����Ϊ0�Ķ���
        cout << this->vertexs[curNode] << ' ';    // ����ö���
        count++;			                // ������+1
        for (j = 0; j < this->verNum; ++j) {      // �ڽӵ���ȼ�1	
            if (edges[curNode][j] != noEdge)
                if (--inDegree[j] == 0)
                    Q.push(j); 	            // ���Ϊ0�Ķ��������
        }
    }
    cout << endl;
    if (count == this->verNum)
        return true; 		                // ���ȫ�����㣬��������ɹ�
    return false; 		                    // ������ͼ�л�����������ʧ��
}

//�����������·��  
template <class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::floyd() const {
    EdgeType** D = new EdgeType * [this->verNum];
    int** pre = new int* [this->verNum];
    int i, j, k;
    for (i = 0; i < this->verNum; ++i) {
        D[i] = new EdgeType[this->verNum];
        pre[i] = new int[this->verNum];
        for (j = 0; j < this->verNum; ++j) {
            D[i][j] = (i == j) ? 0 : edges[i][j];
            pre[i][j] = (edges[i][j] == noEdge) ? -1 : i;
        }
    }
    printFloyed(D, pre);
    cout << "---------------------��ʼ---------------------" << endl;
    //��������
    for (k = 0; k < this->verNum; ++k) {
        for (i = 0; i < this->verNum; ++i) {
            for (j = 0; j < this->verNum; ++j)
                if (D[i][k] != noEdge && D[k][j] != noEdge && D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    pre[i][j] = pre[k][j];
                }
        }
     printFloyed(D, pre);
     cout << "---------------------------------------------" << endl;
    }
    //printFloyed(D, pre);
    for (i = 0; i < this->verNum; ++i) {
        delete[]D[i];
        delete[]pre[i];
    }
    delete[]D;
    delete[]pre;
}

//��������������·��
template <class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::printFloyed(EdgeType** D, int** pre) const {
    int i, j;
    cout << "shortest path��\n";
    for (i = 0; i < this->verNum; ++i) {
        for (j = 0; j < this->verNum; ++j)
            cout << D[i][j] << '\t';
        cout << endl;
    }
    cout << "precursor of vertex��\n";
    for (i = 0; i < this->verNum; ++i) {
        for (j = 0; j < this->verNum; ++j)
            cout << pre[i][j] << '\t';
        cout << endl;
    }
}

template<class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::printMst() const
{   
    for (int i = 0; i < this->verNum - 1; i++) {
        cout << '(' <<vertexs[this->TE[i].vex1] << ','
            <<vertexs[this->TE[i].vex2] << ','
            << this->TE[i].weight << ')';
        cout << endl;
    }
}
