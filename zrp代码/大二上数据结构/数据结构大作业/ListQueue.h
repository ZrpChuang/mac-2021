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

typedef struct LNode//�жӵĽڵ� 
{
	int data;
	LNode* next;
}LNode;

typedef struct List//�������ȥ�� 
{
	int count;//ͳ���ж��й��ж�������
	LNode* front;
	LNode* rear;//ͷָ�� ,βָ�� 
	
}list;


 
Status InitList(List &l1)//��ʼ��һ���ж�
{
	l1.front = (LNode*)malloc(sizeof(LNode));
	if(!l1.front)exit(OVERFLOW);
	
	l1.rear = l1.front;
	
	l1.front->next = NULL;//ͷ�ڵ��ָ��NULL 
	
	l1.count = 0;//��ʼ�� 
	
	
	return OK; 
} 
Status InList(List &l1,int n)//�Ӷ�β���� �����������n 
{
	
	LNode* pNew;
	
	pNew = (LNode*)malloc(sizeof(LNode));
	if(!pNew)exit(OVERFLOW);//�����µĵ�ַ
	
	pNew->data = n;
	pNew->next = l1.rear->next;
	l1.rear->next = pNew;
	l1.rear = pNew;//��β������ 
	
	l1.count++;
	
	return OK;
}

int OutList(List &l1)//�Ӷ�ͷ�Ƴ� 
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
			
			return n;//������Ч��¥����
		}
		else
		{
			int n = l1.front->next->data;
			
			LNode* Trash;
			Trash = l1.front->next;
			l1.front->next = Trash->next;
			
			free(Trash);
			l1.count--;
			return n;//������Ч��¥����
		}
	}
	else
	{
		return 0;
	}
	 
}





