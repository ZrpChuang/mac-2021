#include <iostream>
#include<algorithm>
using namespace std;

int gcd(int a,int b){
    int m = a < b ? a : b;
    while (m)
    {
        if (m % a == 0 && m % b == 0)
        {
            break;
        }
        m++;
    }
    return m;
}

int main()
{
    int g[2030][2030] = {-1};
    for(int i = 1;i <= 2021;i ++) g[i][i] = 0;
    for(int i = 1;i <= 2021;i ++){
        for(int j = i + 1;j <= i + 21;j ++){
            //对称填写优化结果
            g[j][i] = gcd(i,j);
            g[i][j] = g[j][i];
        }
    }

    int status[2030] = {0};
    int dis[2030] = {0};
    status[1] = 1;

    for(int i = 1;i <=2021;i ++) dis[i] = g[1][i];


    for(int i = 2;i <= 2021;i ++){
        int greedy = 2021 * 2021;
        int number;
        for(int j = 2;j <= 2021;j ++){
            if(dis[j] < greedy){
                greedy = dis[j];
                number = j;
            }
        }
        status[i] = 1;
        for(int k = 1;k <= 2021;k ++){
            if(status[k] == 0 && (dis[number]+g[greedy][k] < dis[k] || dis[k] == -1) ){
                dis[k] = dis[number] + g[number][k];
            }
        }
    }

    cout << dis[2021];
    // 请在此输入您的代码
    return 0;
}
