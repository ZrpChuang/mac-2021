#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;

char** Graycode(int n)//返回一个二维数组数表
{
	int i,j;//需要用到的辅助变量
	if (n == 1){//如果格雷码是一位的
		char** head = new char*[2];//(char**)malloc(2 * sizeof(char*));
		
		head[0] = new char[2];
		head[1] = new char[2];
		head[0][0] = '0';head[0][1] = '\0';
		head[1][0] = '1';head[1][1] = '\0';
		return head;
	}
	else
	{
		int result = pow(2, n - 1);
		char** temp = Graycode(n - 1);//分治思想，调用之前的结果 
		char** head = new char*[2*result];
		
		for (i = 0; i < result; i++) {
			head[i] = new char[n+1];//字符串结束符
			head[i][0] = '0';head[i][1] = '\0';
			strcat(head[i], temp[i]);
			head[i][n] = '\0';
		}
		for (i = result,j = result-1; i < 2 * result; i++,j--) {
			head[i] = new char[n+1];
			head[i][0] = '1';head[i][1] = '\0';
			strcat(head[i], temp[j]);
			head[i][n] = '\0';
		}
		delete []temp;
		return head;
	}
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



