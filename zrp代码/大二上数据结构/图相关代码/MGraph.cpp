# include"MiniSpanTree_PRIM.h"
# include"MGraphCreate.h"

int main(void)
{
	MGraph G1;
	Create(G1);
	
	printf("ʵ�ֹ�����С�������㷨��");
	printf("��������ʼ�ڵ�����ƣ�");
	fflush(stdin);
	scanf("%s",&name);
	miniSpanTree_PRIM(G1,name);
	
	return 0;
}
