#include<stdio.h>

int Knapsack(int* v, int* w, int n, int c,int* tb) {//w为代价array v为价值数组 n为物品的数目 w为背包的容量
	int dp[n+1][c+1];//打算0单元不使用
	for (int i = 0; i <= c;i++) {
		dp[n][i] = 0;//初始化全部置零
	}
	for (int i = w[n-1]; i <= c; i++) {
		dp[n][i] = v[n-1];
	}
	for (int i = n - 1; i >= 1; i--) {
		dp[i][0] = 0;
		for (int j = 1; j <= c; j++) {
			dp[i][j] = dp[i + 1][j];//先假设不放入该行
			if (w[i-1]<=j) {//假设满足条件，贪心
				if ((v[i-1] + dp[i + 1][j - w[i-1]]) > dp[i][j]) {
					dp[i][j] = v[i-1] + dp[i + 1][j - w[i-1]];//改值
				}
			}
		}
	}
	printf("为了让大家看着更加方便，打印二维表：\n");
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=c;j++){
			printf("%-5d",dp[i][j]);
		}
		printf("\n");
	}//输出表格 
	
	int i = 1,j = c;
	
	for(;i<n;i++){
		printf("第%d个物品的检查：",i);
		if(dp[i][j]>dp[i+1][j]){
			tb[i] = 1;j-=w[i-1];
			printf("物品%d放进去了，该物品重量是%d，跳转到j是：%d",i,w[i],j); 
		}
		else{
			printf("没有放进去！");
		}
		printf("\n");
	}
	if(dp[n][j]>0) {
		tb[n] = 1;printf("最后一个物品：也放进去了！"); 
	}
	else printf("最后一个物品：没有放进去!");
	
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
