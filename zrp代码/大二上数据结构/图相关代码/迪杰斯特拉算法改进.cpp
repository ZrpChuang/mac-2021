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
typedef char VertaxType[3];//���浥���ڵ������
 
typedef int VRType;
typedef enum{DG = 1,DN,UDG,UDN} GraphKind;//�ֱ��ǣ�����ͼ������ͼ�������Ȩͼ�������Ȩͼ��
typedef int PathMatrix[MAX_VERTEX_NUM];//���ڴ洢
typedef int ShortPathTable[MAX_VERTEX_NUM];//�洢���վ��� 
typedef int VRType;//������С����������ķ�㷨 

Status Visit[MAX_VERTEX_NUM];
//��һ��ֵ Ĭ������
 
typedef struct ArcCell//�Ǿ����и�����Ԫ�� 
{
	VRType adj;//Ӧ���Ǽ�¼��Ӧ��Ȩֵ����0��1�����ǲ�֪��VRTYpe��û�б�Ҫ
	 
	//ʡ��info,̫�鷳������	
}AdjMartrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

struct MGraph//��������ͼ 
{
	VertaxType vex[MAX_VERTEX_NUM];//����Ԫ��һά����
	AdjMartrix arcs;//��Ҫһ����ά����,�������ķ�ʽ�е��ر� ���ϵ�
	int vexnum;//��ͼ�ĵ��� 
	int arcnum;// ��ͼ�ı��� 
	GraphKind kind;//��Ҫ��֪�������͵�ͼ������ͼ������ͼ�������Ȩͼ�������Ȩͼ�� 
};

typedef struct MINSIDE
{
	VertaxType adjvex;
	VRType lowcost;
		
}minside[MAX_VERTEX_NUM];

//����ǰ������
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
int Min(MGraph G,MINSIDE closedge[]);//��Ҫ���� 
void PrintPath(MGraph G,PathMatrix &P,int v0);
//����ǰ������ 

int main(void)
{ 
	MGraph G1;
	Create(G1);
	PathMatrix p1;
	ShortPathTable d1;
	char name[3];
	int v0;//����λ�ã��������ھ��� 
	
	
	printf("ʵ�����·���Ͻ���˹�㷨");
	printf("���������ѡȡһ���ڵ㣬����������ʼ�ڵ�����ƣ�");
	fflush(stdin);
	scanf("%s",&name);
	v0 = Find(G1,name);
	ShortestPath_DIJ(G1,v0,p1,d1);//�����v0���������·�� ��ֵ��shorttable�� 
	PrintPathLong(G1,d1,name);//��� 
	PrintPath(G1,p1,v0);
	
	printf("\n\n");
	printf("�������ѧ�뼼�� 2020101124 ������ ��л�ۿ�");
	 
	return 0;
}

Status PrintPathLong(MGraph G1,ShortPathTable d1,char name[])
{
	int m;
	
	printf("���·���Ѿ��ֱ���ã�%s������ĵ�ľ������£�\n",name);
	for(m = 1; m <= G1.vexnum ; m++)
	{
		printf("��%s���:",G1.vex[m]);//�����ֵĽڵ��һ��ʼ 
		printf("%d\n\n",d1[m]);
	}
	
	return OK;
}

Status Create(MGraph &G)//ѡ�񴰿� 
{
	printf("������ͼ�����ͣ�1.����ͼ,2.������,3.����ͼ,4.������\n");
	scanf("%d",&G.kind);
	
	switch(G.kind)
	{
		case DG:return CreateDG(G);//��������������ֺ��� 
		case DN:return CreateDN(G);
		case UDG:return CreateUDG(G);	
		case UDN:return CreateUDN(G);
		default: return ERROR;		
	}
	return OK;
}

