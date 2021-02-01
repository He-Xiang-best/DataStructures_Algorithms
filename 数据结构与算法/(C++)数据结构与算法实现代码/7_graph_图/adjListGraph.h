#ifndef _ADJ_LIST_GRAGH_H_
#define _ADJ_LIST_GRAGH_H_
#include "graph.h"
#include "disjointset.h"
#include "priorityqueue.h"
template <class VertexType, class EdgeType>
class adjList :public graph<VertexType,EdgeType> {
private:
    struct edgeNode {							// �߱�������
        int to; 								// �ߵ��յ��ţ��ڶ��߱��е��±꣩
        EdgeType weight;  						// ���ϵ�Ȩֵ
        edgeNode *next; 							// ָ����һ���߱���
        edgeNode(){ }							// �޲ι��캯��
        edgeNode(int t, EdgeType w, edgeNode *n = NULL){
            to = t; 	weight = w; 	next = n;
        }
    };
    struct verNode{								// ����������
        VertexType vertex;  						// ������Ϣ
        edgeNode *firstEdge;  					// ָ���һ���ڽӵ��ָ��
        verNode(edgeNode *h = NULL)  { firstEdge = h; }
    }; 
    verNode *verList;							// �����
    int *topOrder;								// �����������У�������ؼ�·��
    void  dfs(int start) const;					// ��start�Ŷ������������ȱ���ͼ
public:
    adjList(int size);
    ~adjList();
    void createGraph(const VertexType V[],const EdgeType A[]);
    void printGraph()const;						// ���ͼ
    bool searchEdge(int from, int to) const; 		// ���ұ�
    bool insertEdge(int from, int to, EdgeType w); 	// ����һ����
    bool removeEdge(int from, int to); 			// ɾ��һ����
    void dfsTraverse() const;						// ����˽��dfs������ȱ���ͼ
    void bfsTraverse() const; 					// ������ȱ���ͼ
    bool topSort() const; 						// ��������
    void prim(EdgeType noEdge) const; 				// prim�㷨����С������
    void kruskal() const; 						// kruskal�㷨����С������
    void printMst()const; 						// �����С������
    bool criticalPath()const;						// �ؼ�·���㷨
    bool dijkstra(int start, EdgeType noEdge) const;	// ��Դ�����·��
    void printDijPath(int from, int to, int pre[]) const;	// ���Դ�㵽������������·��
};

template <class VertexType, class EdgeType>
bool adjList<VertexType, EdgeType>::dijkstra(int start, EdgeType noEdge) const{ 
    if (start < 0 || start > this->verNum - 1 )			// Դ���±�Խ��
        return false; 
    EdgeType *D = new EdgeType[this->verNum];			// ��¼������������·���ĳ���
    int *pre = new int[this->verNum];					// ��¼���·�������һ��ǰ��
    edgeNode *p;
    EdgeType min;
    int i, j, k;
    for (i = 0; i< this->verNum; ++i) {					// ��ʼ��
        this->visited[i] = false;  D[i] = noEdge;  pre[i]=-1;
    } 
    D[start] = 0;  pre[start] = start;				// Դ��start�������·��������Ϊ0
    min = D[start];  k = start;    

    for (i = 1; i < this->verNum; ++i) {
        this->visited[k] = true; 	
        // k����S���󣬴�start�����ɾ���k��ˢ��start��k���ڽӵ�����·������
        for (p = verList[k].firstEdge; p != NULL; p = p->next) 
            if (!this->visited[p->to] && D[p->to] > min + p->weight) {
                D[p->to] = min + p->weight;
                pre[p->to] = k;   
            }
		for (int x = 0; x< this->verNum; ++x) 					// ��ʼ��
			cout<<D[x]<<","<<pre[x]<<","<<this->visited[x]<<"  " ;

        min = noEdge; k = start;
        // ��ȡ��start�����ܹ������·�����������δ�����ʹ��Ķ���s
        for (j = 0; j < this->verNum; ++j)
            if (!this->visited[j] && D[j] < min) { 
                k = j;					
                min = D[k];    
            }
        if(k != start){
            printDijPath(start, k, pre);			// ���start��k�����·��
            cout<<" : "<<D[k] << endl;
        }
    }
    delete  []D;
    delete  []pre;
    return  true; 
}



template <class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::printDijPath(int from, int to, int pre[]) const{  
	if (from == to) {
		cout << verList[from].vertex ;
		return;
	}
    printDijPath(from, pre[to], pre);
    cout << "->" << verList[to].vertex ;
} 

