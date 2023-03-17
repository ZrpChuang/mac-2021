# include<stdio.h>//Ԥ����ָ�ͷ�ļ��������� ��׼������� 
# include<stdlib.h>//malloc����Ҫ��  ������������  

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

struct Car//�������� ���� 
{
	int number;//����
	int Itime;
	int Otime;
};

struct Stack//������������ջ ����ջ 
{
	Car* top;
	Car* base;
	int stacksize;	
};

struct QNode//����Ľڵ� 
{
	QNode* next;
	Car  data;
};

struct Queue//�����������Ͷ��� ʹ����ʽ�洢ʵ�� 
{
	QNode* front;
	QNode*  rear;	
	int Queuesize;//�����ջ��һ������Ϊû�����Ƴ��� 
};



//����ǰ������
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

//����ǰ������ 
int main(void)
{
	int AOD;//A or D ���ﻹ���뿪 
	int i;//��Ǯ 
	int time,num;//
	int place1;
	Car x1,x2;//��Ϊ������Ϣ�ݴ浥Ԫ 
	
	Queue q1;
	Stack s1,s2;
	
	InitQueue(q1);
	InitStack(&s1);
	InitStack(&s2);
	
	while(AOD != 69)
	{
		printf("\n");
		printf("==========================================\n");
		printf("�����복����Ϣ����ʽ���£���_ ��, _ , _ ��\n");
		
		fflush(stdin);//��ջ����� 
		getchar();
		scanf("%c,%d,%d)",&AOD,&num,&time);//��������ȥ ���ƺ��� �������ߵ�ʱ�� 
		printf("\n");
		
		//printf("%d,%d,%d\n",AOD,num,time);
		
		if(AOD == 65 )
			{
				x1.number = num;//���ƺ���һ��Ҫ���� 
				if(s1.stacksize >= 2)//ջ�� ���ñ���ʱ�� ��¼����λ�����Ӧ����δ��� 
					{
						InQueue(&q1,&x1);
						QCount(&q1,&x1);
					}
				else //ջ����  ��s1����ѹջ ����λ�� ��¼ʱ�� ���Ӧ����δ��� 
					{
						x1.Itime = time;//��ջҪ����ʱ�� 
						Push(&s1 , &x1);
						SCount(&s1,&x1);
					}
			
			}
		else if(AOD == 68)//�뿪����  
			{
				x1.number = num;//���ƺ���һ��Ҫ����
				x1.Otime = time; 
				SSure(&s1,&x1,&place1);
				x1.Otime = time; 
				//printf("����λ�ú���������û�д���%d\n",place1);
					if(place1 == 2)
			 		{
			 			i = x1.Otime - x1.Itime;
						i = i*5;
			 			printf("����ÿ��λʱ��5Ԫ\n");
			 			printf("���ͣ���ķ�����%dԪ\n",i); 
			 			Pop(&s1,&x1);//ɾ��ջ������ 
			 			printf("����%d�뿪ͣ����\n",x1.number );
			 			
			 			if(q1.front != q1.rear )
			 			{
			 				printf("�����Ϊ��\n" );
			 				DeQueue(&q1,&x1);//��ȡɾ������еĳ���x1�� 
			 				x1.Itime = time;//�������ջ 
			 				Push(&s1,&x1);//�Ž�ȥ 
							printf("�������%d����ͣ����\n",x1.number );
							SCount(&s1,&x1);
						}
			 			/*DeQueue(&q1,&x1);//��ȡɾ������еĳ���x1�� 
			 			x1.Itime = time;//�������ջ */
			 			
					}
					else if(place1 == 1)
					{
						i = x1.Otime - x1.Itime;
						i = i*5;
						printf("����ÿ��λʱ��5Ԫ\n");
			 			printf("���ͣ���ķ�����%dԪ\n",i); 
			 			Pop(&s1,&x1);//ɾ��ջ������
			 			printf("����%d��ʱ�뿪ͣ�������õ�\n",x1.number);
			 			Push(&s2,&x1);//��ʱ��s2��SCount(&s1,&x1);
			 			
			 			
						Pop(&s1,&x1);//ɾ��ջ������ 
						printf("����%d�뿪ͣ����\n",x1.number );
						
						Pop(&s2,&x1);//s2�е�Ԫ��ȡ���� ����s1�� 
						Push(&s1,&x1);//����s1�� 
						printf("����%d���½���ͣ����\n",x1.number );
						SCount(&s1,&x1);
						
						if(q1.front != q1.rear )//��������Ϊ�� 
			 			{
			 				printf("�����Ϊ��\n" );
							DeQueue(&q1,&x1);//��ȡɾ������еĳ���x1�� 
			 				x1.Itime = time;//�������ջ 
			 				Push(&s1,&x1);//�Ž�ȥ 
							printf("�������%d����ͣ����\n",x1.number );
							SCount(&s1,&x1);
						}
						
					}
					
					else
					printf("�ڴ˴�����\n");
				
			}
	}
	
	return 0;	
} 



