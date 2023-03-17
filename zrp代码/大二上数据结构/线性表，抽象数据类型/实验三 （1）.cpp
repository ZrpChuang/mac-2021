# include<stdio.h>
# include<stdlib.h>//malloc函数要用 ,随机产生随机数  

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2

# define STACK_INIT_SIZE 10//栈的长度默认值是10 
# define STACKINCREMENT 2//默认增加长度是2 

/*建立顺序栈，将元素{8，9，5，4}放入顺序栈 实现顺序栈的建立与 入栈操作
  实现元素{8，9}的出栈
  
  建立链列队 （4，5，7，6，8）的入队，实现入队和建立操作 (4,5)出队 
   */ 
typedef int Status;//利用状态函数 



struct SqStack//利用结构体定义数据类型 ：栈 
{
	int* top;// 顶部指针 
	int* base;//  
	int stacksize; //长度 
};

typedef struct QNode//列队中的每一个节点 
{
	int data;
	struct QNode *next;
}*QueuePtr;

struct LinkQueue//整个列队 
{
	QueuePtr front;//队头指针 
	QueuePtr rear;//队尾指针	
};


//函数前置声明 
Status InitStack(SqStack* s);
Status Push(SqStack* s);
Status Pop(SqStack* s);
Status InitQueue(LinkQueue* Q) ;
Status EnQueue(LinkQueue* Q);
Status DeQueue(LinkQueue* Q);

int main(void)
{
	LinkQueue Q1;
	
	InitQueue(&Q1);
	
	int choose2 = 1;
	
	int choose = 1;
	SqStack s1;//定义一个栈的变量 
	
	InitStack(&s1);//创建空的栈 
	
	printf("======================================\n");
	printf("||     请问需要对栈进行什么操作     ||\n");
	printf("||     0.退出程序                   ||\n");
	printf("||                                  ||\n");
	printf("||     1.把元素压入栈中             ||\n");
	printf("||                                  ||\n");
	printf("||     2.把栈顶元素删除并返回       ||\n");
	printf("======================================\n");
	printf("\n\n\n");
	
	while(choose != 0)
	{
		printf("请输入您的选择0,1或者2\n");
		printf("你的选择则是："); 
		scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				Push(&s1);
				break;
			case 2:	
				Pop(&s1);
				break;
			case 0:
				printf("对栈的操作已经结束\n"); 
				break;
			default:
				printf("error\n"); 
				break;
		} 
	}
	printf("\n\n\n");
	printf("========================================\n");
	printf("||     请问需要对队列进行什么操作     ||\n");
	printf("||     0.退出对队列操作的程序         ||\n");
	printf("||                                    ||\n");
	printf("||     1.把元素插入队列尾中           ||\n");
	printf("||                                    ||\n");
	printf("||     2.把队头元素删除并返回其值     ||\n");
	printf("========================================\n");
	printf("\n\n\n");
	
	while(choose2 != 0)
	{
		printf("\n");
		printf("请输入您的选择0,1或者2\n");
		printf("你的选择则是：");
		scanf("%d",&choose2);
		switch(choose2)
		{
			case 1:
				EnQueue(&Q1);
				break;
			case 2:	
				DeQueue(&Q1); 
				break;
			case 0:
				printf("对队列的操作已经结束了\n"); 
				break;
			default:
				printf("error\n"); 
				break;
		}
	}
	
	return 0;
}

Status InitQueue(LinkQueue* Q) 
{
	(*Q).front = (*Q).rear =(QueuePtr)malloc(sizeof(QNode));
	if(!((*Q).front))exit(OVERFLOW);
	(*Q).front->next = (*Q).rear->next = NULL;//赋予空指针 
	
	return OK;
}//建立一个空的列队

Status EnQueue(LinkQueue* Q)//接受队列 
{
	int n;//入队元素 
	QueuePtr p;
	
	printf("请输入队元素:");
	scanf("%d",&n);
	
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)exit(OVERFLOW);
	p->data  = n;
	
	p->next = (*Q).rear->next;//赋予空指针 
	(*Q).rear->next = p;
	
	(*Q).rear = (*Q).rear->next;
	
	return OK;
}

Status DeQueue(LinkQueue* Q)//删除队头元素 
{
	//首先检查队列中元素是否为空
	printf("现在将删除队首元素\n");
	if((*Q).front == (*Q).rear)
		{
			printf("检测到没有元素了，别删了 >_< \n");
			return ERROR;
		}
		
 	int n;
	QueuePtr p;//定义一个指针
	p = (*Q).front->next;//定位指针去哪
	
	n = p->data;//读取元素
	 
	if((*Q).rear == p)//如果快到最后一个元素了，移动尾指针 
	{
		(*Q).rear = (*Q).front; 
	}
	
	(*Q).front->next = p->next;
	
	free(p); 
	
	printf("队列元素首位的返回值是%d已删除\n",n);	
	printf("已删除\n",n);
	return OK;
}


Status InitStack(SqStack* s)//构造函数 
{
	//写在一起 让代码看起来更加精炼 
	(*s).top = (*s).base =(int*)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!((*s).base))exit(OVERFLOW);
	 
	(*s).stacksize =  STACK_INIT_SIZE;
	
	return OK;//完成构造 
}


Status Push(SqStack* s)//压栈 
{
	
	int* newbase;
	//先判断是否满
	if((*s).top - (*s).base == (*s).stacksize)
	{
		newbase = (int*)realloc((*s).base,(STACK_INIT_SIZE+STACKINCREMENT) * sizeof(int));
		if(!newbase)exit(OVERFLOW);
		//newbase = (ElemType *)realloc((*L).elem,((*L).listsize + LISTINCREMENT)*sizeof(ElemType));
		//if(!newbase)exit(OVERFLOW);
		(*s).base = newbase;
	} 
	//先插入再移动指针 
	int n;//n定义的是需要返回的 
	printf("请输入压入栈的元素:");
	scanf("%d",&n);
	
	*((*s). top )= n;
	(*s).top++ ;
		
	return OK;
}

Status Pop(SqStack* s)//出栈 
{
	//先移动指针再返回值 
	
	int n;//n定义的是需要返回的 
	(*s).top-- ;
	n = *((*s). top );
	
	printf("栈顶元素出栈成功！\n");
	printf("栈顶元素返回值是：%d\n",n);
	
	return OK;
}











