# include "MGraphCreate.h"

typedef int ShortPathTable[MAX_VERTEX_NUM];//桌面数组 
typedef int VRType;//用于最短路径普利姆算法 取出点的方法 


void ShortestPath_DIJ(MGraph G,int v0,PathMatrix &P,ShortPathTable &D);//最短路径 
Status PrintPathMatrix(MGraph G1,PathMatrix p1);
Status PrintPathLong(MGraph G1,ShortPathTable d1,char name[]);

Status PrintPathLong(MGraph G1,ShortPathTable d1,char name[])
{
	int m;
	
	printf("%s到其余的点的距离如下：\n",name);
	for(m = 0; m < G1.vexnum ; m++)
	{
		printf("到%s结点:",G1.vex[m+1]);//存名字的节点从一开始 
		printf("%d\n",d1[m]);
	}
	
	return OK;
}

Status PrintPathMatrix(MGraph G1,PathMatrix p1)
{
	printf("\n");
	printf("输出路径矩阵,\n");
	int m,i;
	
	for(m = 0;m<G1.vexnum;m++)//到时候再优化一下 
	{
		printf("\n\n");
		for(i = 0;i<G1.vexnum;i++)
		{
			printf("%d ",p1[m][i]);//输出路径矩阵 
		}
	}
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
	
	for(v = 0;v < G.vexnum;v++)
	{
		D[v] = G.arcs[v0][v].adj;//完整的把要求的那一行复制过去
		Final[v] = FALSE;
		for(m = 0;m < G.vexnum;m++)
		{
			P[v][m] = FALSE;//初始化P矩阵 
		}
		if(D[v]<INFINITY)
		{
			P[v][v] = TURE;
			P[v][v0] = TURE;
		}
	} 
	
	Final[0] = TURE;//默认第一个值是ture 
	
	//寻找
	for(i = 1; i<G.vexnum ; i++)//一次找一个点，没说找谁，不知道找谁，刚好找完 
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
		
		//v = m;记录自己犯的错误把这个东西放在循环外面，很不合理应该在里面
		 
		Final[v] = TURE;//已经被解决
		//去检查min+min到达会不会比其他小，如果小的话，替换
		for(m = 0 ;m < G.vexnum;m++)
		{
			if(Final[m] == FALSE && min<INFINITY &&G.arcs[v][m].adj<INFINITY&&(min+G.arcs[v][m].adj<D[m]))
			//条件成立就应该换了 
			{//什么要换1.D要换 3.矩阵元素要换
				D[m] = min + G.arcs[v][m].adj;
				for(j = 0;j<G.vexnum;j++)
				{
					//记录一个问题 这里不用更新 只用完整照搬v的路径即ok 
					P[m][j] = P[v][j];//搬迁过去v的必经之路成了m的之前的要刷新
					P[m][m] = TURE;
				}//找到节点后的更改 
			}//是否需要修改节点 
		}//for(m = 0;w < G.vexnum;m++)逐个寻找 
	}//一次找一个点，没说找谁，不知道找谁，刚好找完

}





