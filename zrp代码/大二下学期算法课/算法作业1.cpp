#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

void transfrom(char* text,long &num)//字符串模式转换为整型模式 
{
	num = 0;
	int len = strlen(text);
	for(int i =0;i<len;i++)
	{
		int position = 1;
		for(int j = 0;j<len-i-1;j++){
			position*=10;
		}
		printf("展示大小%d\n",text[i]-'0');
		num=num+((int)(text[i]-'0'))*position;
	}
	printf("输出num的大小%d\n",num); printf("输出len的大小%d",len);
}
int main(void)
{
	char text[10];//读入文件
	FILE* fp1;
	fp1 = fopen("numberfile.txt","r");
	fscanf(fp1,"%s",text);
	fclose(fp1);//scanf("%s",text);
	printf("测试数据是多少：%s\n",text);
	
	long num;
	transfrom(text,num);
	int len = strlen(text);
	//printf("%s\n",text);
	
	//算法处理
	long a[10] = { 0 };//初始化数组
	//先算个位
	int single = num % 10;//取出个位数
	int left = num / 10;//取出其余位数
	for (int i = 0; i <= single; i++)
	{
		a[i] += 1;//
	}//各位多余的数字
	for (int i = 0; i <= 9; i++) {
		a[i] += left;
	}
	
	a[0] -= 1;
	//printf("%d", a[0]);
	//再算其他位数
	for (int i = 2; i <= len - 1; i++)
	{
		int position = 1;
		for (int j = 0; j <i-1; j++){
			position *= 10;
		}
		int rightnow = (num / position) % 10;//取出当前位数。这个和处理的位数有关
		int before = num % position;//取出在此之前的数，这个和处理的位数有关
		int after = num / (position*10);//取出在此之后的数字
		a[rightnow] += before + 1;
		for (int i = 0; i < rightnow; i++){
			a[i] += position;//这个和处理的位数有关
		}//处理多出来的数字
		for (int i = 0; i <= 9; i++){
			a[i] += after * position;
		}//算当前数字的一轮
		a[0]-=position;
	}
	//再算头顶位数
	int position = 1;
	for (int i = 0; i < len - 1; i++){
		position *= 10;
	}
	int rightnow = num / position;//取出当前位数。这个和处理的位数有关
	int before = num % position;//取出在此之前的数，这个和处理的位数有关
	a[rightnow] += before + 1;
	printf("打印现在数值大小%d\n", rightnow);
	for(int i = 1; i < rightnow; i++){
		a[i] += position;//这个和处理的位数有关
	}//处理多出来的数字
	
	//输出文件
	FILE* fp2;fp2 = fopen("result.txt","w");
	for (int i = 0; i <= 9; i++)
	{
		fprintf(fp2,"数字%d使用的次数是%d\n", i, a[i]);
	}
	fclose(fp2);
	for (int i = 0; i <= 9; i++)
	{
		printf("数字%d使用的次数是%d\n", i, a[i]);
	}
	

	return 0;
}
