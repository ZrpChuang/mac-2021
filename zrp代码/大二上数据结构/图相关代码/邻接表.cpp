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

//构造零阶矩阵 
typedef int Status;
typedef char VertaxType[3];
typedef enum{DG = 1,DN,UDG,UDN} GraphKind;//分别是（无向图

typedef struct ArcNode//相邻弧的节点 
{
	int adjvex;
	ArcNode* next;
	int cost;//存储长度 
	
}ArcNode; 

typedef struct VNode 
{
	
	VertaxType name;//点的名字 
	ArcNode* firstarc;
	
}VNode,AdjList[MAX_VERTEX_NUM];//书上头号节点用的 

typedef struct ALGraph
{
	AdjList vertices;//零阶表
	int vexnum;
	int arcnum;
	GraphKind kind;//枚举变量 
}ALGraph;//整个图 

//
int locate(ALGraph G,VertaxType name);
Status InitALGraph_DN(ALGraph &G);
void Show(ALGraph G);
//
int main(void)
{
	ALGraph G2;
	InitALGraph_DN(G2);
	Show(G2);
	return 0;
}

Status InitALGraph_DN(ALGraph &G)//初始化,直接写有向网 
{
	printf("请依次输入顶点的个数："); 
	scanf("%d",&G.vexnum);
	fflush(stdin);
	printf("请依次输入边的个数："); 
	scanf("%d",&G.arcnum);
	G.kind = DN;
	
	int i;
	
	VertaxType c1;
	VertaxType c2;
	
	int k1,k2;
	int cost1;
	
	for(i = 0 ; i <= MAX_VERTEX_NUM ; i++)
	{
		G.vertices[i].firstarc = NULL;
	}
	 
	for(i = 0;i < G.vexnum;i++)
	{
		printf("请输入第%d个顶点的名字：",i+1);
		fflush(stdin);
		scanf("%s",&G.vertices[i].name);	
	}
	
	for(i = 0;i<G.arcnum;i++)
	{
		printf("请输入第%d条边的出度节点\n",i+1);
		fflush(stdin);
		scanf("%s",&c1);	
		printf("请输入第%d条边的入度节点\n",i+1);
		fflush(stdin);
		scanf("%s",&c2);
		printf("请输入第%d条边的权值\n",i+1);
		fflush(stdin);
		scanf("%d",&cost1);
		
		k1 = locate(G,c1);//找到这样一个节点 
		k2 = locate(G,c2);
		
		ArcNode *p;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		if(!p)exit(OVERFLOW);
		
		p->adjvex = k2;//等等检查位置对不对 
		p->cost = cost1;
		
		p->next = G.vertices[k1].firstarc;
		G.vertices[k1].firstarc = p;//指针的连接 
	}
	
	return OK;
	
} 

int locate(ALGraph G,VertaxType name)
{
	int i = 0;//用于计数 
	
	while( strcmp(G.vertices[i].name,name)!=0 && i < G.vexnum)
	{
		i++;
	}
	
	if(i>=G.vexnum)
	{
		printf("请输入正确的名称！");	
	}
	else
	{
		return i-1;
	} 
	
	
}

void Show(ALGraph G)
{
	int i;
	ArcNode *p;
	int adjvex;
	int cost;
	
	for(i = 0;i<G.vexnum;i++)
	{
		p = G.vertices[i].firstarc;
		while(p!=NULL)
		{
			adjvex = p->adjvex;
			cost = p->cost;
			printf("节点%s指向节点%s长度为%d的弧",G.vertices[i].name,G.vertices[adjvex].name,cost);
			p = p->next;
		}
		
	 } 
}






