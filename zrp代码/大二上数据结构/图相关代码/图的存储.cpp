# include<stdio.h>
# include<stdlib.h>
# include<string.h>

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2
# define INFINITY INT_MAX//ϵͳ���� 
# define MAX_VERTEX_NUM 20

/*
��һ��ͼ����׾���洢��������ӡһ�¿�һ��Ч��
 
*/
typedef int Status;
typedef char VertaxType[3];//���浥���ڵ������ 
typedef int VRType;
typedef enum{DG = 1,DN,UDG,UDN} GraphKind;//�ֱ��ǣ�����ͼ������ͼ�������Ȩͼ�������Ȩͼ��
//��һ��ֵĬ������
 
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

//����ǰ������
Status CreateUDN(MGraph &G);
Status CreateDG(MGraph &G);
Status CreateDN(MGraph &G);
Status CreateUDG(MGraph &G);
Status Create(MGraph &G);
Status Print(MGraph G);
int Find(MGraph G,char v[]);
//����ǰ������ 

int main(void)
{
	MGraph G1;
	int choice;
	
	printf("1.���Կ�ʼ 0.ȡ������");
	scanf("%d",&choice);
	while(choice!=0)
	{
		Create(G1);
		printf("1.���Լ��� 0.ֹͣ����"); 
		fflush(stdin);
		scanf("%d",&choice);
	}
	
	return 0;
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
	
	for(i = 0;i <G.vexnum;i++)
		{
			for(j = 0;j <G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
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
	
	for(i = 0;i <G.vexnum;i++)
		{
			for(j = 0;j <G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
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
	
	for(i = 0;i <G.vexnum;i++)
		{
			for(j = 0;j <G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
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
	
	for(i = 0;i <G.vexnum;i++)
		{
			for(j = 0;j <G.vexnum; j++)
				{
					G.arcs[i][j].adj= INFINITY;
				} 
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
	
	return i-1;
}

Status Print(MGraph G)//ȫͼ���д�ӡ 
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

//����ѡַ���⣬��������֮������·��


//�Ͻ���˹�㷨 







