#include<iostream>
#include<stdio.h>
using namespace std;

int findlesscoins(int* value, int* nums, int total,int n) {
	int** dp = new int* [11];
	int** remember = new int* [11];
	int* traceback = new int[n+1];
	for (int i = 0; i <= 10; i++) {
		dp[i] = new int[total+1];
		remember[i] = new int[total + 1];
	}//定义二维矩阵
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= total; j++) {
			remember[i][j] = 0;
		}
	}

	for (int i = 0; i <= 10; i++) {
		dp[i][0] = 0;
	}//初始化首列元素

	for (int j = 1; j <= total;j++) {//初始化首行元素
		int times = j / value[1];
		int left = j % value[1];
		if (times <= nums[1] && left == 0) { dp[1][j] = times; remember[1][j] = times; }
		else { dp[1][j] = -1; remember[1][j] = 0; }
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= total; j++) {
			int times = j / value[i];
			int left = j % value[i];
			if (times <= nums[i]) {//够的，按需求拿
				if (dp[i - 1][left] == -1) dp[i][j] = -1;
				else {
					dp[i][j] = times + dp[i - 1][left];
					remember[i][j] = times;
				}
			}
			else {//不够全部拿完
				if(dp[i - 1][j-nums[i]*value[i]] == -1) dp[i][j] = -1;
				else {
					dp[i][j] = nums[i] + dp[i - 1][j - nums[i] * value[i]];
					remember[i][j] = nums[i];
				}
			}
		}
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= total; j++) {
			printf("%-3d", dp[i][j]);
		}
		cout << endl;
	}
	if (dp[n][total] != -1) {
		int j = total;
		for (int i = n; i > 0; i--) {
			traceback[i] = remember[i][j];
			j -= value[i] * remember[i][j];
		}
		cout << "分别的选取结果" << endl;
		for (int i = 1; i <= n; i++) {
			cout << traceback[i] << " ";
		}
	}
	return dp[n][total];
}

int main(void)
{
	int n = 4;
	int value[5] = {0,2,4,6,7};
	int nums[5] = {0,3,2,2,2};
	int total = 19;
	

	cout << "test example:" << endl;
	cout << n << endl;
	for (int i = 1; i <= n; i++) {
		cout << value[i] << "  " << nums[i] << endl;
	}
	cout << total << endl;
	
	
	int result = findlesscoins(value, nums, total, n);
	if (result == -1) cout << "no result" << endl;
	else {
		cout <<endl<< "the result is:" << result<<endl;
	}
	return 0;
}

/*
cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= total; j++) {
			printf("%-3d", dp[i][j]);
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= total; j++) {
			printf("%-3d", remember[i][j]);
		}
		cout << endl;
	}




*/









