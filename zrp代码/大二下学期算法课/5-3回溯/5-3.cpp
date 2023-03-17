#include<iostream>
using namespace std;
int weight[4][4] = {
 {0,0,0,0},
 {0,7,2,2},
 {0,3,2,3},
 {0,3,5,4}
};
int cost[4][4] = {
 {0,0,0,0},
 {0,2,4,3},
 {0,3,7,1},
 {0,8,2,1}
};
int n = 3;
int m = 3;
int limit = 12;

void traceback(int* x, int* bestlist, int t, int c, int w, int &bestw) {

	while (t>0) {//x内部索引-1，
		x[t] += 1;//第t个零件，共有n个 第x[t]个商家
		while (((c + cost[t][x[t]]) > limit) || ((w + weight[t][x[t]]) >= bestw)) {
			if (x[t] <= m) {
				x[t]++;
			}
			else break;
		}
		
		if (x[t] <= m) {
			c += cost[t][x[t]];
			w += weight[t][x[t]];
			if (t == n) {
				bestw = w;
				for (int i = 1; i <= n; i++) {
					bestlist[i] = x[i];
				}//之后同一层里面继续走
				c -= cost[t][x[t]];
				w -= weight[t][x[t]];
			}
			else {
				t++;
				x[t] = 0;
			}
		}
		else {
			t--;
			c -= cost[t][x[t]];
			w -= weight[t][x[t]];
		}//所有可能都在这里弹出
	}
	return;
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


int main(void) {
	int  c = 0, w = 0, bestw = 1000;
	int x[4] = { 0 };
	int bestlist[4] = { 0 };

	cout << "test example:" << endl;
	printf("%-3d%-3d%-3d\n\n", n, m, limit);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=m; j++) {
			printf("%-3d", cost[i][j]);
		}
		cout << endl;
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%-3d", weight[i][j]);
		}
		cout << endl;
	}

	traceback(x, bestlist, 1, c, w, bestw);

	cout << "the result is:" << endl;
	cout << bestw << endl;
	for (int i = 1; i <= n;i++) {
		printf("%-3d", bestlist[i]);
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