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
typedef int Status;
typedef struct Node
{
	char name[10];
	char number[20];
	int type;//2.表示食品 1.表示日用品 
	int left;
	int price;
	
}Node; 

typedef struct List
{
	Node* n;
	int total;
}List;

Status InitList(List &l);
Status PrintRY(List &l); 
Status PrintMAXMIN(List &l);
Status Jisuan(List &l);
Status Input(List &l);
Status Adj(List &l); 
Status Delect(List &l);

int main(void)
{

	List l;
	InitList(l);
	//InputList(l);
	PrintRY(l);
	PrintMAXMIN(l);
	Jisuan(l);
	Input(l);
	Adj(l);
	Delect(l);
	PrintRY(l);
	PrintMAXMIN(l);
	
	printf("计算机科学与技术 2020101124 张瑞鹏\n"); 
	return 0;
}
Status Adj(List &l)
{
	int i =1;
	char c1[10];
	printf("请输入修改的名称：");
	fflush(stdin);
	scanf("%s",&c1); 
	while(strcmp(l.n[i].name,c1)!=0&&i<=l.total)
	{
		i++;
	}
	if(i<=l.total)
	{
		printf("请输入你需要修改商品的价格：");
		fflush(stdin);scanf("%d",&l.n[i].price) ;printf("\n");
	
		printf("请输入你需要修改商品的库存量：");
		fflush(stdin);scanf("%d",&l.n[i].left) ;printf("\n");
	}
	else{
		printf("输入错误！");
	}
	printf("修改成功！"); 
	return OK;
}
Status Delect(List &l)
{
	int i =1;
	char c1[10];
	printf("请输入删除的名称：");
	fflush(stdin);
	scanf("%s",&c1); 
	while(strcmp(l.n[i].name,c1)!=0&&i<=l.total)
	{
		i++;
	}
	for(i = i+1;i<=l.total;i++)
	{
		l.n[i-1] = l.n[i];
	 } 
	
	printf("删除成功！");
	 
	
	return OK;
}
Status Input(List &l)
{
	int total = l.total;
	if(l.total>=MAXNUM)
	{
		Node* newbase;
		newbase = (Node*)realloc(l.n,(MAXNUM+MAXNUM)*sizeof(Node));
		l.n = newbase;
	}
	
	total++;
	l.total++;
	
	printf("请输入你需要插入商品的编号：");
	fflush(stdin);scanf("%s",&l.n[total].number) ;printf("\n");
	
	printf("请输入你需要插入商品的类型：");
	fflush(stdin);scanf("%d",&l.n[total].type) ;printf("\n");
	
	printf("请输入你需要插入商品的名称：");
	fflush(stdin);scanf("%s",&l.n[total].name) ;printf("\n");
	
	printf("请输入你需要插入商品的价格：");
	fflush(stdin);scanf("%d",&l.n[total].price) ;printf("\n");
	
	printf("请输入你需要插入商品的库存量：");
	fflush(stdin);scanf("%d",&l.n[total].left) ;printf("\n");
	
	
	printf("插入成功！");
	 
	return OK;
}
Status Jisuan(List &l)
{
	//分类
	int kucun1=0;
	int kucun2=0;
	int avg1=0;
	int avg2=0;
	int shang1=0;
	int shang2=0;
	for(int i=1;i<=l.total;i++)
	{
		if(l.n[i].type==1)
		{
			shang1++;
			kucun1 = kucun1 + l.n[i].left;
			avg1 = avg1 + l.n[i].price;
			
		 } 
		else if(l.n[i].type == 2)
		{
			shang2++;
			kucun2 = kucun2 + l.n[i].left;
			avg2 = avg2 + l.n[i].price;
		}
	}
	avg1 = avg1/shang1;
	avg2 = avg2/shang2;
	
	printf("日用品商品总数是：%d\n",shang1);
	printf("日用品平均价格是：%d\n",avg1);
	printf("日用品库存总数是：%d\n",kucun1);
	
	printf("食品商品总数是：%d\n",shang2);
	printf("食品平均价格是：%d\n",avg2);
	printf("食品库存总数是：%d\n",kucun2);
	
}
Status PrintMAXMIN(List &l)
{
	int cmp = 0;
	int max;
	for(int i = 1;i<=l.total;i++)
	{
		if(l.n[i].left>cmp)
		{
			cmp = l.n[i].left;
			max = i;
		}
	}
	
	printf("打印最大库存量信息\n");
	
	printf("商品编号是：%-10s 商品名称是：%-5s 库存数量是%-5d 单价是：%-5d\n",l.n[max].number,l.n[max].name,l.n[max].left,l.n[max].price);
	
	cmp = 1000;
	int min;
	for(int i = 1;i<=l.total;i++)
	{
		if(l.n[i].left<cmp)
		{
			cmp = l.n[i].left;
			min = i;
		}
	}
	printf("打印最少库存量信息\n");
	
	printf("商品编号是：%-10s 商品名称是：%-5s 库存数量是%-5d 单价是：%-5d\n",l.n[min].number,l.n[min].name,l.n[min].left,l.n[min].price);
	
}
Status PrintRY(List &l)
{
	int i = 1;
	printf("打印日用品信息\n"); 
	for(i = 1;i<=l.total;i++)
	{
		if(l.n[i].price!=0&&l.n[i].type==1)
		{
			printf("商品编号是：%-10s 商品名称是：%-5s 库存数量是%-5d 单价是：%-5d\n",l.n[i].number,l.n[i].name,l.n[i].left,l.n[i].price);
		}
	}
	
	return OK;
}
/*Status InputList(List &l)
{
	if(l.total>=MAXNUM)
	{
		
	}
	
	int i;
	while(l.n[i].price!=0)
	{
		i++;
	}
	
	printf("前请输入插入商品的编号"); 
	
	printf("前请输入插入商品的编号"); 
	printf("前请输入插入商品的编号"); 
	printf("前请输入插入商品的编号"); 
	
	return OK;
}*/
Status InitList(List &l)
{
	l.n = (Node*)malloc(MAXNUM*sizeof(Node));
	if(!l.n)exit(OVERFLOW);
	
	for(int i = 1;i<=20;i++)
	{
		l.n[i].price = 0; 
	}
	l.total = 6;
	
	
	l.n[1].left = 76;
	strcpy(l.n[1].name,"抽纸");
	strcpy(l.n[1].number,"920408001");
	l.n[1].price = 23;
	l.n[1].type = 1;
	 
	l.n[2].left = 85;
	strcpy(l.n[2].name,"牛奶");
	strcpy(l.n[2].number,"920408002");
	l.n[2].price = 28;
	l.n[2].type = 2;
	
	l.n[3].left = 34;
	strcpy(l.n[3].name,"薯片");
	strcpy(l.n[3].number,"920408003");
	l.n[3].price = 23;
	l.n[3].type = 2;
	
	l.n[4].left = 52;
	strcpy(l.n[4].name,"洗脸巾");
	strcpy(l.n[4].number,"920408004");
	l.n[4].price = 9;
	l.n[4].type = 1;
	
	l.n[5].left = 21;
	strcpy(l.n[5].name,"牙膏");
	strcpy(l.n[5].number,"920408005");
	l.n[5].price = 14;
	l.n[5].type = 1;
	
	l.n[6].left = 91;
	strcpy(l.n[6].name,"可乐");
	strcpy(l.n[6].number,"920408006");
	l.n[6].price = 5;
	l.n[6].type = 2;
	
	return OK;
}




















