# include<stdio.h>//预处理指令，头文件包含进来 标准输入输出 
# include<stdlib.h>//malloc函数要用  随机产生随机数  

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2

/*定义结构体 一共有三个 1表示整张表：包含头结点 整体的长度 表的初始化操作
 
 						2表示每一个节点，包含指针域与数据域
						3表示每一个数据域的数据的细节 
						第一个结构体一旦定义，就存在一张表，总结为结构体的
						嵌套，混乱，要记得主题是第一个结构体 
						
						表格为from
						学生为students
						学生信息为data 
*/

//实现功能： 
typedef int Status;
typedef struct Data//设定了学生的3个基本数据，包括了学生学号，学生单科成绩，学生姓名 
{
	int Number;
	float Mark1;
	float Mark2;
	float Total;
	char Name[100];//字符串数组表示姓名；
	char Sex[50]; 
}D;

typedef struct Student
{
	Data data;
	Student* next;
}S;

typedef struct Form//表格 
{
	int Formsize;
	Student* head;//头指针，指向第一个同学 
}F;


//函数前置声明
Status InputMark(F* f);
Status Create(F* f);
Status OutputAvg1(F* f);
Status OutputAvg2(F* f);
Status Insert(F* f);
Status Search(F* f,int num); 
Status Delect(F* f,int num);
Status PrintPhoto(F*f);
Status Heightest(F*f);

int main(void)
{
	F f1;//定义表格 
	int n;//初始化班上有多少同学！ 
	int i;//用于计数
	int choice = 1;//case的选择 
	int number;
	float H;//用于输出最高分 
	
	printf("-----首先我们先建立一张空表------\n\n");
	
	Create(&f1);
	
	printf("然后我们需要往表里面输入学生的基本信息，以及各科成绩\n\n\n");
	system("pause");
	printf("\n\n\n");
	printf("本次是首次对空表进行输入，请输入班上共有多少名同学（不要写太多，不然要手动输入内容过多！）\n");
	scanf("%d",&n);//初始化班机有多少名同学 
	
	for (i = 0;i < n;i++)
		{
			
			printf("=====第%d个学生======\n",i+1);
			
			InputMark(&f1);	
		}//用循环输入所有数据 
	
	printf("=======展示表格=========\n\n");
	//Sort(&f1);
	PrintPhoto(&f1);
	printf("\n\n\n\n\n");
	
	printf("=======数据结构的平均分如下=========\n\n");
	OutputAvg1(&f1);
	printf("=======高等数学的平均分如下=========\n\n");
	OutputAvg2(&f1);
	
	printf("==========现在可以在头部继续插入插班学生==========\n\n");
	Insert(&f1);
	//Sort(&f1);
	printf("=======展示表格=========\n\n");
	PrintPhoto(&f1);
	printf("\n\n\n\n\n");
	
	printf("==========现在可以通过查找学号输出该学生的所有信息=========\n\n");
	scanf("%d",&number); 
	Search(&f1,number);
	
	printf("==========现在可以通过查找学号删除该学生的所有信息=========\n\n");
	scanf("%d",&number); 
	Delect(&f1,number);
	printf("=======展示表格=========\n\n");
	PrintPhoto(&f1);
	printf("\n\n\n\n\n");
	
	printf("==================================\n\n\n\n\n\n");
	printf("======请问还需要实现什么功能======\n");
	printf(" 1 查找某个学生成绩\n\n 2 插入新同学\n\n 3 输出数据结构平均成绩 \n\n 4 输出高等数学平均成绩\n\n 5 输出总分最高成绩\n\n 0 退出"); 
	choice = 1;
	
	while(choice != 0)
	{
		printf("\n\n\n");
		printf("请输入"); 
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("==========现在可以通过查找学号输出该学生的所有信息=========\n\n");
				scanf("%d",&number); 
				Search(&f1,number);
				break;
			case 2:
				Insert(&f1);
				printf("=======展示表格=========\n\n");
				PrintPhoto(&f1);
				printf("\n\n\n\n\n");
				break;
			case 3:
				OutputAvg1(&f1);
				break;
			case 4:
				OutputAvg2(&f1); 
				break;
			case 5:
				Heightest(&f1);
			default:
				printf("error\n"); 
				break;
		}
	}
	
	printf("谢谢使用程序 >_< \n!");
	
	return 0;
}

Status Create(F* f)
{
	f->head = NULL;
	f->Formsize  = 0;
}

Status InputMark(F* f)
{
	Student* p;
	p = (Student*)malloc(sizeof(Student));
	
	
	printf("请输入该学生的学号\n");
	scanf("%d",&(p->data.Number ));
	printf("请输入该学生数据结构的成绩\n");
	scanf("%f",&(p->data.Mark1));
	printf("请输入该学生高等数学的成绩\n");
	scanf("%f",&(p->data.Mark2) );
	printf("请输入该学生的姓名\n");
	scanf("%s",&(p->data.Name));//关于字符串的输入输出不太明白 
	printf("请输入该学生的性别\n");
	scanf("%s",&(p->data.Sex));
	
	p->data.Total = p->data.Mark1 + p->data.Mark2; //计算总分 
	
	printf("\n\n\n");
	
	p->next = (*f).head;//指针明显不是这样写 
	(*f).head = p;
	
	f->Formsize += 1;
	
	return OK;
}

