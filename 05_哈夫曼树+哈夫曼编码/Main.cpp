
//============================================================================
// @FileName     ��Main.cpp
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.11.29
// Description   ������Ӧ��
/*
���������͹��������룺���ն��������ɸ��ַ���ͳ���ַ����ֵ�Ƶ�ʣ����ַ����ֵ�Ƶ����Ϊ����Ȩֵ��
��������������Ȼ��Ը��ַ����й��������롣����ӡ���������Ͷ�Ӧ�Ĺ��������롣
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include<string>
#include<cstdlib>
#include"huffmanTree.h"
using namespace std;

void test_huffmanTree() {
    cout << "������һ���ַ�����" << endl;
    string str;
    getline(cin, str);
    int strLength = str.size();
    char *d = new char[strLength];
    strcpy(d, str.c_str());
    double* w = new double[strLength];
    cout << "\n�����������ַ�����ÿ���ַ���Ӧ��Ȩֵ��" << endl;
    double weight;
    for (int i = 0; i < strLength; i++) {
        cin >> weight;
        w[i] = weight;
    }
    huffmanTree<char> tree(strLength);
    tree.createHuffmanTree(d, w);
    tree.huffmanEncoding();
    cout << "\n" << "�ַ���" << str << "�Ĺ������������£�\n" << endl;
    tree.printHuffmanCode();
    delete[] w,d;
}
int main()
{
    test_huffmanTree();
    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
