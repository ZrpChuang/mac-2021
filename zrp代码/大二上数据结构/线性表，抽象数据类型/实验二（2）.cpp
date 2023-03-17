# include<stdio.h>//Ԥ����ָ�ͷ�ļ��������� ��׼������� 
# include<stdlib.h>//malloc����Ҫ��  ������������  

# define TURE 1
# define FALSE 0
# define OK 1
# define ERROR 0
# define INFEASLBLE -1
# define OVERFLOW -2

/*����ṹ�� һ�������� 1��ʾ���ű�����ͷ��� ����ĳ��� ��ĳ�ʼ������
 
 						2��ʾÿһ���ڵ㣬����ָ������������
						3��ʾÿһ������������ݵ�ϸ�� 
						��һ���ṹ��һ�����壬�ʹ���һ�ű��ܽ�Ϊ�ṹ���
						Ƕ�ף����ң�Ҫ�ǵ������ǵ�һ���ṹ�� 
						
						���Ϊfrom
						ѧ��Ϊstudents
						ѧ����ϢΪdata 
*/

//ʵ�ֹ��ܣ� 
typedef int Status;
typedef struct Data//�趨��ѧ����3���������ݣ�������ѧ��ѧ�ţ�ѧ�����Ƴɼ���ѧ������ 
{
	int Number;
	float Mark1;
	float Mark2;
	float Total;
	char Name[100];//�ַ��������ʾ������
	char Sex[50]; 
}D;

typedef struct Student
{
	Data data;
	Student* next;
}S;

typedef struct Form//��� 
{
	int Formsize;
	Student* head;//ͷָ�룬ָ���һ��ͬѧ 
}F;


//����ǰ������
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
	F f1;//������ 
	int n;//��ʼ�������ж���ͬѧ�� 
	int i;//���ڼ���
	int choice = 1;//case��ѡ�� 
	int number;
	float H;//���������߷� 
	
	printf("-----���������Ƚ���һ�ſձ�------\n\n");
	
	Create(&f1);
	
	printf("Ȼ��������Ҫ������������ѧ���Ļ�����Ϣ���Լ����Ƴɼ�\n\n\n");
	system("pause");
	printf("\n\n\n");
	printf("�������״ζԿձ�������룬��������Ϲ��ж�����ͬѧ����Ҫд̫�࣬��ȻҪ�ֶ��������ݹ��࣡��\n");
	scanf("%d",&n);//��ʼ������ж�����ͬѧ 
	
	for (i = 0;i < n;i++)
		{
			
			printf("=====��%d��ѧ��======\n",i+1);
			
			InputMark(&f1);	
		}//��ѭ�������������� 
	
	printf("=======չʾ���=========\n\n");
	//Sort(&f1);
	PrintPhoto(&f1);
	printf("\n\n\n\n\n");
	
	printf("=======���ݽṹ��ƽ��������=========\n\n");
	OutputAvg1(&f1);
	printf("=======�ߵ���ѧ��ƽ��������=========\n\n");
	OutputAvg2(&f1);
	
	printf("==========���ڿ�����ͷ������������ѧ��==========\n\n");
	Insert(&f1);
	//Sort(&f1);
	printf("=======չʾ���=========\n\n");
	PrintPhoto(&f1);
	printf("\n\n\n\n\n");
	
	printf("==========���ڿ���ͨ������ѧ�������ѧ����������Ϣ=========\n\n");
	scanf("%d",&number); 
	Search(&f1,number);
	
	printf("==========���ڿ���ͨ������ѧ��ɾ����ѧ����������Ϣ=========\n\n");
	scanf("%d",&number); 
	Delect(&f1,number);
	printf("=======չʾ���=========\n\n");
	PrintPhoto(&f1);
	printf("\n\n\n\n\n");
	
	printf("==================================\n\n\n\n\n\n");
	printf("======���ʻ���Ҫʵ��ʲô����======\n");
	printf(" 1 ����ĳ��ѧ���ɼ�\n\n 2 ������ͬѧ\n\n 3 ������ݽṹƽ���ɼ� \n\n 4 ����ߵ���ѧƽ���ɼ�\n\n 5 ����ܷ���߳ɼ�\n\n 0 �˳�"); 
	choice = 1;
	
	while(choice != 0)
	{
		printf("\n\n\n");
		printf("������"); 
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("==========���ڿ���ͨ������ѧ�������ѧ����������Ϣ=========\n\n");
				scanf("%d",&number); 
				Search(&f1,number);
				break;
			case 2:
				Insert(&f1);
				printf("=======չʾ���=========\n\n");
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
	
	printf("ллʹ�ó��� >_< \n!");
	
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
	
	
	printf("�������ѧ����ѧ��\n");
	scanf("%d",&(p->data.Number ));
	printf("�������ѧ�����ݽṹ�ĳɼ�\n");
	scanf("%f",&(p->data.Mark1));
	printf("�������ѧ���ߵ���ѧ�ĳɼ�\n");
	scanf("%f",&(p->data.Mark2) );
	printf("�������ѧ��������\n");
	scanf("%s",&(p->data.Name));//�����ַ��������������̫���� 
	printf("�������ѧ�����Ա�\n");
	scanf("%s",&(p->data.Sex));
	
	p->data.Total = p->data.Mark1 + p->data.Mark2; //�����ܷ� 
	
	printf("\n\n\n");
	
	p->next = (*f).head;//ָ�����Բ�������д 
	(*f).head = p;
	
	f->Formsize += 1;
	
	return OK;
}

