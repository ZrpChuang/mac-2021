#include<iostream>
using namespace std;

const int V = 1010;//背包容积
const int N = 1010;//数目

int v_array[N];
int w_array[N];

int dp[N][V];


int main(void){
    int n,v;
    
    cin >> n >> v;
    
    for(int i = 1;i <= n;i ++ ) cin >> v_array[i] >> w_array[i];//输入每件物品的体积，还有权重
    
    for(int j = 0;j <= v;j ++ ) {
        if(v_array[n] <= j) dp[n][j] = w_array[n];//放得下
        else dp[n][j] = 0;//放不下
    }
    
    for(int i = n - 1;i >= 1;i --){
        for(int j = 0;j <= v;j ++ ){
            if(v_array[i] <= j) dp[i][j] = max(dp[i + 1][j],dp[i + 1][j - v_array[i]] + w_array[i]);//如果放得下
            else dp[i][j] = dp[i + 1][j];
        }
    }
    
    cout << dp[1][v];
    
    // for(int i = 1;i <= n;i ++){
    //     for(int j = 0;j <= v;j++)
    //     {
    //         cout<< dp[i][j] << " ";
    //     }
    //     cout<< endl;
    // }
    return 0;
}