template <class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::printGraph()const{
    int i;      
    for (i = 0; i<this->verNum ; i++) {
		cout<<verList[i].vertex<<":";
        edgeNode *p = verList[i].firstEdge;
        while (p != NULL){						// ���Ҷ���vδ�����ʵ��ٽӵ�      
			cout << verList[p->to].vertex <<","<<p->weight<< ' ';	// ���ʶ���p->to
            p = p->next;
        }
		cout<<endl;
    }
}

template <class VertexType, class EdgeType>
bool adjList<VertexType, EdgeType>::criticalPath( ) const {     
    if(topSort() == false) return false;
    EdgeType *eVetex = new  EdgeType[this->verNum];   	// ��������翪ʼʱ������  
    EdgeType *lVetex = new  EdgeType[this->verNum];   	// ���������ʼʱ������  
    EdgeType eArc; 								// ������翪ʼʱ��
    EdgeType lArc; 								// �������ʼʱ��
    int i,k=0;
    edgeNode *p;
    for(i=0; i<this->verNum; ++i) 
        eVetex[i] = 0;							// eVetex��ʼ��Ϊ0 
    for(i=0; i<this->verNum; ++i){  
        int curNode = topOrder[i];  				// ���������м���eVetex 
        for (p = verList[curNode].firstEdge; p != NULL; p = p->next){  
            if( eVetex[p->to] < eVetex[curNode] + p->weight ) 
                eVetex[p->to] = eVetex[curNode] + p->weight;
        }  
    }  
    for(i=0; i<this->verNum; ++i)
        lVetex[i] = eVetex[this->verNum-1];      			// lVetex��ʼ��Ϊ�������翪ʼʱ��
    for(i=this->verNum-2; i>=0; --i){					// ��ȥ��㣬��verNum-2��ʼ����  
        int curNode = topOrder[i];				// �����������м���lVetex
        for (p = verList[curNode].firstEdge; p != NULL; p = p->next){  
            if(lVetex[curNode] > lVetex[p->to] - p->weight) 
                lVetex[curNode] = lVetex[p->to] - p->weight;
        } 
    }
    for(i=0; i<this->verNum; ++i)    					// ��ÿ�����eArc��lArc
        for(p = verList[i].firstEdge; p != NULL; p = p->next){ 
            eArc = eVetex[i];		
            lArc = lVetex[p->to] - p->weight;
            char tag=(eArc==lArc)?'*':' ';			// �ؼ����־
            cout<< "arc" << k++ << ":\t"			// ����
                << "<" << i << "," << p->to << "," << p->weight << ">" 
                << "\t" << eArc << " " << lArc << tag << endl;		
        }
    delete []eVetex;  
    delete []lVetex;  
    return true;
}  


template <class VertexType, class EdgeType>
adjList<VertexType, EdgeType>::adjList(int size){
    this->verNum = size;
    this->edgeNum = 0;
    verList = new verNode[size];
    this->visited = new bool[this->verNum];
    this->TE = new typename graph<VertexType, EdgeType>::mstEdge[this->verNum-1];
    topOrder = new int[this->verNum];
}

template <class VertexType, class EdgeType>
adjList<VertexType, EdgeType>::~adjList(){
    int i;
    edgeNode *p;
    for (i = 0; i < this->verNum; i++) {				// �ͷű߱�
        while ((p = verList[i].firstEdge) != NULL) {	// �ͷŵ�i��������
            verList[i].firstEdge = p->next;
            delete p;
        }
    }
    delete[] verList; 							// �ͷŶ����
    delete[] this->visited;
    delete[] this->TE;
    delete[] topOrder;
}

