#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "ListQueue.h"

#define Num 10
# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2

typedef int Status;

// ��ʼ��һ������, ����λ��һ¥,ֹͣ״̬
int dianti[2]={1,0};

// ����һ���洢�����ڲ�����������
int init[10];

// ��ͼ����

int print()
{
    printf("\n\n\t\t>>>����ģ��ͼ<<<:\t\t�������з���\n\n\n");
    int i;
    for(i=0;i<10;i++)
    {
        printf("\t\t\t%2d| ",10-i);
        if(10-i==dianti[0])
            {
                printf("�����ݣ�\t\t   ");
                if(-1==dianti[1])
                    printf("��");
                if(1==dianti[1])
                    printf("��");
                if(0==dianti[1])//ֹͣ״̬ 
                    printf("ͣ");
            }
        printf("\n");
    }
    printf("\t\t\t\t\t\t����¥��:%d",dianti[0]);
    printf("\n\n\t\t\t\t\t\t��һ��¥:__\b\b");
}
// ���ݵ�����
int run(int n)
{   //����һ���Ĳ���,���ݽ��������е�ָ��¥��.
    while(n!=dianti[0])
    {
        if(n>dianti[0])
        {
            dianti[1]=1;
            dianti[0]++;
        }
        if(n<dianti[0])
        {
            dianti[1]=-1;
            dianti[0]--;
        }
        Sleep(1000);
        system("cls");
        if(n==dianti[0])
            dianti[1]=0;
        print();
    }
    return n;
}


struct Floor
{
	int whichfloor;
	Floor* next;
};

struct PassengerNode
{
	int PassengerNum;
	Floor* UpFloor;
	Floor* DownFloor;
};

struct PassengerList
{
	PassengerNode ListFloor[10];
};

