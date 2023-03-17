# include<stdio.h>
# include<stdio.h>
# include<string.h>
# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2

# define RADIX 26//26��Ӣ����ĸ
# define MAX_NUM_OF_KEY 8
typedef int KeyType;
typedef int Status;
typedef struct Node
{
	KeyType keys[MAX_NUM_OF_KEY];
	char name[20];
	int next;
}SLCell;

typedef struct 
{
	SLCell r[20];
	int keynum;//�ؼ������� 
	int recnum;//��̬������ 

}SLList;




void Collect(SLList &l,int i,int f[],int e[])
{
	int t=0;//tail��¼β�� 
	int j=0;
	for(j = 0;!f[j];j++);
    if (f[j]) {
        l.r[0].next=f[j];t=e[j];
    }
	
	while (j<RADIX-1) {//只需要指向10-2，后面会自动加一，所以最后j指向9
        for (j=j+1; j<RADIX-1&&!f[j]; j=j+1);
        if (f[j]) {
            l.r[t].next=f[j];t=e[j];
        }
    }
	l.r[t].next = 0;
}
void Distribute(SLList &l,int i,int f[],int e[])//i�ڼ����ؼ��� 
{
	int j;
	for(j = 0; j<RADIX; j++)
	{
		f[j] = 0;
		e[j] = 0;//��ʼ�����е� 
	}
	for(int p = l.r[0].next; p ;p = l.r[p].next)
	{
		j = l.r[p].keys[i]-65;//ӳ���ϵ����-65 	
		if(!f[j])
		{
			f[j] = p;
		}
		else
		{
			l.r[e[j]].next = p;
		}
		e[j] = p;
	}
}
void RadixSort(SLList &l)
{
	
	int i;
	for(i = 0;i<l.recnum;i++)
	{
		l.r[i].next = i+1;
	}
	l.r[l.recnum].next = 0;//��ʼ�� ��̬����
	
	int f[RADIX];//���帨������ 
	int e[RADIX];
	for(i = l.keynum-1;i>=0;i--)//���Ϊ���Թؼ��������i��Ԫ�صĲ��� 
	{ 
		
		Distribute(l,i,f,e);
		Collect(l,i,f,e);
	} 
	
}
Status InitSllist(SLList &l)
{
	
	l.keynum = 3;//�ؼ��ָ��� 
	printf("�����빲�ж��ٸ�ͬѧ��");fflush(stdin);
	scanf("%d",&l.recnum);printf("\n");
	
	int i;
	
	for(i = 1;i<=l.recnum;i++)
	{
		printf("�������%d��ͬѧƴ����ĸ,ÿһ���ֿ�ͷ��д��",i);fflush(stdin);
		scanf("%s",&l.r[i].name);printf("\n");
		int n = strlen(l.r[i].name);
		
		char D1,D2,D3;
		int k = 0;
		for(int j = 0;j<n;j++)
		{
			if(l.r[i].name[j]>=65&&l.r[i].name[j]<=90)
			{
				l.r[i].keys[k] = l.r[i].name[j];
				k++;
			}
		}
		/*
		fflush(stdin);
		scanf("%c",&D1);getchar();
        scanf("%c",&D2);getchar();
        scanf("%c",&D3);getchar();
        l.r[i].keys[0]=D1;l.r[i].keys[1]=D2;l.r[i].keys[2]=D3;
		*/
		
	}
	
	return OK;
}
Status printresult(SLList &l)
{
	printf("��ʾѧ�Ź�����:\n");
	int j;
	for(int i = l.r[0].next, j = 1;i!=0;j++,i = l.r[i].next)
	{
		printf("ѧ�ţ�20200%d ������д��%c %c %c",j,l.r[i].keys[0],l.r[i].keys[1],l.r[i].keys[2]);
		printf("ȫ��%s\n",l.r[i].name);
	}
	return OK;
}
int main(void)
{
	SLList l;
	
	InitSllist(l);
	RadixSort(l);
	
	printresult(l);
	
	return 0;
}








