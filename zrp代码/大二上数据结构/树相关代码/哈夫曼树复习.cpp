# include<stdio.h>
#include <iostream>
# include<stdlib.h>
# include<string.h>

# define TURE 1
# define FALSE 0

# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2 
# define MAX 100 

typedef struct HuffumanNode
{
	int weight;
	int parents;
	int lchild;
	int rchild;
	char name;
	
}*HuffmanTree;

typedef char** Huffmancoding;

void Huffumancoding(HuffmanTree &T,Huffmancoding &C,int n,int w[],char name[])
{
	void select(HuffmanTree T,int i,int &s1,int &s2);
	int m = 2*n-1;
	T = (HuffumanNode*)malloc((m+1)*sizeof(HuffumanNode));
	if(!T)exit(OVERFLOW);
	
	int i;
	
	for(i = 1;i<=n;i++)
	{//给表初始化
		T[i].lchild = 0;
		T[i].parents = 0;
		T[i].weight = w[i];
		T[i].rchild = 0;
		T[i].name = name[i];
	}//叶子节点的初始化 
	
	for(i = n+1;i<=m;i++)
	{
		T[i].lchild = 0;
		T[i].parents = 0;
		T[i].weight = 0;
		T[i].rchild = 0;
	}//非叶子节点的初始化
	
	HuffmanTree q;//定义一个移动的指针 
	
	int s1,s2;
	for(i = n+1 ;i <= m; i++)
	{
		select(T,i-1,s1,s2);
		printf("s1 s2%d,%d\n",s1,s2);
		T[i].weight = T[s1].weight + T[s2].weight;
		T[i].lchild = s1;
		T[i].rchild = s2;
		T[s1].parents = i;
		T[s2].parents = i;
	} 
	/*for(i = n+1;i <= m ;i++)
	{
		Select(HT,i-1,s1,s2);//返回权的下标
		
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[s1].parent = i;
		HT[s2].parent = i;
		
	} //到这里为止，哈夫曼树已经存好了 */
	C = (Huffmancoding)malloc(n*sizeof(char*));
	if(!C)exit(OVERFLOW);
	

	char* cd;
	cd = (char*)malloc(n*sizeof(char));//动态分配 
	if(!cd)exit(OVERFLOW);
	
	
	
	int pt;//表示父母
	int cld;//表示儿女 
	int start;
	for(i = 1;i<=n;i++)
	{
		cd[n-1] = '\0';
		start = n-1;
		
		for(pt = T[i].parents,cld = i; pt!=0 ;cld = pt,pt = T[pt].parents) 
		{
			if(cld == T[pt].lchild)
			{
				start--;
				cd[start] = '0';
			}
			else if(cld = T[pt].rchild)
			{
				start--;
				cd[start] = '1';
			}
			
		}
		C[i] = (char*)malloc((n-start)*sizeof(char));
		strcpy(C[i],&cd[start]);
	}
	//free(cd);
	
	printf("7\n");
}
void select(HuffmanTree T,int i,int &s1,int &s2)
{
	int j;
	int max = 10000;
	
	for(j = 1;j<=i;j++)
	{
		if(T[j].weight<max&&T[j].parents==0)
		{
			max = T[j].weight;
			s1= j;
		}
	}//s1是最小的 
	max = 10000;
	for(j = 1;j<=i;j++)
	{
		if(j!=s1)
		{
			if(T[j].weight<max&&T[j].parents==0)
			{
				max = T[j].weight;
				s2 = j;
			}
		}
	}
}

int main(void)
{
	HuffmanTree T;
	Huffmancoding C;
	int n;
	/*printf("请问共有多少的字符：\n");
	scanf("%d",&n);*/
	
	char name[n];
	int weight[n];
	
	
	n = 3;
	weight[1] = 3;
	weight[2] = 5;
	weight[3] = 7;
	name[1] = 'a';
	name[2] = 'b';
	name[3] = 'c';
	
	/*
	for(int i = 1;i<=n;i++)
	{
		printf("请问第%d个字符的名字叫做\n",i);
		fflush(stdin);scanf("%c",&name[i]);
		
		printf("请问第%d个字符的权值是多少？\n",i);
		fflush(stdin);scanf("%d",&weight[i]);
	}
	*/
	Huffumancoding(T,C,n,weight,name);
	printf("well done\n");
	for(int i = 1;i<=n;i++)
	{
		printf("%s\n",C[i]);
	}
	
	
	return 0;
}







