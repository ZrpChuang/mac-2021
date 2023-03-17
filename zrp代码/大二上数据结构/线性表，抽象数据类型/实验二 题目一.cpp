# include<stdio.h>
# include<stdlib.h>//malloc����Ҫ�� ,������������  
# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2


/*   ˳ �� �� 
	��1������4��Ԫ�ص����Ա�L = {2��3��4��5}��
	��2����4��5֮�����9��ʵ�ֻ����������
	��3��ָ��ɾ��i3�ϵ�Ԫ��
	 
	 ������ 
	 (1)����4��Ԫ�ص����Ա�L = {2��3��4��5}��
	 (2)��4��5֮�����9��ʵ�ֻ����������
	 (3)ָ��ɾ��i3�ϵ�Ԫ��

*/ 

typedef int Status;

typedef struct LNode
{
	int data;
	struct LNode *next;
		
}LNode,*LinkList;//�����ṹ�壬 ���Ҷ���һ��ָ�룻 

void CreatList_L(LinkList *L,int n);
Status Print_L(LinkList L,int n);
Status Delete_L(LinkList *L,int n);//����ǰ������ 
Status Insert_L(LinkList *L,int n);

int main(void)
{
	int n = 4; 
	int i;
	LinkList L1;

	printf("���ڰ�����ĿҪ�󼴽�����һ��������\n");
	CreatList_L(&L1,n);//����һ������//����û�г��� 
	system("pause");
	printf("���������չʾ����Ч��\n");
	system("pause");
	Print_L(L1,n);
	
	printf("����4��5֮������Ԫ��\n");
	system("pause");
	Insert_L(&L1,9);
	n = n + 1;
	printf("���������չʾ����Ч��Ч��\n");
	system("pause");
	Print_L(L1,n);
	
	system("pause");
	printf("���������ʵ��ɾ��������Ԫ��\n");
	system("pause");
	Delete_L(&L1,3);
	n = n-1;
	printf("���������չʾɾ��Ч��Ч��\n");
	system("pause");
	Print_L(L1,n);
	
	printf("2020101124 ������ �������ѧ�뼼��"); 
	
	//Print_L(L1,3);
	
	return 0;
}


void CreatList_L(LinkList *L,int n)//�������� 
{
	LinkList p;
	int i;
	int a[3];//������ֵ 

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
}//����һ������Ϊn������; 

Status Insert_L(LinkList *L,int n)//n = 9//����һ���� 
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
 
Status Delete_L(LinkList *L,int n)//ɾ�������е�ĳ��Ԫ�� 
{
	int i;//���� 
	
	LinkList p = (*L);
	LinkList q = (*L);
	
	for(i = 1;i < n-1;i++)//�ҵ�Ҫɾ��Ԫ�ص�ǰһ�� 
	{
		p = p->next;
	}
	
	q = p->next ;//��λ��Ҫɾ��Ԫ�� 
	p->next  = p->next->next;
	free(q);//�ͷ�ɾ����Ԫ�� 
	
	return OK;
}

Status Print_L(LinkList L,int n)//������� 
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


