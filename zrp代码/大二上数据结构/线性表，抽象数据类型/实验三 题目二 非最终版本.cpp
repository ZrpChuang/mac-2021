# include<stdio.h>//预处理指令，头文件包含进来 标准输入输出 
# include<stdlib.h>//malloc函数要用  随机产生随机数  

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2 
# define STACKSIZE 3

/*# define A 10
# define D 11
# define E 12*/

typedef int Status;

struct Car//数据类型 车辆 
{
	int number;//车号
	int Itime;
	int Otime;
};

struct Stack//抽象数据类型栈 线性栈 
{
	Car* top;
	Car* base;
	int stacksize;	
};

struct QNode//链表的节点 
{
	QNode* next;
	Car  data;
};

struct Queue//抽象数据类型队列 使用链式存储实现 
{
	QNode* front;
	QNode*  rear;	
	int Queuesize;//这个和栈不一样，因为没有限制长度 
};



//函数前置声明
Status InitStack(Stack* s);//
Status Pop(Stack* s , Car* x );
Status Push(Stack* s , Car* x); 
Status SCount(Stack* s,Car* x);

Status SSure(Stack* s,Car* x,int* place);

Status InitQueue(Queue &Q);
Status InQueue(Queue* Q,Car* x);
Status DeQueue(Queue* Q,Car* x);
Status QCount(Queue* Q,Car* x);
Status QSure(Queue* Q,Car* x,int* place);

//函数前置声明 
int main(void)
{
	int AOD;//A or D 到达还是离开 
	int i;//算钱 
	int time,num;//
	int place1;
	Car x1,x2;//作为车的信息暂存单元 
	
	Queue q1;
	Stack s1,s2;
	
	InitQueue(q1);
	InitStack(&s1);
	InitStack(&s2);
	
	while(AOD != 69)
	{
		printf("\n");
		printf("==========================================\n");
		printf("请输入车辆信息，格式如下（“_ ”, _ , _ ）\n");
		
		fflush(stdin);//清空缓存区 
		getchar();
		scanf("%c,%d,%d)",&AOD,&num,&time);//车辆来来去 车牌号码 来或者走的时间 
		printf("\n");
		
		//printf("%d,%d,%d\n",AOD,num,time);
		
		if(AOD == 65 )
			{
				x1.number = num;//车牌号码一定要记载 
				if(s1.stacksize >= 2)//栈满 不用报告时间 记录对列位置相对应操作未完成 
					{
						InQueue(&q1,&x1);
						QCount(&q1,&x1);
					}
				else //栈不满  对s1进行压栈 报告位置 记录时间 相对应操作未完成 
					{
						x1.Itime = time;//入栈要记载时间 
						Push(&s1 , &x1);
						SCount(&s1,&x1);
					}
			
			}
		else if(AOD == 68)//离开车库  
			{
				x1.number = num;//车牌号码一定要记载
				x1.Otime = time; 
				SSure(&s1,&x1,&place1);
				x1.Otime = time; 
				//printf("看看位置函数计算有没有错误%d\n",place1);
					if(place1 == 2)
			 		{
			 			i = x1.Otime - x1.Itime;
						i = i*5;
			 			printf("假设每单位时间5元\n");
			 			printf("这次停车的费用是%d元\n",i); 
			 			Pop(&s1,&x1);//删除栈顶车辆 
			 			printf("车辆%d离开停车场\n",x1.number );
			 			
			 			if(q1.front != q1.rear )
			 			{
			 				printf("便道不为空\n" );
			 				DeQueue(&q1,&x1);//读取删除便道中的车到x1中 
			 				x1.Itime = time;//便道车入栈 
			 				Push(&s1,&x1);//放进去 
							printf("便道车辆%d进入停车场\n",x1.number );
							SCount(&s1,&x1);
						}
			 			/*DeQueue(&q1,&x1);//读取删除便道中的车到x1中 
			 			x1.Itime = time;//便道车入栈 */
			 			
					}
					else if(place1 == 1)
					{
						i = x1.Otime - x1.Itime;
						i = i*5;
						printf("假设每单位时间5元\n");
			 			printf("这次停车的费用是%d元\n",i); 
			 			Pop(&s1,&x1);//删除栈顶车辆
			 			printf("车辆%d暂时离开停车场，让道\n",x1.number);
			 			Push(&s2,&x1);//暂时存s2中SCount(&s1,&x1);
			 			
			 			
						Pop(&s1,&x1);//删除栈顶车辆 
						printf("车辆%d离开停车场\n",x1.number );
						
						Pop(&s2,&x1);//s2中的元素取出来 存在s1中 
						Push(&s1,&x1);//存在s1中 
						printf("车辆%d重新进入停车场\n",x1.number );
						SCount(&s1,&x1);
						
						if(q1.front != q1.rear )//如果便道不为空 
			 			{
			 				printf("便道不为空\n" );
							DeQueue(&q1,&x1);//读取删除便道中的车到x1中 
			 				x1.Itime = time;//便道车入栈 
			 				Push(&s1,&x1);//放进去 
							printf("便道车辆%d进入停车场\n",x1.number );
							SCount(&s1,&x1);
						}
						
					}
					
					else
					printf("在此处出错！\n");
				
			}
	}
	
	return 0;	
} 



