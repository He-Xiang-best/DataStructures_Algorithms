#ifndef _GRAGH_H_
#define _GRAGH_H_
template <class VertexType, class EdgeType> 
class graph {
public:
	int numOfVertex() const { return verNum; }					// ����ͼ�Ķ�����
    int numOfEdge() const { return edgeNum; }					// ����ͼ�ı���
    virtual void createGraph(const VertexType V[],const EdgeType E[])=0; // ����ͼ
    virtual void dfsTraverse()const = 0;						// ������ȱ���
    virtual void bfsTraverse()const = 0;						// ������ȱ���
    virtual bool topSort()const=0;							// ��������
    virtual void prim(EdgeType noEdge) const=0;					// prim�㷨
    virtual void kruskal() const=0; 							// kruskal�㷨
    virtual void printMst()const=0; 							// �����С������
    virtual bool searchEdge(int from, int to) const = 0;			// ���ұ�
    virtual bool insertEdge(int from, int to, EdgeType w) = 0; 	// ����ȨֵΪw�ı�
    virtual bool removeEdge(int from, int to) = 0;				// ɾ����
	virtual void printGraph()const=0;							// ���ͼ
protected:
    struct mstEdge {								// ��С�������ı߽������
        int vex1, vex2;			
        EdgeType weight;							// �ߵ���Ԫ��(ʼ�㣬�յ㣬Ȩֵ)
        bool operator<(const  mstEdge &e) const {  	// ʹ�����ȼ�������Ҫ����<
            return weight < e.weight;
        }
    }*TE;									// ��С�������ı߼�
	int verNum, edgeNum;							// ͼ�Ķ������ͱ���
	bool *visited;									// ���ʱ�־����
};


#endif
