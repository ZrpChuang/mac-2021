#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#define Num 10

# define TURE 1
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2

typedef int Status;

typedef struct LNode//列队的节点 
{
	int data;
	LNode* next;
}LNode;

typedef struct List//储存电梯去向 
{
	int count;//统计列队中共有多少人数
	LNode* front;
	LNode* rear;//头指针 ,尾指针 
	
}list;


 
Status InitList(List &l1)//初始化一个列队
{
	l1.front = (LNode*)malloc(sizeof(LNode));
	if(!l1.front)exit(OVERFLOW);
	
	l1.rear = l1.front;
	
	l1.front->next = NULL;//头节点的指向NULL 
	
	l1.count = 0;//初始化 
	
	
	return OK; 
} 
Status InList(List &l1,int n)//从队尾插入 插入的数据是n 
{
	
	LNode* pNew;
	
	pNew = (LNode*)malloc(sizeof(LNode));
	if(!pNew)exit(OVERFLOW);//分配新的地址
	
	pNew->data = n;
	pNew->next = l1.rear->next;
	l1.rear->next = pNew;
	l1.rear = pNew;//从尾部插入 
	
	l1.count++;
	
	return OK;
}

int OutList(List &l1)//从对头移除 
{
	if(l1.front!=l1.rear)
	{
		if(l1.front->next==l1.rear)
		{
			l1.rear = l1.front;
			int n = l1.front->next->data;
			LNode* Trash;
			Trash = l1.front->next;
			l1.front->next = Trash->next;
			
			free(Trash); 
			l1.count--;
			
			return n;//返回有效的楼层数
		}
		else
		{
			int n = l1.front->next->data;
			
			LNode* Trash;
			Trash = l1.front->next;
			l1.front->next = Trash->next;
			
			free(Trash);
			l1.count--;
			return n;//返回有效的楼层数
		}
	}
	else
	{
		return 0;
	}
	 
}





