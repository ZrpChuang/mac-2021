# include<stdio.h>
//ʵ�����ݣ�ʵ��������������Ӽ�����ˣ����

int Input(float *a,float *b)
{
	printf("�������һ����������ֵ\n");
	scanf("%f",&(*a));
	printf("������ڶ�����������ֵ\n");
	scanf("%f",&(*b));
	return 0;
} 
 
int plus(float *a,float *b)
{
	float x;
	x = *a + *b;
	return x;
}

int minus(float *a,float *b)
{
	float x;
	x = *a - *b;
	return x;
}

int times(float *a,float *b)
{
	float x;
	x = (*a) * (*b);
	return x;
}

int main (void)
{
	float i,j;
	float x,y,z;
	
	Input(&i,&j);
	
	x = plus(&i,&j);
	
	y = minus(&i,&j);
	
	z = times(&i,&j);
	
	printf("���������Ϊ%f\n",x);
	
	printf("���������Ϊ%f\n",y);
	
	printf("���������Ϊ%f\n",z);
	
	return 0;
	
}

