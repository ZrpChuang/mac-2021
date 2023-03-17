#include<stdio.h>
#include<iostream>
using namespace std;

struct help{
	int val;
	int num;
};
int patition(int* a, int p, int r, int x) {//x��һ��λ�� 
	if (p == r)return r;
	int temp = a[x];//���������temp��
	a[x] = a[p];//�൱�ڵ���λ��
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

int select(int a[], int p, int r, int k)//k����index����ʾ���ǵڼ�����˼
{
	if (r - p <= 10) {
		QSort(a, p, r, p);
		return a[p + k - 1];//�ݹ�ĳ���
	}
	for (int i = 0; i <= (p - r - 4) / 5; i++)//��3���µ�ȫ����Ҫ�ˣ���4��Ҫ
	{
		QSort(a, p + i * 5, p + i * 5 + 4, p + i * 5);
		int temp = a[p + i];//���ڽ���
		a[p + i] = a[p + i * 5 + 2];
		a[p + i * 5 + 2] = temp;//�������
	}
	select(a, p, p + (p - r - 4) / 5, (p - r + 6) / 10);
	int i = patition(a, p, r, (p - r + 6) / 10); int j = i - p + 1;
	if (j == k)return a[i];
	else if (k < j) return select(a, p, i - 1, k);
	else return select(a, i + 1, r, k - j);
}
//�������� 
int patition(help* a, int p, int r, int x) {
	if (p == r)return r;
	help temp;
	temp = a[x];//���������temp��
	a[x] = a[p];//�൱�ڵ���λ��
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

int select(help a[], int p, int r, int k)//k����index����ʾ���ǵڼ�����˼
{
	if (r - p <= 10) {
		QSort(a, p, r, p);
		return a[p + k - 1].val;//�ݹ�ĳ���
	}
	for (int i = 0; i <= (p - r - 4) / 5; i++)//��3���µ�ȫ����Ҫ�ˣ���4��Ҫ
	{
		QSort(a, p + i * 5, p + i * 5 + 4, p + i * 5);
		help temp = a[p + i];//���ڽ���
		a[p + i] = a[p + i * 5 + 2];
		a[p + i * 5 + 2] = temp;//�������
	}
	select(a, p, p + (p - r - 4) / 5, (p - r + 6) / 10);
	int i = patition(a, p, r, (p - r + 6) / 10); int j = i - p + 1;
	if (j == k)return a[i].val;
	else if (k < j) return select(a, p, i - 1, k);
	else return select(a, i + 1, r, k - j);
}

int* findkclose(int* arry,int start,int end, int k)//���ݹ����������㣬�յ㣬k�ĸ���
{
	int len = end - start + 1;//�������������ĳ���
	if(k>=len) return arry;
	int mid,left ,right,i,j;;//place��ʾ��ǰӦ����д�ڼ���λ��
	help* result = new help[2*k];//����ֵ����
	
	left = len / 2; right = len / 2+1;
	if (len % 2 == 0) {//������֧����ʾż��
		int leftval = select(arry, start, end, left);//��ֵ��ֵ�Ѿ����
		int rightval = select(arry, start + right-1, end, 1);
		mid = (leftval+rightval)/2;
	}
	else if (len % 2 == 1) {//��ʾ����
		mid = select(arry, start, end, len/2+1);
		right = len / 2 + 2; 
	}//�������λ��
	printf("���������λ����%d\n",mid);
	int lboundary= 1;int rboundary= len;//������߽���ұ߽� 
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
	cout<<"�������У�";
	for (int i = 0; i < 12; i++) {
		printf("%d    ", a[i]);
	}
	printf("\n");
	int* result = findkclose(a,0,11,5);
	
	
	printf("��ӡ%d������ӽ���λ��������:",k);
	
	for(int i =0;i<k;i++){
		printf("%d    ",result[i]);
	}
	printf("\n");
	
	/*
	int result = select(a, 0, 13, 1);printf("the result is:%d\n", result);*/
	QSort(a, 0, 11, 5);
	cout<<"\n\n\n\n\n�㷨֮��Ĳ��裬����Դ�\n";
	printf("�۲�����:"); 
	for (int i = 0; i < 12; i++) {
		printf("%d    ", a[i]);
	}
	printf("\n");
	
	

	return 0;
}

