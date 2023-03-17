#include<stdio.h>
#include<stdlib.h>

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2 
# define STACKSIZE 3

/*
	���������������������õ��µĶ������������������
	���������� 
	���������� 
	���������
*/
typedef int Status;

typedef struct BiTNode//���Ľڵ� 
{
	
	int data;//���������ֱ����int���� 
	BiTNode* lchild;//���������������ϵ� 
	BiTNode* rchild;
	
}*BiTree;

Status InitBiTree(BiTree* T);//�����µĶ����� 
Status CreateBiTree(BiTree* T);//����Ԫ�� 
Status OutPutBiTree(BiTree* T);//������������� 
Status ExchangeChild(BiTree* T);//���������� 
Status ReNumBiTree(BiTree* T);
//Status WithOtrcrsn(BiTree* T);
/*Status PTraverse();//����������ڱ�������������� 
Status Print();*/

static int i;

int main(void)
{
	
	i = 0; 
	BiTree T1;
	InitBiTree(&T1);
	printf("==========================================\n");
	printf("=   ������һ�������������ܽ�����������   =\n");
	printf("=      ���ĳ���ڵ�Ϊ�սڵ�������666     =\n");
	printf("=        ����Ķ����������ٰ���666       =\n");
	printf("==========================================\n");
	CreateBiTree(&T1);
	
	printf("\n");
	printf("��⹹��Ч��,�������\n");
	OutPutBiTree(&T1);

	ReNumBiTree(&T1);
	printf("���ؽڵ����%d\n",i);
	i = 0;

	
	printf("\n");
	
	
	
	
	printf("\n");
	printf("��⽻��Ч�����������\n");
	
	ExchangeChild(&T1);
	OutPutBiTree(&T1);

	ReNumBiTree(&T1);
	printf("���ؽڵ����%d\n",i);
	i = 0;
	
	
	printf("\n");
	
	
	
	return 0;
} 

Status InitBiTree(BiTree* T)//�����յĶ����� 
{
	*T = NULL;
	
	return OK;
}

Status CreateBiTree(BiTree* T)
{
	int ch;
	*T = (BiTNode*)malloc(sizeof(BiTNode));
	if(!(*T))exit(OVERFLOW);
	
	printf("�밴����������������������Ԫ��\n");
	fflush(stdin);
	scanf("%d",&ch);
	
	if(ch == 666)
		{
			(*T) = NULL; 
		}
	else
	{
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
	return OK; 
}

Status OutPutBiTree(BiTree* T)
{
	if(T == NULL)
	{
		printf("error");
	}
	else if(T!=NULL)
		{
			printf("%d    ",(*T)->data);
			if((*T)->lchild)
				{
					OutPutBiTree(&(*T)->lchild);
				}
			else
				{
					printf("��    ",(*T)->data);
				}
			if((*T)->rchild)
				{
					OutPutBiTree(&(*T)->rchild);
				}
			else
				{
					printf("��    ",(*T)->data);
				}
		}
	
	return OK; 
}

Status ExchangeChild(BiTree* T)//
{
	if(*T == NULL)
	{
		printf("error");
	}//Ԥ�Ʋ��ᴫ��ָ��
	 
	if((*T)->lchild != NULL ||(*T)->rchild != NULL )
	{
		BiTNode* q;
		
		q = (*T)->lchild;
		
		(*T)->lchild = (*T)->rchild;
		(*T)->rchild = q;
		
		if((*T)->lchild != NULL)
			{
				ExchangeChild(&(*T)->lchild);
			}
			
		if((*T)->rchild != NULL)
			{
				ExchangeChild(&(*T)->rchild);
			}
	}
	return OK;
}

Status ReNumBiTree(BiTree* T)
{
	if(*T != NULL)
		{
			i = i+1;
		}
		
	if((*T)->lchild != NULL)
		{
			ReNumBiTree(&(*T)->lchild);
		}
			
	if((*T)->rchild != NULL)
		{
			ReNumBiTree(&(*T)->rchild);
		}
	return OK;
}
