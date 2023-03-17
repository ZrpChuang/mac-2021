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

//������׾��� 
typedef int Status;
typedef char VertaxType[3];
typedef enum{DG = 1,DN,UDG,UDN} GraphKind;//�ֱ��ǣ�����ͼ

typedef struct ArcNode//���ڻ��Ľڵ� 
{
	int adjvex;
	ArcNode* next;
	int cost;//�洢���� 
	
}ArcNode; 

typedef struct VNode 
{
	
	VertaxType name;//������� 
	ArcNode* firstarc;
	
}VNode,AdjList[MAX_VERTEX_NUM];//����ͷ�Žڵ��õ� 

typedef struct ALGraph
{
	AdjList vertices;//��ױ�
	int vexnum;
	int arcnum;
	GraphKind kind;//ö�ٱ��� 
}ALGraph;//����ͼ 

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

Status InitALGraph_DN(ALGraph &G)//��ʼ��,ֱ��д������ 
{
	printf("���������붥��ĸ�����"); 
	scanf("%d",&G.vexnum);
	fflush(stdin);
	printf("����������ߵĸ�����"); 
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
		printf("�������%d����������֣�",i+1);
		fflush(stdin);
		scanf("%s",&G.vertices[i].name);	
	}
	
	for(i = 0;i<G.arcnum;i++)
	{
		printf("�������%d���ߵĳ��Ƚڵ�\n",i+1);
		fflush(stdin);
		scanf("%s",&c1);	
		printf("�������%d���ߵ���Ƚڵ�\n",i+1);
		fflush(stdin);
		scanf("%s",&c2);
		printf("�������%d���ߵ�Ȩֵ\n",i+1);
		fflush(stdin);
		scanf("%d",&cost1);
		
		k1 = locate(G,c1);//�ҵ�����һ���ڵ� 
		k2 = locate(G,c2);
		
		ArcNode *p;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		if(!p)exit(OVERFLOW);
		
		p->adjvex = k2;//�ȵȼ��λ�öԲ��� 
		p->cost = cost1;
		
		p->next = G.vertices[k1].firstarc;
		G.vertices[k1].firstarc = p;//ָ������� 
	}
	
	return OK;
	
} 

int locate(ALGraph G,VertaxType name)
{
	int i = 0;//���ڼ��� 
	
	while( strcmp(G.vertices[i].name,name)!=0 && i < G.vexnum)
	{
		i++;
	}
	
	if(i>=G.vexnum)
	{
		printf("��������ȷ�����ƣ�");	
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
			printf("�ڵ�%sָ��ڵ�%s����Ϊ%d�Ļ�",G.vertices[i].name,G.vertices[adjvex].name,cost);
			p = p->next;
		}
		
	 } 
}






