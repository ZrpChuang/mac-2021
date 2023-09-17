#include<iostream>
using namespace std;

class Solution {
public:
    int h[5010],e[5010],ne[5010],idx = 0;
    int d[5010];//入度

    void add(int a,int b){//邻接表的表示方式
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx ++;
    }

    bool topsort(int n){//拓扑排序摸板
        int q[n + 5];//手动模拟的队列
        int hh = 0,tt = -1;//队头 队尾

        for(int i = 0;i < n;i ++){
            if(d[i] == 0) q[++tt] = i;
        }//一开始入度为0的点全部加入队列

        while(hh <= tt){//只要队列非空执行，宽度优先搜索的摸板
            //队列非空
            int node = q[hh ++];//取出队头元素
            for(int i = h[node];i != -1;i = ne[i]){//队头进行拓展
                int j = e[i];
                d[j] --;
                if(d[j] == 0) q[++tt] = j;
//                大概的意思就是每次从队列里面取出一个节点进行拓展，拓展过的节点就把出度给删掉
            }//这个for循环方式是邻接表的遍历方式
        }

        return tt == n - 1;//判断依据是所有元素入队成功

    }

    // bool topsort(int n){
    //     int q[n+5];
    //     int hh = 0,tt  = -1;
    //     for(int i = 0;i < n;i ++){
    //         if(d[i] == 0) q[tt++] = i;
    //     }

    //     while(hh <= tt){
    //         int node = q[hh++];

            // for(int i = h[node];i != -1;i = ne[i]){
            //     int j = e[i];
            //     d[j]--;
            //     if(d[j] == 0) q[hh++] = j;
            // }
    //         }
    //     }
    //     return hh = n - 1;
    // }

    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        memset(h,-1,sizeof(h));//
        memset(d,0,sizeof(d));

        for(int i = 0;i < prerequisites.size();i ++){
            vector<int> edge = prerequisites[i];
            add(edge[1],edge[0]);
            d[edge[0]] ++;
            // d[edge[0]] ++;
        }

        bool res = topsort(numCourses);

        return res;
    }
};