//栈 
Status InitStack(Stack* s)//接受一个变量然后构造  构造栈 
{
	//写在一起 让代码看起来更加精炼 
	s->top = s->base =(Car*)malloc((STACKSIZE+1)*sizeof(Car));//初始位置赋予两个 
	//注意：这里申请的地址的大小是Car变量的大小 
	if(!s->base)exit(OVERFLOW);
	 
	s->stacksize = 0;//实际元素是零个 
	
	return OK;//完成构造 
}


Status Pop(Stack* s , Car* x )//接受变量 出栈 
{
	s->top--;//移动指针 
	
	*x = *s->top;//返回值 
	
	s->stacksize -= 1;
	
	return OK;
}

Status Push(Stack* s , Car* x)//压入元素 
{//总结:
 //1.第一个问题：不改变car的值为什么用指针 
 //2.第二个问题：即使改变car的值，实战操作使用引用
  
	*s->top = *x;//结构体的相互赋值 
	(*s).top ++ ;
	
	(*s).stacksize += 1;
	
	return OK;
}

Status SCount(Stack* s,Car* x)//未完 
{
	int i = 1;
	Car* q = s->base;
	 
	while(x->number != q->number && i <= s->stacksize)//找到或者溢出 
		{
			i++;
			q++;
		}
		
	if(i > s->stacksize)
		{
			printf("停车场里没有这辆车"); //        =====here
		}
		
	else
		{
			printf("该车辆在停车场%d号位\n",i);
			;
		}
	return OK;
}

Status SSure(Stack* s,Car* x,int* place)//确定是否在栈中 
{
	int i = 1;
	Car* q = (*s).base;
	 
	while((*x).number != q->number && i <= (*s).stacksize)
		{
			i++;
			q++;
		}
		
	if(i > (*s).stacksize)
		{
			//printf("停车场里没有这辆车");
			return FALSE; 
		}
		
	else
		{
			//printf("该车辆在停车场%d号位\n",i);
			*place = i;
			
			*x = *q;//读取该数据
			 
			return OK;
		}
	
}

//队列 
Status InitQueue(Queue &Q)//接受一个变量然后构造 
{
	//有头节点的队列 
	Q.front = Q.rear =(QNode*)malloc(sizeof(QNode));//为完成Car类型数据类型的定义 
	//注意：这里申请的空间是指针节点的大小 
	if(!Q.front)exit(OVERFLOW);
	
	Q.rear->next = NULL;//赋予空指针 
	
	return OK;
}//建立一个空的列队

Status InQueue(Queue* Q,Car* x)//传入变量包括需要入对的队列以及车的基本信息 
{
	QNode* q;
	q = (QNode*)malloc(sizeof(QNode));
	if(!q)exit(OVERFLOW);
	
	q->data  = *x;//结构体之间的相互赋值，直接附上Car结构体的值 
	
	q->next  = (*Q).rear->next; 
	(*Q).rear->next = q;
	(*Q).rear = q;
	
	(*Q). Queuesize += 1;
	
	return OK;
}

Status DeQueue(Queue* Q,Car* x)//删除后返回  
{
	QNode* q;
	q = (*Q).front->next;
	
	if((*Q).front == (*Q).rear)
		{
			printf("排队车辆数为 0无法删除\n");
		}
	
	(*Q).front->next = q->next ;
	
	*x = q->data ;//返回值 
	
	if((*Q).front->next == (*Q).rear) 
		{
			(*Q).rear = (*Q).front;
		}//只剩最后一个元素的情况 
		
	free(q);
	(*Q). Queuesize -= 1;
	return OK;
}

Status QCount(Queue* Q,Car* x)//查找 
{
	int i = 1;
	QNode* q = (*Q).front->next ;//有头节点 
	
	while(q->data.number != (*x).number && q != NULL)
	{
		q = q->next ;
		i = i+1;
	}
	
	if(q == NULL)
		{
			printf("便道中没有该车！\n");
			return FALSE;//返回值0 可以利用 
		}
	else
		{
			printf("该车辆在便道的%d号位\n",i);
			return OK;
		}	
	
}

Status QSure(Queue* Q,Car* x,int* place)//确认车在哪 用函数值返回 不需要打印 返回1存在 返回0 不存在 
{
	int i = 1;
	QNode* q = (*Q).front->next ;//有头节点 
	
	while(q->data.number != (*x).number || q != NULL)
	{
		q = q->next ;
		i = i+1;
	}
	
	if(q == NULL)
		{
			//printf("便道中没有该车！\n");
			return FALSE;//返回值0 可以利用 
		}
	else
	{
		*place = i;
		*x = q->data ;
		return OK;
	}
		
}








