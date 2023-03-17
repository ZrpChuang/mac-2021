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

typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�Ż��ɶ�ά���� 

typedef int Status;
typedef char VertaxType[20];//���浥���ڵ������
typedef char VertaxInformation[200];
 
typedef int VRType;
typedef enum{DG = 1,DN,UDG,UDN} GraphKind;


//�ṹ�� 
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
//����ǰ������ 

int main(void)
{
	DrawGraph();
	MGraph G1;
	CreateUDN(G1);
	
	DistancMatrix D1;
	//PathMatrix P1;
	DFSTraverse(G1) ;//д��һ���������㷨 
	//ShortestPath_FLOYD(G1,P1,D1);
	
	//PrintP(G1,P1);

	//Guide(G1,P1,D1);
	//Infomation(G1);
	
	printf("2020101124 ������ �������ѧ�뼼��\n");
	 
	return 0;
}
/*//δ���ƣ�������� 
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
	printf("����%d\n",v);
	
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
	cout <<"=  ��Ӿ��__________________________ѧ������___________          "<< endl;
	cout <<"=    \\             9                 /              13\\        "<< endl;
	cout <<"=     \\                             /                  \\       "<< endl;
	cout <<"=     3\\                           /  1        ________����  "<< endl;
	cout <<"=       \\                         /           /                "<< endl;
	cout <<"=        \\                       /           /13               "<< endl;
	cout <<"=         ͼ���_____________��ѧ¥_________/                  "<< endl;
	cout <<"=          \\         2         /                             "<< endl;
	cout <<"=           \\                 /                               "<< endl;
	cout <<"=          4 \\               / 4             				    "<< endl;
	cout <<"=             \\             /              					"<< endl;
	cout <<"=              \\___ʵ��¥__/                         	 	    "<< endl;
	cout <<"=                                       					    "<< endl;
	cout <<"================================================================="<< endl;
	return OK;
}

Status CreateUDN(MGraph &G)//���� ��������Ȩ
{//������׾�
 //�涨v1ͼ��ݣ�v2��ѧ¥��v3ѧ�����ã�v4ʵ��¥��v5��Ӿ�أ�v6����
 //  
	//G.kind = 4;//������
	G.vexnum = 6;//�������ص� 
	G.arcnum = 8; 
	
	strcpy(G.vex[1],"ͼ���");
	strcpy(G.vex[2],"��ѧ¥");
	strcpy(G.vex[3],"ѧ������");
	strcpy(G.vex[4],"ʵ��¥");
	strcpy(G.vex[5],"��Ӿ��");
	strcpy(G.vex[6],"����");
	strcpy(G.vexInfor[1],"ͼ���:��۴������գ��������¥�ߣ�ÿ��¥���кܶ���Ϊ��ʦ���Ķ�ѧϰ");
	strcpy(G.vexInfor[2],"��ѧ¥��������ͼ��ݣ���ѧ������Ҳ�ܽ�������ѧ���¿κ󵽷��þͲ�");
	strcpy(G.vexInfor[3],"ѧ�����ã��۸�ʵ�ݣ����෱�ࡣ������¥�ߣ�ÿһ�������ɫ");
	strcpy(G.vexInfor[4],"ʵ��¥���ڽ�ѧ¥��ͼ��ݵĺӶ԰�����ѧУ���Ž�������ӳ�������ı���ʵ��¥");
	strcpy(G.vexInfor[5],"��Ӿ�أ��ھ��˶�����������С���У�������50�׵ĳ��ȣ���������󲿷�ѧ��������");
	strcpy(G.vexInfor[6],"���򳡣����򽨵���Բ���ܺ�����λλ����ԱȽ�Զ�������ʻ�綯��ǰ��");

	int i,j;
	for(i = 0;i <G.vexnum;i++)
		{
			for(j = 0;j <G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
			G.arcs[i][i].adj= 0;//�Խ��߸�ֵ����
		}
		
	G.arcs[0][1].adj = G.arcs[1][0].adj = 2;
	G.arcs[0][3].adj = G.arcs[3][0].adj = 4;
	G.arcs[0][4].adj = G.arcs[4][0].adj = 3;
	G.arcs[1][2].adj = G.arcs[2][1].adj = 1;
	G.arcs[1][3].adj = G.arcs[3][1].adj = 4;
	G.arcs[1][5].adj = G.arcs[5][1].adj = 13;
	G.arcs[2][4].adj = G.arcs[4][2].adj = 7;
	G.arcs[2][5].adj = G.arcs[5][2].adj = 13;

	Print(G);//������֮�����ȫͼ��ӡ 
	return OK;
}


void ShortestPath_FLOYD(MGraph G , PathMatrix &P,DistancMatrix &D)
{
	int u,v,w;//�����Ӧ��v��㣬w�յ㣬u�м�ڵ㣨�����꣩
	//��ʼ�� 
	for(v = 0;v < G.vexnum;v ++)//��Ӧ�����λ�ÿ�ʼʹ�� 
	{
		for(w = 0;w < G.vexnum;w++)
		{
			D[v][w] = G.arcs[v][w].adj;
			P[v][w] = -1;
			if(D[v][w]<INFINITY) P[v][w] = v;//��ʼ���ܹ�����ľ���		
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
	printf("           ====��ӭʹ��У�ڵ���ϵ====             \n");
	printf("               (������������λ��)                 \n");
	printf("1.ͼ��� 2��ѧ¥ 3ѧ������ 4ʵ��¥ 5��Ӿ�� 6����\n");
	printf("                                                  \n");
	printf("==================================================\n");
	printf("����������λ���ǣ�");
	fflush(stdin);
	scanf("%d",&v1);
	
 	printf("\n");
 	printf("��������Ҫȥ��");
 	fflush(stdin);
	scanf("%d",&v2); 
	
	printf("%sȥ��%v2�����·�����£�\n",G.vex[v1],G.vex[v2]);
	
	v1--;
	v2--;//��һ���в��� 
	
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
	printf("���·����·���þ���洢�����·������洢Ч����ͼ��ʾ\n");
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
	printf("���·���Ĵ�С�þ���洢�����·������洢Ч����ͼ��ʾ\n");
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

Status Infomation(MGraph G)//ʵ�ֹ���2 
{
	printf("\n\n");
	printf("==================================================\n");
	printf("=====����Ҫ�˽�����ѧУ������Ϣ�������������=====\n");
	printf("1.ͼ��� 2��ѧ¥ 3ѧ������ 4ʵ��¥ 5��Ӿ�� 6����\n");
	printf("===================����0����======================\n");
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
		printf("=====����Ҫ�˽�����ѧУ������Ϣ�������������=====\n");
		printf("1.ͼ��� 2��ѧ¥ 3ѧ������ 4ʵ��¥ 5��Ӿ�� 6����\n");
		printf("===================����0����======================\n");
		printf("\n\n");
		fflush(stdin);
		scanf("%d",&choose);
	}
}







