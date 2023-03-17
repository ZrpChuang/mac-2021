# include<iostream>
using namespace std;
int n = 4;

int matrix[5][5] = {
	{0,0,0,0,0},
	{0,10,2,3,3},
	{0,2,3,4,5},
	{0,3,4,5,1},
	{0,3,4,5,2}
};
int x[5] = { 0,1,2,3 ,4};
int bestpointer[10] = {0};
void swap(int* x, int from, int to) {
	int temp = x[from];
	x[from] = x[to];
	x[to] = temp;
	return;
}
void traceback(int t,int &best,int* x, int help) {
	if (t == n) {
		help += matrix[t][x[t]];
		if (help <= best) {
			best = help;
			for (int i = 1; i <= n; i++) {
				bestpointer[i] = x[i];
			}
		}
		return;
	}
	for (int i = t; i <= n; i++) {
		swap(x, t, i);
		help += matrix[t][x[t]];
		if(help<=best)traceback(t+1, best, x,help);
		help -= matrix[t][x[t]];
		swap(x, t, i);
	}
}
int main(void) {
	int best = 100;
	int help = 0;
	cout << "test example:" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%-3d", matrix[i][j]);
		}
		cout << endl;
	}

	traceback(1, best, x,help);
	
	cout << "the result is:" << best << endl;
	for (int i = 1; i <= n; i++) {
		printf("%-3d", bestpointer[i]);
	}

	return 0;
}