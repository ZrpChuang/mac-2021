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

typedef struct ResTypeList
{
	RedType* l;
	int num;
	
}List;

void InsertSort(RedType a[],int n);//�������� 
void Print(RedType a[],int n);
int Partition(RedType a[],int low ,int hight);//����������Ҫ���õ� 
void Qsort(RedType a[],int low,int hight);//��������
void ShellInsert(RedType a[],int dk,int n);
void ShellSort(RedType a[],int t,int n);//��ϣ�������������д�t�ݼ���1

//������ 
void HeapAdjust(RedType a[],int s,int m);//���飬�ı�ڵ㣬���ڳ��� 
Status HeapSort(RedType a[],int n);

void table(RedType a[],int n);
void Input(int n,RedType a[]);

 
int main(void)
{
	//���λ��δʹ�� 
	int n;
	printf("������һ���ж��ٸ����֣�"); 
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
		printf("�������%d�����֣�",i);
		fflush(stdin);
		scanf("%d",&a[i].key);
	}
}

void table(RedType a[],int n)
{
	int choose;
	int t;
	printf(">>>                                 <<<\n");
	printf(">>>      ��ѡ��һ������ʽ         <<<\n");
	printf(">>>         1.��������              <<<\n");
	printf(">>>         2.ϣ������              <<<\n");
	printf(">>>         3.������                <<<\n");
	printf(">>>         4.��������              <<<\n");
	printf(">>>         0.��������              <<<\n");
	printf(">>>                                 <<<\n");
	
	
	printf("�����룺"); 
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
		printf(">>>      ��ѡ��һ������ʽ         <<<\n");
		printf(">>>         1.��������              <<<\n");
		printf(">>>         2.ϣ������              <<<\n");
		printf(">>>         3.������                <<<\n");
		printf(">>>         4.��������              <<<\n");
		printf(">>>         0.��������              <<<\n");
		printf(">>>                                 <<<\n");
		printf("�����룺"); 
		scanf("%d",&choose);
		if(choose)
		{
			printf("�������������²��Ա������\n");
		    Input(n,a);//��������
		}
		 
	}
	
}

Status HeapSort(RedType a[],int n)//���飬�������鳤��
{
	int i;//���ڼ���
	RedType temp;
	for(i = n/2;i>0;i--)
	{
		HeapAdjust(a,i,n);
	}
	
	for(i = n;i > 1;i--)
	{
		temp = a[1];
		a[1] = a[i];
		a[i] = temp;//����ĩβ 
		HeapAdjust(a,1,i-1);
	} 
	Print(a,n);
	return OK;
} 

void HeapAdjust(RedType a[],int s,int m)//���飬�ı�ڵ㣬���ڳ��� 
{
	//s����Ҫ�����ı�ţ�m�ǳ���
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



void ShellSort(RedType a[],int t,int n)//��ϣ�������������д�t�ݼ���1 
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
			a[0].key = a[i].key;//��ʱ�洢
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

void InsertSort(RedType a[],int n)//�������� 
{
	int j,i;
	for( i = 2;i<=n;i++)
	{
		if(a[i].key < a[i-1].key)//��Ҫ����
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
	printf("���������Ϊ��"); 
	for(int i = 1;i<=n;i++)
	{
		printf("%d ",a[i].key);
	}
	printf("\n");
}
