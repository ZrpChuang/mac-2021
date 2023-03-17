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

// 初始化一个电梯, 电梯位于一楼,停止状态
int dianti[2]={1,0};

// 定义一个存储电梯内部按键的数组
int init[10];

// 绘图函数

int print()
{
    printf("\n\n\t\t>>>电梯模拟图<<<:\t\t电梯运行方向\n\n\n");
    int i;
    for(i=0;i<10;i++)
    {
        printf("\t\t\t%2d| ",10-i);
        if(10-i==dianti[0])
            {
                printf("（电梯）\t\t   ");
                if(-1==dianti[1])
                    printf("下");
                if(1==dianti[1])
                    printf("上");
                if(0==dianti[1])//停止状态 
                    printf("停");
            }
        printf("\n");
    }
    printf("\t\t\t\t\t\t所在楼层:%d",dianti[0]);
    printf("\n\n\t\t\t\t\t\t下一层楼:__\b\b");
}
// 电梯的运行
int run(int n)
{   //给定一定的层数,电梯将会逐步运行到指定楼层.
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
{//这个函数应该是最困难最为重要的一个函数，随机产生一些客观条件再
 //把客观要求体现在一个数字队列中，供电梯运行
 void ClearStatusList(Status List[]);
 void Clear_lfloor(PassengerList &lfloor);
 void RandomCreate(PassengerList &lfloor);//模拟生成
  
 	Status ListGoingUp[10];//状态表 
 	Status ListGoingDown[10];
 	ClearStatusList(ListGoingUp);
 	ClearStatusList(ListGoingDown);//初始化两个序列 
 
 	PassengerList lfloor;
 	Clear_lfloor(lfloor);//初始化电梯乘客表 
 	RandomCreate(lfloor);
 	int i;
 	
 	for(i = 1;i<=10;i++)//扫描后得到状态表 
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
				}//读取所有上升楼层，并且放到状态上升数组 
			}//判断是否有上行的人 
		}//判断该楼层是否有人 
	}//扫描整个表 
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
				}//读取所有下降楼层，并且放到状态下降数组 
			}//判断是否有下行的人 
		}//判断该楼层是否有人 
	}//扫描整个表
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
{//这个函数应该是最困难最为重要的一个函数，随机产生一些客观条件再
 //把客观要求体现在一个数字队列中，供电梯运行
 void ClearStatusList(Status List[]);
 void Clear_lfloor(PassengerList &lfloor);
 void HeadmakeCreate(PassengerList &lfloor);//模拟生成
  
 	Status ListGoingUp[10];//状态表 
 	Status ListGoingDown[10];
 	ClearStatusList(ListGoingUp);
 	ClearStatusList(ListGoingDown);//初始化两个序列 
 
 	PassengerList lfloor;
 	Clear_lfloor(lfloor);//初始化电梯乘客表 
 	HeadmakeCreate(lfloor);
 	int i;
 	
 	for(i = 1;i<=10;i++)//扫描后得到状态表 
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
				}//读取所有上升楼层，并且放到状态上升数组 
			}//判断是否有上行的人 
		}//判断该楼层是否有人 
	}//扫描整个表 
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
				}//读取所有下降楼层，并且放到状态下降数组 
			}//判断是否有下行的人 
		}//判断该楼层是否有人 
	}//扫描整个表
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
	int n;//人数 
	int floornum;
	for(i = 1;i<=10;i++)//十层楼
	{
		printf("请输入第%d层楼的人数：",i);
		scanf("%d",&n);printf("\n");
		
		if(n!=0)
		{
			for(j = 1;j<=n;j++)
			{
				printf("%d个人中其中第%d个人去多少楼：",n,j);
				scanf("%d",&floornum);printf("\n");
				
				if(floornum>i)
				{
					lfloor.ListFloor[i].PassengerNum++;//防止有傻逼从i到i
					Floor* F1;
					
					F1 = (Floor*)malloc(sizeof(Floor));if(!F1)exit(OVERFLOW);
					F1->whichfloor = floornum;
					
					F1->next = lfloor.ListFloor[i].UpFloor;
					lfloor.ListFloor[i].UpFloor = F1;
				}
				else if(floornum<i)
				{
					lfloor.ListFloor[i].PassengerNum++;//防止有傻逼从i到i
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
void RandomCreate(PassengerList &lfloor)//随机数法模拟楼层人数 
{
	int i,j;
	int n;//人数 
	int floornum;
	printf("________________________________\n");
	for(i = 1;i<=10;i++)//十层楼 
	{
		n=rand()%4;//产生0到3的随机数
		
		if(n!=0)
		{
			printf("    第%d层门口有%d个人在等待\n",i,n);
			for(j = 1;j<=n;j++)
			{//现在是第i层 
				floornum = rand()%11;//产生0到10的随机数
				while(floornum==0||floornum==i)
				{
					floornum = rand()%11;//产生0到10的随机数
				}
				
				if(floornum>i)
				{
					if(n == 1) 
					{
						
			          //printf("________________________________\n");
						printf("     那一个人想上升到%d层\n",floornum);
					}
					else
					{
			          //printf("________________________________\n");
						printf("     第%d个人想上升到%d层\n",j,floornum);
					} 
					
					lfloor.ListFloor[i].PassengerNum++;//防止有傻逼从i到i
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
						printf("     那一个人想下降到%d层\n",floornum);
					}
					else
					{
						printf("     第%d个人想下降到%d层\n",j,floornum);
					} 
					
					lfloor.ListFloor[i].PassengerNum++;//防止有傻逼从i到i
					Floor* F1;
					F1 = (Floor*)malloc(sizeof(Floor));if(!F1)exit(OVERFLOW);
					F1->whichfloor = floornum;
					 
					F1->next = lfloor.ListFloor[i].DownFloor;
					lfloor.ListFloor[i].DownFloor = F1;
				}
			}//遍历随机人数 
			
			printf("--------------------------------\n");
		} //判断随机数是否为0 
		
	} //循环十层 
	printf("      模拟结束准备进入测试      \n");
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
	List WhereToGoTable;//这个队列将是电梯运行的最终队列 
	Sleep(2000);
	system("cls");
	printf(">>>                                                  <<<\n");
	printf("                欢迎使用随机产生模式                 \n");
	printf("        本系统随机产生每层楼有多少人以及那些人分        \n");
	printf("        别想去第几层楼然后通过动画模拟电梯的调度         \n");
	printf(">>>                                                  <<<\n");
		
	printf("简要说明：\n");
	printf("本程序设计共有十层楼，一台升降电梯因为一楼通常会\n");
	printf("比较多人因此电梯在闲置的时候会添加命令返回首层\n");
	printf("\n"); 
	printf("\n点击开始模拟\n") ;
	
	system("pause");
	
	InitList(WhereToGoTable);
	StarCountculate(WhereToGoTable);
	printf("通过计算整个调度过程要开门%d次\n",WhereToGoTable.count);
	
	/*LNode* p = WhereToGoTable.front->next;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p = p->next;
	}*/
	system("pause");
    int n = 1;
    int r=0;//目前所在楼层 
	print();
    while(n)
    {
        n = OutList(WhereToGoTable);//产生0-10的随机数
		
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
    int r=0;//目前所在楼层 
    
	print();
    while(n!=0)
    {
        //产生0-10的随机数
		printf("请输入想要到达的楼层："); 
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
	List WhereToGoTable;//这个队列将是电梯运行的最终队列 
	printf(">>>                                                  <<<\n");
	printf("               欢迎使用电梯调度模拟系统                 \n");
	printf("         系统手动输入每层楼有多少人以及那些人分别       \n");
	printf("         想去哪个楼层，然后通过动画模拟电梯的调度       \n");
	printf(">>>                                                  <<<\n");
	
	printf("简要说明：\n");
	printf("本程序设计共有十层楼，一台升降电梯因为一楼通常会比较\n");
	printf("多人因此电梯在闲置的时候会添加命令返回首层\n");
	printf("\n点击开始输入\n") ;
	
	
	system("pause");
	
	InitList(WhereToGoTable);
	HeadmakeCountculate(WhereToGoTable);
	printf("通过计算整个调度过程要开门%d次\n",WhereToGoTable.count);
	
	system("pause");
    int n = 1;
    int r=0;//目前所在楼层 
	print();
    while(n)
    {
        n = OutList(WhereToGoTable);//产生0-10的随机数
		
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
	printf("\t\t\t\t               欢迎使用电梯调度模拟系统                 \n");
	printf("\t\t\t\t           1.随机产生使用电梯的人数以及方向             \n");
	printf("\t\t\t\t           2.简单对电梯发出指令                         \n");
	printf("\t\t\t\t           3.手动输入所有测试数据                       \n");
	printf("\t\t\t\t           0.结束测试                                   \n");
	printf("\t\t\t\t                                                        \n");
	printf("\t\t\t\t>>>                                                  <<<\n");
	
	printf("\t\t\t\t请输入：");
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
		printf("\t\t\t\t               如果需要继续使用请指示                   \n");
		printf("\t\t\t\t           1.随机产生使用电梯的人数以及方向             \n");
		printf("\t\t\t\t           2.简单对电梯发出指令                         \n");
		printf("\t\t\t\t           3.手动输入所有测试数据                       \n");
		printf("\t\t\t\t           0.结束测试                                   \n");
		printf("\t\t\t\t                                                        \n");
		printf("\t\t\t\t>>>                                                  <<<\n");
		printf("\t\t\t\t请输入：");
		scanf("%d",&choice);
	} 
	printf("\t\t\t\t非常感谢您的使用和支持，再见[>_<]\n");
	
	return 0;
}