Status OutputAvg1(F* f)
{
	int i;//���ڼ��� 
	Student* q;//ָ��student��ָ�룬���ڶ�ȡ
	int size = (*f).Formsize;//���㣬���ǰѳ��ȶ�ȡ 
	float Avg[size-1];//�����������ڴ���
	float AVG;
	
	q = (*f).head;
	
	for(i = 0;i < size;i++ )
	{
		Avg[i] = q->data.Mark1 ;
		q = q->next;
	}//��ȡ���еĿ�Ŀ1�ɼ���
	
	for(i = 0;i < size;i++)
	{
		AVG = AVG + Avg[i];
	}
	
	AVG = AVG/size;
	
	printf("���ݽṹ��ƽ������%f\n\n",AVG);
	return OK;
}

Status OutputAvg2(F* f)
{
	int i;//���ڼ��� 
	Student* q;//ָ��student��ָ�룬���ڶ�ȡ
	q = (*f).head;
	int size = (*f).Formsize;//���㣬���ǰѳ��ȶ�ȡ 
	float Avg[size-1];//�����������ڴ���
	float AVG;
	
	
	
	for(i = 0;i < size;i++ )
	{
		Avg[i] = q->data.Mark2 ;
		q = q->next;
	}//��ȡ���еĿ�Ŀ1�ɼ���
	
	for(i = 0;i < size;i++)
	{
		AVG = AVG + Avg[i];
	}
	
	AVG = AVG/size;
	
	printf("�ߵ���ѧ��ƽ������%f\n\n",AVG);
	
	return OK;
}

Status Insert(F* f)
{
	Student* p;
	p = (Student*)malloc(sizeof(Student));
	
	
	printf("�������ѧ����ѧ��\n");
	scanf("%d",&(p->data.Number ));
	printf("�������ѧ�����ݽṹ�ĳɼ�\n");
	scanf("%f",&(p->data.Mark1));
	printf("�������ѧ���ߵ���ѧ�ĳɼ�\n");
	scanf("%f",&(p->data.Mark2) );
	printf("�������ѧ��������\n");
	scanf("%s",&(p->data.Name));//�����ַ��������������̫���� 
	printf("�������ѧ�����Ա�\n");
	scanf("%s",&(p->data.Sex));
	
	p->data.Total = p->data.Mark1 + p->data.Mark2; //�����ܷ� 
	
	printf("==================================\n\n\n");
 
	//ʲô���ʵ�λ��
	p->next = (*f).head;
	(*f).head = p; //��ͷ������ 
	
	(*f).Formsize += 1;
	
	return OK;
}

Status Delect(F* f,int num)
{
	Student* q = (*f).head;//��ֵͷָ��//ָ��student��ָ�룬���ڶ�ȡ
	Student* d = (*f).head;//��ֵͷָ��;//����free 
	
	
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
				} //�ҵ�Ҫɾ��Ԫ�ص�ǰһλ
			//if(q == NULL) printf("�������\n");
			d = q->next;
			q->next = q->next->next ;
			free(d); 
		}
	
	(*f).Formsize -= 1;	

	return OK;
}

Status Search(F* f,int num)
{
	Student* q;//ָ��student��ָ�룬���ڶ�ȡ
	
	q = (*f).head;//��ֵͷָ��
	
	int num1 = q->data.Number  ;
	while(num1 != num)
	{
		q = q->next ;
		num1 = q->data.Number ;
	} 
	printf("---------\n");
	printf("��ѧ����ѧ��Ϊ\n");
	printf("%d\n",q->data.Number );
	
	printf("��ѧ�����ݽṹ�ĳɼ�Ϊ\n");
	printf("%f\n",q->data.Mark1);
	
	printf("��ѧ���ߵ���ѧ�ɼ�Ϊ\n");
	printf("%f\n",q->data.Mark2);
	
	printf("��ѧ���ܳɼ�Ϊ\n");
	printf("%f\n",q->data.Total );
	
	printf("��ѧ��������Ϊ\n");
	printf("%s\n",q->data.Name);//�����ַ��������������̫����
	
	printf("��ѧ�����Ա�Ϊ\n");
	printf("%s\n",q->data.Sex);
	
	
	printf("==================================");
	
	return OK;
}

Status PrintPhoto(F*f)
{
	int i; 
	int size = (*f).Formsize;
	Student* q;//ָ��student��ָ�룬���ڶ�ȡ
	q = (*f).head;
	printf("%-12s%-12s%-12s%-19s%-19s%-19s\n","ѧ��","����","�Ա�","���ݽṹ�ɼ�","�ߵ���ѧ�ɼ�","�ܳɼ�"); 
	for(i = 0;i < size;i++)
	{
		printf("%-12d%-12s%-12s%-19f%-19f%-19f\n",q->data.Number ,q->data.Name,q->data.Sex ,q->data.Mark1 ,q->data.Mark2,q->data.Total );
		q = q->next ;
	}
	return OK;
}

Status Heightest(F*f)
{
	int i,j;//���ڼ��� 
	Student* q;//ָ��student��ָ�룬���ڶ�ȡ
	q = (*f).head;
	int size = (*f).Formsize;//���㣬���ǰѳ��ȶ�ȡ 
	float Tol[size-1];//�����������ڴ���
	float temp;
	
	for(i = 0;i < size;i++ )
	{
		Tol[i] = q->data.Total  ;
		q = q->next;
	}//��ȡ���еĿ�Ŀ1�ɼ���
	
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
	//�������������
	
	printf("�ܷ���߷���%f\n",Tol[0]);
	
	return OK;
}

Status Sort(F*f)
{
	Student* q;//ָ��student��ָ�룬���ڶ�ȡ
	q = (*f).head;
	int size = (*f).Formsize;//���㣬���ǰѳ��ȶ�ȡ
	
	return OK;
}




