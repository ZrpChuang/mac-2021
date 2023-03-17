# include<stdio.h>
# include<stdlib.h>
# include<string.h>

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2
# define INFINITY INT_MAX 
# define MAX_VERTEX_NUM 20
typedef int Status;
typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef Status PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef int Status;
typedef char VertaxType[20];//储存单个节点的名称
typedef char VertaxInformation[200];
 
typedef int VRType;
typedef enum{DG = 1,DN,UDG,UDN} GraphKind;


//结构体 
typedef struct ArcCell//是矩阵中个单个元素 
{
	VRType adj;//应该是记录相应的权值或者0，1，但是不知道VRTYpe有没有必要
	 
}AdjMartrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

struct MGraph//定义整个图 
{
	VertaxType vex[MAX_VERTEX_NUM];//顶点名字
	VertaxInformation vexInfor[MAX_VERTEX_NUM];//顶点信息 
	AdjMartrix arcs;//零阶矩阵 
	int vexnum;//该图的点数 
	int arcnum;// 该图的边数 
	GraphKind kind;//需要告知那种类型的图（无向图，有向图，无向带权图，有向带权图） 
};
struct Table
{
	int number;//尾部节点的序号 
	int time;//(路径节点的多少)
};
//结构体 
//函数前置声明 
Status CreateUDN(MGraph &G);
Status Print(MGraph G);
Status PrintD(MGraph G ,DistancMatrix D);
void ShortestPath_FLOYD(MGraph G , PathMatrix &P,DistancMatrix &D);
Status Infomation(MGraph G);
Status Guide(MGraph G,PathMatrix P,DistancMatrix D);
int sort(MGraph G,PathMatrix P,int v1,int v2,int a[]);
int check(MGraph G,PathMatrix P,int v1,int v2);
//函数前置声明 

int main(void)
{
	MGraph G1;
	CreateUDN(G1);
	
	DistancMatrix D1;
	PathMatrix P1;
	
	ShortestPath_FLOYD(G1,P1,D1);
	
	/*
	int v,w,u;
	for(v = 0;v < G1.vexnum;v ++)//对应从零号位置开始使用 
	{
		for(w = 0;w < G1.vexnum;w++)
		{	
			for(u = 0;u < G1.vexnum;u++)
			{
				printf("%d",P1[v][w][u]);
			}
		}
	}
	*/
	
	Guide(G1,P1,D1);
	Infomation(G1);
	printf("2020101124 张瑞鹏 计算机科学与技术\n");
	 
	return 0;
}

