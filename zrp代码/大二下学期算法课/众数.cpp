#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct mode {
	int val;//����ֵ�ô�С 
	int times;//�������ֵĴ��� 
	int place;//�������ڵ�λ�� 
};
struct modelist {//�����б� 
	int times;//���ǵ����� 
	int *result;//��ֵ�Ĵ�С������ 
	int resultsize;//���鱾��ĵĴ�С 
};

mode parttition(int* arry, int &start, int &end) {//���ڿ���˼��ļ�������//start end�����Ķ�
	int left = start; 	int right = end;	mode result;//����ṹ�����ڷ���
	result.times = 1;
	result.val = arry[start];//��¼��ͷ��Ԫ�� ���Ԫ��Ϊ�����������Ŧ
	while (left<right)
	{
		while (left < right && result.val < arry[right])right--;
		if (arry[left] > arry[right]) arry[left] = arry[right];
		else if (arry[left] == arry[right]&& left < right){
			result.times += 1;
			for (int i = left; i > start; i--) {
				arry[i] = arry[i - 1];
			}
			start += 1;//�����������ڷ�����ȣ�ɾ�����Ԫ�أ�left+1�����㷨
		}
		if(left <start) left += 1;

		while (left < right && result.val >arry[left])left++;
		if (arry[left] > arry[right]) arry[right] = arry[left];
		else if (arry[left] == arry[right]&& left < right) {
			result.times += 1;
			for (int i = right; i < end; i++) {
				arry[i] = arry[i + 1];
			}
			end-= 1;
		}
		if(right>end)right -= 1;
	}
	result.place = left;
	arry[left] = result.val;
	return result;//result �����������ֵ��С���Ұ�������ĸ���
}

modelist FandMode(int* arry, int start, int end) {
	mode  midd= parttition(arry, start, end);//���� ��ʼ������ᱻ�ı�
	modelist fromleft; modelist fromright;
	if (((midd.place - start >= midd.times)&&(midd.place-start>1)) || ((end - midd.place >= midd.times)&&(end - midd.place>1)))
	{
		if (midd.place - start >= midd.times && midd.place - start != 1) {
			fromleft = FandMode(arry, start, midd.place - 1);
			if (fromleft.times == midd.times) {//��һ��
				fromleft.resultsize += 1;
				fromleft.result = (int*)realloc(fromleft.result, (fromleft.resultsize+1) * sizeof(int));
				fromleft.result[fromleft.resultsize - 1] = midd.val;//�����ӵ�����
			}
			else if (fromleft.times < midd.times) {
				fromleft.resultsize = 1;
				fromleft.times = midd.times;
				fromleft.result = (int*)realloc(fromleft.result, 1 * sizeof(int));
				fromleft.result[0] = midd.val;//�����ӵ�����
			}
		}
		else {
			fromleft.resultsize = 1;
			fromleft.times = midd.times;
			fromleft.result = (int*)malloc(1*sizeof(int));
			fromleft.result[0] = midd.val;
		}
		if (end - midd.place >= midd.times && end - midd.place != 1) {
			fromright = FandMode(arry, midd.place + 1, end);
			if (fromleft.times == fromright.times) {//��һ��
				int newsize = fromleft.resultsize = fromleft.resultsize + fromright.resultsize;
				fromleft.result = (int*)realloc(fromleft.result, newsize * sizeof(int));
				for (int i = newsize - fromright.resultsize, j = 0; i < fromleft.resultsize; i++, j++) {
					fromleft.result[i] = fromright.result[j];//�����ӵ�����
				}
			}
			else if (fromleft.times < fromright.times) {
				fromleft = fromright;//ֱ�Ӹ���
			}
		}//���ն�������fromleft����֮��
	}
	else {
		fromleft.resultsize = 1;
		fromleft.times = midd.times;
		fromleft.result = (int*)malloc(1*sizeof(int));
		fromleft.result[0] = midd.val;
	}
	return fromleft;
}

int main(void) {
	int a[13] = {2,2,4,5,2,6,65,36,1,1,6,1,6};
	int start = 0;
	int end = 12;
	modelist re =  FandMode(a, start, end);

	if (re.times > 1) {
		printf("�������£�");
		for (int i = 0; i < re.resultsize; i++) {
			printf("%d  ", re.result[i]);
		}

		printf("\n");
		printf("�����ǣ�%d", re.times);
	}
	else printf("û����������");
	
	return 0;
}



