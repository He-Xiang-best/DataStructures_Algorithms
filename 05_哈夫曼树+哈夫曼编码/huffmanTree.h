#pragma once
using namespace std;
template <class T>
class huffmanTree {
private:
    struct  Node {
        T data;				            // ����������
        int weight;			            // ����Ȩֵ		  
        int parent, left, right;		// ˫�׼����Һ��ӵ��±�
        Node() {				        // ���캯��
            weight = parent = left = right = 0;
        };
    };
    struct huffmanCode {
        T data;
        string code;			        // ����data�Ĺ���������
        huffmanCode() { code = ""; }	// ���캯��������ǰcode�ǿմ�
    };
    Node* hfTree;		                // ˳��ṹ������huffman��
    huffmanCode* hfCode;	            // ˳��ṹ������huffman����
    int size;			                // Ҷ�����
    void selectMin(int m, int& p);	    // ѡ����ǰ�����е���СԪ��
public:
    huffmanTree(int initSize);  	    // ���캯��
    ~huffmanTree() { delete[] hfTree; delete[]hfCode; }
    void createHuffmanTree(const T* d, const double* w);
                                        // ������������
    void huffmanEncoding();	            // ��ȡhuffman����
    void printHuffmanCode();	        // ���huffman����
};

//���캯��
template <class T>
huffmanTree<T>::huffmanTree(int initSize) {
    size = initSize;	            // sizeΪ��ʼ�����еĽ����
    hfTree = new Node[2 * size];
    // ������������˳�򴢴�ṹ
    hfCode = new huffmanCode[size]; // ����������
}

//����Ҷ�����������d����Ȩֵ����w��������������
template <class T>
void huffmanTree<T>::createHuffmanTree(const T* d, const double* w) {
    int i, min1, min2;		            // ��С��������С�����±�
    for (i = size; i < 2 * size; ++i) {	// size��Ҷ��㸳ֵ
        hfTree[i].data = d[i - size];
        hfTree[i].weight = w[i - size];
    }
    for (i = size - 1; i > 0; --i) {   // �ϲ�����n-1���½��  
     // ѡ��parent ��ֵΪ0��Ȩֵ��С����������min1��min2��Ϊ���i�����Һ���
        selectMin(i + 1, min1);	hfTree[min1].parent = i;
        selectMin(i + 1, min2);	hfTree[min2].parent = i;
        hfTree[i].weight = hfTree[min1].weight + hfTree[min2].weight;
        hfTree[i].left = min1;
        hfTree[i].right = min2;
    }
}

//ѡ��parent ��ֵΪ0��Ȩֵ��С�������ĸ������±ꡣ
template<class T>
void huffmanTree<T>::selectMin(int m, int& p) {
    int j = m;
    while (hfTree[j].parent != 0) j++;	    // ��������˫�׵Ľ��
    for (p = j, j += 1; j < 2 * size; j++)	// ���ɨ��ʣ��Ԫ��
        if ((hfTree[j].weight < hfTree[p].weight)
            && 0 == hfTree[j].parent)
            p = j;			                // ���ָ�С�ļ�¼����¼����λ��
}

//���ݹ�������Ϊÿ��Ҷ������ɹ��������롣
template <class T>
void huffmanTree<T>::huffmanEncoding() {
    int f, p;		                   // p�ǵ�ǰ���ڴ���Ľ�㣬f��p��˫�׵��±�
    for (int i = size; i < 2 * size; ++i) {
        hfCode[i - size].data = hfTree[i].data;
        p = i;
        f = hfTree[p].parent;
        while (f) {
            if (hfTree[f].left == p)   // p����˫��f�����ӣ�����+��0��
                hfCode[i - size].code = '0' + hfCode[i - size].code;
            else  		               // p����˫��f���Һ��ӣ�����+��1��
                hfCode[i - size].code = '1' + hfCode[i - size].code;
            p = f;
            f = hfTree[p].parent;
        }
    }
}

template<class T>
void huffmanTree<T>::printHuffmanCode() {
    for (int i = 0; i < size; i++) {
        cout << hfCode[i].data << ':' << hfCode[i].code << endl;
    }

}