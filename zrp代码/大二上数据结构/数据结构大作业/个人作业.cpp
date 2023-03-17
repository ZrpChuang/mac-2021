#include<stdio.h>
#include<stdlib.h>
# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2
# define MAXSIZE 15//��������������Ϊ15��
# define MAXLEVEL 13 

//��ǰ�¼����� 
/*
 
���յ�Ŀ����ʵ����̨���ݵĵ���
ϣ���ܹ���Ƴ��ܹ������ֱ�ӵ���¥���ָ�� ָ��ֱ�Ӵ�������չ�ֶ���Ч��

Ŀǰ���뷨�ǣ�
�����������ȱ�ţ�1��2������һ�����ݻ����ȵ��ã�����Ҫ����¥�� ���õ���������
���������У������е�Ԫ���𲽽������Ķ���Ч���У�����չʾ 

����һ������
����ʵ�����м�������ݵ�·���洢���ж��У�Ȼ��ͼ��ʵ�ְ��ն��е�˳��ʵ�� 


*/

//��ǰ״̬����
typedef int Status;

typedef enum tagT_STATUSType 
{
	
    STATUS_STOP = 0,
    STATUS_UP,//1������ 
    STATUS_DOWN,//2���½� 
    STATUS_WARN//���� 
    
}T_STATUSType;


typedef struct Elevator//���ݽṹ�� 
{
    int num;//�������� 
    int level;
    T_STATUSType status;//˵��״̬
	int wheretogo[13]; //ֻҪ������治��ȫ�� ��Ҫ�������� 
    
}El, *Ele;

//����ǰ������
Status WhereToGo(int Out[],int In[],Elevator E);
Status Move(int Out[],int In[],Elevator &E);
//����ǰ������ 

int main(void)
{
	int OSApply[13];//�����±��ʾ¥���� 
	int ISApply[13];//�����ڲ���ʾ�ڲ�����
	Elevator E1;
	
//WhereToGo(OSApply,ISApply,E1);//������Ҫȥ���� 
	
	return 0;
}

Status Refrash(Elevator &E)
{
	E.level = 1;//��ʼ¥����һ¥ 
	E.num = 0;//��ʼ����Ϊ�� 
	E.status = 0;//��ʼ״̬Ϊֹͣ״̬ 
	int i;
	
	for(i = 1;i <= MAXLEVEL;i++)
	{
		E.wheretogo[i] = 0;
	}
	
	return OK;
}
Status MakeSureStatus(int Out[],int In[],Elevator &E)
{
	int level = E.level;//ȷ���������� 
	int sum1;//�����ж��Ƿ��и�ֵ 
	int sum2;
	int i;
	for(i = 1;i <= MAXLEVEL;i++) 
	{
		sum1 = sum1 + Out[i];
		sum2 = sum2 + In[i];
	} 
	
	if(sum1 == sum2 == 0)//�������涼û���˰� 
	{
		Refrash(E);
	}
	else if(sum1!= 0&&sum2 == 0)//���������˰� 
	{
		
	}
	else if(sum1 == 0 && sum2 != 0 )//���������˰� 
	{
		
	}
	else if(sum1 == 0&&sum2 == 0)//�������涼�����˰� 
	{
		
	}
	
	return OK;
}