Status StarCountculate(List &WhereToGoTable)
{//�������Ӧ������������Ϊ��Ҫ��һ���������������һЩ�͹�������
 //�ѿ͹�Ҫ��������һ�����ֶ����У�����������
 void ClearStatusList(Status List[]);
 void Clear_lfloor(PassengerList &lfloor);
 void RandomCreate(PassengerList &lfloor);//ģ������
  
 	Status ListGoingUp[10];//״̬�� 
 	Status ListGoingDown[10];
 	ClearStatusList(ListGoingUp);
 	ClearStatusList(ListGoingDown);//��ʼ���������� 
 
 	PassengerList lfloor;
 	Clear_lfloor(lfloor);//��ʼ�����ݳ˿ͱ� 
 	RandomCreate(lfloor);
 	int i;
 	
 	for(i = 1;i<=10;i++)//ɨ���õ�״̬�� 
 	{
 		if(lfloor.ListFloor[i].PassengerNum!=0)
 		{
 			if(lfloor.ListFloor[i].UpFloor!=NULL)
 			{
 				ListGoingUp[i] = 1;
 				Floor* p = lfloor.ListFloor[i].UpFloor;
 				while(p!=NULL)
 				{
 					int data = p->whichfloor;
 					ListGoingUp[data] = 1;
 					p = p->next;
				}//��ȡ��������¥�㣬���ҷŵ�״̬�������� 
			}//�ж��Ƿ������е��� 
		}//�жϸ�¥���Ƿ����� 
	}//ɨ�������� 
 	for(i = 10;i>=1;i--)
 	{
 		if(lfloor.ListFloor[i].PassengerNum!=0)
 		{
 			if(lfloor.ListFloor[i].DownFloor!=NULL)
 			{
 				ListGoingDown[i] = 1;
 				Floor* p = lfloor.ListFloor[i].DownFloor;
 				while(p!=NULL)
				{
					int data = p->whichfloor;
 					ListGoingDown[data] = 1;
 					p = p->next;
				}//��ȡ�����½�¥�㣬���ҷŵ�״̬�½����� 
			}//�ж��Ƿ������е��� 
		}//�жϸ�¥���Ƿ����� 
	}//ɨ��������
	for(i = 1;i<=10;i++)
	{
		if(ListGoingUp[i]!=0)
		{
			InList(WhereToGoTable,i);
			
		}
	}
	
	for(i = 10;i>=1;i--)
	{
		if(ListGoingDown[i]!=0)
		{
			InList(WhereToGoTable,i);
		}
	}
	if(WhereToGoTable.front->next->data==1)
	{
		OutList(WhereToGoTable);
	}
	if(WhereToGoTable.rear->data!=1)
	{
		InList(WhereToGoTable,1);
	}
	return OK;
}
Status HeadmakeCountculate(List &WhereToGoTable)
{//�������Ӧ������������Ϊ��Ҫ��һ���������������һЩ�͹�������
 //�ѿ͹�Ҫ��������һ�����ֶ����У�����������
 void ClearStatusList(Status List[]);
 void Clear_lfloor(PassengerList &lfloor);
 void HeadmakeCreate(PassengerList &lfloor);//ģ������
  
 	Status ListGoingUp[10];//״̬�� 
 	Status ListGoingDown[10];
 	ClearStatusList(ListGoingUp);
 	ClearStatusList(ListGoingDown);//��ʼ���������� 
 
 	PassengerList lfloor;
 	Clear_lfloor(lfloor);//��ʼ�����ݳ˿ͱ� 
 	HeadmakeCreate(lfloor);
 	int i;
 	
 	for(i = 1;i<=10;i++)//ɨ���õ�״̬�� 
 	{
 		if(lfloor.ListFloor[i].PassengerNum!=0)
 		{
 			if(lfloor.ListFloor[i].UpFloor!=NULL)
 			{
 				ListGoingUp[i] = 1;
 				Floor* p = lfloor.ListFloor[i].UpFloor;
 				while(p!=NULL)
 				{
 					int data = p->whichfloor;
 					ListGoingUp[data] = 1;
 					p = p->next;
				}//��ȡ��������¥�㣬���ҷŵ�״̬�������� 
			}//�ж��Ƿ������е��� 
		}//�жϸ�¥���Ƿ����� 
	}//ɨ�������� 
 	for(i = 10;i>=1;i--)
 	{
 		if(lfloor.ListFloor[i].PassengerNum!=0)
 		{
 			if(lfloor.ListFloor[i].DownFloor!=NULL)
 			{
 				ListGoingDown[i] = 1;
 				Floor* p = lfloor.ListFloor[i].DownFloor;
 				while(p!=NULL)
				{
					int data = p->whichfloor;
 					ListGoingDown[data] = 1;
 					p = p->next;
				}//��ȡ�����½�¥�㣬���ҷŵ�״̬�½����� 
			}//�ж��Ƿ������е��� 
		}//�жϸ�¥���Ƿ����� 
	}//ɨ��������
	for(i = 1;i<=10;i++)
	{
		if(ListGoingUp[i]!=0)
		{
			InList(WhereToGoTable,i);
			
		}
	}
	
	for(i = 10;i>=1;i--)
	{
		if(ListGoingDown[i]!=0)
		{
			InList(WhereToGoTable,i);
		}
	}
	if(WhereToGoTable.front->next->data==1)
	{
		OutList(WhereToGoTable);
	}
	if(WhereToGoTable.rear->data!=1)
	{
		InList(WhereToGoTable,1);
	}
	return OK;
}
void HeadmakeCreate(PassengerList &lfloor)
{
	int i,j;
	int n;//���� 
	int floornum;
	for(i = 1;i<=10;i++)//ʮ��¥
	{
		printf("�������%d��¥��������",i);
		scanf("%d",&n);printf("\n");
		
		if(n!=0)
		{
			for(j = 1;j<=n;j++)
			{
				printf("%d���������е�%d����ȥ����¥��",n,j);
				scanf("%d",&floornum);printf("\n");
				
				if(floornum>i)
				{
					lfloor.ListFloor[i].PassengerNum++;//��ֹ��ɵ�ƴ�i��i
					Floor* F1;
					
					F1 = (Floor*)malloc(sizeof(Floor));if(!F1)exit(OVERFLOW);
					F1->whichfloor = floornum;
					
					F1->next = lfloor.ListFloor[i].UpFloor;
					lfloor.ListFloor[i].UpFloor = F1;
				}
				else if(floornum<i)
				{
					lfloor.ListFloor[i].PassengerNum++;//��ֹ��ɵ�ƴ�i��i
					Floor* F1;
					F1 = (Floor*)malloc(sizeof(Floor));if(!F1)exit(OVERFLOW);
					F1->whichfloor = floornum;
					 
					F1->next = lfloor.ListFloor[i].DownFloor;
					lfloor.ListFloor[i].DownFloor = F1;
				}	 
			}
		}
	printf("\n\n");
	}
}
void RandomCreate(PassengerList &lfloor)//�������ģ��¥������ 
{
	int i,j;
	int n;//���� 
	int floornum;
	printf("________________________________\n");
	for(i = 1;i<=10;i++)//ʮ��¥ 
	{
		n=rand()%4;//����0��3�������
		
		if(n!=0)
		{
			printf("    ��%d���ſ���%d�����ڵȴ�\n",i,n);
			for(j = 1;j<=n;j++)
			{//�����ǵ�i�� 
				floornum = rand()%11;//����0��10�������
				while(floornum==0||floornum==i)
				{
					floornum = rand()%11;//����0��10�������
				}
				
				if(floornum>i)
				{
					if(n == 1) 
					{
						
			          //printf("________________________________\n");
						printf("     ��һ������������%d��\n",floornum);
					}
					else
					{
			          //printf("________________________________\n");
						printf("     ��%d������������%d��\n",j,floornum);
					} 
					
					lfloor.ListFloor[i].PassengerNum++;//��ֹ��ɵ�ƴ�i��i
					Floor* F1;
					
					F1 = (Floor*)malloc(sizeof(Floor));if(!F1)exit(OVERFLOW);
					F1->whichfloor = floornum;
					
					F1->next = lfloor.ListFloor[i].UpFloor;
					lfloor.ListFloor[i].UpFloor = F1;
				}
				else if(floornum<i)
				{
					if(n == 1)
					{
						printf("     ��һ�������½���%d��\n",floornum);
					}
					else
					{
						printf("     ��%d�������½���%d��\n",j,floornum);
					} 
					
					lfloor.ListFloor[i].PassengerNum++;//��ֹ��ɵ�ƴ�i��i
					Floor* F1;
					F1 = (Floor*)malloc(sizeof(Floor));if(!F1)exit(OVERFLOW);
					F1->whichfloor = floornum;
					 
					F1->next = lfloor.ListFloor[i].DownFloor;
					lfloor.ListFloor[i].DownFloor = F1;
				}
			}//����������� 
			
			printf("--------------------------------\n");
		} //�ж�������Ƿ�Ϊ0 
		
	} //ѭ��ʮ�� 
	printf("      ģ�����׼���������      \n");
	printf("________________________________\n");
}
void Clear_lfloor(PassengerList &lfloor)
{
	int i;
	for(i = 1;i<=10;i++)
	{
		lfloor.ListFloor[i].DownFloor = NULL;
		lfloor.ListFloor[i].UpFloor = NULL;
		lfloor.ListFloor[i].PassengerNum = 0;
	}
}
void ClearStatusList(Status List[])
{
	int i;
	for(i = 1;i<=10;i++)
	{
		List[i] = 0;
	} 
}

