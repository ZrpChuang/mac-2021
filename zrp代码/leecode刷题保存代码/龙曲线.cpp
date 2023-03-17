#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* combine(char* before) {
	int len = strlen(before);
	//printf("len = %d\n",len);
	int nowlen = 2 * len + 1;
	char* result = (char*)realloc(before, (nowlen+1) * sizeof(char));
	result[len] = 'L'; result[len + 1] = 'F';
	//printf("result[len] =%c,result[len + 1] = %c",result[len],result[len + 1]);
	for(int i = len+2,j = len-2;i<=nowlen-2;i+=2,j-=2)
		{
			result[i+1] = 'F';
			if(result[j]=='R') result[i] = 'L';
			else result[i] = 'R';
		}
	result[nowlen] = '\0';
//	printf("before内：%s\n",result);
	return result;
}
char* Dgline(int n) 
{
	char* result = NULL;
	
	if (n == 1) {
		result = (char*)malloc(2* sizeof(char));;//定义返回结果 
		result[0] = 'F';
		result[1] = '\0';
	}
	else if (n == 2) {
		result = (char*)malloc(4* sizeof(char));;//定义返回结果 
		result[0] = 'F';
		result[1] = 'L';
		result[2] = 'F';
		result[3] = '\0';
	}
	else if(n>2){
		char* before = Dgline(n - 1);
		return combine(before);
	}
	
	return result;
}
int main(void)//主函数 
{
	int n;
	scanf("%d",&n);
	printf("\n");
	
	char *result;
	result = Dgline(n);
	printf("\nthe result is:%s",result);
	
	return 0;
}
