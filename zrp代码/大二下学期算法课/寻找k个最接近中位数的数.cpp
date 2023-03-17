#include<stdio.h>
#include<iostream>
using namespace std;

int patition(int* a, int p, int r, int x) {
	if (p == r)return r;
	int temp;
	temp = a[x];//把中枢放在temp中
	a[x] = a[p];//相当于调换位置
	while (p < r) {
		while (p < r && a[r] >= temp) r--;
		a[p] = a[r];
		while (p < r && a[p] <= temp) p++;
		a[r] = a[p];
	}
	a[r] = temp;
	return r;
}

void QSort(int a[], int p, int r, int x) {
	int min = patition(a, p, r, x);
	if (min - 1 > p) QSort(a, p, min - 1, p);
	if (min + 1 < r) QSort(a, min + 1, r, min + 1);
}

int select(int a[], int p, int r, int k)//k不是index，表示的是第几的意思
{
	if (r - p <= 10) {
		QSort(a, p, r, p);
		return a[p + k - 1];//递归的出口
	}
	for (int i = 0; i <= (p - r - 4) / 5; i++)//余3以下的全都不要了，余4还要
	{
		QSort(a, p + i * 5, p + i * 5 + 4, p + i * 5);
		int temp = a[p + i];//用于交换
		a[p + i] = a[p + i * 5 + 2];
		a[p + i * 5 + 2] = temp;//交换完成
	}
	int x = select(a, p, p + (p - r - 4) / 5, (p - r + 6) / 10);
	int i = patition(a, p, r, (p - r + 6) / 10); int j = i - p + 1;
	if (j == k)return a[i];
	else if (k < j) return select(a, p, i - 1, k);
	else return select(a, i + 1, r, k - j);
}

int* findkclose(int* arry,int start,int end, int k)//传递过来数组的起点，终点，k的个数
{
	int len = end - start + 1;//计算出传递数组的长度
	if(k>=len) return arry;
	int mid;//表示中位数
	int left ,right,place;//place表示当前应该填写第几个位置
	int* result = new int[k];//返回值数组
	if (len % 2 == 0) {//条件分支，表示偶数
		int leftval, rightval;left = len / 2; right = len / 2+1;
		leftval = select(arry, start, end, left);//左值右值已经完成
		rightval = select(arry, start + right-1, end, 1);
		printf("left = %d,right = %d\n",arry[start + left - 1],arry[start + right - 1]);
		mid = (leftval+rightval)/2;
		place = 0;
	}
	else if (len % 2 == 1) {//表示奇数
		mid = select(arry, start, end, len/2+1);
		left = len / 2; right = len / 2 + 2; 
		result[0] = mid; if (k == 1)return result;
		place = 1;
		select(arry, start, start + left-1,left);//一个也不能多
		select(arry, start + right - 1, end, 1);//一个也不多
	}//计算出中位数
	printf("中位数的大小是%d\n",mid);
	while (place < k) {
		printf("left = %d,right = %d\n",arry[start + left - 1],arry[start + right - 1]);
		if (start + right - 1 > end) {
			result[place] = arry[start + left - 1]; place++;//位置++
			left--;
			select(arry, start, start + left - 1, left);//更新左位置
		}
		else if (left < 1) {
			result[place] = arry[start + right - 1]; place++;
			right++;
			select(arry, start + right - 1, end, 1);
		}
		else {
			if ((mid - arry[start + left - 1]) < (arry[start + right - 1] - mid)) {//左边应该放进数组
				result[place] = arry[start + left - 1]; place++;//位置++
				left--;
				select(arry, start, start + left - 1, left);//更新左位置
			}
			else if ((mid - arry[start + left - 1]) > (arry[start + right - 1] - mid)) {
				result[place] = arry[start + right - 1]; place++;
				right++;
				select(arry, start + right - 1, end, 1);
			}
			else {
				result[place] = arry[start + left - 1]; place++;
				if (place >= k) return result;
				result[place] = arry[start + right - 1]; place++;
				right++; left--;
				select(arry, start, start + left - 1, left); select(arry, start + right - 1, end, 1);
			}
		}
	}

	return result;
}

int main(void)
{
	
	int a[12] = { 42,33,12,5,7,234,1,0,9,8,23,-1};
	int k = 5;
	cout<<"输入序列：";
	for (int i = 0; i < 12; i++) {
		printf("%d    ", a[i]);
	}
	printf("\n");
	
	int* result = findkclose(a,0,11,5);
	
	
	
	printf("打印%d个最近接近中位数的数字:",k);
	
	for(int i =0;i<k;i++){
		printf("%d    ",result[i]);
	}
	printf("\n");
	
	QSort(a, 0, 11, 5);
	printf("排序观察:"); 
	for (int i = 0; i < 12; i++) {
		printf("%d    ", a[i]);
	}
	printf("\n");
	
	

	return 0;
}

