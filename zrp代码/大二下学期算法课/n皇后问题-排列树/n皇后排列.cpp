#include<iostream>
using namespace std;
void swap(int* x, int from, int to) {
	int temp = x[to];
	x[to] = x[from];
	x[from] = temp;
}//��������

bool place(int *x,int t) {
	for (int i = 1; i < t; i++) {
		if (abs(t - i) == abs(x[t] - x[i])) return false;
	}//������Խ���
	return true;
}
void QueenBack(int t,int n,int *x,int &result) {
	if (t == n) {
		if (place(x, n)) {
			result++;
			for (int i = 1; i <= n; i++) {
				cout << x[i] << "  ";
			}
			cout << endl;
		}
	}
	for (int i = t; i <= n; i++) {
		swap(x, t, i);
		if (place(x,t)) QueenBack(t + 1, n, x, result);
		swap(x, i, t);//�ֳ���ԭ
	}
}
int main(void) {
	int n = 4;
	int x[5] = { 0,1,2,3,4};
	int result = 0;
	QueenBack(1, n, x, result);
	if (result) {
		cout << "the result is:" << result << endl;
	}
	else cout << "no result" << endl;
	return 0;
}