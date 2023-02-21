#include<iostream>
using namespace std;

const int N = 100010;
const int M = 1000010;

int n,m;//读进来数组的长度
char s[M];
char p[N];
int ne_xt[N];//next

int main(void){
    
    cin >> n >> p + 1 >> m >> s + 1;
    
    ne_xt[1] = 0;
    for(int i = 2,j = 0;i <= n;i ++){//填写每一个next数组的取值
        while(j && p[i] != p[j + 1]) j = ne_xt[j];//利用之前的记录回退
        if(p[i] == p[j + 1]) j++;//基本上都是要加的，写个判断是因为，考虑到j == 0的情况
        ne_xt[i] = j;
    }
    
    for(int i = 1,j = 0;i <= m;i ++){//i只用循环一遍
        while(j && s[i] != p[j + 1]) j = ne_xt[j];//不匹配会会退，知道退到j == 0 为止
        if(s[i] == p[j + 1]) j++;
        if(j == n){//走到尽头
            cout << i - n << ' ';
            j = ne_xt[j];
        }
    }
    
    
    return 0;
}