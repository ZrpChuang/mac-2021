#include<stdio.h>
int patition(int* a, int p, int r, int x) {//�����ϻ��ǿ������� 
	if (p == r)return r;
	int temp;
	temp = a[x];//���������temp��
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
	if(min-1>p) QSort(a, p, min-1, p);
	if(min+1<r) QSort(a, min + 1, r, min + 1);
}

int select(int a[], int p, int r, int k)
{
	if (r - p <= 10) {
		QSort(a, p, r, p);
		return a[p + k - 1];//�ݹ�ĳ���
	}
	for (int i = 0; i <= (p - r - 4) / 5; i++)//��3���µ�ȫ����Ҫ�ˣ���4��Ҫ
	{
		QSort(a, p+i*5, p+i*5+4, p + i * 5);
		int temp = a[p+i];//���ڽ���
		a[p + i] = a[p + i * 5 + 2];
		a[p + i * 5 + 2] = temp;//�������
	}
	int x = select(a, p, p + (p - r - 4) / 5, (p - r + 6) / 10);
	int i = patition(a, p, r, x); int j = i - p + 1;
	if (j == k)return a[i];
	else if (k < j) return select(a, p, i - 1, k);
	else return select(a, i + 1, r, k - j);

}

 

int main(void)
{
	
	int a[14] = {4,3,2,5,7,8,1,0,54,65,23,546,78,87};
	int result = select(a, 0, 13, 6);
	for (int i = 0; i < 13; i++) {
		printf("%d\n", a[i]);
	}
	printf("the result is:%d\n", result);
	//QSort(a, 0, 13, 5);
	for (int i = 0; i < 13; i++) {
		printf("%d\n", a[i]);
	}
	
	

	return 0;
}
