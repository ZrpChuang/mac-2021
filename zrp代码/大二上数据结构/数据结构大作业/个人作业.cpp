#include<stdio.h>
#include<stdlib.h>
# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2
# define MAXSIZE 15//电梯最多承重人数为15人
# define MAXLEVEL 13 

//当前事件类型 
/*
 
最终的目的是实现两台电梯的调度
希望能够设计出能够计算出直接到达楼层的指令 指令直接传给动画展现动画效果

目前的想法是：
给两个电梯先编号，1，2，其中一个电梯会优先调用，把需要到达楼层 放置到队列里面
有两个队列，队列中的元素逐步进入后面的动画效果中，进行展示 

先做一部电梯
根据实际序列计算出电梯的路径存储在列队中，然后图像实现按照队列的顺序实现 


*/

//当前状态类型
typedef int Status;

typedef enum tagT_STATUSType 
{
	
    STATUS_STOP = 0,
    STATUS_UP,//1是上升 
    STATUS_DOWN,//2是下降 
    STATUS_WARN//警告 
    
}T_STATUSType;


typedef struct Elevator//电梯结构体 
{
    int num;//所在人数 
    int level;
    T_STATUSType status;//说明状态
	int wheretogo[13]; //只要这个里面不是全零 就要继续运作 
    
}El, *Ele;

//函数前置声明
Status WhereToGo(int Out[],int In[],Elevator E);
Status Move(int Out[],int In[],Elevator &E);
//函数前置声明 

int main(void)
{
	int OSApply[13];//数组下表表示楼层数 
	int ISApply[13];//数组内部表示内部人数
	Elevator E1;
	
//WhereToGo(OSApply,ISApply,E1);//返回需要去哪里 
	
	return 0;
}

Status Refrash(Elevator &E)
{
	E.level = 1;//初始楼层是一楼 
	E.num = 0;//初始人数为零 
	E.status = 0;//初始状态为停止状态 
	int i;
	
	for(i = 1;i <= MAXLEVEL;i++)
	{
		E.wheretogo[i] = 0;
	}
	
	return OK;
}
Status MakeSureStatus(int Out[],int In[],Elevator &E)
{
	int level = E.level;//确定现在流程 
	int sum1;//用于判断是否有赋值 
	int sum2;
	int i;
	for(i = 1;i <= MAXLEVEL;i++) 
	{
		sum1 = sum1 + Out[i];
		sum2 = sum2 + In[i];
	} 
	
	if(sum1 == sum2 == 0)//外面里面都没有人按 
	{
		Refrash(E);
	}
	else if(sum1!= 0&&sum2 == 0)//仅外面有人按 
	{
		
	}
	else if(sum1 == 0 && sum2 != 0 )//仅里面有人按 
	{
		
	}
	else if(sum1 == 0&&sum2 == 0)//外面里面都有有人按 
	{
		
	}
	
	return OK;
}

Status WhereToGo(int Out[],int In[],Elevator &E)//去哪里取决于内外申请 ,往电梯的想去数组里面赋值了 
{//只是赋值了电梯预备去向列表，具体方向还未写算法 
	int nowlevel = E.level;
	int i;
	
	if(E.num<=15)//两边的数据都需要处理，安排进出 
	{
		
		if(E.status == 1 )//当电梯处于上行阶段
		{
			for(i = 1;i<=13;i++)
			{
				if(E.level < i && Out[i] != 0)E.wheretogo[i] = 1;
				if(E.level < i && In[i] != 0)E.wheretogo[i] = 1;
				//wheretogo数组只赋值0或1，表示需不需要到达 
			}
		}
		else if(E.status == 2)//电梯处于下行阶段 
		{
			for(i = 1; i <= 13 ; i++)
			{
				if(E.level > i && Out[i] != 0) E.wheretogo[i] = 1;
				if(E.level > i && In[i] != 0)E.wheretogo[i] = 1;
			}
		} 
		else//电梯处于等待阶段 ,
		需要改变状态 ，是个难题，晚点处理 
		{
			for(i = 1; i <= 13;i++)
				{
					if(Out[i] != 0)
					{
						E.wheretogo[i] = 1;//wheretogo数组只赋值0或1，表示需不需要到达 
					}
				}
		}
	}
	
	else//满载则只需要考虑in的人的意愿 
	{
		if(E.status == 1 )//当电梯处于上行阶段
		{
			for(i = 1;i<=13;i++)
			{
				if(E.level < i && In[i] != 0)E.wheretogo[i] = 1;
				//wheretogo数组只赋值0或1，表示需不需要到达 
			}
		}
		else if(E.status == 2)//电梯处于下行阶段 
		{
			for(i = 1; i <= 13 ; i++)
			{
				if(E.level > i && In[i] != 0)E.wheretogo[i] = 1;
			}
		}
	}
	
	return OK;
}

status Press(int Out[],int In[])//模仿用户按按钮实现对电梯的控制
{//用两个数组来接受用户的命令 
	int m = MAXLEVEL;//最高层数 
	int i;
	printf("请依次输入每层楼等待的人数\n");
	for(i = 1;1<=m;i++)
	{
		printf("请输入%d楼层等待进入电梯的人数：");//没有指令输入0 
		fflush(stdin);
		scanf("%d",Out[i]);
	}
	
	int sum ; 
	printf("请依次输入初始状态电梯内想要到达某层楼的人数\n");
	for(i = 1;1<=m;i++)
	{
		printf("请输入初始状态下想去第%d楼的人数：");
		fflush(stdin);
		scanf("%d",In[i]);
		sum = sum+ In[i];
		if(sum>15)printf("出错，人数过多"); 
	}
	return OK;
} 

Status Move(int Out[],int In[],Elevator &E) 
{
	int i;
	int level = E.level;
	if(E.status == 1)//是上升
	{
		for(i = level + 1 ; i < 13 ; i++ )
		{
			if(E.wheretogo[i] != 0)//证明这一层有人希望到达
			{
				E.level = i;//给level重新赋值 
				E.wheretogo[i] = 0;//到达了这层重置 
				E.num = E.num-In[i];In[i] = 0;//电梯内人数必将减少一部分离开的人，想要离开的人数组 
				E.num = E.num + Out[i];//外面的人进来 
				if(E.num <= 15)//测试是否超重 
				{
					Out[i] = 0;
				}
				else
				{
					int more = E.num - 15;
					E.num = 15;//载荷 
					Out[i] = more;//多出来的人能进电梯 
				}
				
			} 
		}// 楼层逐步循环 
	}
	else if(E.status == 2)//是下降 
	{
		for(i = level - 1 ; i > 0 ; i-- )
		{
			if(E.wheretogo[i] != 0)//证明这一层有人希望到达
			{
				E.level = i;//到达新的一层 
				E.wheretogo[i] = 0;//到达了这层重置 
				E.num = E.num-In[i];In[i] = 0;//电梯内人数必将减少一部分离开的人，想要离开的人数组 
				E.num = E.num + Out[i];//外面的人进来 
				if(E.num <= 15)//测试是否超重 
				{
					Out[i] = 0;
				}
				else
				{
					int more = E.num - 15;
					E.num = 15;//载荷 
					Out[i] = more;//多出来的人能进电梯 
				}
				
			} 
		}// 楼层逐步循环 
	}
	/*
	else//是等待
	{
			
	} 
	*/
	return OK;
}













