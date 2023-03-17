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
	二叉树左右子树交换，得到新的二叉树，并输出二叉树
	建立二叉树 
	交换二叉树 
	输出二叉树
*/
typedef int Status;

typedef struct BiTNode//树的节点 
{
	
	int data;//储存的数据直接用int类型 
	BiTNode* lchild;//命名尽量考虑书上的 
	BiTNode* rchild;
	
}*BiTree;

Status InitBiTree(BiTree* T);//构造新的二叉树 
Status CreateBiTree(BiTree* T);//加入元素 
Status OutPutBiTree(BiTree* T);//先序输出二叉树 
Status ExchangeChild(BiTree* T);//交换二叉树 
Status ReNumBiTree(BiTree* T);
//Status WithOtrcrsn(BiTree* T);
/*Status PTraverse();//先序遍历，在遍历过程中再输出 
Status Print();*/

static int i;

int main(void)
{
	
	i = 0; 
	BiTree T1;
	InitBiTree(&T1);
	printf("==========================================\n");
	printf("=   先输入一个二叉树，才能进行其他操作   =\n");
	printf("=      如果某个节点为空节点请输入666     =\n");
	printf("=        输入的二叉树不能再包括666       =\n");
	printf("==========================================\n");
	CreateBiTree(&T1);
	
	printf("\n");
	printf("检测构造效果,先序输出\n");
	OutPutBiTree(&T1);

	ReNumBiTree(&T1);
	printf("返回节点个数%d\n",i);
	i = 0;

	
	printf("\n");
	
	
	
	
	printf("\n");
	printf("检测交换效果，线序输出\n");
	
	ExchangeChild(&T1);
	OutPutBiTree(&T1);

	ReNumBiTree(&T1);
	printf("返回节点个数%d\n",i);
	i = 0;
	
	
	printf("\n");
	
	
	
	return 0;
} 

Status InitBiTree(BiTree* T)//建立空的二叉树 
{
	*T = NULL;
	
	return OK;
}

Status CreateBiTree(BiTree* T)
{
	int ch;
	*T = (BiTNode*)malloc(sizeof(BiTNode));
	if(!(*T))exit(OVERFLOW);
	
	printf("请按二叉树先序逐个输入二叉树元素\n");
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
					printf("空    ",(*T)->data);
				}
			if((*T)->rchild)
				{
					OutPutBiTree(&(*T)->rchild);
				}
			else
				{
					printf("空    ",(*T)->data);
				}
		}
	
	return OK; 
}

Status ExchangeChild(BiTree* T)//
{
	if(*T == NULL)
	{
		printf("error");
	}//预计不会传空指针
	 
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
