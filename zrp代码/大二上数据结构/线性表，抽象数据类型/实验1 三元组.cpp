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
typedef ElemType* Triplet;//Triplet����Ϊָ�� 

/*��Ԫ����������
Status InitTriplet(Triplet &T,ElemType v1, ElemType v2, ElemType v3)
//������Ԫ��T,Ԫ��e1,e2,e3,�ֱ�ֵ��v1,v2.v3
Status Get(Triplet &T,int i,ElemType e)
//��ȡ��Ԫ�飬��ȡ��i������ͨ��e������
Status Put(Triplet T,int I,ElemType &e)
//�ı���Ԫ���i������ֵ
Status Max(Triplet T,ElemType & e)
//����T�е����ֵ
Status Min(Triplet T,ElemType & e)
����T�е���Сֵ*/ 


Status InitTriplet(Triplet* T,int v1,int v2,int v3) 
{
	(*T) = (ElemType *)malloc (LIST_INIT_SIZE*sizeof(int));//����һ��ָ�� 
	If(!(*T))exit(OVERFLOW);
	//����洢�ռ�ʧ��
	(*T)[0] = v1;
	(*T)[1] = v2;
	(*T)[2] = v3;
	
	return OK;
}
Status Put(Triplet* T)//���뺯�� 
{
	int i,e;
	printf("����Ҫ�ı�ڼ���Ԫ��\n");
	scanf("%d",&i);
	printf("��Ҫ�Ѹ�Ԫ�ظĳɶ���\n"); 
 	scanf("%d",&e);
 	(*T)[i-1] = e;
 return OK;
}

/*int Max(struct Triplet *T)//������ 
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

Status Get(struct Triplet T)//������� 
{
	int i,e;
	printf("��Ҫ����ڼ���Ԫ��");
	scanf("%d",&i);
	printf("%d\n",T[i-1]);
	
	return OK;
} */ 
 

int main(void)
{
 int T1;
 Triplet T = &T1;
 int v1,v2,v3;
 
 printf("������v1,v2,v3��ֵ���ö��Ÿ���\n");
 
 scanf("%d,%d,%d",&v1,&v2,&v3);
 //InitTriplet(&T,v1,v2,v3);
 printf("%d,%d,%d",T[1],T[2],T[3]);
 return 0;
}
