#include<iostream>

using namespace std;

const int N = 110;

long dp[N][N];

int main(void){
    
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++ ){
        for(int j = 1;j <= n;j ++){
            cin >> dp[i][j];
        }
    }
    
    
    
    for(int i = n;i > 0;i --){
        for(int j = n;j > 0;j -- ){
            if(j + 1 <= n && i + 1 <= n) dp[i][j] += min(dp[i + 1][j],dp[i][j + 1]);
            else if(j + 1 <= n) dp[i][j] += dp[i][j+1];
            else if(i + 1 <= n) dp[i][j] += dp[i + 1][j];
        }
    }
    cout << dp[1][1];
    
    return 0;
}