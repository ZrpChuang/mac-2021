#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>//字符串头文件 

# define TURE 1
# define FALSE 0

# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2 
# define STACKSIZE 3
# define MAX 100
/*
	
	1.第一步，先搞定怎么根据给的n，相应的权值来构造一个哈夫曼树
	
	C语言中主要通过标准I/O函数来对文本文件进行处理。
	相关的操作包括打开、读写、关闭与设置缓冲区。
	相关的存取函数有：fopen(), fclose(), fgetc(), fputc(), fgets(), fputs(), fprintf(), fscanf() 
	
	fopen()函数打开的文件会先将文件复制到缓冲区
	
	只有当使用fclose()函数关闭文件时，缓冲区中的数据才会写入磁盘
	
	在c语言中通常用一个字符数组来存放字符串，’\0’ 
	是字符串的结束标志，任何字符串之后都会自动加上’\0’
	。如果字符串末尾少了‘\0’转义字符，则在输出时可能会出现乱码问题。

	
*/
typedef int Status;

typedef struct
{
	int weight;
	int parent,lchild,rchild;
	char c;
	
}HTNode,*HuffmanTree;//HTNode（哈夫曼树节点），Huffmantree（能够指向HTNode的指针）动态数组

typedef char** HuffmanCode;//用于存储哈夫曼树的编码
 
//函数前置声明 
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n,char c1[]);
Status Select(HuffmanTree t,int n,int &s1,int &s2); 
int min(HuffmanTree t,int n); 
//文件相关文件 
Status InputHfmTree(HuffmanTree HT,int m);//把哈夫曼树放到一个文件中去
Status InputCodeFlie(int n,char* c1,char** h2);//把编码表放到文件中去 

Status Interpre(HuffmanCode HB,char* c1,int n);
//

int main(void)
{
	HuffmanTree h1;//哈夫曼树的节点,哈夫曼树 
	HuffmanCode h2;//编码表 节点 一个字符型二重指针 
	int i,n;//个数 
	int* w;//权重指针 
	
		
	printf("请输入字符集大小\n");
	scanf("%d",&n);//字符集大小是n 
	char c1[n];//存了字符集字符名字 
	
	w = (int*)malloc(n*sizeof(int));
	if (!w) exit(OVERFLOW); 
	
	printf("请依次输入字符\n");
	for(i = 1;i <= n;i++)
	{
		printf("第%d个字符是：",i);
		fflush(stdin);
		scanf("%c",&c1[i]);
	}
	
	printf("请依次输入字符的权值\n");
	for(i = 0;i < n;i++)
		{
			printf("第%d个字符的权值是：",i+1);
			scanf("%d",w+i);
		}
		
	HuffmanCoding(h1,h2,w,n,c1); //w是指针 
	
	for(i = 1;i<=n;i++)
	{
		printf("字符%c的编码是：",c1[i]);
		printf("%s\n",h2[i]);
	}//输出编码 
	
	InputCodeFlie(n,c1,h2);
	InputHfmTree(h1,2*n-1);
	
	int choose = 1;
	while(choose != 0)
	{
		Interpre(h2,c1,n);//翻译二叉树的
		printf("\n");
		printf("请问还需要译码吗？1.继续使用译码功能 0.退出译码");
		scanf("%d",&choose);
	}
	
	 
	printf("2020101124 计算机科学与技术 张瑞鹏");
	 
	return OK;
}

/*
Status Interpre(HuffmanCode HB,char c1[],int n)//HuffmanCode HB是编码表,char* c1 是字符名字表 
{
	
	int i;
	int chose;
	char c2[10];
	char c3[10];
	
	printf("是否需要实现译码功能？\n");
	printf("请选择：1.是的  0.不需要 \n");
	scanf("%d",&chose);
	
	while(chose==1)
	{
		printf("请输入你需要编译的编码：");
		fflush(stdin);
		scanf("%s",c2);
		
		for(i = 1; i <= n;i++)//从第一个开始比较直到最后一个 
		{
			
			if(strcmp(HB[i],c2)==0)
			{	
				printf("译码结果为:%c\n",c1[i]);
			}
		}
		
		printf("请选择：1.继续  0.到此结束 \n");
		fflush(stdin);
		scanf("%d",&chose);
	}
	
	printf("请输入你需要编译的编码：");
	scanf("%s",c2);
	
	for(i = 1; i <= n;i++)//从第一个开始比较直到最后一个 
	{
		
		if(strcmp(HB[i],c2)==0)
		{	
			printf("译码结果为:%c\n",c1[i]);
		}
	}
	
	return OK; 
} 
*/

