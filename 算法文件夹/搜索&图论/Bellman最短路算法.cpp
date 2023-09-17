#include<iostream>
using namespace std;


// class Solution {
// public:
//     int dist[110];
//     int backup[110];
//     //这个算法的特点是可以指定确定步数的最短路算法
//     //基于动态规划的思想
//     // 外层循环是表示的允许经过多少条边
//     // 内层循环表示的是遍历所有的边

//     // 其实可以想像遍历一个二位表 动态规划一行一行更新 但是每一行的更新
//     // 不是按顺序更新的
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         memset(dist,0x3f,sizeof(dist));//上机测试时候的技巧 用这种函数初始化看起来优雅
//         dist[src] = 0;

//         for(int i = 0;i < k + 1;i ++){
//             memcpy(backup,dist,sizeof dist);//为什么建立一个备份数组 实际上
//             for(int j = 0;j < flights.size();j ++){
//                 vector<int> temp = flights[j];
//                 int from = temp[0];
//                 int to = temp[1];
//                 int price = temp[2];

//                 dist[to] = min(dist[to],backup[from] + price);//实现细节
//             }
//         }

//         if(dist[dst] > 0x3f3f3f3f / 2) return -1;
//         else return dist[dst];
//     }
// };

const int N = 1010;
const int M = 1010;
int n, m;       // n表示点数，m表示边数
int dist[N];        // dist[x]存储1到x的最短路距离
int backup[N];

struct Edge     // 边，a表示出点，b表示入点，w表示边的权重
{
    int a, b, w;
}edges[M];


void bellman(int n){
    memset(dist,0x3f,sizeof(dist));
    dist[1] = 0;

    for(int i = 0;i < n;i ++){//限制次数，对于限制次数的最短路的唯一解法
        memcpy(backup,dist,sizeof(dist));
        for(int j = 0;j < m;j ++){
            int a = edges[j].a;
            int b = edges[j].b;
            int w = edges[j].w;
            dist[b] = min(dist[b],dist[a]+ w);
        }
    }
    return;
}

int main(){

    int n;
    cin >> n;

    for(int i = 1;i <= n;i ++){
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }//读入所有的边


    return 0;
}