# include<iostream>
using namespace std;
int n = 3;

int matrix[5][5] = {
	{0,0,0,0},
	{0,10,2,3},
	{0,2,3,4},
	{0,3,4,5}
};
int x[5] = { 0,1,2,3,4 };
int bestpointer[10] = { 0 };
void swap(int* x, int from, int to) {
	int temp = x[from];
	x[from] = x[to];
	x[to] = temp;
	return;
}
void traceback(int t, int& best, int* x, int help) {
	int remember[10] = {0};//¼ÇÂ¼¸úË­»»
	while (t > 0) {
		remember[t] += 1;
		if (remember[t] <= n) {
			swap(x, t, remember[t]);
			help += matrix[t][x[t]];
		}
		while (help >= best && remember[t] <= n) {
			help -= matrix[t][x[t]];
			swap(x, t, remember[t]);
			remember[t]+=1;
			if (remember[t] <= n) {
				swap(x, t, remember[t]);
				help += matrix[t][x[t]];
			}
		}
		if (remember[t] <= n) {
			if (t == n) {
				best = help;
				for (int i = 1; i <= n; i++) { bestpointer[i] = x[i]; }
				help -= matrix[t][x[t]];
				t-=1;
				help -= matrix[t][x[t]];
				swap(x, t, remember[t]);
			}
			else {
				t+=1;
				remember[t] = t - 1;
			}
		}
		else {
			t--;
			help -= matrix[t][x[t]];
			swap(x, t, remember[t]);
		}
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

	traceback(1, best, x, help);

	cout << "the result is:" << best << endl;
	for (int i = 1; i <= n; i++) {
		printf("%-3d", bestpointer[i]);
	}

	return 0;
}

/*
	{0,0,0,0},
	{0,10,2,3},
	{0,2,3,4},
	{0,3,4,5}*/