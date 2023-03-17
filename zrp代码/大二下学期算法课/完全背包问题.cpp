#include<stdio.h>
#include<iostream>
using namespace std;

int Knapsack(int* v, int* w, int n, int c,int* tb) {//wΪ����array vΪ��ֵ���� nΪ��Ʒ����Ŀ wΪ����������
	int dp[n+1][c+1];//����0��Ԫ��ʹ��
	int remember[n+1][c+1];
	
	int time;
	for (int j = 0; j <= c;j++) {
		time = j/w[n-1];//��ʾ�ܷ��¶��ٸ��ͷ��¶��ٸ� 
		dp[n][j] = time*v[n-1];//��ʼ��ȫ����
		remember[n][j] = time;
	}
	for (int i = n - 1; i >= 1; i--) {
		dp[i][0] = 0;remember[i][0] = 0;
		for (int j = 1; j <= c; j++) {
			dp[i][j] = dp[i + 1][j];//��ʼ��Ϊ���費���� 
			time = j/w[i-1];//��������ܷŽ�ȥ�ĸ���
			remember[i][j] = 0;
			for(int k = 1;k<=time;k++){//һ��һ���̰�� 
				if ((v[i-1]*k + dp[i + 1][j - k*w[i-1]]) > dp[i][j]) {
					dp[i][j] = v[i-1]*k + dp[i + 1][j - k*w[i-1]];//��ֵ
					remember[i][j] = k;
				}
			}
		}
	}
	printf("Ϊ���ô�ҿ��Ÿ��ӷ��㣬��ӡ��ά��\n");
	for(int j = 0;j<=c;j++){
			printf("%-3d",j);
		}
	cout<<"����ʾ����ʣ��������";
		printf("\n");
		printf("\n");
		
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=c;j++){
			printf("%-3d",dp[i][j]);
		}
		printf("\n");
	}//������ 
	printf("\n");
	printf("\n");
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=c;j++){
			printf("%-3d",remember[i][j]);
		}
		printf("\n");
	}//������ 
	
	int i = 1,j = c;
	
	for(;i<=n;i++){
		
		tb[i] = remember[i][j];
		j -= remember[i][j]*w[i-1];
		printf("��%d����Ʒ�Ž�ȥ%d��",i,tb[i]);
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
