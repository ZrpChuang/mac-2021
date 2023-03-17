#include<stdio.h>
#include<iostream>
using namespace std;

int Knapsack(int* v, int* w, int n, int c,int* tb) {//w为代价array v为价值数组 n为物品的数目 w为背包的容量
	int dp[n+1][c+1];//打算0单元不使用
	int remember[n+1][c+1];
	
	int time;
	for (int j = 0; j <= c;j++) {
		time = j/w[n-1];//表示能放下多少个就放下多少个 
		dp[n][j] = time*v[n-1];//初始化全部置
		remember[n][j] = time;
	}
	for (int i = n - 1; i >= 1; i--) {
		dp[i][0] = 0;remember[i][0] = 0;
		for (int j = 1; j <= c; j++) {
			dp[i][j] = dp[i + 1][j];//初始化为假设不放入 
			time = j/w[i-1];//计算最多能放进去的个数
			remember[i][j] = 0;
			for(int k = 1;k<=time;k++){//一层一层的贪心 
				if ((v[i-1]*k + dp[i + 1][j - k*w[i-1]]) > dp[i][j]) {
					dp[i][j] = v[i-1]*k + dp[i + 1][j - k*w[i-1]];//改值
					remember[i][j] = k;
				}
			}
		}
	}
	printf("为了让大家看着更加方便，打印二维表：\n");
	for(int j = 0;j<=c;j++){
			printf("%-3d",j);
		}
	cout<<"（表示背包剩余容量）";
		printf("\n");
		printf("\n");
		
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=c;j++){
			printf("%-3d",dp[i][j]);
		}
		printf("\n");
	}//输出表格 
	printf("\n");
	printf("\n");
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=c;j++){
			printf("%-3d",remember[i][j]);
		}
		printf("\n");
	}//输出表格 
	
	int i = 1,j = c;
	
	for(;i<=n;i++){
		
		tb[i] = remember[i][j];
		j -= remember[i][j]*w[i-1];
		printf("第%d个物品放进去%d个",i,tb[i]);
		printf("\n");
	}
	printf("\n\n");
	
	return dp[1][c];
}



int main(void)
{
	int v[6] = { 2,5,5,1,10,6 };
	int w[6] = { 2,3,4,1,5,6 };
	int tb[7] = {0,0,0,0,0,0,0};
	int n = 6;//物品数量
	int c = 23;//容量

	int result = Knapsack(v, w, n, c,tb);
	printf("结果是%d", result);
	printf("\n选择结果是：");
	for(int i = 1;i<=n;i++){
		printf("%d ",tb[i]);
	}
	return 0;
}
