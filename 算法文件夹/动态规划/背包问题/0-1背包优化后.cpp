#include<iostream>

using namespace std;

const int N = 1010;
int dp[N];
int n,m;


int main(void){
    
    cin >> n >> m;
    
    //dp没有用一个矩阵表示，用的是一个数组表示，倒着填写，利用以前的结果
    for(int i = 0;i < n ; i ++ ){
        int v,w;
        cin >> v >> w;
        for(int j = m;j >= v;j --){
            dp[j] = max(dp[j],dp[j - v] + w);
        }
    }
    cout << dp[m];
    return 0;
}

//主要做的是空间的优化