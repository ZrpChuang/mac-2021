#include<iostream>
using namespace std;
int weight[3][3] = {

 {7,8,6},
 {4,3,6},
 {2,7,2}
};
int cost[3][3] = {
 {7,8,6},
 {4,3,6},
 {2,7,2}
};
int n = 3;
int m = 3;
int limit = 12;


void traceback(int* x, int* bestlist, int t, int& c, int& w, int& bestw) {
	if (t > n) {
		bestw = w;
		for (int i = 0; i < n; i++) {
			bestlist[i] = x[i];
		}
	}
	for (int i = 1; i <= m; i++) {

		if (((c + cost[t - 1][i - 1]) <= limit) && ((w + weight[t - 1][i - 1]) < bestw)) {
			c += cost[t - 1][i - 1];
			w += weight[t - 1][i - 1];
			x[t - 1] = i;
			traceback(x, bestlist, t + 1, c, w, bestw);
			c -= cost[t - 1][i - 1];
			w -= +weight[t - 1][i - 1];
		}
	}
	return;
}



int main(void) {
	int  c = 0, w = 0, bestw = 1000;
	int x[3];
	int bestlist[3];

	cout << "test example:" << endl;
	printf("%-3d%-3d%-3d\n\n", n, m, limit);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%-3d", cost[i][j]);
		}
		cout << endl;
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%-3d", weight[i][j]);
		}
		cout << endl;
	}

	traceback(x, bestlist, 1, c, w, bestw);

	cout << "the result is:" << endl;
	cout << bestw << endl;
	for (auto n : bestlist) {
		cout << n << "   ";
	}

	return 0;
}

/*
void traceback(int* x,int* bestlist,int t,int &c,int &w,int &bestw) {
 if (t > n) {
  bestw = w;
  for (int i = 0; i < n; i++) {
   bestlist[i] = x[i];
  }
 }
 for (int i = 1; i <= m; i++) {

  if (  ((c + cost[t-1][i-1]) <= limit) && ((w + weight[t-1][i-1]) < bestw) ) {
   c += cost[t - 1][i - 1];
   w += weight[t - 1][i - 1];
   x[t - 1] = i;
   traceback(x,bestlist,t + 1, c, w, bestw);
   c -= cost[t - 1][i - 1];
   w -= +weight[t - 1][i - 1];
  }
 }
 return;
}
*/