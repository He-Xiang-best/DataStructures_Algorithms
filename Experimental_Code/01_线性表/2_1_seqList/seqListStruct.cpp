
//============================================================================
// @FileName     ��
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.10.21
// Description   ��
/*
ʵ��˳���������Ա�Ļ���������
��ʼ�����Ա�������Ա������Ա��ȡ�������Ա��Ƿ�Ϊ�ա��������Ա�
�����Ա��в���Ԫ�ء������Ա��в��������Ԫ��ֵ��ͬ��Ԫ�������Ա��е�λ�á�����Ԫ�ء�ɾ��Ԫ�ء�
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include"seqList.h"
#include<iostream>  
//#include<stdlib.h>
//#include<time.h>
#include<windows.h>
#define random(x) rand()%(x)
using namespace std;

//����˳��������
template <class T>
void seqListTraverse(seqList<T>& sq) {
    if (sq.isEmpty())
    {
        cout << "��ǰ��˳���Ϊ�ձ���ǰ��������" << endl;
    }
    else {
        cout << "��ǰ˳����Ԫ����������:\n" << endl;
        sq.traverse();
    }

}

//��ֵ��ѯ����
template <class T>
void FindNumInValue(seqList<T>& sq) {
	if (sq.size() == 0) {
		cout << "��ǰΪ�ձ�û�����ݿɹ���ѯ��" << endl;
	}
	else {
		cout << "�������ѯ��ֵ������������λ�õ���ţ�";
		T value; cin >> value; cout << endl;
		int location = sq.search(value);
		if (location == 0) {
			cout << "˳����в����ڴ����ݣ�" << endl;
		}
		else
			cout << "���������ڵ�λ��Ϊ��" << location << endl;
	}
}

//����Ų�ѯ����
template <class T>
void FindNumInOrder(seqList<T>& sq) {
	if (sq.size() == 0) {
		cout << "��ǰΪ�ձ�û�����ݿɹ���ѯ��" << endl;
	}
	else {
		cout << "��������Ҫ��ѯ���ݵ���ţ� ";
		int i; cin >> i; cout << endl;
		while (i<1 || i>sq.size()) {
			cout << "(��ǰ�Ϸ��Ĳ�ѯλ��Ϊ����1......" << sq.size() << "��)\n" << endl;
			cout << "��ѯ�����ݷ�Χ����!���������룺 ";
			cin >> i;
			cout << endl;
		}
		cout << "��" << i << "�����ݶ�Ӧ����ֵΪ ���� " << sq.visit(i) << endl;
	}
}


//�����ɾ��
template <class T>
void seqListRemoveInOrder(seqList<T>& sq) {
	if (sq.size() == 0) {
		cout << "��ǰΪ�ձ�û�����ݿɹ�ɾ����" << endl;
	}
	else {
		cout << "��������Ҫɾ�����ݵ���ţ� ";
		int i; cin >> i; cout << endl;
		while (i<1 || i>sq.size()) {
			cout << "(��ǰ�Ϸ���ɾ��λ��Ϊ����1......" << sq.size() << "��)\n" << endl;
			cout << "ɾ�������ݷ�Χ����!���������룺 ";
			cin >> i;
			cout << endl;
		}
		sq.remove(i);
		cout << "\n����ɾ���ɹ���" << endl;
	}
}

//������ɾ��
template <class T>
void seqListRemoveRange(seqList<T>& sq) {
	if (sq.size() == 0) {
		cout << "��ǰΪ�ձ�û�����ݿɹ�ɾ����" << endl;
	}
	else {
		cout << "��������Ҫɾ�����ݵ����䣺���������߶�ȡ�õ��� ";
		int i,j; cin >> i>>j; cout << endl;
		while (i<1 || i>sq.size()||j<1 || j>sq.size()||j<=i) {
			cout << "(��ǰ�Ϸ���ɾ������Ϊ����1......" << sq.size() << "�����Ӽ�)\n" << endl;
			cout << "����ʱɾ����������������!���������룺 ";
			cin >> i>>j;
			cout << endl;
		}
		for (int k=i;k<=j;k++) {
			sq.remove(i);
		}
		
		cout << "\n����ɾ���ɹ���" << endl;
	}
}

//��ֵɾ������
template <class T>
void seqListRemoveInValue(seqList<T>& sq) {
	if (sq.size() == 0) {
		cout << "��ǰΪ�ձ�û�����ݿɹ�ɾ����" << endl;
	}
	else {
		cout << "��������Ҫɾ�����ݵ�ֵ�� ";
		T value; cin >> value; cout << endl;
		int i = sq.search(value);
		if (i == 0) {
			cout << "��ǰ��ֵ�����ڣ�ɾ��ʧ�ܣ�" << endl;
		}
		else {
			sq.remove(i);
			cout << "����ɾ���ɹ���" << endl;
		}
	}
}

//��˳����в�����ֵ
template <class T>
void seqListInsert(seqList<T>& sq) {
	if (sq.size() == 0) {
		cout << "��ǰΪ�ձ�û�����ݿɹ����룡" << endl;
	}
	else {
		cout << "������������Ҫ�������ݵ�λ���Լ���ֵ��\n" << endl;
		int location;
		T value;
		cin >> location >> value;
		if (sq.isFull()) sq.resize();//�������ʱ����������������
		while (location > sq.size() + 1 || location < 1)
		{
			cout << "(��ǰ�Ϸ��Ĳ���λ��Ϊ����1......" << sq.size() + 1 << "��)\n" << endl;
			cout << "����ʱ���������λ���������������룺";
			cin >> location;
			cout << endl;
		}
		sq.insert(location, value);
		cout << "\n���ݲ���ɹ���" << endl;
	}
}


//��ʼ����������
template <class T>
void seqListCreat(seqList<T> &sq) {
    cout << "������Ҫ�����������ݣ� ";
    int n;
    cin >> n;
    //��������������������ʼ��ʼ������������������
    while(sq.isOutOfRange(n) < 0)
        sq.resize();
    //srand((int)time(0));
	cout << "\n���������ݣ�\n" << endl;
	T value;
    for (int i = 0; i < n; i++) {
		cin >> value;
            sq.push_Back(value);
        }
        cout << "\n���ݴ����ɹ���" << endl;
}

template <class T>
void seqListUnionAndSort(seqList<T>& sq) {
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl <<
		"                                   ���ڳ�ʼ���ϲ���B...........";
	Sleep(1000);//ҳ������1��
	system("cls");//ʵ����������
	seqList<int> B;
	cout << "�ϲ���B��������";
	seqListCreat(B);
	cout << "\n���ںϲ�˳��������±��������..........." << endl;
	Sleep(1000);//ҳ������1��
	sq.getUnionAndSort(B);
	cout << "\n�ϲ�˳�������ɹ���" << endl;
}


//������
int scan() {
    cout << "  =================================================================\n";
    cout << " ��                                                                ��\n";
    cout << " ��                        ˳���Ļ�������                        ��\n";
    cout << " ��                                                                ��\n";
    cout << " ��                                                                ��\n";
    cout << " ��                        ���������ݡ���(1)                       ��\n";
    cout << " ��                                                                ��\n";
    cout << " ��                        ���������ݡ���(2)                       ��\n";
    cout << " ��                                                                ��\n";
    cout << " ��                        ���������ݡ���(3)                       ��\n";
    cout << " ��                                                                ��\n";
    cout << " ��               ����> ����ֵ��ѯԪ��λ�á�  ��(4)                 ��\n";
    cout << " ��               ��                                                ��\n";
    cout << " ��               ����> ����λ��ѯԪ����ֵ��  ��(5)                 ��\n";
    cout << " ��               ��                                                ��\n";
    cout << " ������ѯ��������>����> ���鿴˳����������  ��(6)                 ��\n";
    cout << " ��               ��                                                ��\n";
    cout << " ��               ����> ���鿴Ԫ�صĴ洢����  ��(7)                 ��\n";
    cout << " ��               ��                                                ��\n";
    cout << " ��               ����> ���鿴˳����Ƿ�Ϊ�ա���(8)                 ��\n";
    cout << " ��                                                                ��\n";
    cout << " ��                      �������ɾ�����ݡ�   ��(9)                ��\n";
    cout << " ��                                                                ��\n";
    cout << " ��                      ������ֵɾ�����ݡ�   ��(10)               ��\n";
    cout << " ��                                                                ��\n";
	cout << " ��                      ��������ɾ�����ݡ�   ��(11)               ��\n";
	cout << " ��                                                                ��\n";
    cout << " ��                        ���������ݡ���(12)                      ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ���ϲ����ݡ���(13)                      ��\n";
	cout << " ��                                                                ��\n";
	cout << " ��                        ��������ݡ���(14)                      ��\n";
    cout << " ��                                                                ��\n";
    cout << " ��                                                                ��\n";
    cout << " ��                        ���˳���������(0)                       ��\n";
    cout << " ��                                                                ��\n";
    cout << "  =================================================================\n";
    int choice;
    cout << "\n                     �ף���������Ҫ�����ı�ţ�";
    cin >> choice;
    return choice;
}


int main()
{
	seqList<int> sq;
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl <<
        "                                   ���ڳ�ʼ��˳���...........";
    Sleep(1000);//ҳ������1��
    system("cls");//ʵ����������

    for (;;) {
		switch (scan()) {
		case 1:
			system("cls");
			seqListCreat(sq);
			getchar();
			getchar();
			break;
		case 2:
			system("cls");
			seqListTraverse(sq);
			getchar();
			getchar();
			break;
		case 3:
			system("cls");
			seqListInsert(sq);
			getchar();
			getchar();
			break;
		case 4:
			system("cls");
			FindNumInValue(sq);
			getchar();
			getchar();
			break;
		case 5:
			system("cls");
			FindNumInOrder(sq);
			getchar();
			getchar();
			break;
		case 6:
			system("cls");
			cout << "��ǰ˳��������Ϊ�� " << sq.getMaxSize() << endl;
			getchar();
			getchar();
			break;
		case 7:
			system("cls");
			cout << "��ǰԪ�صĴ洢��Ϊ�� " << sq.size() << endl;
			getchar();
			getchar();
			break;
		case 8:
			system("cls");
			if (sq.isEmpty()) cout << "��ǰ˳���Ϊ�ձ�" << endl;
			else cout << "��ʱ˳���Ϊ�գ��� "<<sq.size()<<" ��Ԫ������" << endl;
			getchar();
			getchar();
			break;
		case 9:
			system("cls");
			seqListRemoveInOrder(sq);
			getchar();
			getchar();
			break;
		case 10:
			system("cls");
			seqListRemoveInValue(sq);
			getchar();
			getchar();
			break;
		case 11:
			system("cls");
			seqListRemoveRange(sq);
			getchar();
			getchar();
			break;
		case 12:
			system("cls");
			if (sq.isEmpty()) cout << "��ǰ˳���Ϊ�ձ�û�����ݿɹ����ã�" << endl;
			else {
				sq.inverse();
				cout << "�������óɹ���" << endl;
			}
			getchar();
			getchar();
			break;
		case 13:
			system("cls");
			seqListUnionAndSort(sq);
			getchar();
			getchar();
			break;
		case 14:
			system("cls");
			sq.clear();
			cout << "������������գ�" << endl;
			getchar();
			getchar();
			break;
		case 0:
			system("cls");
			cout << "�������˳�!" << endl;
			exit(0);
			break;
		}
		system("cls");

    }

    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
