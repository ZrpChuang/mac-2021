# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2
# define SIZE 20
//ϣ������Ĳ�����Ĭ�ϵ�
//������ṹ��û���ú� 

typedef int Status;
typedef struct RedType
{
	int key;
	char information[20];
		
}RedType;
void Input(int n,RedType a[])
{
	int i; 
	for(i = 1;i <= n;i++)
	{
		printf("�������%d�����֣�",i);
		fflush(stdin);
		scanf("%d",&a[i].key);
	}
}
void QsortMiniK(RedType a[],int low,int hight,int k)//Ѱ�ҵ�kС���� 
{
	int Partition(RedType a[],int low ,int hight); 
	int pivotloc;
	if(low<=hight)
	{
		pivotloc = Partition(a,low,hight);
		if(pivotloc!=k)
		{
			if(pivotloc<k)
			{
				QsortMiniK(a,pivotloc+1,hight,k);
			}
			else//����k 
			{
				QsortMiniK(a,low,pivotloc-1,k);
			}
		}
		else
		printf("��%dС������%d",k,a[k].key);
	}
} 

int Partition(RedType a[],int low ,int hight)
{
	a[0].key = a[low].key;
	int pivotkey = a[low].key;
	while(low < hight)
	{
		while(low < hight && a[hight].key >= pivotkey) 
		{
			--hight;
		}
		a[low].key = a[hight].key;
		while(low<hight&& a[low].key<=pivotkey)
		{
			++low;
		}
		a[hight].key = a[low].key;
	}
	a[low].key = a[0].key;
	
	return low;
}
int main(void)
{
	//���λ��δʹ�� 
	int n;
	printf("������һ���ж��ٸ����֣�"); 
	scanf("%d",&n);
	RedType a[n] ;
	Input(n,a);
	int k;
	printf("������k��ֵ��");
	scanf("%d",&k);
	
	QsortMiniK(a,1,n,k);
	
	return 0;
}
