#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 210;
int dp[N][N];
int n,m,k;
const int INF = 1e9;

void floyd(){
    
    for(int k = 1; k <= n;k ++ ){
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++ ){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
            }
        }
    }
    
    return;
}


int main(void){
    cin >> n >> m >> k;
    
    for(int i = 1; i <= n;i ++ ){
        for(int j = 1;j <= n; j ++ ){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = INF;
        }
    }
    
    while(m -- ){
        int x,y,z;
        cin >> x >> y >> z;
        dp[x][y] = min(dp[x][y],z);
    }
    
    floyd();
    
    while(k -- ){
        int x,y;
        cin >> x >> y;
        if(dp[x][y] > INF / 2) puts("impossible");
        else cout << dp[x][y] << endl;
    }
    
    
    return 0;
}
/*
floyd 算法基于动态规划

首先这种数据结构读入相对是比较复杂的；

floyd算法形式上很简单，思路是动态规划
完整的状态其实是dp[i][j][k],k表示的其实是：
从i到j，允许经过的前k个点；

后面的状态是从前面状态转移的，因此动态规划的空间压缩就用在上面了，就是一个空间压缩。

这样就理解一年前在做floyd算法的时候为什么老师讲述的两种算法，三维和二维；

*/