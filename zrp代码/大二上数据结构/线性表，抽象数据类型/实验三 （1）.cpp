# include<stdio.h>
# include<stdlib.h>//malloc����Ҫ�� ,������������  

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2

# define STACK_INIT_SIZE 10//ջ�ĳ���Ĭ��ֵ��10 
# define STACKINCREMENT 2//Ĭ�����ӳ�����2 

/*����˳��ջ����Ԫ��{8��9��5��4}����˳��ջ ʵ��˳��ջ�Ľ����� ��ջ����
  ʵ��Ԫ��{8��9}�ĳ�ջ
  
  �������ж� ��4��5��7��6��8������ӣ�ʵ����Ӻͽ������� (4,5)���� 
   */ 
typedef int Status;//����״̬���� 



struct SqStack//���ýṹ�嶨���������� ��ջ 
{
	int* top;// ����ָ�� 
	int* base;//  
	int stacksize; //���� 
};

typedef struct QNode//�ж��е�ÿһ���ڵ� 
{
	int data;
	struct QNode *next;
}*QueuePtr;

struct LinkQueue//�����ж� 
{
	QueuePtr front;//��ͷָ�� 
	QueuePtr rear;//��βָ��	
};


//����ǰ������ 
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
	SqStack s1;//����һ��ջ�ı��� 
	
	InitStack(&s1);//�����յ�ջ 
	
	printf("======================================\n");
	printf("||     ������Ҫ��ջ����ʲô����     ||\n");
	printf("||     0.�˳�����                   ||\n");
	printf("||                                  ||\n");
	printf("||     1.��Ԫ��ѹ��ջ��             ||\n");
	printf("||                                  ||\n");
	printf("||     2.��ջ��Ԫ��ɾ��������       ||\n");
	printf("======================================\n");
	printf("\n\n\n");
	
	while(choose != 0)
	{
		printf("����������ѡ��0,1����2\n");
		printf("���ѡ�����ǣ�"); 
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
				printf("��ջ�Ĳ����Ѿ�����\n"); 
				break;
			default:
				printf("error\n"); 
				break;
		} 
	}
	printf("\n\n\n");
	printf("========================================\n");
	printf("||     ������Ҫ�Զ��н���ʲô����     ||\n");
	printf("||     0.�˳��Զ��в����ĳ���         ||\n");
	printf("||                                    ||\n");
	printf("||     1.��Ԫ�ز������β��           ||\n");
	printf("||                                    ||\n");
	printf("||     2.�Ѷ�ͷԪ��ɾ����������ֵ     ||\n");
	printf("========================================\n");
	printf("\n\n\n");
	
	while(choose2 != 0)
	{
		printf("\n");
		printf("����������ѡ��0,1����2\n");
		printf("���ѡ�����ǣ�");
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
				printf("�Զ��еĲ����Ѿ�������\n"); 
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
	(*Q).front->next = (*Q).rear->next = NULL;//�����ָ�� 
	
	return OK;
}//����һ���յ��ж�

Status EnQueue(LinkQueue* Q)//���ܶ��� 
{
	int n;//���Ԫ�� 
	QueuePtr p;
	
	printf("�������Ԫ��:");
	scanf("%d",&n);
	
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)exit(OVERFLOW);
	p->data  = n;
	
	p->next = (*Q).rear->next;//�����ָ�� 
	(*Q).rear->next = p;
	
	(*Q).rear = (*Q).rear->next;
	
	return OK;
}

Status DeQueue(LinkQueue* Q)//ɾ����ͷԪ�� 
{
	//���ȼ�������Ԫ���Ƿ�Ϊ��
	printf("���ڽ�ɾ������Ԫ��\n");
	if((*Q).front == (*Q).rear)
		{
			printf("��⵽û��Ԫ���ˣ���ɾ�� >_< \n");
			return ERROR;
		}
		
 	int n;
	QueuePtr p;//����һ��ָ��
	p = (*Q).front->next;//��λָ��ȥ��
	
	n = p->data;//��ȡԪ��
	 
	if((*Q).rear == p)//����쵽���һ��Ԫ���ˣ��ƶ�βָ�� 
	{
		(*Q).rear = (*Q).front; 
	}
	
	(*Q).front->next = p->next;
	
	free(p); 
	
	printf("����Ԫ����λ�ķ���ֵ��%d��ɾ��\n",n);	
	printf("��ɾ��\n",n);
	return OK;
}


Status InitStack(SqStack* s)//���캯�� 
{
	//д��һ�� �ô��뿴�������Ӿ��� 
	(*s).top = (*s).base =(int*)malloc(STACK_INIT_SIZE*sizeof(int));
	if(!((*s).base))exit(OVERFLOW);
	 
	(*s).stacksize =  STACK_INIT_SIZE;
	
	return OK;//��ɹ��� 
}


Status Push(SqStack* s)//ѹջ 
{
	
	int* newbase;
	//���ж��Ƿ���
	if((*s).top - (*s).base == (*s).stacksize)
	{
		newbase = (int*)realloc((*s).base,(STACK_INIT_SIZE+STACKINCREMENT) * sizeof(int));
		if(!newbase)exit(OVERFLOW);
		//newbase = (ElemType *)realloc((*L).elem,((*L).listsize + LISTINCREMENT)*sizeof(ElemType));
		//if(!newbase)exit(OVERFLOW);
		(*s).base = newbase;
	} 
	//�Ȳ������ƶ�ָ�� 
	int n;//n���������Ҫ���ص� 
	printf("������ѹ��ջ��Ԫ��:");
	scanf("%d",&n);
	
	*((*s). top )= n;
	(*s).top++ ;
		
	return OK;
}

Status Pop(SqStack* s)//��ջ 
{
	//���ƶ�ָ���ٷ���ֵ 
	
	int n;//n���������Ҫ���ص� 
	(*s).top-- ;
	n = *((*s). top );
	
	printf("ջ��Ԫ�س�ջ�ɹ���\n");
	printf("ջ��Ԫ�ط���ֵ�ǣ�%d\n",n);
	
	return OK;
}











