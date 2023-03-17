# include"MiniSpanTree_PRIM.h"
# include"MGraphCreate.h"

int main(void)
{
	MGraph G1;
	Create(G1);
	
	printf("实现功能最小生成树算法！");
	printf("请输入起始节点的名称：");
	fflush(stdin);
	scanf("%s",&name);
	miniSpanTree_PRIM(G1,name);
	
	return 0;
}
