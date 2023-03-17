# include<stdio.h>
//实验内容：实现两个有理数相加减，相乘，相除

int Input(float *a,float *b)
{
	printf("请输入第一个有理数的值\n");
	scanf("%f",&(*a));
	printf("请输入第二个有理数的值\n");
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
	
	printf("两个数相加为%f\n",x);
	
	printf("两个数相减为%f\n",y);
	
	printf("两个数相乘为%f\n",z);
	
	return 0;
	
}

