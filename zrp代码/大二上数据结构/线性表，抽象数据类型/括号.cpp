#include<stdio.h>
#define true 1
#define false 0
#define maxsize 100

typedef int status;

status match(char exp[], int n)//��һ���β���һ���ַ������飬�Ѿ��������Ӧ���ַ��� 
{//������ʽ��ֻ��С���ţ�nΪ���鳤��

    
    char stack[maxsize];
	int top = -1;
	
    for (int i=0; i<n; i++)//nΪ���� 
    {
        if(exp[i] == '(')
            stack[++top] = exp[i];
        if(exp[i] == ')')
        {
            if(top != -1)
                top--;
            else 
            {
                printf("ƥ��ʧ�ܣ�");
                return false;
            }
        }
    }
    if(top == -1)
    {
        printf("ƥ��ɹ���");
        return true;
    }
        
    else
    {
        printf("ƥ��ʧ�ܣ�");
        return false;
    }
}

int main(void)
{
    char exp[maxsize];//�ַ������� 
    int n, i, x;
    printf("��������ʽ�ĳ���n��\n");
    scanf("%d", &n);
    getchar();  //���ڽ��ջس���
    if(n>0)
    {
        printf("�����������ʽ�е��ַ���\n");
        for(i=0; i<n; i++)
        {
            x = getchar();      //���ûس���ֱ���������
            exp[i] = x;
            printf("exp[%d]=%c\n", i, exp[i]);
        }
    }
    
    match(exp, n);
    return 0;
}

/*��������������������������������
��Ȩ����������ΪCSDN������С���㷨ϰ���¼������ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/qq_43661234/article/details/100984994*/
