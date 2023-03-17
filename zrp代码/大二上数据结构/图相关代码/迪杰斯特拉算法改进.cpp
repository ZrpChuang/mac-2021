# include<stdio.h>
# include<stdlib.h>
# include<string.h>

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2
# define INFINITY 1000
# define MAX_VERTEX_NUM 20

typedef int Status;
typedef char VertaxType[3];//储存单个节点的名称
 
typedef int VRType;
typedef enum{DG = 1,DN,UDG,UDN} GraphKind;//分别是（无向图，有向图，无向带权图，有向带权图）
typedef int PathMatrix[MAX_VERTEX_NUM];//用于存储
typedef int ShortPathTable[MAX_VERTEX_NUM];//存储最终距离 
typedef int VRType;//用于最小生成树普利姆算法 

Status Visit[MAX_VERTEX_NUM];
//第一个值 默认是零
 
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

typedef struct MINSIDE
{
	VertaxType adjvex;
	VRType lowcost;
		
}minside[MAX_VERTEX_NUM];

//函数前置声明
Status CreateUDN(MGraph &G);
Status CreateDG(MGraph &G);
Status CreateDN(MGraph &G);
Status CreateUDG(MGraph &G);
Status Create(MGraph &G);
Status Print(MGraph G);
int Find(MGraph G,char v[]);

void ShortestPath_DIJ(MGraph G,int v0,PathMatrix &P,ShortPathTable &D);
//Status PrintPathMatrix(MGraph G1,PathMatrix p1);
Status PrintPathLong(MGraph G1,ShortPathTable d1,char name[]);

void miniSpanTree_PRIM(MGraph G,VertaxType u);
int Min(MGraph G,MINSIDE closedge[]);//需要调用 
void PrintPath(MGraph G,PathMatrix &P,int v0);
//函数前置声明 

int main(void)
{ 
	MGraph G1;
	Create(G1);
	PathMatrix p1;
	ShortPathTable d1;
	char name[3];
	int v0;//返回位置，可以用在矩阵 
	
	
	printf("实现最短路径迪杰拉斯算法");
	printf("请随机输入选取一个节点，并且输入起始节点的名称：");
	fflush(stdin);
	scanf("%s",&name);
	v0 = Find(G1,name);
	ShortestPath_DIJ(G1,v0,p1,d1);//求关于v0的所有最短路径 赋值到shorttable中 
	PrintPathLong(G1,d1,name);//输出 
	PrintPath(G1,p1,v0);
	
	printf("\n\n");
	printf("计算机科学与技术 2020101124 张瑞鹏 感谢观看");
	 
	return 0;
}