/*
template <class VertexType, class EdgeType>
bool adjList<VertexType, EdgeType>::insertEdge(int from, int to, EdgeType w){
	if (from < 0 || from > verNum - 1 || to < 0 || to > verNum - 1)
		return false;
	edgeNode *p = verList[from].firstEdge;
	while (p != NULL && p->to != to) p = p->next;
	if (p == NULL){					// ͷ�巨��˳�����ҵ�
		verList[from].firstEdge =new edgeNode(to, w, verList[from].firstEdge);
		++edgeNum;
	}
	else if( p->weight == w )return false;// �Ѿ����ڴ�from��toȨֵΪw�ı�
	else p->weight = w;						// ���±���ȨֵΪw
	return true;
}
*/
template <class VertexType, class EdgeType>
bool adjList<VertexType, EdgeType>::insertEdge(int from, int to, EdgeType w){
    if (from < 0 || from > this->verNum - 1 || to < 0 || to > this->verNum - 1)
        return false; 						// �±�Խ��
    edgeNode *p = verList[from].firstEdge,*pre,*s;
    while(p!= NULL && p->to<to) {				// ���Ҳ���λ��
        pre=p;  p= p->next;	
    } 
    if(p!=NULL && p->to == to) { 				// �ñ��Ѿ�����
        if(p->weight != w)p->weight = w;		// �޸�Ȩֵ
        else return false;
    }
    else {									// �ñ߲�����
        s = new edgeNode(to, w, p);
        if(p == verList[from].firstEdge) 		// ����Ϊ��Ԫ���
            verList[from].firstEdge = s;
        else  pre->next=s;					// ����������λ�ò�����
        ++this->edgeNum;							// ����һ���ߣ�������1
    }
    return true;
}
/*
template <class VertexType, class EdgeType>
bool adjList<VertexType, EdgeType>::removeEdge(int from, int to){
	if (from < 0 || from > verNum - 1 || to < 0 || to > verNum - 1)
		return false;
	edgeNode *p = verList[from].firstEdge, *s;
	if (p == NULL) return false;  		// û�д�from�����ı�
	if (p->to == to)					// �������е���Ԫ������Ҫɾ���ı�
	{
		verList[from].firstEdge = p->next;
		delete p; 
		--edgeNum;
		return true;
	}
	while (p->next != NULL && p->next->to != to) 
		p = p->next;
	if (p->next == NULL) 
		return false;					// û���ҵ���ɾ���ı�
	s = p->next; p->next = s->next; delete s;
	--edgeNum;
	return true;
}
*/
template <class VertexType, class EdgeType>
bool adjList<VertexType, EdgeType>::removeEdge(int from, int to){
    if (from < 0 || from > this->verNum - 1 || to < 0 || to > this->verNum - 1)
        return false; 						// �±�Խ��
    edgeNode *p = verList[from].firstEdge,*pre=NULL;
    while(p!= NULL && p->to < to){ 				// ���ұ�   
        pre = p;    p = p->next;	
    }
    if((p == NULL)||(p->to > to))				// �ñ߲�����
        return false;			
    if(p->to == to){ 						// �ñߴ��� 
        if(p == verList[from].firstEdge)		// �ñ��Ǳ߱��е���Ԫ���
            verList[from].firstEdge = p->next;
        else pre->next = p->next;
        delete p;
        --this->edgeNum;
        return true;
    }
}


template <class VertexType, class EdgeType>
bool adjList<VertexType, EdgeType>::searchEdge(int from, int to) const{
    if (from < 0 || from > this->verNum - 1 || to < 0 || to > this->verNum - 1)
        return false; 							// �±�Խ��
    edgeNode *p = verList[from].firstEdge;
    while (p != NULL && p->to != to) 
        p = p->next;
    if (p == NULL) return false; 					// �ñ߲�����
    else  return true;
}

template <class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::createGraph(const VertexType V[],const EdgeType A[]){
    int i,j;
    for ( i = 0; i < this->verNum; i++)
        verList[i].vertex = V[i];
    for ( i = 0; i < this->verNum; i++)
        for ( j = 0; j < this->verNum; j++) {
            if (A[i*this->verNum + j] > 0)
                insertEdge(i, j, A[i*this->verNum + j]); 	// insertEdge����߰�toֵ����
        }
}

template <class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::dfsTraverse() const{
	int i,count=0;											// countͳ������ͼ��ͨ������
	for (i = 0; i < this->verNum; i++) this->visited[i] = false;
	for (i = 0; i < this->verNum; i++) {
		if ( !this->visited[i] ){
			dfs(i);	
			count++;
		}								
	}
	cout<<endl;
	cout<<"����ͼ��ͨ����������"<<count<<endl;				// ����ͼ�У�countΪ��ͨ��������
}
template <class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::dfs(int start) const{
	edgeNode *p = verList[start].firstEdge;

	cout << verList[start].vertex << ' ';
	this->visited[start] = true;
	while (p != NULL){
		if (this->visited[p->to] == false) dfs(p->to);
		p = p->next;
	}
}
template <class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::bfsTraverse()const{
    int v,i,count=0;								// count��ͳ����ͨ��������
    queue<int> q;
    edgeNode *p;
    for (i = 0; i < this->verNum; i++) this->visited[i] = false; 	// �÷��ʱ�־Ϊfalse
    for (i = 0; i < this->verNum; i++) {
        if (this->visited[i] == true) continue;
        cout << verList[i].vertex << ' '; 				// ���ʶ���i
       	this->visited[i] = true; 							// �÷��ʱ�־Ϊtrue
        q.push(i);   count++;							// ����i���
        while (!q.empty()) {
            v = q.front(); q.pop();					// ����v����
            p = verList[v].firstEdge;
            while (p != NULL){						// ���Ҷ���vδ�����ʵ��ٽӵ�
                if (this->visited[p->to] == false){   
                    cout << verList[p->to].vertex << ' ';	// ���ʶ���p->to
                    this->visited[p->to] = true; 				// �÷��ʱ�־Ϊtrue
                    q.push(p->to); 					// ����p->to���
                }
                p = p->next;
            }
        }
    }
    cout<< endl;
}

