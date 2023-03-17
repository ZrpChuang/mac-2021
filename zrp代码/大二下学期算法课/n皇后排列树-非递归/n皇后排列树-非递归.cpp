#include<iostream>
using namespace std;
void swap(int* x, int from, int to) {
	//cout << endl <<"检查：" << from <<"\t" << to << endl;
	int temp = x[to];
	x[to] = x[from];
	x[from] = temp;
}//交换函数

bool place(int* x, int t) {
	for (int i = 1; i < t; i++) {
		if (abs(t - i) == abs(x[t] - x[i])) return false;
	}//逐个检查对角线
	return true;
}
void QueenBack(int t, int n, int* x, int& result) {
	int help[20] = {0};
	while (t >= 1) {
		help[t] += 1;
		if(help[t] <= n) swap(x, t, help[t]);
		while (place(x, t) == 0 && help[t] <= n) {
			swap(x, t, help[t]);
			help[t] += 1;
			if (help[t] <= n) swap(x, t, help[t]);
		}
		if (help[t]<=n) {
			if (t == n) {
				result++;
				for (int i = 1; i <= n; i++) {
					cout << x[i] << "  ";
				}
				cout << endl;
				t--;
				swap(x, t, help[t]);
			}
			else {
				t++;
				help[t] = t - 1;
			}
		}
		else {
			t--;
			if(t>=1) swap(x, t, help[t]);
		}
	}
	return;
}
int main(void) {
	int n = 10;
	int x[11] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int result = 0;
	QueenBack(1, n, x, result);
	if (result) {
		cout << "the result is:" << result << endl;
	}
	else cout << "no result" << endl;
	return 0;
}
/*
2  4  1  3
3  1  4  2
the result is:2
*/