#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20010;

int f[N],g[N],q[N];//q为维护的单队列，存的是是符合要求的下标记

int main(void){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n ;i ++){
        memcpy(g,f,sizeof(f));
        int v,w,s;
        cin >> v >> w >> s;
        for(int j = 0;j < v;j ++){//枚举余数；
            int hh = 0,tt = -1;//队列初始化
            for(int k = j;k <= m;k += v){
                   
                if(hh <= tt && q[hh] < k - s * v) hh ++;
                while(hh <= tt && g[q[tt]] - (q[tt] - j)/v * w  <= g[k] - (k - j)/v * w) tt --;
                q[++tt] = k;
                f[k] = g[q[hh]] + (k - q[hh]) / v * w;
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}

/*
    个人理解：
    区别于完全背包问题，完全背包问题能够利用前面所有值，多重背包只能利用部分值；

    
*/