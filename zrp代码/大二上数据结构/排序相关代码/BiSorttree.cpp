#include<stdio.h>
#include<stdlib.h>

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2 
# define STACKSIZE 3

typedef struct BiTNode//树的节点 
{
	
	int data;//储存的数据直接用int类型 
	BiTNode* lchild;//命名尽量考虑书上的 
	BiTNode* rchild;
	
}*BiTree;

typedef int Status;

//函数前置声明 
Status InitSortTree(BiTree &T);//建立空的二叉树
Status SortTree_Insert(BiTree &T,int data); 
Status OutPutSortTree(BiTree &T);

//函数前置声明 

int main(void)
{
	BiTree T;
	 
	InitSortTree(T);
	
	SortTree_Insert(T,3);
	SortTree_Insert(T,45);
	SortTree_Insert(T,34);
	SortTree_Insert(T,93);
	SortTree_Insert(T,51);
	SortTree_Insert(T,87);
	
	OutPutSortTree(T);//中序输出即有序 
	
	return 0;
}

Status InitSortTree(BiTree &T)//建立空的二叉树 
{
	T = (BiTNode*)malloc(sizeof(BiTNode));
	if(!T)exit(OVERFLOW);
	
	T->lchild = NULL;
	T->rchild = NULL;
	
	T->data = 50;
	
	return OK;
}

Status SortTree_Insert(BiTree &T,int data)
{
	BiTNode* q;//操作域 
	if(data < T->data)
	{
		if(T->lchild == NULL)
		{
			
			q = (BiTNode*)malloc(sizeof(BiTNode));
			if(!T)exit(OVERFLOW);
			
			q->lchild = NULL;
			q->rchild = NULL;
			q->data = data;
			
			T->lchild = q;
		}
		else
		{
			SortTree_Insert(T->lchild,data);
		}
	}
	else if(data > T->data)
	{
		if(T->rchild == NULL)
		{
			
			q = (BiTNode*)malloc(sizeof(BiTNode));
			if(!T)exit(OVERFLOW);
			
			q->lchild = NULL;
			q->rchild = NULL;
			q->data = data;
			
			T->rchild = q;
		}
		else
		{
			SortTree_Insert(T->rchild,data);
		}
	}
	
	return OK;
}

Status OutPutSortTree(BiTree &T)
{
	if (T!=NULL)
	{
		if(T->lchild != NULL)
		{
			OutPutSortTree(T->lchild);
		}
		
		printf("%d\n",T->data);
		
		if(T->rchild != NULL)
		{
			OutPutSortTree(T->rchild);
		}
	} 
	return OK;
}















