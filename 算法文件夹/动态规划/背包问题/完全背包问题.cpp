#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];
/*
    完全背包问题的优化：
    1. 因为每一件物品正常来说是需要枚举所有次数的，通过数学表达式，找到了对应的规律，
    因此实现了状态的优化
    dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - k * v[i]]+k * w[i])
            k = 1,2,3....
    考虑
    dp[i][j-v[i]] = max(dp[i-1][j-k*v[i]]+k*w[i]) k = 0,1,2,3...\

    2.另外就是传统的空间压缩

    
*/
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++ )
        for (int j = v[i]; j <= m; j ++ )
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}