Status Interpre(HuffmanCode HB,char c1[],int n)//HuffmanCode HB是编码表,char* c1 是字符名字表 
{
	char* q;
	char* p;
	FILE* fp3;
	
	q = (char*)malloc(2*(sizeof(char)));
	if(!q)exit(OVERFLOW);
	p = (char*)malloc(2*(sizeof(char)));
	if(!p)exit(OVERFLOW);
	
	q[1] = '\0';
	p[1] = '\0';//运输工具  
	
	char c2[20];//c2是用户输入的未编译的编码 
	
	//需要译码的字符串的长度
	//printf("请输入需要译码的字符串的长度：");
	//scanf("%d",&x);
	printf("\n");
	printf("请输入需要译码的字符串：");
	scanf("%s",&c2);
	
	int x = strlen(c2);
	printf("计算出字符串长度为 %d\n",x);
	
	
	char c3[x];//操作空间 比较空间 
	char result[x];//装载最终结果的数组 
	strcpy(result," ");//
	
	q[0] = c2[0];
	strcpy(c3,q);
	int j;
	int see;
	for(int i = 1;i <= x;i++)//每一个用户输入的元素 
	{
		see = 0;
		for(j = 1;j <= n;j++)//每一个最佳前缀码 
		{
			if(strcmp(HB[j],c3)==0)//如果比较成功 
			{	
				p[0] = c1[j];//这个是为了把翻译出来的字符追加到结果里 
				strcat(result,p);//追加 
				q[0] = c2[i];//这里有一个问题是，比较成功可以理解为：不是i的功劳，再i之前就已经有结果了 
				strcpy(c3,q);//如果能够译码成功，直接覆盖 
				see = 1;
			}
		}
		if(see == 0)
		{
			q[0] = c2[i];//
			strcat(c3,q);//如果译码不成功，追加 
		}
	}
	//这段代码自己写的，觉得很有想法，自己也觉得挺高兴的 
	//使用了操作空间 使用了三种比较函数  
	//缺点：定义变量的时候尽量备注清楚或者与之相关的英语单词
	//自己写的代码看起来也费力，这是个很不好的缺点
	//看不懂的代码就不是好的代码，尽量避免 
	
	printf("最终结果是:%s",result);
	
	fp3 = fopen("Textfile.txt","a");//写入 
	if(!fp3)printf("fail to open");
	else
	{
		fprintf(fp3,"\n");
		fprintf(fp3,"译码的测试数据是%s\n",c2);
		fprintf(fp3,"最终结果是:%s",result);
	}
	fclose(fp3);
	 
	
	return OK; 
} 

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n,char c1[])
{
	int m,i;//m是总结点数
	 
	int s1,s2;//用于找最小值 然后返回 
	
	if(n <= 1)return;
	
	m = 2*n - 1;
	
	HT = (HuffmanTree )malloc((m+1)*sizeof(HTNode));//附上节点0号未使用 
	if(!HT)exit(OVERFLOW);
	
	HuffmanTree q;//定义一个移动的指针 
	
	//初始化表格 
	for(i = 1,q = HT+1;i <= n; i++,q++)
	{
		q->c = c1[i];
	}
	
	for(i = 1,q = HT+1;i <= n;w++,q++,i++)
	{
		q->weight = *w;
		q->parent = 0;
		q->lchild = 0;
		q->rchild = 0;	
	}
	
	for(;i <= m;q++,i++)
	{
		q->weight = 0;
		q->parent = 0;
		q->lchild = 0;
		q->rchild = 0;
		q->c = '0';
	}
	
	//开始对表格进行修改
	
	for(i = n+1;i <= m ;i++)
	{
		Select(HT,i-1,s1,s2);//返回权的下标
		
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[s1].parent = i;
		HT[s2].parent = i;
		
	} //到这里为止，哈夫曼树已经存好了 
	
	
	for(i = 1,q = HT+1;i <= m;q++,i++)
	{
		printf("%-20d%-20d%-20d%-20d\n\n",q->weight,q->parent,q->lchild,q->rchild);
	}
	
	//下面是根据哈夫曼树构造编码表
	 
	HC = (char**)malloc((n+1)*sizeof(char*));//给二级指针附上地址
	
	int p1;
	int child1;
	int start;//记录为开始 
	
	char* cd;
	cd = (char*)malloc(n*sizeof(char));//动态分配 
	if(!cd)exit(OVERFLOW);
	cd[n-1] = '\0';
	
	char* hb;
	for(i = 1;i <= n;i++)//一个一个节点来 
	{
		//此处i表示当前元素 
		start = n-1;
		for(p1 =HT[i].parent ,child1 = i; p1 != 0;child1 = p1,p1 = HT[p1].parent)
		{
			
			if(HT[p1].lchild == child1)//说明该赋值0
			{
				start--;
				cd[start] = '0';
			}
			else//说明该赋值1
			{
				start--;
				cd[start] = '1';
			}
		}
		HC[i] = (char*)malloc((n-start)*sizeof(char)); 
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
}

Status Select(HuffmanTree t,int n,int &s1,int &s2)
{
	s1 = min(t,n);//最小 
	s2 = min(t,n);//第二小 
	
	return OK;
}

int min(HuffmanTree t,int n)
{
	int flag,j,k;//用于返回 用于计数 
	k = MAX;
	
	for(j = 1;j <= n;j++)
	{
		if(t[j].weight < k && t[j].parent == 0)
		{
			flag = j;
			k = t[j].weight;
		}
	}
	
	//printf("flag=%d\n",flag); 
	t[flag].parent = 100;//放一个不可能的数字 便于程序运行 等会再覆盖
	return flag;
}

Status InputHfmTree(HuffmanTree HT,int m)
{
	FILE* fp1;
	HuffmanTree q;
	int i;
	
	
	fp1 = fopen("hfm Tree.txt","w");//写入 
	fprintf(fp1,"%-20s%-20s%-20s%-20s\n","权值","双亲","左子树","右子树");
	if(!fp1)printf("fail to open");
	else
	{
		for(i = 1,q = HT+1;i <= m;q++,i++)
		{
			fprintf(fp1,"%-20d%-20d%-20d%-20d\n",q->weight,q->parent,q->lchild,q->rchild);
		}
	}
	fclose(fp1);
	
	return OK;
}

Status InputCodeFlie(int n,char* c1,char** h2)//接收个数 
{
	FILE* fp2;
	int i;
	
	fp2 = fopen("Codefile.txt","w");//写入 
	if(!fp2)printf("fail to open");
	else
	{
		fprintf(fp2,"字符编码结果\n");
		for(i = 1;i<=n;i++)
			{
				fprintf(fp2,"字符%c的编码是：",c1[i]);
				fprintf(fp2,"%s\n",h2[i]);
			}//输出编码 
	}
	fclose(fp2);
	
	return OK;
}













	
	/*检验表格 
	q = HT+1;
	printf("%d,%d,%d,%d\n",q->weight,q->parent,q->rchild,q->lchild);
	q++;
	printf("%d,%d,%d,%d\n",q->weight,q->parent,q->rchild,q->lchild);
	q++;
	printf("%d,%d,%d,%d\n",q->weight,q->parent,q->rchild,q->lchild);
	q++;
	printf("%d,%d,%d,%d\n",q->weight,q->parent,q->rchild,q->lchild);
	q++;
	printf("%d,%d,%d,%d\n",q->weight,q->parent,q->rchild,q->lchild);
	q++;
	printf("%d,%d,%d,%d\n",q->weight,q->parent,q->rchild,q->lchild);
	q++;
	printf("%d,%d,%d,%d\n",q->weight,q->parent,q->rchild,q->lchild);
	*/











