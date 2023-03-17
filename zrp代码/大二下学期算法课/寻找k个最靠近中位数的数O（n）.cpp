#include<stdio.h>
#include<iostream>
using namespace std;

struct help{
	int val;
	int num;
};
int patition(int* a, int p, int r, int x) {//x是一个位置 
	if (p == r)return r;
	int temp = a[x];//把中枢放在temp中
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
	select(a, p, p + (p - r - 4) / 5, (p - r + 6) / 10);
	int i = patition(a, p, r, (p - r + 6) / 10); int j = i - p + 1;
	if (j == k)return a[i];
	else if (k < j) return select(a, p, i - 1, k);
	else return select(a, i + 1, r, k - j);
}
//函数重载 
int patition(help* a, int p, int r, int x) {
	if (p == r)return r;
	help temp;
	temp = a[x];//把中枢放在temp中
	a[x] = a[p];//相当于调换位置
	while (p < r) {
		while (p < r && a[r].val >= temp.val) r--;
		a[p] = a[r];
		while (p < r && a[p].val <= temp.val) p++;
		a[r] = a[p];
	}
	a[r] = temp;
	return r;
}

void QSort(help a[], int p, int r, int x) {
	int min = patition(a, p, r, x);
	if (min - 1 > p) QSort(a, p, min - 1, p);
	if (min + 1 < r) QSort(a, min + 1, r, min + 1);
}

int select(help a[], int p, int r, int k)//k不是index，表示的是第几的意思
{
	if (r - p <= 10) {
		QSort(a, p, r, p);
		return a[p + k - 1].val;//递归的出口
	}
	for (int i = 0; i <= (p - r - 4) / 5; i++)//余3以下的全都不要了，余4还要
	{
		QSort(a, p + i * 5, p + i * 5 + 4, p + i * 5);
		help temp = a[p + i];//用于交换
		a[p + i] = a[p + i * 5 + 2];
		a[p + i * 5 + 2] = temp;//交换完成
	}
	select(a, p, p + (p - r - 4) / 5, (p - r + 6) / 10);
	int i = patition(a, p, r, (p - r + 6) / 10); int j = i - p + 1;
	if (j == k)return a[i].val;
	else if (k < j) return select(a, p, i - 1, k);
	else return select(a, i + 1, r, k - j);
}

int* findkclose(int* arry,int start,int end, int k)//传递过来数组的起点，终点，k的个数
{
	int len = end - start + 1;//计算出传递数组的长度
	if(k>=len) return arry;
	int mid,left ,right,i,j;;//place表示当前应该填写第几个位置
	help* result = new help[2*k];//返回值数组
	
	left = len / 2; right = len / 2+1;
	if (len % 2 == 0) {//条件分支，表示偶数
		int leftval = select(arry, start, end, left);//左值右值已经完成
		int rightval = select(arry, start + right-1, end, 1);
		mid = (leftval+rightval)/2;
	}
	else if (len % 2 == 1) {//表示奇数
		mid = select(arry, start, end, len/2+1);
		right = len / 2 + 2; 
	}//计算出中位数
	printf("算出来的中位数是%d\n",mid);
	int lboundary= 1;int rboundary= len;//定义左边界和右边界 
	if(left-k+1>1){
		lboundary = left-k+1;
		select(arry,start,start + left-1,left-k+1);
	} 
	
	if(right+k-1<len){
		rboundary = right+k-1;
		select(arry, start + right - 1, end, k);
	}
	
	int resultlen = 0 ;
	for(i = 0,j = start+lboundary-1;j <=start + left-1;i++,j++){
		result[i].num = arry[j];
		result[i].val = mid-arry[j];
		resultlen +=1;
	}
	for(j = start+right-1;j<=start + rboundary-1;i++,j++){
		result[i].num = arry[j];
		result[i].val = arry[j] - mid;
		resultlen +=1;
	}
	if(len % 2 == 1) {
		result[i].num = mid;
		result[i].val = 0;
		resultlen+=1;
	}
	select(result,0,resultlen-1,k);
	int* outcome = new int(k);
	for(i = 0;i<k;i++){
		outcome[i] = result[i].num;
	}
	
	return outcome;
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
	
	/*
	int result = select(a, 0, 13, 1);printf("the result is:%d\n", result);*/
	QSort(a, 0, 11, 5);
	cout<<"\n\n\n\n\n算法之外的步骤，方便对答案\n";
	printf("观察序列:"); 
	for (int i = 0; i < 12; i++) {
		printf("%d    ", a[i]);
	}
	printf("\n");
	
	

	return 0;
}