void RandomSystem()
{
	List WhereToGoTable;//������н��ǵ������е����ն��� 
	Sleep(2000);
	system("cls");
	printf(">>>                                                  <<<\n");
	printf("                ��ӭʹ���������ģʽ                 \n");
	printf("        ��ϵͳ�������ÿ��¥�ж������Լ���Щ�˷�        \n");
	printf("        ����ȥ�ڼ���¥Ȼ��ͨ������ģ����ݵĵ���         \n");
	printf(">>>                                                  <<<\n");
		
	printf("��Ҫ˵����\n");
	printf("��������ƹ���ʮ��¥��һ̨����������Ϊһ¥ͨ����\n");
	printf("�Ƚ϶�����˵��������õ�ʱ������������ײ�\n");
	printf("\n"); 
	printf("\n�����ʼģ��\n") ;
	
	system("pause");
	
	InitList(WhereToGoTable);
	StarCountculate(WhereToGoTable);
	printf("ͨ�������������ȹ���Ҫ����%d��\n",WhereToGoTable.count);
	
	/*LNode* p = WhereToGoTable.front->next;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p = p->next;
	}*/
	system("pause");
    int n = 1;
    int r=0;//Ŀǰ����¥�� 
	print();
    while(n)
    {
        n = OutList(WhereToGoTable);//����0-10�������
		
        if(n!=0&&n!=r)
        printf("%d",n);
        if(0<n && n < Num+1 && n!=r)
            r=run(n);
        Sleep(2000);
    }
}

