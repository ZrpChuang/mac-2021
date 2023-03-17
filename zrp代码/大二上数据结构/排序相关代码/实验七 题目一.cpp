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
//希尔排序的步长是默认的
//堆排序结构体没有用好 
typedef int Status;

typedef struct RedType
{
	int key;
	char information[20];
		
}RedType;

typedef struct ResTypeList
{
	RedType* l;
	int num;
	
}List;

void InsertSort(RedType a[],int n);//插入排序 
void Print(RedType a[],int n);
int Partition(RedType a[],int low ,int hight);//快速排序需要调用的 
void Qsort(RedType a[],int low,int hight);//快速排序
void ShellInsert(RedType a[],int dk,int n);
void ShellSort(RedType a[],int t,int n);//简化希尔排序，增量序列从t递减到1

//堆排序 
void HeapAdjust(RedType a[],int s,int m);//数组，改变节点，调节长度 
Status HeapSort(RedType a[],int n);

void table(RedType a[],int n);
void Input(int n,RedType a[]);

 
int main(void)
{
	//零号位置未使用 
	int n;
	printf("请输入一共有多少个数字："); 
	scanf("%d",&n);
	RedType a[n] ;
	Input(n,a);
	
	table(a,n);
	return 0;
}

void Input(int n,RedType a[])
{
	int i; 
	for(i = 1;i <= n;i++)
	{
		printf("请输入第%d个数字：",i);
		fflush(stdin);
		scanf("%d",&a[i].key);
	}
}

void table(RedType a[],int n)
{
	int choose;
	int t;
	printf(">>>                                 <<<\n");
	printf(">>>      请选择一种排序方式         <<<\n");
	printf(">>>         1.插入排序              <<<\n");
	printf(">>>         2.希尔排序              <<<\n");
	printf(">>>         3.堆排序                <<<\n");
	printf(">>>         4.快速排序              <<<\n");
	printf(">>>         0.结束排序              <<<\n");
	printf(">>>                                 <<<\n");
	
	
	printf("请输入："); 
	scanf("%d",&choose);
	printf("\n");
	while(choose)
	{
		switch(choose)
		{
			case 1:
				InsertSort(a,n);
				Print(a,n);
				break;
			case 2:
				t = n/2;
				ShellSort(a,t,n);
				Print(a,n);
				break;
			case 3:
				HeapSort(a,n);
				break;
			case 4:
				Qsort(a,1,n);
				Print(a,n);
				break;
			default:
				break;	
		}
		printf(">>>                                 <<<\n");
		printf(">>>      请选择一种排序方式         <<<\n");
		printf(">>>         1.插入排序              <<<\n");
		printf(">>>         2.希尔排序              <<<\n");
		printf(">>>         3.堆排序                <<<\n");
		printf(">>>         4.快速排序              <<<\n");
		printf(">>>         0.结束排序              <<<\n");
		printf(">>>                                 <<<\n");
		printf("请输入："); 
		scanf("%d",&choose);
		if(choose)
		{
			printf("重置数组以重新测试别的排序\n");
		    Input(n,a);//重置数组
		}
		 
	}
	
}

Status HeapSort(RedType a[],int n)//数组，还有数组长度
{
	int i;//用于计数
	RedType temp;
	for(i = n/2;i>0;i--)
	{
		HeapAdjust(a,i,n);
	}
	
	for(i = n;i > 1;i--)
	{
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;//放在末尾 
		HeapAdjust(a,1,i-1);
	} 
	Print(a,n);
	return OK;
} 

void HeapAdjust(RedType a[],int s,int m)//数组，改变节点，调节长度 
{
	//s是需要调整的编号，m是长度
	RedType rc = a[s];
	int j;
	for(j = 2*s;j<=m;j*=2)
	{
		if(j<m && a[j].key<a[j+1].key) 
		{
			j++;
		}
		if(!(rc.key < a[j].key))
		{
			break;
		} 
		a[s] = a[j];
		s = j;
	}
	a[s] = rc;
}



void ShellSort(RedType a[],int t,int n)//简化希尔排序，增量序列从t递减到1 
{ 
	for(;t>=1;t--)
	{
		ShellInsert(a,t,n);
	}
	 
}

void ShellInsert(RedType a[],int dk,int n)
{
	int i;
	for(i = 1+dk;i<=n;i++)
	{
		if(a[i].key<a[i-dk].key)
		{
			a[0].key = a[i].key;//暂时存储
			int j;
			for(j = i;a[j].key<a[j-dk].key&&j-dk>0;j=j-dk)
			{
				a[j].key = a[j-dk].key;
			}
			a[j].key = a[0].key; 
		}
	}
}

void Qsort(RedType a[],int low,int hight)
{
	int pivotloc;
	if(low<hight)
	{
		pivotloc = Partition(a,low,hight);
		Qsort(a,low,pivotloc-1);
		Qsort(a,pivotloc+1,hight);
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

void InsertSort(RedType a[],int n)//插入排序 
{
	int j,i;
	for( i = 2;i<=n;i++)
	{
		if(a[i].key < a[i-1].key)//需要排序
		{
			a[0].key = a[i].key;
			a[i].key = a[i-1].key;
			for(j = i-2;a[0].key < a[j].key ;j--)
			{
				a[j+1].key = a[j].key;	
			} 
			a[j+1].key = a[0].key;
		 } 
	}
	
}
void Print(RedType a[],int n)
{
	printf("排序后序列为："); 
	for(int i = 1;i<=n;i++)
	{
		printf("%d ",a[i].key);
	}
	printf("\n");
}
