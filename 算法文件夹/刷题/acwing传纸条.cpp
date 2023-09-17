#include<iostream>

using namespace std;

const int N = 55;
const int M = 55;

int dp[N + M][N][M];
int w[N][M];

int main(void){
    
    int n,m;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i ++){//读入数组
        for(int j = 1; j <= m; j ++){
            cin >> w[i][j];
        }
    }
    
    // for(int i = 1; i <= n; i ++){//读入数组
    //     for(int j = 1; j <= m; j ++){
    //         cout << w[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    for(int k = 2; k <= n + m; k ++){
        for(int i1 = 1;i1 < k && i1 <= n; i1 ++){
            for(int i2 = 1;i2 < k && i2 <= n; i2 ++){
                
                if(i1 == i2 && k != n + m && k != 2) continue;//相同的情况不计算
                int j1 = k -i1,j2 = k -i2;
                if(j1 >= 1 && j1 <= m && j2 >= 1 && j2 <= m){
                    int t = w[i1][j1] + w[i2][j2];//特殊情况时0，可以正常使用
                    int &x = dp[k][i1][i2] = 0;
                    x = max(x,t + dp[k - 1][i1 - 1][i2 - 1]);
                    if(i1 - 1 != i2) x = max(x,t + dp[k - 1][i1 - 1][i2]);
                    if(i1 != i2 - 1) x = max(x,t + dp[k - 1][i1][i2 - 1]);
                    x = max(x,t + dp[k - 1][i1][i2]);
                }
                
            }
        }
    }
    
    cout << dp[n + m][n][n];

    return 0;
}