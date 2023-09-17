#include<iostream>
using namespace std;

class Solution {
public:
    int g[1010][1010];
    int dist[1010];
    int status[1010];

    int minCostConnectPoints(vector<vector<int> >& points) {
        for(int i = 0;i < points.size();i ++){
            for(int j = 0;j < points.size();j ++){
                int s_x = points[i][0];
                int s_y = points[i][1];
                int d_x = points[j][0];
                int d_y = points[j][1];

                g[i][j] = g[j][i] = abs(s_x - d_x) + abs(s_y - d_y);
            }
        }//建图

        
        memset(dist,0x3f,sizeof(dist));
        dist[0] = 0;
        int res = 0,n = points.size();
        for(int i = 0;i < n;i ++){
            int t = -1;
            for(int j = 0;j < n;j ++){
                if(status[j] == false && (t == -1 || dist[t] > dist[j]) )
                    t = j;
            }

            status[t] = true;
            res += dist[t];
            for(int j = 0;j < n;j ++){
                dist[j] = min(dist[j],g[t][j]);
            }
        }

        return res;
    }
};
//leetcode 1584
// 给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。

// 连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。

// 请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连