Status PrintPathLong(MGraph G1,ShortPathTable d1,char name[])
{
	int m;
	
	printf("最短路径已经分别求得，%s到其余的点的距离如下：\n",name);
	for(m = 1; m <= G1.vexnum ; m++)
	{
		printf("到%s结点:",G1.vex[m]);//存名字的节点从一开始 
		printf("%d\n\n",d1[m]);
	}
	
	return OK;
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
	
	for(i = 1;i <=G.vexnum;i++)
		{
			for(j = 1;j <=G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
			G.arcs[i][i].adj= 0;//对角线赋值是零
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
	
	for(i = 1;i <=G.vexnum;i++)
		{
			for(j = 1;j <=G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
			G.arcs[i][i].adj= 0;//对角线赋值是零 
		}
	
	char v1[3];//操作空间顶点 
	char v2[3];
	int a1,a2;
	int w;//操作空间权值	
	for(i = 1 ;i <= G.arcnum ; i++)
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
	
	for(i = 1;i <=G.vexnum;i++)
		{
			for(j = 1;j <=G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
			G.arcs[i][i].adj= 0;//对角线赋值是零
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
	
	for(i = 1;i <=G.vexnum;i++)
		{
			for(j = 1;j <=G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
			G.arcs[i][i].adj= 0;//对角线赋值是零
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
	
	return i;//名称0号位置没有放东西 但是矩阵0号开始 
}

Status Print(MGraph G)//全图进行打印 
{
	int i,j;
	printf("\n\n");
	printf("\n\n");
	printf("图用零阶矩阵存储，零阶矩阵存储效果如图所示\n");
	printf("\n\n");
	
	printf("     ");
	for(j = 1;j <=G.vexnum; j++)
		{
			printf("v%d  ",j);
		} 
	
	for(i = 1;i <=G.vexnum;i++)
		{
			printf("\n\n");
			printf("v%d   ",i);
			for(j = 1;j <=G.vexnum; j++)
				{
					if(G.arcs[i][j].adj <1000)
					printf("%d   ",G.arcs[i][j].adj);
					else
					printf("~   ");
				} 
		}
		
	printf("\n");
	return OK;
}


void ShortestPath_DIJ(MGraph G,int v0,PathMatrix &P,ShortPathTable &D)//最短路径 
{
//table从零号位置开始用的数组 
 //PathMatrix 用来存储不知道什么 暂时 好像是路径
	Status Final[MAX_VERTEX_NUM];//最终结果
	int m;//用于循环操作 
	int v;//用于确定最小值 
	int min;
	int j;
	int i;
	
	
	//初始化矩阵，table，final
	
	for(v = 1;v <= G.vexnum;v++)
	{//为了对应矩阵因此0号位置使用 
		D[v] = G.arcs[v0][v].adj;//完整的把要求的那一行复制过去
		Final[v] = FALSE;
		P[v] = -1;//初始化P矩阵 
		if(D[v]<INFINITY)
		{
			P[v] =  v0;//v0是一个整数 表示矩阵中v0上的元素 
		}
	} 
	
	Final[v0] = TURE;//默认第一个值是ture 
	
	//寻找
	for(i = 1; i<G.vexnum ; i++)//一次找一个点，没说找谁，不知道找谁，刚好找完 
	{
		min = INFINITY;
		for(m = 1;m<=G.vexnum;m++)
		{
			if(D[m]<min && Final[m] == FALSE)
			{
				min = D[m];
				v = m;
			}
		}//for(m = 0;m<G.vexnum;m++)
		
		//v = m;记录自己犯的错误把这个东西放在循环外面，很不合理应该在里面
		 
		Final[v] = TURE;//已经被解决
		//去检查min+min到达会不会比其他小，如果小的话，替换
		for(m = 1 ;m <= G.vexnum;m++)
		{
			if(Final[m] == FALSE && min<INFINITY &&G.arcs[v][m].adj<INFINITY&&(min+G.arcs[v][m].adj<D[m]))
			//条件成立就应该换了 
			{//什么要换1.D要换 3.矩阵元素要换
				D[m] = min + G.arcs[v][m].adj;
				P[m] = v;
			}//是否需要修改节点 
		}//for(m = 0;w < G.vexnum;m++)逐个寻找 
	}//一次找一个点，没说找谁，不知道找谁，刚好找完

}

void PrintPath(MGraph G,PathMatrix &P,int v0)
{
	int i;
	int a[G.vexnum];
	int v;//v0为传过来的参数不用定义 
	int j;
	for(i = 1;i<=G.vexnum;i++)
	{
		printf("\n");
		v = i;
		if(i!=v0)
		{
			printf("%s到%s的路径如下所示：",G.vex[v0],G.vex[v]);
			j = 0;
			while(v!=v0)
			{
				a[j] = v;
				v = P[v];
				j++;
			}
			j--;printf("%s",G.vex[v0]);
			for(;j>=0;j--)
			{
				printf("->%s",G.vex[a[j]]);
			}
				
		}
	}
}

void miniSpanTree_PRIM(MGraph G,VertaxType u)//最小生成树 
{
	int i,j;
	int k = Find(G,u);
	minside closedge;
	
	for(i = 1;i <= G.vexnum;i++)
	{
		if(i!=k)
		{
			strcpy(closedge[i].adjvex,u);
			closedge[i].lowcost = G.arcs[k][i].adj;
		}
	}//初始化
	closedge[k].lowcost = 0;
	
	for(j = 1;j<G.vexnum;j++)
	{
		k = Min(G,closedge);//新找到的 ,注意编写函数的时候去掉已经是0的 
		
		printf("选取%s与%s长%d的边\n",closedge[k].adjvex,G.vex[k],closedge[k].lowcost);
		closedge[k].lowcost = 0;
		
		for(i = 1;i <= G.vexnum;i++)//更新路径 
		{
			if(closedge[i].lowcost!=0 && G.arcs[k][i].adj<closedge[i].lowcost)
			{
				//换点集 换数据
				strcpy(closedge[i].adjvex,G.vex[k]);
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
















































































































