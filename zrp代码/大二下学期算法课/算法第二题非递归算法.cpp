#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
char** Graycode(int n)//返回一个二维数组数表
{
	int i,j,k;//需要用到的辅助变量
	
	//如果格雷码是一位的
	char** head = (char**)malloc(pow(2, n)*sizeof(char*));//(char**)malloc(2 * sizeof(char*));
	for(i = 0;i<n;i++){
		head[i] = (char*)malloc((n+10)*sizeof(char));
	}
	head[0][0] = '0';head[0][1] = '\0';
	head[1][0] = '1';head[1][1] = '\0';
	if (n==1) return head;
	for(k = 2;k<=n;k++)
	{
		cout<<"1\n";
		int result = pow(2, k - 1);
		for (i = result,j = result-1; i < 2 * result; i++) {
			strcpy(head[i],head[j]);cout<<head[i]<<"\n";
			head[i][k-1] = '1';head[i][k] = '\0';cout<<head[i]<<"\n";
			j--;
		}
		for (i = 0; i < result; i++) {
			head[i][k-1] = '0';head[i][k] = '\0';
		}
	}
	return head;
}
int main(void)
{
	int n;
	printf("请输入n的大小：");
	scanf("%d", &n);
	printf("\n");
	
	char** result = Graycode(n);
	int sq = pow(2, n);//计算格雷码位数

	for (int i; i < sq; i++){
		printf("%s\n", result[i]);
	}
	return 0;
}
