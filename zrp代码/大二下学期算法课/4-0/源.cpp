#include<iostream>
using namespace std;
int valuemax(int n,int weightlimit, int* value, int* weight) {
	int left = weightlimit;
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (weight[i] <= left) {
			left -= weight[i];
			cout << "物品  " << value[i]<<"     " << weight[i] << "  放入背包" << endl;
			result += value[i];
		}
		else break;
	}
	return result;
}
int main(void) {
	int n = 6;
	int weightlimit = 18;
	int value[6] = { 18,16,15,14,13,11 };
	int weight[6] = { 2,3,5,8,9,10 };
	cout << "test example" << endl;
	for (int i = 0; i < n; i++) {
		cout << value[i] << "     " << weight[i] << endl;
	}
	int result = valuemax(n,weightlimit, value, weight);
	cout << "the result is:" << result << endl;
	return 0;
}