#include<stdio.h>

int Knapsack(int* v, int* w, int n, int c,int* tb) {//wΪ����array vΪ��ֵ���� nΪ��Ʒ����Ŀ wΪ����������
	int dp[n+1][c+1];//����0��Ԫ��ʹ��
	for (int i = 0; i <= c;i++) {
		dp[n][i] = 0;//��ʼ��ȫ������
	}
	for (int i = w[n-1]; i <= c; i++) {
		dp[n][i] = v[n-1];
	}
	for (int i = n - 1; i >= 1; i--) {
		dp[i][0] = 0;
		for (int j = 1; j <= c; j++) {
			dp[i][j] = dp[i + 1][j];//�ȼ��費�������
			if (w[i-1]<=j) {//��������������̰��
				if ((v[i-1] + dp[i + 1][j - w[i-1]]) > dp[i][j]) {
					dp[i][j] = v[i-1] + dp[i + 1][j - w[i-1]];//��ֵ
				}
			}
		}
	}
	printf("Ϊ���ô�ҿ��Ÿ��ӷ��㣬��ӡ��ά��\n");
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=c;j++){
			printf("%-5d",dp[i][j]);
		}
		printf("\n");
	}//������ 
	
	int i = 1,j = c;
	
	for(;i<n;i++){
		printf("��%d����Ʒ�ļ�飺",i);
		if(dp[i][j]>dp[i+1][j]){
			tb[i] = 1;j-=w[i-1];
			printf("��Ʒ%d�Ž�ȥ�ˣ�����Ʒ������%d����ת��j�ǣ�%d",i,w[i],j); 
		}
		else{
			printf("û�зŽ�ȥ��");
		}
		printf("\n");
	}
	if(dp[n][j]>0) {
		tb[n] = 1;printf("���һ����Ʒ��Ҳ�Ž�ȥ�ˣ�"); 
	}
	else printf("���һ����Ʒ��û�зŽ�ȥ!");
	
	printf("\n\n");
	
	return dp[1][c];
}



int main(void)
{
	int v[6] = { 2,5,5,1,10,6 };
	int w[6] = { 2,3,4,1,5,6 };
	int tb[7] = {0,0,0,0,0,0,0};
	int n = 6;//��Ʒ����
	int c = 23;//����

	int result = Knapsack(v, w, n, c,tb);
	printf("�����%d", result);
	printf("\nѡ�����ǣ�");
	for(int i = 1;i<=n;i++){
		printf("%d ",tb[i]);
	}
	return 0;
}
