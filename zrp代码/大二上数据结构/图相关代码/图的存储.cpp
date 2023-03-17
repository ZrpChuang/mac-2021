# include<stdio.h>
# include<stdlib.h>
# include<string.h>

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2
# define INFINITY INT_MAX//系统常量 
# define MAX_VERTEX_NUM 20

/*
把一个图用零阶矩阵存储起来，打印一下看一下效果
 
*/
typedef int Status;
typedef char VertaxType[3];//储存单个节点的名称 
typedef int VRType;
typedef enum{DG = 1,DN,UDG,UDN} GraphKind;//分别是（无向图，有向图，无向带权图，有向带权图）
//第一个值默认是零
 
typedef struct ArcCell//是矩阵中个单个元素 
{
	VRType adj;//应该是记录相应的权值或者0，1，但是不知道VRTYpe有没有必要
	 
	//省略info,太麻烦了算了	
}AdjMartrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

struct MGraph//定义整个图 
{
	VertaxType vex[MAX_VERTEX_NUM];//顶点元素一维数组
	AdjMartrix arcs;//需要一个二维数组,这个定义的方式有点特别 树上的
	int vexnum;//该图的点数 
	int arcnum;// 该图的边数 
	GraphKind kind;//需要告知那种类型的图（无向图，有向图，无向带权图，有向带权图） 
};

//函数前置声明
Status CreateUDN(MGraph &G);
Status CreateDG(MGraph &G);
Status CreateDN(MGraph &G);
Status CreateUDG(MGraph &G);
Status Create(MGraph &G);
Status Print(MGraph G);
int Find(MGraph G,char v[]);
//函数前置声明 

int main(void)
{
	MGraph G1;
	int choice;
	
	printf("1.测试开始 0.取消测试");
	scanf("%d",&choice);
	while(choice!=0)
	{
		Create(G1);
		printf("1.测试继续 0.停止测试"); 
		fflush(stdin);
		scanf("%d",&choice);
	}
	
	return 0;
}

Status Create(MGraph &G)//选择窗口 
{
	printf("请输入图的类型：1.有向图,2.有向网,3.无向图,4.无向网\n");
	scanf("%d",&G.kind);
	
	switch(G.kind)
	{
		case DG:return CreateDG(G);//四种情况调用四种函数 
		case DN:return CreateDN(G);
		case UDG:return CreateUDG(G);	
		case UDN:return CreateUDN(G);
		default: return ERROR;		
	}
	return OK;
}

