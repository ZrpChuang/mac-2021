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

typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�Ż��ɶ�ά���� 

typedef int Status;
typedef char VertaxType[20];//���浥���ڵ������
typedef char VertaxInformation[200];
 
typedef int VRType;
typedef enum{DG = 1,DN,UDG,UDN} GraphKind;

typedef struct MINSIDE
{
	VertaxType adjvex;
	VRType lowcost;
		
}minside[MAX_VERTEX_NUM];


typedef struct ArcCell//�Ǿ����и�����Ԫ�� 
{
	VRType adj;//Ӧ���Ǽ�¼��Ӧ��Ȩֵ����0��1�����ǲ�֪��VRTYpe��û�б�Ҫ
	 
}AdjMartrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

struct MGraph//��������ͼ 
{
	VertaxType vex[MAX_VERTEX_NUM];//��������
	VertaxInformation vexInfor[MAX_VERTEX_NUM];//������Ϣ 
	AdjMartrix arcs;//��׾��� 
	int vexnum;//��ͼ�ĵ��� 
	int arcnum;// ��ͼ�ı��� 
	GraphKind kind;//��Ҫ��֪�������͵�ͼ������ͼ������ͼ�������Ȩͼ�������Ȩͼ�� 
};

Status CreateUDN(MGraph &G);
int Min(MGraph G , MINSIDE closedge[]); 
void miniSpanTree_PRIM(MGraph G,VertaxType u);//��С������
int Find(MGraph G,char v[]);

int main(void)
{
	MGraph G;
	CreateUDN(G);
	VertaxType u;
	printf("��������С����������ʼ�ڵ�");fflush(stdin);
	scanf("%s",&u); 
	miniSpanTree_PRIM(G,u);
	return 0;
}



Status CreateUDN(MGraph &G)//���� ��������Ȩ
{//������׾�
 //�涨v1ͼ��ݣ�v2��ѧ¥��v3ѧ�����ã�v4ʵ��¥��v5��Ӿ�أ�v6����
 //  
	//G.kind = 4;//������
	G.vexnum = 5;//�������ص� 
	G.arcnum = 8; 
	Status Print(MGraph G);//ȫͼ���д�ӡ 
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
			G.arcs[i][i].adj= 0;//�Խ��߸�ֵ����
		}
		
	G.arcs[0][1].adj = G.arcs[1][0].adj = 3;
	
	G.arcs[0][2].adj = G.arcs[2][0].adj = 4;
	G.arcs[0][4].adj = G.arcs[4][0].adj = 9;
	G.arcs[1][2].adj = G.arcs[2][1].adj = 8;
	G.arcs[1][3].adj = G.arcs[3][1].adj = 13;
	G.arcs[1][4].adj = G.arcs[4][1].adj = 11;
	G.arcs[2][3].adj = G.arcs[3][2].adj = 7;
	G.arcs[3][4].adj = G.arcs[4][3].adj = 4;

	Print(G);//������֮�����ȫͼ��ӡ 
	return OK;
}
Status Print(MGraph G)//ȫͼ���д�ӡ 
{
	int i,j;
	printf("\n\n");
	printf("\n\n");
	printf("ͼ����׾���洢����׾���洢Ч����ͼ��ʾ\n");
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


void miniSpanTree_PRIM(MGraph G,VertaxType u)//��С������ 
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
	}//��ʼ��
	
	for(j = 1;j<G.vexnum;j++)
	{
		k = Min(G,closedge);//���ҵ��� ,ע���д������ʱ��ȥ���Ѿ���0�� 
		
		printf("ѡȡ%s��%s��%d�ı�\n",closedge[k].adjvex,G.vex[k+1],closedge[k].lowcost);
		closedge[k].lowcost = 0;
		
		for(i = 0;i<G.vexnum;i++)//����·�� 
		{
			if(closedge[i].lowcost!=0&&G.arcs[k][i].adj<closedge[i].lowcost)
			{
				//���㼯 ������
				strcpy(closedge[i].adjvex,G.vex[k+1]);
				closedge[i].lowcost = G.arcs[k][i].adj;
			}
		}	
	}
	printf("���ϱ߹�����С������\n");
	printf("\n\n");
	
}

int Min(MGraph G , MINSIDE closedge[])//��С���������õĺ��� 
{
	int min,i;
	int flag;
	min = INFINITY;//��ֵ���޴� 
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

int Find(MGraph G,char v[])//���Ҹ��ڵ���������λ�� 
{
	int i;
	for(i = 1 ; strcmp(G.vex[i],v) != 0 && i<MAX_VERTEX_NUM ; i++ );
	if(i>=MAX_VERTEX_NUM)
	{
		printf("��������ȷ������\n");
	}
	
	return i-1;//����0��λ��û�зŶ��� ���Ǿ���0�ſ�ʼ 
}
















