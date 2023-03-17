#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>//�ַ���ͷ�ļ� 

# define TURE 1
# define FALSE 0

# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2 
# define STACKSIZE 3
# define MAX 100
/*
	
	1.��һ�����ȸ㶨��ô���ݸ���n����Ӧ��Ȩֵ������һ����������
	
	C��������Ҫͨ����׼I/O���������ı��ļ����д���
	��صĲ��������򿪡���д���ر������û�������
	��صĴ�ȡ�����У�fopen(), fclose(), fgetc(), fputc(), fgets(), fputs(), fprintf(), fscanf() 
	
	fopen()�����򿪵��ļ����Ƚ��ļ����Ƶ�������
	
	ֻ�е�ʹ��fclose()�����ر��ļ�ʱ���������е����ݲŻ�д�����
	
	��c������ͨ����һ���ַ�����������ַ�������\0�� 
	���ַ����Ľ�����־���κ��ַ���֮�󶼻��Զ����ϡ�\0��
	������ַ���ĩβ���ˡ�\0��ת���ַ����������ʱ���ܻ�����������⡣

	
*/
typedef int Status;

typedef struct
{
	int weight;
	int parent,lchild,rchild;
	char c;
	
}HTNode,*HuffmanTree;//HTNode�����������ڵ㣩��Huffmantree���ܹ�ָ��HTNode��ָ�룩��̬����

typedef char** HuffmanCode;//���ڴ洢���������ı���
 
//����ǰ������ 
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n,char c1[]);
Status Select(HuffmanTree t,int n,int &s1,int &s2); 
int min(HuffmanTree t,int n); 
//�ļ�����ļ� 
Status InputHfmTree(HuffmanTree HT,int m);//�ѹ��������ŵ�һ���ļ���ȥ
Status InputCodeFlie(int n,char* c1,char** h2);//�ѱ����ŵ��ļ���ȥ 

Status Interpre(HuffmanCode HB,char* c1,int n);
//

int main(void)
{
	HuffmanTree h1;//���������Ľڵ�,�������� 
	HuffmanCode h2;//����� �ڵ� һ���ַ��Ͷ���ָ�� 
	int i,n;//���� 
	int* w;//Ȩ��ָ�� 
	
		
	printf("�������ַ�����С\n");
	scanf("%d",&n);//�ַ�����С��n 
	char c1[n];//�����ַ����ַ����� 
	
	w = (int*)malloc(n*sizeof(int));
	if (!w) exit(OVERFLOW); 
	
	printf("�����������ַ�\n");
	for(i = 1;i <= n;i++)
	{
		printf("��%d���ַ��ǣ�",i);
		fflush(stdin);
		scanf("%c",&c1[i]);
	}
	
	printf("�����������ַ���Ȩֵ\n");
	for(i = 0;i < n;i++)
		{
			printf("��%d���ַ���Ȩֵ�ǣ�",i+1);
			scanf("%d",w+i);
		}
		
	HuffmanCoding(h1,h2,w,n,c1); //w��ָ�� 
	
	for(i = 1;i<=n;i++)
	{
		printf("�ַ�%c�ı����ǣ�",c1[i]);
		printf("%s\n",h2[i]);
	}//������� 
	
	InputCodeFlie(n,c1,h2);
	InputHfmTree(h1,2*n-1);
	
	int choose = 1;
	while(choose != 0)
	{
		Interpre(h2,c1,n);//�����������
		printf("\n");
		printf("���ʻ���Ҫ������1.����ʹ�����빦�� 0.�˳�����");
		scanf("%d",&choose);
	}
	
	 
	printf("2020101124 �������ѧ�뼼�� ������");
	 
	return OK;
}

/*
Status Interpre(HuffmanCode HB,char c1[],int n)//HuffmanCode HB�Ǳ����,char* c1 ���ַ����ֱ� 
{
	
	int i;
	int chose;
	char c2[10];
	char c3[10];
	
	printf("�Ƿ���Ҫʵ�����빦�ܣ�\n");
	printf("��ѡ��1.�ǵ�  0.����Ҫ \n");
	scanf("%d",&chose);
	
	while(chose==1)
	{
		printf("����������Ҫ����ı��룺");
		fflush(stdin);
		scanf("%s",c2);
		
		for(i = 1; i <= n;i++)//�ӵ�һ����ʼ�Ƚ�ֱ�����һ�� 
		{
			
			if(strcmp(HB[i],c2)==0)
			{	
				printf("������Ϊ:%c\n",c1[i]);
			}
		}
		
		printf("��ѡ��1.����  0.���˽��� \n");
		fflush(stdin);
		scanf("%d",&chose);
	}
	
	printf("����������Ҫ����ı��룺");
	scanf("%s",c2);
	
	for(i = 1; i <= n;i++)//�ӵ�һ����ʼ�Ƚ�ֱ�����һ�� 
	{
		
		if(strcmp(HB[i],c2)==0)
		{	
			printf("������Ϊ:%c\n",c1[i]);
		}
	}
	
	return OK; 
} 
*/

