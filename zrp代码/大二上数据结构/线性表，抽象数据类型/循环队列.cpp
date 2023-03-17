#include<stdio.h>
#include<stdlib.h> 

#define MAX 20

//循环列队
typedef struct Node
{
	int num;
	char* info;
}QNode;

typedef struct sqQueue
{
	int rear;
	int front;
	QNode* Q;
	
 }sqQueue ;
int main(void)
{
	void InitQueue(sqQueue &q);
	sqQueue q;
	InitQueue(q);
	
	return 0;
}

void InitQueue(sqQueue &q)
{
	q.Q= (QNode*)malloc(MAX*sizeof(QNode));
	if(!q.Q)exit(-2);
	
	q.front = q.rear = 0;
	
}

int EnQueue(sqQueue &q,QNode n)
{
	if((q.rear+1)%MAX==q.front)
	{
		printf("队列已满"); 
		return 1;
	}
	else
	{
		q.Q[q.rear] = n;
		q.rear = (q.rear+1)%MAX;
		return 0;
	}
	
}

int DeQueue(sqQueue &q,QNode &n)
{
	if(q.front==q.rear)
	{
		printf("队列无元素");
		return 1; 
	}
	else
	{
		n = q.Q[q.front];
		q.front = (q.front+1)%MAX;
		return 0;
	}
}


