#include <iostream>
#include<cstdlib>
#include<stack>
#include<string>
#include "linkStack.h"
#include "seqStack.h"
using namespace std;


template<class T>
void testStack(Stack<T>& s) {
	for (int i = 0; i < 10; i++) {
		s.push(2 * i);
		cout << "curLength=" << s.size() << endl;
	}
	cout << "curLength=" << s.size() << endl;
	while (!s.empty()) { cout << s.pop() << " "; }
	cout << "\ncurLength=" << s.size() << endl;
	try {
		cout << s.getTop();
	}
	catch (outOfRange& e) {
		cout << e.what();
	}

}

//求阶乘
template<class T>
long factorial(Stack<T>& s, long n) {
	long result = 1;
	while (n > 0)
		s.push(n--);
	while (!s.empty()) {
		result *= s.pop();
	}
	return result;
}


//进阶转换
void convert() {
	linkStack<int> S;
	int N, e;
	cin >> N;
	while (N != 0) {
		S.push(N % 16);
		N = N / 16;

	}
	while (!S.empty()) {
		e = S.pop();
		if (e > 9)
			cout << char(e - 10 + 'a');
		else cout << e << "";

		cout << endl;
	}

}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	linkStack<int> ls;
	seqStack<int> ss;
	testStack(ss);
	testStack(ls);
	long x;
	cout << "请输入一个数：\n";
	cin >> x;
	cout << "阶乘" << x << "是" << factorial(ss, x) << endl;
	cin >> x;

	return 0;

}