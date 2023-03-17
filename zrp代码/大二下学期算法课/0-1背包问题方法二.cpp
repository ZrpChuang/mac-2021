#include<stdio.h>

int Knapsack(int* v, int* w, int n, int c,int* Tb) {//w为代价array v为价值数组 n为物品的数目 w为背包的容量
	int dp[n+1][c+1];//打算0单元不使用
	for (int i = 0; i <= c;i++) {
		dp[n][i] = 0;//初始化全部置零
	}
	for (int i = w[n-1]; i <= c; i++) {
		dp[n][i] = v[n-1];
	}
	for(int i = 1;i<n;i++){
		dp[i][0] = 0;
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= c; j++) {
			dp[i][j] = dp[i + 1][j];//先假设不放入该行
			if (w[i-1]<=j) {//假设满足条件，贪心
				if ((v[i-1] + dp[i + 1][j - w[i-1]]) > dp[i][j]) {
					dp[i][j] = v[i-1] + dp[i + 1][j - w[i-1]];//改值
				}
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=c;j++){
			printf("%-5d",dp[i][j]);
		}
		printf("\n");
	}
	int c1 = c;
	for(int i = 1;i<n;i++){
		if(dp[i][c]==dp[i+1][c]) Tb[i]=0;
		else{
			Tb[i] = 1;c-=w[i];
		}
	}
	if(dp[n][c1]>0) Tb[n];
	
	return dp[1][c1];
}



int main(void)
{
	int v[6] = { 2,5,5,1,10,6 };
	int w[6] = { 2,3,4,1,5,6 };
	int n = 6;//物品数量
	int c = 13;//容量
	int x[7]={0,0,0,0,0,0,0};

	int result = Knapsack(v, w, n, c,x);
	printf("结果是%d", result);
	printf("\n");
	
	for(int i=1;i<=6;i++){
		printf("%d ",x[i]);
	}
	return 0;
}