Status CreateDG(MGraph &G)//构造有向图 
{
	printf("请输入图中点的个数:\n");
	fflush(stdin);
	scanf("%d",&G.vexnum);
	printf("请输入图中边的条数:\n");
	fflush(stdin);
	scanf("%d",&G.arcnum);
	
	int i,j;
	for(i = 1;i <= G.vexnum;i++)
	{
		printf("请输入第%d个点的名称:",i);
		fflush(stdin);
		scanf("%s",&G.vex[i]);
	}
	
	for(i = 0;i <G.vexnum;i++)
		{
			for(j = 0;j <G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
		}
	
	char v1[3];//操作空间顶点 
	char v2[3];
	int a1,a2;
	int w = 1; //操作空间权值	
	for(i= 1 ;i <= G.arcnum ; i++)
	{
		printf("请输入第%d条边的起始节点:",i);
		fflush(stdin); 
		scanf("%s",&v1);
		printf("请输入第%d条边的终止节点:",i);
		fflush(stdin); 
		scanf("%s",&v2);
		
		a1 = Find(G,v1);
		a2 = Find(G,v2);//构造函数查找出位置 
		G.arcs[a1][a2].adj = w;
	}
	
	Print(G);
	return OK;
}

Status CreateDN(MGraph &G)//构造 有向网 
{
	printf("请输入图中点的个数:\n");
	fflush(stdin);
	scanf("%d",&G.vexnum);
	printf("请输入图中边的条数:\n");
	fflush(stdin);
	scanf("%d",&G.arcnum);
	
	int i,j;
	for(i = 1;i <= G.vexnum;i++)
	{
		printf("请输入第%d个点的名称:",i);
		fflush(stdin);
		scanf("%s",&G.vex[i]);
	}
	
	for(i = 0;i <G.vexnum;i++)
		{
			for(j = 0;j <G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
		}
	
	char v1[3];//操作空间顶点 
	char v2[3];
	int a1,a2;
	int w;//操作空间权值	
	for(i= 1 ;i <= G.arcnum ; i++)
	{
		printf("请输入第%d条边的起始节点:",i);
		fflush(stdin); 
		scanf("%s",&v1);
		printf("请输入第%d条边的终止节点:",i);
		fflush(stdin); 
		scanf("%s",&v2);
		printf("请输入第%d条边的相应权值:",i);
		fflush(stdin); 
		scanf("%d",&w);
		
		a1 = Find(G,v1);
		a2 = Find(G,v2);//构造函数查找出位置 
		G.arcs[a1][a2].adj = w;
	}
	
	Print(G);
	return OK;
}

Status CreateUDG(MGraph &G)//构造  无向图
{
	printf("请输入图中点的个数:\n");
	fflush(stdin);
	scanf("%d",&G.vexnum);
	printf("请输入图中边的条数:\n");
	fflush(stdin);
	scanf("%d",&G.arcnum);
	
	int i,j;
	for(i = 1;i <= G.vexnum;i++)
	{
		printf("请输入第%d个点的名称:",i);
		fflush(stdin);
		scanf("%s",&G.vex[i]);
	}
	
	for(i = 0;i <G.vexnum;i++)
		{
			for(j = 0;j <G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
		}
	
	char v1[3];//操作空间顶点 
	char v2[3];
	int a1,a2;
	int w = 1;//操作空间权值	
	for(i= 1 ;i <= G.arcnum ; i++)
	{
		printf("请输入第%d条边的起始节点:",i);
		fflush(stdin); 
		scanf("%s",&v1);
		printf("请输入第%d条边的终止节点:",i);
		fflush(stdin); 
		scanf("%s",&v2);
		
		a1 = Find(G,v1);
		a2 = Find(G,v2);//构造函数查找出位置 
		G.arcs[a1][a2].adj = w;
		G.arcs[a2][a1].adj = G.arcs[a1][a2].adj;
	}
	
	Print(G);
	return OK;
}

Status CreateUDN(MGraph &G)//构造 无向网带权
{//采用零阶矩
	printf("请输入图中点的个数:\n");
	fflush(stdin);
	scanf("%d",&G.vexnum);
	printf("请输入图中边的条数:\n");
	fflush(stdin);
	scanf("%d",&G.arcnum);
	
	int i,j;
	for(i = 1;i <= G.vexnum;i++)
	{
		printf("请输入第%d个点的名称:",i);
		fflush(stdin);
		scanf("%s",&G.vex[i]);
	}
	
	for(i = 0;i <G.vexnum;i++)
		{
			for(j = 0;j <G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
		}
	
	char v1[3];//操作空间顶点 
	char v2[3];
	int a1,a2;
	int w;//操作空间权值	
	for(i= 1 ;i <= G.arcnum ; i++)
	{
		printf("请输入第%d条边的起始节点:",i);
		fflush(stdin); 
		scanf("%s",&v1);
		printf("请输入第%d条边的终止节点:",i);
		fflush(stdin); 
		scanf("%s",&v2);
		printf("请输入第%d条边的相应权值:",i);
		fflush(stdin); 
		scanf("%d",&w);
		
		a1 = Find(G,v1);
		a2 = Find(G,v2);//构造函数查找出位置 
		G.arcs[a1][a2].adj = w;
		G.arcs[a2][a1].adj = G.arcs[a1][a2].adj;
	}
	
	Print(G);
	return OK;
}

int Find(MGraph G,char v[])//查找给节点名称所在位置 
{
	int i;
	for(i = 1 ; strcmp(G.vex[i],v) != 0 && i<MAX_VERTEX_NUM ; i++ );
	if(i>=MAX_VERTEX_NUM)
	{
		printf("请输入正确的数字\n");
	}
	
	return i-1;
}

Status Print(MGraph G)//全图进行打印 
{
	int i,j;
	
	for(i = 0;i <G.vexnum;i++)
		{
			printf("\n\n");
			
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

//中心选址问题，求两个点之间的最短路径


//迪杰拉斯算法 







