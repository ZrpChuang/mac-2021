# include<stdio.h> 
# include<stdlib.h>
# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2
# define LIST_INIT_SIZE 3

typedef int Status;
typedef int ElemType;
typedef ElemType* Triplet;//Triplet本身为指针 

/*三元组的输入输出
Status InitTriplet(Triplet &T,ElemType v1, ElemType v2, ElemType v3)
//构造三元组T,元素e1,e2,e3,分别赋值给v1,v2.v3
Status Get(Triplet &T,int i,ElemType e)
//读取三元组，读取第i个数，通过e来返回
Status Put(Triplet T,int I,ElemType &e)
//改变三元组第i个数的值
Status Max(Triplet T,ElemType & e)
//返回T中的最大值
Status Min(Triplet T,ElemType & e)
返回T中的最小值*/ 


Status InitTriplet(Triplet* T,int v1,int v2,int v3) 
{
	(*T) = (ElemType *)malloc (LIST_INIT_SIZE*sizeof(int));//返回一个指针 
	If(!(*T))exit(OVERFLOW);
	//分配存储空间失败
	(*T)[0] = v1;
	(*T)[1] = v2;
	(*T)[2] = v3;
	
	return OK;
}
Status Put(Triplet* T)//输入函数 
{
	int i,e;
	printf("你想要改变第几个元素\n");
	scanf("%d",&i);
	printf("想要把该元素改成多少\n"); 
 	scanf("%d",&e);
 	(*T)[i-1] = e;
 return OK;
}

/*int Max(struct Triplet *T)//排序函数 
{
	float s[2];
	s[0] = (*T)[0];
	s[1] = (*T)[1];
	s[2] = (*T)[2];
	int i,j;
	float temp;
	
	for(i = 2;i >= 0;i-- )
	{
		for(j = 2;j <= i;j++)
		{
			if(s[j] < s[j+1])
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
	(*T)[0] = s[0];
	(*T)[1] = s[1];
	(*T)[2] = s[2];
	
	return s[0];
}

Status Get(struct Triplet T)//输出函数 
{
	int i,e;
	printf("想要输出第几个元素");
	scanf("%d",&i);
	printf("%d\n",T[i-1]);
	
	return OK;
} */ 
 

int main(void)
{
 int T1;
 Triplet T = &T1;
 int v1,v2,v3;
 
 printf("请输入v1,v2,v3的值，用逗号隔开\n");
 
 scanf("%d,%d,%d",&v1,&v2,&v3);
 //InitTriplet(&T,v1,v2,v3);
 printf("%d,%d,%d",T[1],T[2],T[3]);
 return 0;
}