//ջ 
Status InitStack(Stack* s)//����һ������Ȼ����  ����ջ 
{
	//д��һ�� �ô��뿴�������Ӿ��� 
	s->top = s->base =(Car*)malloc((STACKSIZE+1)*sizeof(Car));//��ʼλ�ø������� 
	//ע�⣺��������ĵ�ַ�Ĵ�С��Car�����Ĵ�С 
	if(!s->base)exit(OVERFLOW);
	 
	s->stacksize = 0;//ʵ��Ԫ������� 
	
	return OK;//��ɹ��� 
}


Status Pop(Stack* s , Car* x )//���ܱ��� ��ջ 
{
	s->top--;//�ƶ�ָ�� 
	
	*x = *s->top;//����ֵ 
	
	s->stacksize -= 1;
	
	return OK;
}

Status Push(Stack* s , Car* x)//ѹ��Ԫ�� 
{//�ܽ�:
 //1.��һ�����⣺���ı�car��ֵΪʲô��ָ�� 
 //2.�ڶ������⣺��ʹ�ı�car��ֵ��ʵս����ʹ������
  
	*s->top = *x;//�ṹ����໥��ֵ 
	(*s).top ++ ;
	
	(*s).stacksize += 1;
	
	return OK;
}

Status SCount(Stack* s,Car* x)//δ�� 
{
	int i = 1;
	Car* q = s->base;
	 
	while(x->number != q->number && i <= s->stacksize)//�ҵ�������� 
		{
			i++;
			q++;
		}
		
	if(i > s->stacksize)
		{
			printf("ͣ������û��������"); //        =====here
		}
		
	else
		{
			printf("�ó�����ͣ����%d��λ\n",i);
			;
		}
	return OK;
}

Status SSure(Stack* s,Car* x,int* place)//ȷ���Ƿ���ջ�� 
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
			//printf("ͣ������û��������");
			return FALSE; 
		}
		
	else
		{
			//printf("�ó�����ͣ����%d��λ\n",i);
			*place = i;
			
			*x = *q;//��ȡ������
			 
			return OK;
		}
	
}

//���� 
Status InitQueue(Queue &Q)//����һ������Ȼ���� 
{
	//��ͷ�ڵ�Ķ��� 
	Q.front = Q.rear =(QNode*)malloc(sizeof(QNode));//Ϊ���Car�����������͵Ķ��� 
	//ע�⣺��������Ŀռ���ָ��ڵ�Ĵ�С 
	if(!Q.front)exit(OVERFLOW);
	
	Q.rear->next = NULL;//�����ָ�� 
	
	return OK;
}//����һ���յ��ж�

Status InQueue(Queue* Q,Car* x)//�������������Ҫ��ԵĶ����Լ����Ļ�����Ϣ 
{
	QNode* q;
	q = (QNode*)malloc(sizeof(QNode));
	if(!q)exit(OVERFLOW);
	
	q->data  = *x;//�ṹ��֮����໥��ֵ��ֱ�Ӹ���Car�ṹ���ֵ 
	
	q->next  = (*Q).rear->next; 
	(*Q).rear->next = q;
	(*Q).rear = q;
	
	(*Q). Queuesize += 1;
	
	return OK;
}

Status DeQueue(Queue* Q,Car* x)//ɾ���󷵻�  
{
	QNode* q;
	q = (*Q).front->next;
	
	if((*Q).front == (*Q).rear)
		{
			printf("�Ŷӳ�����Ϊ 0�޷�ɾ��\n");
		}
	
	(*Q).front->next = q->next ;
	
	*x = q->data ;//����ֵ 
	
	if((*Q).front->next == (*Q).rear) 
		{
			(*Q).rear = (*Q).front;
		}//ֻʣ���һ��Ԫ�ص���� 
		
	free(q);
	(*Q). Queuesize -= 1;
	return OK;
}

Status QCount(Queue* Q,Car* x)//���� 
{
	int i = 1;
	QNode* q = (*Q).front->next ;//��ͷ�ڵ� 
	
	while(q->data.number != (*x).number && q != NULL)
	{
		q = q->next ;
		i = i+1;
	}
	
	if(q == NULL)
		{
			printf("�����û�иó���\n");
			return FALSE;//����ֵ0 �������� 
		}
	else
		{
			printf("�ó����ڱ����%d��λ\n",i);
			return OK;
		}	
	
}

Status QSure(Queue* Q,Car* x,int* place)//ȷ�ϳ����� �ú���ֵ���� ����Ҫ��ӡ ����1���� ����0 ������ 
{
	int i = 1;
	QNode* q = (*Q).front->next ;//��ͷ�ڵ� 
	
	while(q->data.number != (*x).number || q != NULL)
	{
		q = q->next ;
		i = i+1;
	}
	
	if(q == NULL)
		{
			//printf("�����û�иó���\n");
			return FALSE;//����ֵ0 �������� 
		}
	else
	{
		*place = i;
		*x = q->data ;
		return OK;
	}
		
}








