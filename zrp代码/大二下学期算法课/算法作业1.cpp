#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

void transfrom(char* text,long &num)//�ַ���ģʽת��Ϊ����ģʽ 
{
	num = 0;
	int len = strlen(text);
	for(int i =0;i<len;i++)
	{
		int position = 1;
		for(int j = 0;j<len-i-1;j++){
			position*=10;
		}
		printf("չʾ��С%d\n",text[i]-'0');
		num=num+((int)(text[i]-'0'))*position;
	}
	printf("���num�Ĵ�С%d\n",num); printf("���len�Ĵ�С%d",len);
}
int main(void)
{
	char text[10];//�����ļ�
	FILE* fp1;
	fp1 = fopen("numberfile.txt","r");
	fscanf(fp1,"%s",text);
	fclose(fp1);//scanf("%s",text);
	printf("���������Ƕ��٣�%s\n",text);
	
	long num;
	transfrom(text,num);
	int len = strlen(text);
	//printf("%s\n",text);
	
	//�㷨����
	long a[10] = { 0 };//��ʼ������
	//�����λ
	int single = num % 10;//ȡ����λ��
	int left = num / 10;//ȡ������λ��
	for (int i = 0; i <= single; i++)
	{
		a[i] += 1;//
	}//��λ���������
	for (int i = 0; i <= 9; i++) {
		a[i] += left;
	}
	
	a[0] -= 1;
	//printf("%d", a[0]);
	//��������λ��
	for (int i = 2; i <= len - 1; i++)
	{
		int position = 1;
		for (int j = 0; j <i-1; j++){
			position *= 10;
		}
		int rightnow = (num / position) % 10;//ȡ����ǰλ��������ʹ����λ���й�
		int before = num % position;//ȡ���ڴ�֮ǰ����������ʹ����λ���й�
		int after = num / (position*10);//ȡ���ڴ�֮�������
		a[rightnow] += before + 1;
		for (int i = 0; i < rightnow; i++){
			a[i] += position;//����ʹ����λ���й�
		}//��������������
		for (int i = 0; i <= 9; i++){
			a[i] += after * position;
		}//�㵱ǰ���ֵ�һ��
		a[0]-=position;
	}
	//����ͷ��λ��
	int position = 1;
	for (int i = 0; i < len - 1; i++){
		position *= 10;
	}
	int rightnow = num / position;//ȡ����ǰλ��������ʹ����λ���й�
	int before = num % position;//ȡ���ڴ�֮ǰ����������ʹ����λ���й�
	a[rightnow] += before + 1;
	printf("��ӡ������ֵ��С%d\n", rightnow);
	for(int i = 1; i < rightnow; i++){
		a[i] += position;//����ʹ����λ���й�
	}//��������������
	
	//����ļ�
	FILE* fp2;fp2 = fopen("result.txt","w");
	for (int i = 0; i <= 9; i++)
	{
		fprintf(fp2,"����%dʹ�õĴ�����%d\n", i, a[i]);
	}
	fclose(fp2);
	for (int i = 0; i <= 9; i++)
	{
		printf("����%dʹ�õĴ�����%d\n", i, a[i]);
	}
	

	return 0;
}
