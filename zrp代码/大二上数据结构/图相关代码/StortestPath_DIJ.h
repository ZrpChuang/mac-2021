# include "MGraphCreate.h"

typedef int ShortPathTable[MAX_VERTEX_NUM];//�������� 
typedef int VRType;//�������·������ķ�㷨 ȡ����ķ��� 


void ShortestPath_DIJ(MGraph G,int v0,PathMatrix &P,ShortPathTable &D);//���·�� 
Status PrintPathMatrix(MGraph G1,PathMatrix p1);
Status PrintPathLong(MGraph G1,ShortPathTable d1,char name[]);

Status PrintPathLong(MGraph G1,ShortPathTable d1,char name[])
{
	int m;
	
	printf("%s������ĵ�ľ������£�\n",name);
	for(m = 0; m < G1.vexnum ; m++)
	{
		printf("��%s���:",G1.vex[m+1]);//�����ֵĽڵ��һ��ʼ 
		printf("%d\n",d1[m]);
	}
	
	return OK;
}

Status PrintPathMatrix(MGraph G1,PathMatrix p1)
{
	printf("\n");
	printf("���·������,\n");
	int m,i;
	
	for(m = 0;m<G1.vexnum;m++)//��ʱ�����Ż�һ�� 
	{
		printf("\n\n");
		for(i = 0;i<G1.vexnum;i++)
		{
			printf("%d ",p1[m][i]);//���·������ 
		}
	}
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
	
	for(v = 0;v < G.vexnum;v++)
	{
		D[v] = G.arcs[v0][v].adj;//�����İ�Ҫ�����һ�и��ƹ�ȥ
		Final[v] = FALSE;
		for(m = 0;m < G.vexnum;m++)
		{
			P[v][m] = FALSE;//��ʼ��P���� 
		}
		if(D[v]<INFINITY)
		{
			P[v][v] = TURE;
			P[v][v0] = TURE;
		}
	} 
	
	Final[0] = TURE;//Ĭ�ϵ�һ��ֵ��ture 
	
	//Ѱ��
	for(i = 1; i<G.vexnum ; i++)//һ����һ���㣬û˵��˭����֪����˭���պ����� 
	{
		min = INFINITY;
		for(m = 0;m<G.vexnum;m++)
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
		for(m = 0 ;m < G.vexnum;m++)
		{
			if(Final[m] == FALSE && min<INFINITY &&G.arcs[v][m].adj<INFINITY&&(min+G.arcs[v][m].adj<D[m]))
			//����������Ӧ�û��� 
			{//ʲôҪ��1.DҪ�� 3.����Ԫ��Ҫ��
				D[m] = min + G.arcs[v][m].adj;
				for(j = 0;j<G.vexnum;j++)
				{
					//��¼һ������ ���ﲻ�ø��� ֻ�������հ�v��·����ok 
					P[m][j] = P[v][j];//��Ǩ��ȥv�ıؾ�֮·����m��֮ǰ��Ҫˢ��
					P[m][m] = TURE;
				}//�ҵ��ڵ��ĸ��� 
			}//�Ƿ���Ҫ�޸Ľڵ� 
		}//for(m = 0;w < G.vexnum;m++)���Ѱ�� 
	}//һ����һ���㣬û˵��˭����֪����˭���պ�����

}





