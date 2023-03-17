#include<stdio.h>
#include<stdlib.h>

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2 
# define STACKSIZE 3

typedef int ElemType;

typedef struct BiTreeNode 
{
	BiTreeNode* lchild;
	BiTreeNode* rchild;
	ElemType data;
}BTNode;

typedef BTNode* BiTree;

void InitBiTree(BiTree &T)
{
	T = NULL;
}

void CreateBiTree(BiTree &T)
{
	
	
	ElemType x;
	printf("请输入节点信息：");
	fflush(stdin);
	scanf("%d",&x);
	if(x == 666)
	{
		T = NULL;
	}
	else
	{
		T = (BTNode*)malloc(sizeof(BTNode));
		if(!T)exit(OVERFLOW);
		T->data = x;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
void PrintBiTree(BiTree &T)
{
	if(T!=NULL)
	{
		printf("%-5d",T->data);
		PrintBiTree(T->lchild);
		PrintBiTree(T->rchild);
	}
	else
	{
		printf("\t空"); 
	}
}

int main(void)
{
	BiTree T;
	InitBiTree(T);
	CreateBiTree(T);
	PrintBiTree(T);
	
	return 0;
} 
