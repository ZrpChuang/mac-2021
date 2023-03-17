# include<stdio.h>

int TDkna(int* v, int* w, int* b, int n, int weightlimi, int airlimi,int* tb)
{
	int dp[n + 1][weightlimi + 1][airlimi + 1];
	for (int i = 0; i <= weightlimi; i++) {
		for (int j = 0; j <= airlimi; j++) {
			dp[n][i][j] = 0;
		}
	}
	
	for (int i = w[n]; i <= weightlimi; i++) {
		for (int j = b[n]; j <= airlimi; j++) {
			dp[n][i][j] = v[n];
		}
	}
	
	for (int i = n - 1; i > 0; i--){
		for (int j = 0; j <= weightlimi; j++) {
			for (int k = 0; k <= airlimi; k++) {
				dp[i][j][k] = dp[i+1][j][k];
				if (w[i] <= j && b[i] <= k) {
					if((dp[i + 1][j - w[i]][k - b[i]] + v[i])>dp[i][j][k])
					dp[i][j][k] = dp[i + 1][j - w[i]][k - b[i]] + v[i];
				}
			}
		}
	}
	for(int i = n;i>=1;i--){
		printf("i = %d\n",i);
		for (int j = weightlimi; j >= 0; j--) {
			for (int k = 0; k <= airlimi; k++) {
				printf("%-3d",dp[i][j][k]);
			}
			printf("\n");
		}
	} 
	int i = 1,j = weightlimi,k = airlimi;
	for(;i<n;i++){
		if(dp[i][j][k]>dp[i+1][j][k]){
			tb[i] = 1;j-=w[i];k-=b[i];
		}
	}
	if(dp[n][j][k]>0) tb[n] = 1;
	return dp[1][weightlimi][airlimi];
}
int main(void){
	int v[7] = { 0,2,5,5,1,10,6 };
	int w[7] = { 0,2,3,4,1,5,6 };
	int b[7] = { 0,2,3,4,1,5,6 };
	int tb[7] = {0,0,0,0,0,0,0};
	
	int n = 6;//物品数量
	int weightlimi = 23;//容量
	int airlimi = 23;
	int result = TDkna(v, w, b, n, weightlimi, airlimi,tb);
	printf("输出结果为：%d",result);printf("\n选取结果为：");
	for(int i = 1;i<=n;i++){
		printf("%d ",tb[i]);
	}
	
	return 0;
}
/*
for (int j = 0; j <= weightlimi; j++) {
			for (int k = 0; k <= airlimi; k++) {
				 
				printf("%-3d",dp[n][j][k]);
				
			}
			printf("\n");
		}
*/