Status WhereToGo(int Out[],int In[],Elevator &E)//ȥ����ȡ������������ ,�����ݵ���ȥ�������渳ֵ�� 
{//ֻ�Ǹ�ֵ�˵���Ԥ��ȥ���б����巽��δд�㷨 
	int nowlevel = E.level;
	int i;
	
	if(E.num<=15)//���ߵ����ݶ���Ҫ�������Ž��� 
	{
		
		if(E.status == 1 )//�����ݴ������н׶�
		{
			for(i = 1;i<=13;i++)
			{
				if(E.level < i && Out[i] != 0)E.wheretogo[i] = 1;
				if(E.level < i && In[i] != 0)E.wheretogo[i] = 1;
				//wheretogo����ֻ��ֵ0��1����ʾ�費��Ҫ���� 
			}
		}
		else if(E.status == 2)//���ݴ������н׶� 
		{
			for(i = 1; i <= 13 ; i++)
			{
				if(E.level > i && Out[i] != 0) E.wheretogo[i] = 1;
				if(E.level > i && In[i] != 0)E.wheretogo[i] = 1;
			}
		} 
		else//���ݴ��ڵȴ��׶� ,
		��Ҫ�ı�״̬ ���Ǹ����⣬��㴦�� 
		{
			for(i = 1; i <= 13;i++)
				{
					if(Out[i] != 0)
					{
						E.wheretogo[i] = 1;//wheretogo����ֻ��ֵ0��1����ʾ�費��Ҫ���� 
					}
				}
		}
	}
	
	else//������ֻ��Ҫ����in���˵���Ը 
	{
		if(E.status == 1 )//�����ݴ������н׶�
		{
			for(i = 1;i<=13;i++)
			{
				if(E.level < i && In[i] != 0)E.wheretogo[i] = 1;
				//wheretogo����ֻ��ֵ0��1����ʾ�費��Ҫ���� 
			}
		}
		else if(E.status == 2)//���ݴ������н׶� 
		{
			for(i = 1; i <= 13 ; i++)
			{
				if(E.level > i && In[i] != 0)E.wheretogo[i] = 1;
			}
		}
	}
	
	return OK;
}

status Press(int Out[],int In[])//ģ���û�����ťʵ�ֶԵ��ݵĿ���
{//�����������������û������� 
	int m = MAXLEVEL;//��߲��� 
	int i;
	printf("����������ÿ��¥�ȴ�������\n");
	for(i = 1;1<=m;i++)
	{
		printf("������%d¥��ȴ�������ݵ�������");//û��ָ������0 
		fflush(stdin);
		scanf("%d",Out[i]);
	}
	
	int sum ; 
	printf("�����������ʼ״̬��������Ҫ����ĳ��¥������\n");
	for(i = 1;1<=m;i++)
	{
		printf("�������ʼ״̬����ȥ��%d¥��������");
		fflush(stdin);
		scanf("%d",In[i]);
		sum = sum+ In[i];
		if(sum>15)printf("������������"); 
	}
	return OK;
} 

Status Move(int Out[],int In[],Elevator &E) 
{
	int i;
	int level = E.level;
	if(E.status == 1)//������
	{
		for(i = level + 1 ; i < 13 ; i++ )
		{
			if(E.wheretogo[i] != 0)//֤����һ������ϣ������
			{
				E.level = i;//��level���¸�ֵ 
				E.wheretogo[i] = 0;//������������� 
				E.num = E.num-In[i];In[i] = 0;//�����������ؽ�����һ�����뿪���ˣ���Ҫ�뿪�������� 
				E.num = E.num + Out[i];//������˽��� 
				if(E.num <= 15)//�����Ƿ��� 
				{
					Out[i] = 0;
				}
				else
				{
					int more = E.num - 15;
					E.num = 15;//�غ� 
					Out[i] = more;//����������ܽ����� 
				}
				
			} 
		}// ¥����ѭ�� 
	}
	else if(E.status == 2)//���½� 
	{
		for(i = level - 1 ; i > 0 ; i-- )
		{
			if(E.wheretogo[i] != 0)//֤����һ������ϣ������
			{
				E.level = i;//�����µ�һ�� 
				E.wheretogo[i] = 0;//������������� 
				E.num = E.num-In[i];In[i] = 0;//�����������ؽ�����һ�����뿪���ˣ���Ҫ�뿪�������� 
				E.num = E.num + Out[i];//������˽��� 
				if(E.num <= 15)//�����Ƿ��� 
				{
					Out[i] = 0;
				}
				else
				{
					int more = E.num - 15;
					E.num = 15;//�غ� 
					Out[i] = more;//����������ܽ����� 
				}
				
			} 
		}// ¥����ѭ�� 
	}
	/*
	else//�ǵȴ�
	{
			
	} 
	*/
	return OK;
}













