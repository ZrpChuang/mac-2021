# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<iostream>

using namespace std;

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2
# define INFINITY 2020
# define MAX_VERTEX_NUM 20

typedef int Status;
typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//优化成二维数组 

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

Status CreateUDN(MGraph &G);
Status Print(MGraph G);
Status PrintD(MGraph G ,DistancMatrix D);
void ShortestPath_FLOYD(MGraph G , PathMatrix &P,DistancMatrix &D);
Status Infomation(MGraph G);
Status Guide(MGraph G,PathMatrix P,DistancMatrix D);
int sort(MGraph G,PathMatrix P,int v1,int v2,int a[]);
int check(MGraph G,PathMatrix P,int v1,int v2);
Status DrawGraph(void);
Status PrintP(MGraph G ,DistancMatrix D);

int NextVex(MGraph &G,int v,int w);
void DFSTraverse(MGraph &G) ;
void DFS(MGraph &G,int v,Status visit[]);
//函数前置声明 

int main(void)
{
	DrawGraph();
	MGraph G1;
	CreateUDN(G1);
	
	DistancMatrix D1;
	//PathMatrix P1;
	DFSTraverse(G1) ;//写了一个遍历的算法 
	//ShortestPath_FLOYD(G1,P1,D1);
	
	//PrintP(G1,P1);

	//Guide(G1,P1,D1);
	//Infomation(G1);
	
	printf("2020101124 张瑞鹏 计算机科学与技术\n");
	 
	return 0;
}
/*//未完善，广度优先 
void BFSTraverse(MGraph &G)
{
	int visit[G.vexnum];
	for(int i= 0;i<=G.vexnum;i++)
	{
		visit[i] = 0;
	}
	for(int i = 0;i<G.vexnum;i++)
	{
		if(visit[i]==0)
		{
			visit[i] = 1;
			EnQueue(Q,v);
			while(!QueueEmpty(Q))
			{
				DeQueue(Q);
				for(int w = NextVex(G,v,1);w>0;w = NextVex(G,v,w+1))
				{
					Visit[i] = 1;
					EnQueue(Q,w);
				}
			}
		}
	}
}*/
void DFSTraverse(MGraph &G) 
{
	Status visit[20];
	int v;
	int i;
	
	for(i = 0;i<20;i++)
	{
		visit[i] = 0;
	}
	
	for(v = 0;v<G.vexnum;v++)
	{
		if(visit[v]==0)
		{
			DFS(G,v,visit);
		}
	}
}
void DFS(MGraph &G,int v,Status visit[])
{
	visit[v] = 1;
	printf("遍历%d\n",v);
	
	int w;
	
	for(w = NextVex(G,v,1);w>0;w = NextVex(G,v,w+1))
	{
		if(visit[w] == 0)
		DFS(G,w,visit);
	}
}

int NextVex(MGraph &G,int v,int w)
{
	while(G.arcs[v][w].adj>100||v==w)
	{
		w++;
	}
	if(w>=G.vexnum){
		return -1;
	}
	else{
		return w;
	}
}

Status DrawGraph(void)
{
	cout <<"================================================================="<< endl;
	cout <<"=  游泳池__________________________学生饭堂___________          "<< endl;
	cout <<"=    \\             9                 /              13\\        "<< endl;
	cout <<"=     \\                             /                  \\       "<< endl;
	cout <<"=     3\\                           /  1        ________篮球场  "<< endl;
	cout <<"=       \\                         /           /                "<< endl;
	cout <<"=        \\                       /           /13               "<< endl;
	cout <<"=         图书馆_____________教学楼_________/                  "<< endl;
	cout <<"=          \\         2         /                             "<< endl;
	cout <<"=           \\                 /                               "<< endl;
	cout <<"=          4 \\               / 4             				    "<< endl;
	cout <<"=             \\             /              					"<< endl;
	cout <<"=              \\___实验楼__/                         	 	    "<< endl;
	cout <<"=                                       					    "<< endl;
	cout <<"================================================================="<< endl;
	return OK;
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
	//初始化 
	for(v = 0;v < G.vexnum;v ++)//对应从零号位置开始使用 
	{
		for(w = 0;w < G.vexnum;w++)
		{
			D[v][w] = G.arcs[v][w].adj;
			P[v][w] = -1;
			if(D[v][w]<INFINITY) P[v][w] = v;//初始化能够到达的矩阵		
		}
	}
	
	for(u = 0;u<G.vexnum;u++)
	{
		for(v = 0;v<G.vexnum;v++)
		{
			for(w = 0;w<G.vexnum;w++)
			{
				if(D[v][u] + D[u][w] < D[v][w] && D[v][u]<INFINITY && D[u][w]<INFINITY)
				{
					D[v][w] = D[v][u] + D[u][w];
					P[v][w] = P[u][w];
					
				}//if(D[v][u] + D[u][w] < D[v][w])
			}
		}
	}//for(u = 0;u<G.vexnum;u++)
	PrintD(G,D);
}//ShortestPath_FLOYD 

Status Guide(MGraph G,PathMatrix P,DistancMatrix D)
{
	int v1,v2;
	int a[G.vexnum];
	int i = 0;
	
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
	
	printf("%s去到%v2的最短路径如下：\n",G.vex[v1],G.vex[v2]);
	
	v1--;
	v2--;//减一进行操作 
	
	while(v2!=v1)
	{
		a[i] = v2;
		v2 = P[v1][v2];
		i++;
	}
	
	printf("%s",G.vex[v1+1]);
	for(i ; i > 0 ; i--)
	{
		printf("->%s",G.vex[a[i-1]+1]);
	}
	
	return OK;
}

Status PrintP(MGraph G ,DistancMatrix P)
{
	int i,j;
	printf("\n\n");
	printf("\n\n");
	printf("最短路径的路径用矩阵存储，最短路径矩阵存储效果如图所示\n");
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
					if(P[i][j] != INFINITY)
					printf("%-4d",P[i][j]);
					else
					printf("~   ");
				} 
		}
		
	printf("\n");
	
	return OK;
}

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
			printf("v%-3d",j+1);
		} 
	
	for(i = 0;i <G.vexnum;i++)
		{
			printf("\n\n");
			printf("v%-4d",i+1);
			for(j = 0;j <G.vexnum; j++)
				{
					if(G.arcs[i][j].adj != INFINITY)
					printf("%-4d",G.arcs[i][j].adj);
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







