
//============================================================================
// @FileName     ��1_3_chicken
// @Author       ��04191315_HeXiang
// @Version      ��1.0
// @Date         ��2020.9.23
// Description   ��
/*
 ��Ԫǰ�����ͣ��ҹ��Ŵ���ѧ�������ڡ��㾭��һ��������ˡ��ټ����⡱��
 ����һֵǮ�壬��ĸһֵǮ����������ֵǮһ��
 ��Ǯ��ټ����ʼ��̡���ĸ�����������Σ������һ������Ч�����㷨��⡣
 ����(�˴���չΪnԪǮ��nֻ��)
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

void buyResult(int x, int y, int z, int num) {
	cout << "\t����\t��ĸ\t����" << endl;
	cout << num << "\t" << x << "\t" << y << "\t" << z << endl;
}
void creatData() {
	int x, y, z, n, num = 1;
	cout << "������nԪǮ��nֻ�������nֵ��" << endl;
	cin >> n;
	cout << "������£�\n-----------------------------------" << endl;
	for (x = 0; x <= n / 5; x++) {
		for (y = 0; y <= n / 3; y++) {
			z = n - y - x;
			if (z % 3 != 0) continue;
			if (5 * x + 3 * y + (z / 3) == n) {
				buyResult(x, y, z, num);
				num++;
			}
		}
	}
}

int main()
{
	creatData();
    cout << "\n-----------------------------------" << endl;
    system("pause");
    return EXIT_SUCCESS;

}