Status OutputAvg1(F* f)
{
	int i;//用于计数 
	Student* q;//指向student的指针，用于读取
	int size = (*f).Formsize;//方便，于是把长度读取 
	float Avg[size-1];//构造数组用于储存
	float AVG;
	
	q = (*f).head;
	
	for(i = 0;i < size;i++ )
	{
		Avg[i] = q->data.Mark1 ;
		q = q->next;
	}//读取所有的科目1成绩；
	
	for(i = 0;i < size;i++)
	{
		AVG = AVG + Avg[i];
	}
	
	AVG = AVG/size;
	
	printf("数据结构的平均分是%f\n\n",AVG);
	return OK;
}

Status OutputAvg2(F* f)
{
	int i;//用于计数 
	Student* q;//指向student的指针，用于读取
	q = (*f).head;
	int size = (*f).Formsize;//方便，于是把长度读取 
	float Avg[size-1];//构造数组用于储存
	float AVG;
	
	
	
	for(i = 0;i < size;i++ )
	{
		Avg[i] = q->data.Mark2 ;
		q = q->next;
	}//读取所有的科目1成绩；
	
	for(i = 0;i < size;i++)
	{
		AVG = AVG + Avg[i];
	}
	
	AVG = AVG/size;
	
	printf("高等数学的平均分是%f\n\n",AVG);
	
	return OK;
}

Status Insert(F* f)
{
	Student* p;
	p = (Student*)malloc(sizeof(Student));
	
	
	printf("请输入该学生的学号\n");
	scanf("%d",&(p->data.Number ));
	printf("请输入该学生数据结构的成绩\n");
	scanf("%f",&(p->data.Mark1));
	printf("请输入该学生高等数学的成绩\n");
	scanf("%f",&(p->data.Mark2) );
	printf("请输入该学生的姓名\n");
	scanf("%s",&(p->data.Name));//关于字符串的输入输出不太明白 
	printf("请输入该学生的性别\n");
	scanf("%s",&(p->data.Sex));
	
	p->data.Total = p->data.Mark1 + p->data.Mark2; //计算总分 
	
	printf("==================================\n\n\n");
 
	//什么是适当位置
	p->next = (*f).head;
	(*f).head = p; //在头部插入 
	
	(*f).Formsize += 1;
	
	return OK;
}

Status Delect(F* f,int num)
{
	Student* q = (*f).head;//赋值头指针//指向student的指针，用于读取
	Student* d = (*f).head;//赋值头指针;//用于free 
	
	
	if (q->data.Number == num)
		{
			(*f).head = q->next ;
			free(q);
		}
	else
		{
			int num1 = q->next->data.Number  ;
			while(num1 != num)
				{
					q = q->next ;
					num1 = q->next->data.Number ;
				} //找到要删除元素的前一位
			//if(q == NULL) printf("输入错误\n");
			d = q->next;
			q->next = q->next->next ;
			free(d); 
		}
	
	(*f).Formsize -= 1;	

	return OK;
}

Status Search(F* f,int num)
{
	Student* q;//指向student的指针，用于读取
	
	q = (*f).head;//赋值头指针
	
	int num1 = q->data.Number  ;
	while(num1 != num)
	{
		q = q->next ;
		num1 = q->data.Number ;
	} 
	printf("---------\n");
	printf("该学生的学号为\n");
	printf("%d\n",q->data.Number );
	
	printf("该学生数据结构的成绩为\n");
	printf("%f\n",q->data.Mark1);
	
	printf("该学生高等数学成绩为\n");
	printf("%f\n",q->data.Mark2);
	
	printf("该学生总成绩为\n");
	printf("%f\n",q->data.Total );
	
	printf("该学生的姓名为\n");
	printf("%s\n",q->data.Name);//关于字符串的输入输出不太明白
	
	printf("该学生的性别为\n");
	printf("%s\n",q->data.Sex);
	
	
	printf("==================================");
	
	return OK;
}

Status PrintPhoto(F*f)
{
	int i; 
	int size = (*f).Formsize;
	Student* q;//指向student的指针，用于读取
	q = (*f).head;
	printf("%-12s%-12s%-12s%-19s%-19s%-19s\n","学号","姓名","性别","数据结构成绩","高等数学成绩","总成绩"); 
	for(i = 0;i < size;i++)
	{
		printf("%-12d%-12s%-12s%-19f%-19f%-19f\n",q->data.Number ,q->data.Name,q->data.Sex ,q->data.Mark1 ,q->data.Mark2,q->data.Total );
		q = q->next ;
	}
	return OK;
}

Status Heightest(F*f)
{
	int i,j;//用于计数 
	Student* q;//指向student的指针，用于读取
	q = (*f).head;
	int size = (*f).Formsize;//方便，于是把长度读取 
	float Tol[size-1];//构造数组用于储存
	float temp;
	
	for(i = 0;i < size;i++ )
	{
		Tol[i] = q->data.Total  ;
		q = q->next;
	}//读取所有的科目1成绩；
	
	for(i = size - 1;i > 0;i --)
		for(j = 0;j < i;j ++)
		{
			if(Tol[j] < Tol[j + 1])
			{
				temp = Tol[j];
				Tol[j] = Tol[j + 1];
				Tol[j + 1] = temp;
			}
		}
	//对数组进行排序
	
	printf("总分最高分是%f\n",Tol[0]);
	
	return OK;
}

Status Sort(F*f)
{
	Student* q;//指向student的指针，用于读取
	q = (*f).head;
	int size = (*f).Formsize;//方便，于是把长度读取
	
	return OK;
}