Status CreateDG(MGraph &G)//��������ͼ 
{
	printf("������ͼ�е�ĸ���:\n");
	fflush(stdin);
	scanf("%d",&G.vexnum);
	printf("������ͼ�бߵ�����:\n");
	fflush(stdin);
	scanf("%d",&G.arcnum);
	
	int i,j;
	for(i = 1;i <= G.vexnum;i++)
	{
		printf("�������%d���������:",i);
		fflush(stdin);
		scanf("%s",&G.vex[i]);
	}
	
	for(i = 1;i <=G.vexnum;i++)
		{
			for(j = 1;j <=G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
			G.arcs[i][i].adj= 0;//�Խ��߸�ֵ����
		}
	
	char v1[3];//�����ռ䶥�� 
	char v2[3];
	int a1,a2;
	int w = 1; //�����ռ�Ȩֵ	
	for(i= 1 ;i <= G.arcnum ; i++)
	{
		printf("�������%d���ߵ���ʼ�ڵ�:",i);
		fflush(stdin); 
		scanf("%s",&v1);
		printf("�������%d���ߵ���ֹ�ڵ�:",i);
		fflush(stdin); 
		scanf("%s",&v2);
		
		a1 = Find(G,v1);
		a2 = Find(G,v2);//���캯�����ҳ�λ�� 
		G.arcs[a1][a2].adj = w;
	}
	
	Print(G);
	return OK;
}

Status CreateDN(MGraph &G)//���� ������ 
{
	printf("������ͼ�е�ĸ���:\n");
	fflush(stdin);
	scanf("%d",&G.vexnum);
	printf("������ͼ�бߵ�����:\n");
	fflush(stdin);
	scanf("%d",&G.arcnum);
	
	int i,j;
	for(i = 1;i <= G.vexnum;i++)
	{
		printf("�������%d���������:",i);
		fflush(stdin);
		scanf("%s",&G.vex[i]);
	}
	
	for(i = 1;i <=G.vexnum;i++)
		{
			for(j = 1;j <=G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
			G.arcs[i][i].adj= 0;//�Խ��߸�ֵ���� 
		}
	
	char v1[3];//�����ռ䶥�� 
	char v2[3];
	int a1,a2;
	int w;//�����ռ�Ȩֵ	
	for(i = 1 ;i <= G.arcnum ; i++)
	{
		printf("�������%d���ߵ���ʼ�ڵ�:",i);
		fflush(stdin); 
		scanf("%s",&v1);
		printf("�������%d���ߵ���ֹ�ڵ�:",i);
		fflush(stdin); 
		scanf("%s",&v2);
		printf("�������%d���ߵ���ӦȨֵ:",i);
		fflush(stdin); 
		scanf("%d",&w);
		
		a1 = Find(G,v1);
		a2 = Find(G,v2);//���캯�����ҳ�λ�� 
		G.arcs[a1][a2].adj = w;
	}
	
	Print(G);
	return OK;
}

Status CreateUDG(MGraph &G)//����  ����ͼ
{
	printf("������ͼ�е�ĸ���:\n");
	fflush(stdin);
	scanf("%d",&G.vexnum);
	printf("������ͼ�бߵ�����:\n");
	fflush(stdin);
	scanf("%d",&G.arcnum);
	
	int i,j;
	for(i = 1;i <= G.vexnum;i++)
	{
		printf("�������%d���������:",i);
		fflush(stdin);
		scanf("%s",&G.vex[i]);
	}
	
	for(i = 1;i <=G.vexnum;i++)
		{
			for(j = 1;j <=G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
			G.arcs[i][i].adj= 0;//�Խ��߸�ֵ����
		}
	
	char v1[3];//�����ռ䶥�� 
	char v2[3];
	int a1,a2;
	int w = 1;//�����ռ�Ȩֵ	
	for(i= 1 ;i <= G.arcnum ; i++)
	{
		printf("�������%d���ߵ���ʼ�ڵ�:",i);
		fflush(stdin); 
		scanf("%s",&v1);
		printf("�������%d���ߵ���ֹ�ڵ�:",i);
		fflush(stdin); 
		scanf("%s",&v2);
		
		a1 = Find(G,v1);
		a2 = Find(G,v2);//���캯�����ҳ�λ�� 
		G.arcs[a1][a2].adj = w;
		G.arcs[a2][a1].adj = G.arcs[a1][a2].adj;
	}
	
	Print(G);
	return OK;
}

Status CreateUDN(MGraph &G)//���� ��������Ȩ
{//������׾�
	printf("������ͼ�е�ĸ���:\n");
	fflush(stdin);
	scanf("%d",&G.vexnum);
	printf("������ͼ�бߵ�����:\n");
	fflush(stdin);
	scanf("%d",&G.arcnum);
	
	int i,j;
	for(i = 1;i <= G.vexnum;i++)
	{
		printf("�������%d���������:",i);
		fflush(stdin);
		scanf("%s",&G.vex[i]);
	}
	
	for(i = 1;i <=G.vexnum;i++)
		{
			for(j = 1;j <=G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
			G.arcs[i][i].adj= 0;//�Խ��߸�ֵ����
		}
	
	char v1[3];//�����ռ䶥�� 
	char v2[3];
	int a1,a2;
	int w;//�����ռ�Ȩֵ	
	for(i= 1 ;i <= G.arcnum ; i++)
	{
		printf("�������%d���ߵ���ʼ�ڵ�:",i);
		fflush(stdin); 
		scanf("%s",&v1);
		printf("�������%d���ߵ���ֹ�ڵ�:",i);
		fflush(stdin); 
		scanf("%s",&v2);
		printf("�������%d���ߵ���ӦȨֵ:",i);
		fflush(stdin); 
		scanf("%d",&w);
		
		a1 = Find(G,v1);
		a2 = Find(G,v2);//���캯�����ҳ�λ�� 
		G.arcs[a1][a2].adj = w;
		G.arcs[a2][a1].adj = G.arcs[a1][a2].adj;
	}
	
	Print(G);
	return OK;
}

int Find(MGraph G,char v[])//���Ҹ��ڵ���������λ�� 
{
	int i;
	for(i = 1 ; strcmp(G.vex[i],v) != 0 && i<MAX_VERTEX_NUM ; i++ );
	if(i>=MAX_VERTEX_NUM)
	{
		printf("��������ȷ������\n");
	}
	
	return i;//����0��λ��û�зŶ��� ���Ǿ���0�ſ�ʼ 
}

Status Print(MGraph G)//ȫͼ���д�ӡ 
{
	int i,j;
	printf("\n\n");
	printf("\n\n");
	printf("ͼ����׾���洢����׾���洢Ч����ͼ��ʾ\n");
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


void ShortestPath_DIJ(MGraph G,int v0,PathMatrix &P,ShortPathTable &D)//���·�� 
{
//table�����λ�ÿ�ʼ�õ����� 
 //PathMatrix �����洢��֪��ʲô ��ʱ ������·��
	Status Final[MAX_VERTEX_NUM];//���ս��
	int m;//����ѭ������ 
	int v;//����ȷ����Сֵ 
	int min;
	int j;
	int i;
	
	
	//��ʼ������table��final
	
	for(v = 1;v <= G.vexnum;v++)
	{//Ϊ�˶�Ӧ�������0��λ��ʹ�� 
		D[v] = G.arcs[v0][v].adj;//�����İ�Ҫ�����һ�и��ƹ�ȥ
		Final[v] = FALSE;
		P[v] = -1;//��ʼ��P���� 
		if(D[v]<INFINITY)
		{
			P[v] =  v0;//v0��һ������ ��ʾ������v0�ϵ�Ԫ�� 
		}
	} 
	
	Final[v0] = TURE;//Ĭ�ϵ�һ��ֵ��ture 
	
	//Ѱ��
	for(i = 1; i<G.vexnum ; i++)//һ����һ���㣬û˵��˭����֪����˭���պ����� 
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
		
		//v = m;��¼�Լ����Ĵ���������������ѭ�����棬�ܲ�����Ӧ��������
		 
		Final[v] = TURE;//�Ѿ������
		//ȥ���min+min����᲻�������С�����С�Ļ����滻
		for(m = 1 ;m <= G.vexnum;m++)
		{
			if(Final[m] == FALSE && min<INFINITY &&G.arcs[v][m].adj<INFINITY&&(min+G.arcs[v][m].adj<D[m]))
			//����������Ӧ�û��� 
			{//ʲôҪ��1.DҪ�� 3.����Ԫ��Ҫ��
				D[m] = min + G.arcs[v][m].adj;
				P[m] = v;
			}//�Ƿ���Ҫ�޸Ľڵ� 
		}//for(m = 0;w < G.vexnum;m++)���Ѱ�� 
	}//һ����һ���㣬û˵��˭����֪����˭���պ�����

}

void PrintPath(MGraph G,PathMatrix &P,int v0)
{
	int i;
	int a[G.vexnum];
	int v;//v0Ϊ�������Ĳ������ö��� 
	int j;
	for(i = 1;i<=G.vexnum;i++)
	{
		printf("\n");
		v = i;
		if(i!=v0)
		{
			printf("%s��%s��·��������ʾ��",G.vex[v0],G.vex[v]);
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

void miniSpanTree_PRIM(MGraph G,VertaxType u)//��С������ 
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
	}//��ʼ��
	closedge[k].lowcost = 0;
	
	for(j = 1;j<G.vexnum;j++)
	{
		k = Min(G,closedge);//���ҵ��� ,ע���д������ʱ��ȥ���Ѿ���0�� 
		
		printf("ѡȡ%s��%s��%d�ı�\n",closedge[k].adjvex,G.vex[k],closedge[k].lowcost);
		closedge[k].lowcost = 0;
		
		for(i = 1;i <= G.vexnum;i++)//����·�� 
		{
			if(closedge[i].lowcost!=0 && G.arcs[k][i].adj<closedge[i].lowcost)
			{
				//���㼯 ������
				strcpy(closedge[i].adjvex,G.vex[k]);
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
















































































