template <class VertexType, class EdgeType>
bool adjList<VertexType, EdgeType>::topSort()const{  
    queue<int> q;
    edgeNode *p;
    int i,curNode,count=0, *inDegree = new int[this->verNum];
    for ( i = 0; i < this->verNum; i++)
        inDegree[i] = 0;
    for ( i = 0; i < this->verNum; i++){					// �����߱��󶥵����
        for (p = verList[i].firstEdge; p != NULL; p = p->next)
            ++inDegree[p->to];
    }
    for (i = 0; i < this->verNum; i++)   
        if (inDegree[i] == 0) q.push(i); 				// ���Ϊ0�Ķ��������
    while( !q.empty( ) ){
        curNode = q.front( );	  q.pop();				// ����һ�����Ϊ0�Ķ���
        cout << verList[curNode].vertex << ' ';			// ����ö���
		topOrder[count] = curNode;								
		count++;										// ������+1
        for (p = verList[curNode].firstEdge; p != NULL; p = p->next)	// �ڽӵ���ȼ�1
            if( --inDegree[p->to] == 0 )
                q.push( p->to ); 						// ���Ϊ0�Ķ��������
    }
    cout << endl;
    if( count == this->verNum ) return true; 				// ���ȫ�����㣬��������ɹ�
    return false; 									// ������ͼ�л�����������ʧ��
}

 
template <class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::printMst()const{
	for(int i=0 ; i<this->verNum-1;i++)
		cout << '(' << verList[this->TE[i].vex1].vertex<< ',' 
		<< verList[this->TE[i].vex2].vertex << ',' 
		<< this->TE[i].weight<< ") ";
	cout<<endl;
}
template <class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::kruskal( ) const{ 	
    int count = 0;
    typename graph<VertexType, EdgeType>::mstEdge e; 
    edgeNode *p;
    unionFindSet S(this->verNum);    					// ���鼯S
    priorityQueue<typename graph<VertexType, EdgeType>::mstEdge> Q; 					// ���ȼ�����Q
    for (int i = 0; i < this->verNum; ++i) {			// ��ͼ�еı��������ȼ�����
        for (p = verList[i].firstEdge; p != NULL; p = p->next)
            if (i < p->to) {						// ��ֹ�ظ����
                e.vex1 = i;  e.vex2 = p->to;  e.weight = p->weight;
                Q.enQueue(e); 					// ��e���
            }
    }
    while( count <this->verNum- 1 ) {					// ѡ��verNum-1����
        e = Q.deQueue();						// �����ȼ����г���һ����
        int u = S.find(e.vex1); 					// ���Ҷ���vex1�����Ӽ�
        int v = S.find(e.vex2); 					// ���Ҷ���vex2�����Ӽ�
        if( u != v ) {							// ���ϵ��������㲻����ͬһ��ͨ����
            S.merge( u, v ); 					// �ϲ�u��v�����Ӽ�����ͨ������
            this->TE[count++] = e;						// ������С�������ϵ�һ����
        }
    }
}
template <class VertexType, class EdgeType>
void adjList<VertexType, EdgeType>::prim(EdgeType noEdge) const{ 
    struct Dist{ 
        int  adjVex;								// ��С���۱������Ķ�����
        EdgeType  lowCost;							// ��С����
    }*D=new Dist[this->verNum];
    edgeNode *p;
    EdgeType minCost;
    int u, i, j,count=0;
    for (i = 0; i < this->verNum; ++i) { 
        this->visited[i] = false; 
        D[i].lowCost = noEdge;
    }
    u = 0;  this->visited[u] = true;  						// ��ʼ��U����
    for ( i= 1; i < this->verNum; ++i) {					// ѡ��һ����u��U���Ϻ�
        for (p = verList[u].firstEdge; p != NULL; p = p->next) 	
                            							// ����u�����Ķ����Dֵ
            if (!this->visited[p->to] && D[p->to].lowCost > p->weight) { 
                D[p->to].lowCost = p->weight;			// ����lowcost
                D[p->to].adjVex = u; 					// ����adjVex 
            }
        minCost = noEdge;
        for (j = 0; j < this->verNum; ++j)					// ��V-U����lowCost��С����u
            if (D[j].lowCost < minCost) {
                minCost = D[j].lowCost; u = j;
            }
        this->TE[count].vex1 = D[u].adjVex; 				// ������С��������һ����
        this->TE[count].vex2 = u; 
        this->TE[count++].weight = D[u].lowCost;
        D[u].lowCost = noEdge;						// ����u�Ѳ���U����
        this->visited[u] = true;  							
    }
    delete [] D;
}

#endif
