# include<stdio.h>
# include<stdlib.h>//malloc函数要用 ,随机产生随机数  
# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2


/*   顺 序 表 
	（1）建立4个元素的线性表L = {2，3，4，5}；
	（2）在4，5之间插入9，实现基本插入操作
	（3）指定删除i3上的元素
	 
	 单链表 
	 (1)建立4个元素的线性表L = {2，3，4，5}；
	 (2)在4，5之间插入9，实现基本插入操作
	 (3)指定删除i3上的元素

*/ 

typedef int Status;

typedef struct LNode
{
	int data;
	struct LNode *next;
		
}LNode,*LinkList;//构建结构体， 并且定义一个指针； 

void CreatList_L(LinkList *L,int n);
Status Print_L(LinkList L,int n);
Status Delete_L(LinkList *L,int n);//函数前置声明 
Status Insert_L(LinkList *L,int n);

int main(void)
{
	int n = 4; 
	int i;
	LinkList L1;

	printf("现在按照题目要求即将构造一个单链表\n");
	CreatList_L(&L1,n);//构造一个链表。//构造没有出错 
	system("pause");
	printf("单击任意键展示构造效果\n");
	system("pause");
	Print_L(L1,n);
	
	printf("将在4和5之间插入的元素\n");
	system("pause");
	Insert_L(&L1,9);
	n = n + 1;
	printf("单击任意键展示插入效果效果\n");
	system("pause");
	Print_L(L1,n);
	
	system("pause");
	printf("单击任意键实现删除第三个元素\n");
	system("pause");
	Delete_L(&L1,3);
	n = n-1;
	printf("单击任意键展示删除效果效果\n");
	system("pause");
	Print_L(L1,n);
	
	printf("2020101124 张瑞鹏 计算机科学与技术"); 
	
	//Print_L(L1,3);
	
	return 0;
}


void CreatList_L(LinkList *L,int n)//构造链表 
{
	LinkList p;
	int i;
	int a[3];//给链表赋值 

	a[0] = 2;
	a[1] = 3;
	a[2] = 4;
	a[3] = 5;
	 
	(*L) = (LNode*)malloc(sizeof(LNode));
	if(!(*L))exit(OVERFLOW);
	(*L)->next =  NULL; 
	  
	for(i = n;i > 0;i--)
	{
		p = (LNode*)malloc(sizeof(LNode));
		p->data =  a[i-1];
		p->next = (*L);
		(*L) = p; 
	}
}//构造一个长度为n的链表; 

Status Insert_L(LinkList *L,int n)//n = 9//插入一个数 
{
	int i;
	LinkList p,q;
	q = (LNode*)malloc(sizeof(LNode));
	q->data  = n;
	p = (*L);
	while(p->data != 4)
		p = p->next;
	q->next  = p->next ;
	p->next  = q; 
	
	return OK;
}
 
Status Delete_L(LinkList *L,int n)//删除链表中的某个元素 
{
	int i;//计数 
	
	LinkList p = (*L);
	LinkList q = (*L);
	
	for(i = 1;i < n-1;i++)//找到要删除元素的前一个 
	{
		p = p->next;
	}
	
	q = p->next ;//定位到要删除元素 
	p->next  = p->next->next;
	free(q);//释放删除的元素 
	
	return OK;
}

Status Print_L(LinkList L,int n)//输出链表 
{
	int i;
	LinkList p;
	p = L;
	
	for(i = 1;i <= n;i++)
	{
		printf("%d\n",p->data );
		p = p->next ; 
	}
	
	return OK;
}


