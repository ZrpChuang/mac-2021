# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# define OVERFLOW -2 

typedef struct Node
{
	int data;
	char otherinfo;
}LNode;

typedef struct ListTable
{
	int num;
	LNode* l;
}List;

void Creat(List &T)
{
	int n;//记录元素个数
	printf("请输入元素个数！");fflush(stdin);
	scanf("%d",&n);
	 
	T.l = (LNode*)malloc((n+1)*sizeof(LNode));
	if(!T.l)exit(OVERFLOW);
	
	for(int i = 1;i<=n;i++)
	{
		printf("请输入第%d个数:",i);fflush(stdin);
		scanf("%d",&T.l[i].data);printf("\n");
	} 
	T.num = n; 
}
void shellsort(List &T)//希尔排序是一个逐个控制步长的希尔排序 
{void shellinsert(List &T,int n);
	int n;//步长起始位置
	printf("请输入起始的步长是多少：");
	fflush(stdin);scanf("%d",&n); 
	while(n>T.num)
	{
		printf("请输入起始的步长是多少：");
		fflush(stdin);scanf("%d",&n); 
	}
	
	for(;n>0;n--)
	{
		shellinsert(T,n);
	}
	
}

void shellinsert(List &T,int n)
{
	int i;int j; 
	for(i = n+1;i<=T.num;i++)
	{
		if(T.l[i].data<T.l[i-n].data&&i>n)
		{
			T.l[0] = T.l[i];
			printf("%d",T.l[0].data);
			T.l[i] = T.l[i-n];
			j = i-n;
			while(T.l[0].data<T.l[j].data && j>n)
			{
				T.l[j+n] = T.l[j];
				j = j-n;
			}
			T.l[j+n] = T.l[0];
		} 
	}
}
void print(List &T)
{
	printf("排序后序列为：");
	 
	for(int i = 1;i<=T.num;i++)
	{
		printf("%d",T.l[i].data);
	}
	printf("\n");
}

int main(void)
{
	List T;
	Creat(T);
	shellsort(T);
	print(T);
	
	return 0;
}
