# include<stdio.h> 
# include<stdlib.h>
# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2
# define LIST_INIT_SIZE 3


/*三元组的输入输出
Status InitTriplet(Triplet &T,ElemType v1, ElemType v2, ElemType v3)
//构造三元组T,元素e1,e2,e3,分别赋值给v1,v2.v3
Status Get(Triplet T,int i,ElemType &e)
//读取三元组，读取第i个数，通过e来返回
Status Put(Triplet &T,int I,ElemType e)
//改变三元组第i个数的值
Status Max(Triplet T,ElemType & e)
//返回T中的最大值
Status Min(Triplet T,ElemType & e)
返回T中的最小值*/ 

typedef int Status;
typedef int ElemType;
typedef ElemType* Triplet;//Triplet本身为指针

Status InitTriplet(Triplet*T,int v1,int v2,int v3);
Status Get(Triplet T,int i,int *e);
Status Put(Triplet *T,int i,int e);
Status Max(Triplet T,int *e);
Status Min(Triplet T,int *e);
//以上三个指针分别用于返回三个值 



int main(void)//主函数 
{
 int T1,e,i;
 Triplet T = &T1;//为了防止指向非法变量 
 int v1;int v2;int v3;//插入三元组的原始3个元素 
 
 printf("请输入v1,v2,v3的值，用逗号隔开\n");
 scanf("%d,%d,%d",&v1,&v2,&v3);
 
 InitTriplet(&T,v1,v2,v3);//调用创建函数 
 
 printf("即将提取三元组中的值，请问要提取三元组中的第几个值\n");
 scanf("%d",&i);
 Get(T,i,&e);
 printf("三元组中的第%d个值为%d\n",i,e);

 printf("即将按照您的要求改变三元组的值，请问要改变三元组中的第几个值\n");
 scanf("%d",&i);
 printf("请问要改变成多少\n");
 scanf("%d",&e);
 Put(&T,i,e);//改变其中元素 
 
 printf("现在将求取三元组中的最大值\n");
 Max(T,&e);//求三元组内最大值所有处理后的三元组 
 printf("最大值为%d\n",e);
 
 printf("现在将求取三元组中的最小值\n");
 Min(T,&e);
 printf("最小值为%d\n",e);
 
 printf("输出最终的三元组\n");
 printf("%d,%d,%d\n",T[0],T[1],T[2]);//输出 处理后的三元组 
 
 system("pause");
 
 printf("我的姓名：张瑞鹏\n专业：计算机科学与技术\n学号：2020101124"); 
 
 return 0;
}

Status InitTriplet(Triplet*T,int v1,int v2,int v3)//创建函数 
{
	(*T) = (ElemType *)malloc (LIST_INIT_SIZE*sizeof(int));
	if(!(*T))exit(OVERFLOW);
	
	(*T)[0] = v1;
	(*T)[1] = v2;
	(*T)[2] = v3;
	
	return OK;
}

Status Get(Triplet T,int i,int *e)//提取函数 
{
	
	
	(*e) = T[i-1];
	
	return OK;
}

Status Put(Triplet *T,int i,int e)
{
	
	(*T)[i-1] = e;
	
	return OK;
}

Status Max(Triplet T,int *e)
{
	int temp;
	int s[2];
	s[0] = T[0];
	s[1] = T[1];
	s[2] = T[2];
	
	if (s[0]>s[1])
		{
			temp = s[0];
			s[0] = s[1];
			s[1] = temp;
		}
	if (s[1]>s[2]) 	
		{
			temp = s[1];
			s[1] = s[2];
			s[2] = temp;
		}
	(*e) = s[2];
	
	return OK;
}

Status Min(Triplet T,int *e)
{
	int temp;
	int s[2];
	s[0] = T[0];
	s[1] = T[1];
	s[2] = T[2];
	
	if (s[0]<s[1])
		{
			temp = s[0];
			s[0] = s[1];
			s[1] = temp;
		}
	if (s[1]<s[2]) 	
		{
			temp = s[1];
			s[1] = s[2];
			s[2] = temp;
		}
	(*e) = s[2];
	
	return OK;
}


