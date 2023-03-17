# include<stdio.h> 
# include<stdlib.h>
# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2
# define LIST_INIT_SIZE 3


/*��Ԫ����������
Status InitTriplet(Triplet &T,ElemType v1, ElemType v2, ElemType v3)
//������Ԫ��T,Ԫ��e1,e2,e3,�ֱ�ֵ��v1,v2.v3
Status Get(Triplet T,int i,ElemType &e)
//��ȡ��Ԫ�飬��ȡ��i������ͨ��e������
Status Put(Triplet &T,int I,ElemType e)
//�ı���Ԫ���i������ֵ
Status Max(Triplet T,ElemType & e)
//����T�е����ֵ
Status Min(Triplet T,ElemType & e)
����T�е���Сֵ*/ 

typedef int Status;
typedef int ElemType;
typedef ElemType* Triplet;//Triplet����Ϊָ��

Status InitTriplet(Triplet*T,int v1,int v2,int v3);
Status Get(Triplet T,int i,int *e);
Status Put(Triplet *T,int i,int e);
Status Max(Triplet T,int *e);
Status Min(Triplet T,int *e);
//��������ָ��ֱ����ڷ�������ֵ 



int main(void)//������ 
{
 int T1,e,i;
 Triplet T = &T1;//Ϊ�˷�ָֹ��Ƿ����� 
 int v1;int v2;int v3;//������Ԫ���ԭʼ3��Ԫ�� 
 
 printf("������v1,v2,v3��ֵ���ö��Ÿ���\n");
 scanf("%d,%d,%d",&v1,&v2,&v3);
 
 InitTriplet(&T,v1,v2,v3);//���ô������� 
 
 printf("������ȡ��Ԫ���е�ֵ������Ҫ��ȡ��Ԫ���еĵڼ���ֵ\n");
 scanf("%d",&i);
 Get(T,i,&e);
 printf("��Ԫ���еĵ�%d��ֵΪ%d\n",i,e);

 printf("������������Ҫ��ı���Ԫ���ֵ������Ҫ�ı���Ԫ���еĵڼ���ֵ\n");
 scanf("%d",&i);
 printf("����Ҫ�ı�ɶ���\n");
 scanf("%d",&e);
 Put(&T,i,e);//�ı�����Ԫ�� 
 
 printf("���ڽ���ȡ��Ԫ���е����ֵ\n");
 Max(T,&e);//����Ԫ�������ֵ���д�������Ԫ�� 
 printf("���ֵΪ%d\n",e);
 
 printf("���ڽ���ȡ��Ԫ���е���Сֵ\n");
 Min(T,&e);
 printf("��СֵΪ%d\n",e);
 
 printf("������յ���Ԫ��\n");
 printf("%d,%d,%d\n",T[0],T[1],T[2]);//��� ��������Ԫ�� 
 
 system("pause");
 
 printf("�ҵ�������������\nרҵ���������ѧ�뼼��\nѧ�ţ�2020101124"); 
 
 return 0;
}

Status InitTriplet(Triplet*T,int v1,int v2,int v3)//�������� 
{
	(*T) = (ElemType *)malloc (LIST_INIT_SIZE*sizeof(int));
	if(!(*T))exit(OVERFLOW);
	
	(*T)[0] = v1;
	(*T)[1] = v2;
	(*T)[2] = v3;
	
	return OK;
}

Status Get(Triplet T,int i,int *e)//��ȡ���� 
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


