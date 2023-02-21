#include<iostream>
using namespace std;

const int N = 15;

int dp[N + N][N][N];
//这道题目是升级版的数字三角形类型的题目，也就是走过去，带权值类型的题目，不同的是这道题目走两遍，如果是重复路经的
//话就是权重不作数，只算一遍的含义

//这里用到了的dp数组其实和一般意义的dp数组不是一个意思，不是i，j而是 i，i 用k = j + i从而优化了状态
int w[N][N];//权重数组

int main(void){
    
    int a,b,c,n;
    
    cin >> n;
    
    while( cin >> a >> b >> c , a || b || c )  w[a][b] = c;
    
    for(int k = 2;k <= 2 * n;k ++ ){
        for(int i1 = 1;i1 <= n;i1 ++){
            for(int i2 = 1;i2 <= n;i2 ++){
                int j1 = k - i1,j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
                {
                    int t = w[i1][j1];
                    if (i1 != i2) t += w[i2][j2];
                    int &x = dp[k][i1][i2] ;
                    x = max(x , t + dp[k - 1][i1 - 1][i2 - 1]);
                    x = max(x , t + dp[k - 1][i1 - 1][i2]);
                    x = max(x , t + dp[k - 1][i1][i2 - 1]);
                    x = max(x , t + dp[k - 1][i1][i2]);
                }

            }
        }
    }
    
    cout << dp[n + n][n][n];
    
    return 0;
}