Status CreateUDN(MGraph &G)//构造 无向网带权
{//采用零阶矩
 //规定v1图书馆，v2教学楼，v3学生饭堂，v4实验楼，v5游泳池，v6篮球场
 //  
	//G.kind = 4;//无向网
	G.vexnum = 6;//有六个地点 
	G.arcnum = 8; 
	
	strcpy(G.vex[1],"图书馆");
	strcpy(G.vex[2],"教学楼");
	strcpy(G.vex[3],"学生饭堂");
	strcpy(G.vex[4],"实验楼");
	strcpy(G.vex[5],"游泳池");
	strcpy(G.vex[6],"篮球场");
	strcpy(G.vexInfor[1],"图书馆:外观大气文艺，内有五层楼高，每层楼都有很多作为供师生阅读学习");
	strcpy(G.vexInfor[2],"教学楼：紧挨着图书馆，离学生饭堂也很近，方便学生下课后到饭堂就餐");
	strcpy(G.vexInfor[3],"学生饭堂：价格实惠，种类繁多。有三层楼高，每一层各有特色");
	strcpy(G.vexInfor[4],"实验楼：在教学楼和图书馆的河对岸，从学校拱门进来首先映入眼帘的便是实验楼");
	strcpy(G.vexInfor[5],"游泳池：在旧运动场附近，大小适中，来回有50米的长度，可以满足大部分学生的需求。");
	strcpy(G.vexInfor[6],"篮球场：篮球建得相对不算很合理，地位位置相对比较远，建议驾驶电动车前往");

	int i,j;
	for(i = 0;i <G.vexnum;i++)
		{
			for(j = 0;j <G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
			G.arcs[i][i].adj= 0;//对角线赋值是零
		}
		
	G.arcs[0][1].adj = G.arcs[1][0].adj = 2;
	G.arcs[0][3].adj = G.arcs[3][0].adj = 4;
	G.arcs[0][4].adj = G.arcs[4][0].adj = 3;
	G.arcs[1][2].adj = G.arcs[2][1].adj = 1;
	G.arcs[1][3].adj = G.arcs[3][1].adj = 4;
	G.arcs[1][5].adj = G.arcs[5][1].adj = 13;
	G.arcs[2][4].adj = G.arcs[4][2].adj = 7;
	G.arcs[2][5].adj = G.arcs[5][2].adj = 13;

	Print(G);//构造完之后包含全图打印 
	return OK;
}


void ShortestPath_FLOYD(MGraph G , PathMatrix &P,DistancMatrix &D)
{
	int u,v,w;//意义对应上v起点，w终点，u中间节点（竖坐标）
	int i;
	
	//初始化 
	for(v = 0;v < G.vexnum;v ++)//对应从零号位置开始使用 
	{
		for(w = 0;w < G.vexnum;w++)
		{
			D[v][w] = G.arcs[v][w].adj;
			
			for(u = 0;u < G.vexnum;u++)
			{
				P[v][w][u] = FALSE;//其实我觉得完全没有必要 因为初始值是零 
				if(D[v][w]<INFINITY)
				{
					P[v][w][v] = TURE;
					P[v][w][w] = TURE;
				}
			}
		}
	}
	
	for(u = 0;u<G.vexnum;u++)
	{
		for(v = 0;v<G.vexnum;v++)
		{
			for(w = 0;w<G.vexnum;w++)
			{
				if(D[v][u] + D[u][w] < D[v][w]&&D[v][u]<INFINITY&&D[u][w]<INFINITY)
				{
					if(D[v][u] + D[u][w] >0)
					{
						D[v][w] = D[v][u] + D[u][w];
						for(i = 0;i<G.vexnum;i++)
						{
							P[v][w][i] = P[v][u][i] || P[u][w][i];
						}
					}
				}//if(D[v][u] + D[u][w] < D[v][w])
			}
		}
	}//for(u = 0;u<G.vexnum;u++)
	
	PrintD(G,D);
	
}//ShortestPath_FLOYD 

Status PrintD(MGraph G ,DistancMatrix D)
{
	int i,j;
	printf("\n\n");
	printf("\n\n");
	printf("最短路径的大小用矩阵存储，最短路径矩阵存储效果如图所示\n");
	printf("\n\n");
	
	printf("     ");
	for(j = 0;j <G.vexnum; j++)
		{
			printf("v%-3d",j+1);
		} 
	
	for(i = 0;i <G.vexnum;i++)
		{
			printf("\n\n");
			printf("v%d   ",i+1);
			for(j = 0;j <G.vexnum; j++)
				{
					if(D[i][j] != INFINITY)
					printf("%-4d",D[i][j]);
					else
					printf("~   ");
				} 
		}
		
	printf("\n");
	
	return OK;
}

Status Print(MGraph G)//全图进行打印 
{
	int i,j;
	printf("\n\n");
	printf("\n\n");
	printf("图用零阶矩阵存储，零阶矩阵存储效果如图所示\n");
	printf("\n\n");
	
	printf("     ");
	for(j = 0;j <G.vexnum; j++)
		{
			printf("v%d  ",j+1);
		} 
	
	for(i = 0;i <G.vexnum;i++)
		{
			printf("\n\n");
			printf("v%d   ",i+1);
			for(j = 0;j <G.vexnum; j++)
				{
					if(G.arcs[i][j].adj != INFINITY)
					printf("%d   ",G.arcs[i][j].adj);
					else
					printf("~   ");
				} 
		}
		
	printf("\n");
	return OK;
}

Status Infomation(MGraph G)//实现功能2 
{
	printf("\n\n");
	printf("==================================================\n");
	printf("=====如需要了解我们学校更多信息请输入下列序号=====\n");
	printf("1.图书馆 2教学楼 3学生饭堂 4实验楼 5游泳池 6篮球场\n");
	printf("===================输入0结束======================\n");
	printf("\n\n");
	
	int choose = 1;
	scanf("%d",&choose);
	while(choose)
	{
		switch(choose)
		{
			case 1:
				printf("%s\n",G.vexInfor[1]);
				break;
			case 2:	
				printf("%s\n",G.vexInfor[2]);
				break;
			case 3:
				printf("%s\n",G.vexInfor[3]);
				break;
			case 4:	
				printf("%s\n",G.vexInfor[4]);
				break;
			case 5:
				printf("%s\n",G.vexInfor[5]);
				break;
			case 6:
				printf("%s\n",G.vexInfor[6]);
				break;
			default:
				printf("error\n"); 
				break;
		}//switch(choose)
		printf("\n\n");
		printf("==================================================\n");
		printf("=====如需要了解我们学校更多信息请输入下列序号=====\n");
		printf("1.图书馆 2教学楼 3学生饭堂 4实验楼 5游泳池 6篮球场\n");
		printf("===================输入0结束======================\n");
		printf("\n\n");
		fflush(stdin);
		scanf("%d",&choose);
	}
}

Status Guide(MGraph G,PathMatrix P,DistancMatrix D)
{
	int v1,v2;
	int n;
	int i;
	int a[6];
	int choose = 1;
	while(choose)
	{
		printf("==================================================\n");
		printf("           ====欢迎使用校内导航系====             \n");
		printf("               (请输入你所在位置)                 \n");
		printf("1.图书馆 2教学楼 3学生饭堂 4实验楼 5游泳池 6篮球场\n");
		printf("                                                  \n");
		printf("==================================================\n");
		printf("您现在所在位置是：");
		fflush(stdin);
		scanf("%d",&v1);
		
	 	printf("\n");
	 	printf("请问您想要去：");
	 	fflush(stdin);
		scanf("%d",&v2); 
		
		v1 = v1-1;
		v2 = v2-1;//存储中所有从0开始 
		printf("总距离长度为您计算的结果是%d个单位\n\n\n",D[v1][v2]);
		
		n = sort(G,P,v1,v2,a);
		int j;
		printf("您的最短路径如下所示:\n\n\n");
		
		if(n == 2)printf("可以直接到达，没有中间地点\n");
		for(i = 0;i < n-1;i++)
		{
			j = a[i];
			printf("%s->",G.vex[j+1]);
		} 
		
		j = a[i];
		printf("%s\n\n\n",G.vex[j+1]);
		
		printf("           ====欢迎使用校内导航系====             \n");
		printf("                   (提示您)                       \n");
		printf("             请问您还要继续导航吗                 \n");
		printf("            继续请按 1  否则请按 0                \n");
		fflush(stdin);
		scanf("%d",&choose);
		
	}
	
	
	
	return OK;
}

int sort(MGraph G,PathMatrix P,int v1,int v2,int a[])
{
	int i,j;
	int n = 0;
	Table b[6];//辅助数 
	Table temp;//交换排序 
	
	for(i = 0;i< G.vexnum;i++)
	{
		if(P[v1][v2][i]!=0)
		{
			n++;
			b[n-1].number = i;//把有路径的结点记录 
		}
	}
	//结束时记录了中间节点个数的多少
	
	for(i = 0;i<n;i++)
	{
		b[i].time = check(G,P,v1,b[i].number);
	}//n次n个 
	
	for(i = n-1;i>0;i--)
	{
		for(j = 0;j<i;j++)
		{
			if(b[j].time > b[j+1].time)
			{
				temp = b[j+1];
				b[j+1] = b[j]; 
				b[j] = temp;
			}
		}
	}
	
	for(i = 0;i<n;i++)
	{
		a[i] = b[i].number;
	}
	
	return n;
}

int check(MGraph G,PathMatrix P,int v1,int v2)
{
	int n = 0;
	int i;
	
	for(i = 0;i< G.vexnum;i++)
	{
		if(P[v1][v2][i]!=0)
		{
			n++;
		}
	}
	
	
	return n;
}