void EasySystem()
{
	Sleep(2000);
	system("cls");
	int n = 1;
    int r=0;//Ŀǰ����¥�� 
    
	print();
    while(n!=0)
    {
        //����0-10�������
		printf("��������Ҫ�����¥�㣺"); 
		scanf("%d",&n);
        if(n!=0&&n!=r);
        if(0<n && n < Num+1 && n!=r)
            r=run(n);
        Sleep(2000);
    }
}
void HeadmakeSystem()
{
	Sleep(2000);
	system("cls");
	List WhereToGoTable;//������н��ǵ������е����ն��� 
	printf(">>>                                                  <<<\n");
	printf("               ��ӭʹ�õ��ݵ���ģ��ϵͳ                 \n");
	printf("         ϵͳ�ֶ�����ÿ��¥�ж������Լ���Щ�˷ֱ�       \n");
	printf("         ��ȥ�ĸ�¥�㣬Ȼ��ͨ������ģ����ݵĵ���       \n");
	printf(">>>                                                  <<<\n");
	
	printf("��Ҫ˵����\n");
	printf("��������ƹ���ʮ��¥��һ̨����������Ϊһ¥ͨ����Ƚ�\n");
	printf("������˵��������õ�ʱ������������ײ�\n");
	printf("\n�����ʼ����\n") ;
	
	
	system("pause");
	
	InitList(WhereToGoTable);
	HeadmakeCountculate(WhereToGoTable);
	printf("ͨ�������������ȹ���Ҫ����%d��\n",WhereToGoTable.count);
	
	system("pause");
    int n = 1;
    int r=0;//Ŀǰ����¥�� 
	print();
    while(n)
    {
        n = OutList(WhereToGoTable);//����0-10�������
		
        if(n!=0&&n!=r)
        printf("%d",n);
        if(0<n && n < Num+1 && n!=r)
            r=run(n);
        Sleep(2000);
    }
}

int main(void)
{
	int choice=1;
	 
	
	printf("\t\t\t\t>>>                                                  <<<\n");
	printf("\t\t\t\t               ��ӭʹ�õ��ݵ���ģ��ϵͳ                 \n");
	printf("\t\t\t\t           1.�������ʹ�õ��ݵ������Լ�����             \n");
	printf("\t\t\t\t           2.�򵥶Ե��ݷ���ָ��                         \n");
	printf("\t\t\t\t           3.�ֶ��������в�������                       \n");
	printf("\t\t\t\t           0.��������                                   \n");
	printf("\t\t\t\t                                                        \n");
	printf("\t\t\t\t>>>                                                  <<<\n");
	
	printf("\t\t\t\t�����룺");
	scanf("%d",&choice);
	while(choice)
	{
		switch(choice) 
		{
			case 1:
				RandomSystem();
				break;
			case 2:
				EasySystem();
				break;
			case 3:
				HeadmakeSystem();
				break;
			default:
				break;
		}
		printf("\n");
		Sleep(2000);
		system("cls");
		printf("\t\t\t\t>>>                                                  <<<\n");
		printf("\t\t\t\t               �����Ҫ����ʹ����ָʾ                   \n");
		printf("\t\t\t\t           1.�������ʹ�õ��ݵ������Լ�����             \n");
		printf("\t\t\t\t           2.�򵥶Ե��ݷ���ָ��                         \n");
		printf("\t\t\t\t           3.�ֶ��������в�������                       \n");
		printf("\t\t\t\t           0.��������                                   \n");
		printf("\t\t\t\t                                                        \n");
		printf("\t\t\t\t>>>                                                  <<<\n");
		printf("\t\t\t\t�����룺");
		scanf("%d",&choice);
	} 
	printf("\t\t\t\t�ǳ���л����ʹ�ú�֧�֣��ټ�[>_<]\n");
	
	return 0;
}