Status Interpre(HuffmanCode HB,char c1[],int n)//HuffmanCode HB�Ǳ����,char* c1 ���ַ����ֱ� 
{
	char* q;
	char* p;
	FILE* fp3;
	
	q = (char*)malloc(2*(sizeof(char)));
	if(!q)exit(OVERFLOW);
	p = (char*)malloc(2*(sizeof(char)));
	if(!p)exit(OVERFLOW);
	
	q[1] = '\0';
	p[1] = '\0';//���乤��  
	
	char c2[20];//c2���û������δ����ı��� 
	
	//��Ҫ������ַ����ĳ���
	//printf("��������Ҫ������ַ����ĳ��ȣ�");
	//scanf("%d",&x);
	printf("\n");
	printf("��������Ҫ������ַ�����");
	scanf("%s",&c2);
	
	int x = strlen(c2);
	printf("������ַ�������Ϊ %d\n",x);
	
	
	char c3[x];//�����ռ� �ȽϿռ� 
	char result[x];//װ�����ս�������� 
	strcpy(result," ");//
	
	q[0] = c2[0];
	strcpy(c3,q);
	int j;
	int see;
	for(int i = 1;i <= x;i++)//ÿһ���û������Ԫ�� 
	{
		see = 0;
		for(j = 1;j <= n;j++)//ÿһ�����ǰ׺�� 
		{
			if(strcmp(HB[j],c3)==0)//����Ƚϳɹ� 
			{	
				p[0] = c1[j];//�����Ϊ�˰ѷ���������ַ�׷�ӵ������ 
				strcat(result,p);//׷�� 
				q[0] = c2[i];//������һ�������ǣ��Ƚϳɹ��������Ϊ������i�Ĺ��ͣ���i֮ǰ���Ѿ��н���� 
				strcpy(c3,q);//����ܹ�����ɹ���ֱ�Ӹ��� 
				see = 1;
			}
		}
		if(see == 0)
		{
			q[0] = c2[i];//
			strcat(c3,q);//������벻�ɹ���׷�� 
		}
	}
	//��δ����Լ�д�ģ����ú����뷨���Լ�Ҳ����ͦ���˵� 
	//ʹ���˲����ռ� ʹ�������ֱȽϺ���  
	//ȱ�㣺���������ʱ������ע���������֮��ص�Ӣ�ﵥ��
	//�Լ�д�Ĵ��뿴����Ҳ���������Ǹ��ܲ��õ�ȱ��
	//�������Ĵ���Ͳ��ǺõĴ��룬�������� 
	
	printf("���ս����:%s",result);
	
	fp3 = fopen("Textfile.txt","a");//д�� 
	if(!fp3)printf("fail to open");
	else
	{
		fprintf(fp3,"\n");
		fprintf(fp3,"����Ĳ���������%s\n",c2);
		fprintf(fp3,"���ս����:%s",result);
	}
	fclose(fp3);
	 
	
	return OK; 
} 

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n,char c1[])
{
	int m,i;//m���ܽ����
	 
	int s1,s2;//��������Сֵ Ȼ�󷵻� 
	
	if(n <= 1)return;
	
	m = 2*n - 1;
	
	HT = (HuffmanTree )malloc((m+1)*sizeof(HTNode));//���Ͻڵ�0��δʹ�� 
	if(!HT)exit(OVERFLOW);
	
	HuffmanTree q;//����һ���ƶ���ָ�� 
	
	//��ʼ����� 
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
	
	//��ʼ�Ա������޸�
	
	for(i = n+1;i <= m ;i++)
	{
		Select(HT,i-1,s1,s2);//����Ȩ���±�
		
		HT[i].weight = HT[s1].weight + HT[s2].weight;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[s1].parent = i;
		HT[s2].parent = i;
		
	} //������Ϊֹ�����������Ѿ������ 
	
	
	for(i = 1,q = HT+1;i <= m;q++,i++)
	{
		printf("%-20d%-20d%-20d%-20d\n\n",q->weight,q->parent,q->lchild,q->rchild);
	}
	
	//�����Ǹ��ݹ���������������
	 
	HC = (char**)malloc((n+1)*sizeof(char*));//������ָ�븽�ϵ�ַ
	
	int p1;
	int child1;
	int start;//��¼Ϊ��ʼ 
	
	char* cd;
	cd = (char*)malloc(n*sizeof(char));//��̬���� 
	if(!cd)exit(OVERFLOW);
	cd[n-1] = '\0';
	
	char* hb;
	for(i = 1;i <= n;i++)//һ��һ���ڵ��� 
	{
		//�˴�i��ʾ��ǰԪ�� 
		start = n-1;
		for(p1 =HT[i].parent ,child1 = i; p1 != 0;child1 = p1,p1 = HT[p1].parent)
		{
			
			if(HT[p1].lchild == child1)//˵���ø�ֵ0
			{
				start--;
				cd[start] = '0';
			}
			else//˵���ø�ֵ1
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
	s1 = min(t,n);//��С 
	s2 = min(t,n);//�ڶ�С 
	
	return OK;
}

int min(HuffmanTree t,int n)
{
	int flag,j,k;//���ڷ��� ���ڼ��� 
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
	t[flag].parent = 100;//��һ�������ܵ����� ���ڳ������� �Ȼ��ٸ���
	return flag;
}

Status InputHfmTree(HuffmanTree HT,int m)
{
	FILE* fp1;
	HuffmanTree q;
	int i;
	
	
	fp1 = fopen("hfm Tree.txt","w");//д�� 
	fprintf(fp1,"%-20s%-20s%-20s%-20s\n","Ȩֵ","˫��","������","������");
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

Status InputCodeFlie(int n,char* c1,char** h2)//���ո��� 
{
	FILE* fp2;
	int i;
	
	fp2 = fopen("Codefile.txt","w");//д�� 
	if(!fp2)printf("fail to open");
	else
	{
		fprintf(fp2,"�ַ�������\n");
		for(i = 1;i<=n;i++)
			{
				fprintf(fp2,"�ַ�%c�ı����ǣ�",c1[i]);
				fprintf(fp2,"%s\n",h2[i]);
			}//������� 
	}
	fclose(fp2);
	
	return OK;
}













	
	/*������ 
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











