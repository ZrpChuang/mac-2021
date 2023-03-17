#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct mode {
	int val;//众数值得大小 
	int times;//众数出现的次数 
	int place;//众数所在的位置 
};
struct modelist {//众数列表 
	int times;//他们的重数 
	int *result;//存值的大小的数组 
	int resultsize;//数组本身的的大小 
};

mode parttition(int* arry, int &start, int &end) {//基于快排思想的集中排序//start end发生改动
	int left = start; 	int right = end;	mode result;//定义结构体用于返回
	result.times = 1;
	result.val = arry[start];//记录开头的元素 这个元素为本次排序的枢纽
	while (left<right)
	{
		while (left < right && result.val < arry[right])right--;
		if (arry[left] > arry[right]) arry[left] = arry[right];
		else if (arry[left] == arry[right]&& left < right){
			result.times += 1;
			for (int i = left; i > start; i--) {
				arry[i] = arry[i - 1];
			}
			start += 1;//如果在这个环节发现相等，删除左边元素，left+1继续算法
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
	return result;//result 包含中枢的数值大小，且包含中枢的个数
}

modelist FandMode(int* arry, int start, int end) {
	mode  midd= parttition(arry, start, end);//引用 开始与结束会被改变
	modelist fromleft; modelist fromright;
	if (((midd.place - start >= midd.times)&&(midd.place-start>1)) || ((end - midd.place >= midd.times)&&(end - midd.place>1)))
	{
		if (midd.place - start >= midd.times && midd.place - start != 1) {
			fromleft = FandMode(arry, start, midd.place - 1);
			if (fromleft.times == midd.times) {//归一化
				fromleft.resultsize += 1;
				fromleft.result = (int*)realloc(fromleft.result, (fromleft.resultsize+1) * sizeof(int));
				fromleft.result[fromleft.resultsize - 1] = midd.val;//把它加到里面
			}
			else if (fromleft.times < midd.times) {
				fromleft.resultsize = 1;
				fromleft.times = midd.times;
				fromleft.result = (int*)realloc(fromleft.result, 1 * sizeof(int));
				fromleft.result[0] = midd.val;//把它加到里面
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
			if (fromleft.times == fromright.times) {//归一化
				int newsize = fromleft.resultsize = fromleft.resultsize + fromright.resultsize;
				fromleft.result = (int*)realloc(fromleft.result, newsize * sizeof(int));
				for (int i = newsize - fromright.resultsize, j = 0; i < fromleft.resultsize; i++, j++) {
					fromleft.result[i] = fromright.result[j];//把它加到里面
				}
			}
			else if (fromleft.times < fromright.times) {
				fromleft = fromright;//直接覆盖
			}
		}//最终都在数组fromleft对象之中
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
		printf("众数如下：");
		for (int i = 0; i < re.resultsize; i++) {
			printf("%d  ", re.result[i]);
		}

		printf("\n");
		printf("重数是：%d", re.times);
	}
	else printf("没有众数！！");
	
	return 0;
}



