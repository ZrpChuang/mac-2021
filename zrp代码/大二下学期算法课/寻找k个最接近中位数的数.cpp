#include<stdio.h>
#include<iostream>
using namespace std;

int patition(int* a, int p, int r, int x) {
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
	int x = select(a, p, p + (p - r - 4) / 5, (p - r + 6) / 10);
	int i = patition(a, p, r, (p - r + 6) / 10); int j = i - p + 1;
	if (j == k)return a[i];
	else if (k < j) return select(a, p, i - 1, k);
	else return select(a, i + 1, r, k - j);
}

int* findkclose(int* arry,int start,int end, int k)//���ݹ����������㣬�յ㣬k�ĸ���
{
	int len = end - start + 1;//�������������ĳ���
	if(k>=len) return arry;
	int mid;//��ʾ��λ��
	int left ,right,place;//place��ʾ��ǰӦ����д�ڼ���λ��
	int* result = new int[k];//����ֵ����
	if (len % 2 == 0) {//������֧����ʾż��
		int leftval, rightval;left = len / 2; right = len / 2+1;
		leftval = select(arry, start, end, left);//��ֵ��ֵ�Ѿ����
		rightval = select(arry, start + right-1, end, 1);
		printf("left = %d,right = %d\n",arry[start + left - 1],arry[start + right - 1]);
		mid = (leftval+rightval)/2;
		place = 0;
	}
	else if (len % 2 == 1) {//��ʾ����
		mid = select(arry, start, end, len/2+1);
		left = len / 2; right = len / 2 + 2; 
		result[0] = mid; if (k == 1)return result;
		place = 1;
		select(arry, start, start + left-1,left);//һ��Ҳ���ܶ�
		select(arry, start + right - 1, end, 1);//һ��Ҳ����
	}//�������λ��
	printf("��λ���Ĵ�С��%d\n",mid);
	while (place < k) {
		printf("left = %d,right = %d\n",arry[start + left - 1],arry[start + right - 1]);
		if (start + right - 1 > end) {
			result[place] = arry[start + left - 1]; place++;//λ��++
			left--;
			select(arry, start, start + left - 1, left);//������λ��
		}
		else if (left < 1) {
			result[place] = arry[start + right - 1]; place++;
			right++;
			select(arry, start + right - 1, end, 1);
		}
		else {
			if ((mid - arry[start + left - 1]) < (arry[start + right - 1] - mid)) {//���Ӧ�÷Ž�����
				result[place] = arry[start + left - 1]; place++;//λ��++
				left--;
				select(arry, start, start + left - 1, left);//������λ��
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
	
	QSort(a, 0, 11, 5);
	printf("����۲�:"); 
	for (int i = 0; i < 12; i++) {
		printf("%d    ", a[i]);
	}
	printf("\n");
	
	

	return 0;
}

