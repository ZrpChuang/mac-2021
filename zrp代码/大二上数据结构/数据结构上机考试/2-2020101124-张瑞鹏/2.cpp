# include<stdio.h>
# include<stdlib.h>
# include<string.h>

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2
# define MAXNUM 20

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

typedef struct MINSIDE
{
	VertaxType adjvex;
	VRType lowcost;
		
}minside[MAX_VERTEX_NUM];


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
int Min(MGraph G , MINSIDE closedge[]); 
void miniSpanTree_PRIM(MGraph G,VertaxType u);//最小生成树
int Find(MGraph G,char v[]);

int main(void)
{
	MGraph G;
	CreateUDN(G);
	VertaxType u;
	printf("请输入最小生成树的起始节点");fflush(stdin);
	scanf("%s",&u); 
	miniSpanTree_PRIM(G,u);
	return 0;
}



Status CreateUDN(MGraph &G)//构造 无向网带权
{//采用零阶矩
 //规定v1图书馆，v2教学楼，v3学生饭堂，v4实验楼，v5游泳池，v6篮球场
 //  
	//G.kind = 4;//无向网
	G.vexnum = 5;//有六个地点 
	G.arcnum = 8; 
	Status Print(MGraph G);//全图进行打印 
	strcpy(G.vex[1],"A");
	strcpy(G.vex[2],"B");
	strcpy(G.vex[3],"C");
	strcpy(G.vex[4],"D");
	strcpy(G.vex[5],"E");

	int i,j;
	for(i = 0;i <G.vexnum;i++)
		{
			for(j = 0;j <G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
			G.arcs[i][i].adj= 0;//对角线赋值是零
		}
		
	G.arcs[0][1].adj = G.arcs[1][0].adj = 3;
	
	G.arcs[0][2].adj = G.arcs[2][0].adj = 4;
	G.arcs[0][4].adj = G.arcs[4][0].adj = 9;
	G.arcs[1][2].adj = G.arcs[2][1].adj = 8;
	G.arcs[1][3].adj = G.arcs[3][1].adj = 13;
	G.arcs[1][4].adj = G.arcs[4][1].adj = 11;
	G.arcs[2][3].adj = G.arcs[3][2].adj = 7;
	G.arcs[3][4].adj = G.arcs[4][3].adj = 4;

	Print(G);//构造完之后包含全图打印 
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


void miniSpanTree_PRIM(MGraph G,VertaxType u)//最小生成树 
{
	int i,j;
	int k = Find(G,u);
	minside closedge;
	
	for(i = 0;i<G.vexnum;i++)
	{
		if(i!=k)
		{
			strcpy(closedge[i].adjvex,u);
			closedge[i].lowcost = G.arcs[k][i].adj;
		}
		closedge[k].lowcost = 0;
	}//初始化
	
	for(j = 1;j<G.vexnum;j++)
	{
		k = Min(G,closedge);//新找到的 ,注意编写函数的时候去掉已经是0的 
		
		printf("选取%s与%s长%d的边\n",closedge[k].adjvex,G.vex[k+1],closedge[k].lowcost);
		closedge[k].lowcost = 0;
		
		for(i = 0;i<G.vexnum;i++)//更新路径 
		{
			if(closedge[i].lowcost!=0&&G.arcs[k][i].adj<closedge[i].lowcost)
			{
				//换点集 换数据
				strcpy(closedge[i].adjvex,G.vex[k+1]);
				closedge[i].lowcost = G.arcs[k][i].adj;
			}
		}	
	}
	printf("以上边构成最小生成树\n");
	printf("\n\n");
	
}

int Min(MGraph G , MINSIDE closedge[])//最小生成树运用的函数 
{
	int min,i;
	int flag;
	min = INFINITY;//赋值无限大 
	for (i = 0;i < G.vexnum;i++)
	{
		if(closedge[i].lowcost<min&&closedge[i].lowcost!=0)
		{
			min = closedge[i].lowcost;
			flag = i;
		} 
	}
	
	return flag;
}

int Find(MGraph G,char v[])//查找给节点名称所在位置 
{
	int i;
	for(i = 1 ; strcmp(G.vex[i],v) != 0 && i<MAX_VERTEX_NUM ; i++ );
	if(i>=MAX_VERTEX_NUM)
	{
		printf("请输入正确的数字\n");
	}
	
	return i-1;//名称0号位置没有放东西 但是矩阵0号开始 
}
















