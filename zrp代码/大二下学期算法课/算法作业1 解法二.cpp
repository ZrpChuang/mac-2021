#include "stdio.h"
int main(){
    int n;
    int a[10] = {0};
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)//逐页拆数字的方法 
    {
        int k=i;
        while(k)
        {
            a[k%10]++;
            k = k/10;            
        }
    }
    
    for (i = 0; i < 10; i++)
        printf("%d\n", a[i]);
    
    return 0;
}
