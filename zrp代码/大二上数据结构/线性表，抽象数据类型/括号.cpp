#include<stdio.h>
#define true 1
#define false 0
#define maxsize 100

typedef int status;

status match(char exp[], int n)//第一个形参是一个字符串数组，已经储存好相应的字符串 
{//假设表达式中只有小括号，n为数组长度

    
    char stack[maxsize];
	int top = -1;
	
    for (int i=0; i<n; i++)//n为长度 
    {
        if(exp[i] == '(')
            stack[++top] = exp[i];
        if(exp[i] == ')')
        {
            if(top != -1)
                top--;
            else 
            {
                printf("匹配失败！");
                return false;
            }
        }
    }
    if(top == -1)
    {
        printf("匹配成功！");
        return true;
    }
        
    else
    {
        printf("匹配失败！");
        return false;
    }
}

int main(void)
{
    char exp[maxsize];//字符串数组 
    int n, i, x;
    printf("请输入表达式的长度n：\n");
    scanf("%d", &n);
    getchar();  //用于接收回车键
    if(n>0)
    {
        printf("请逐个输入表达式中的字符：\n");
        for(i=0; i<n; i++)
        {
            x = getchar();      //不敲回车键直接输入完毕
            exp[i] = x;
            printf("exp[%d]=%c\n", i, exp[i]);
        }
    }
    
    match(exp, n);
    return 0;
}

/*————————————————
版权声明：本文为CSDN博主「小白算法习题记录本」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_43661234/article/details/100984994*/
