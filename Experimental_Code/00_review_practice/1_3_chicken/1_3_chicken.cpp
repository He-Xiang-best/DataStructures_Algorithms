
//============================================================================
// @FileName     ：1_3_chicken
// @Author       ：04191315_HeXiang
// @Version      ：1.0
// @Date         ：2020.9.23
// Description   ：
/*
 公元前五世纪，我国古代数学家张丘建在《算经》一书中提出了“百鸡问题”：
 鸡翁一值钱五，鸡母一值钱三，鸡雏三值钱一。
 百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？请设计一个“高效”的算法求解。
 ——(此处拓展为n元钱买n只鸡)
 */
 //============================================================================

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
using namespace std;

void buyResult(int x, int y, int z, int num) {
	cout << "\t鸡翁\t鸡母\t鸡雏" << endl;
	cout << num << "\t" << x << "\t" << y << "\t" << z << endl;
}
void creatData() {
	int x, y, z, n, num = 1;
	cout << "请输入n元钱买n只鸡问题的n值：" << endl;
	cin >> n;
	cout << "求解如下：\n-----------------------------------" << endl;
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
