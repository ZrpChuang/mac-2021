#include<iostream>
#include<algorithm>
using namespace std;
const int N = 10010;
const int M = 10010;

int p[N];//并查集数组

struct edge{
    int a,b,w;

   bool operator< (const edge &W) const{
    return w < W.w;//运算符重载，用于pai xu
   }

}edges[M];//存储所有的边

int find(int a){//find函数的意义是找到该节点所在的祖宗节点
    if(p[a] != a) p[a] = find(p[a]);//优化
    return p[a];//返回对应的连通块
}

int main(){

    sort(edges,edges + M);
    for(int i = 0;i < N;i ++) p[i] = i;

    int res = 0;
    int cnt = 0;
    for(int i = 0;i < M;i ++){//遍历所有边
        int a = edges[i].a,b = edges[i].b,w = edges[i].w;
        a = find(a);
        b = find(b);//找到两个点对应的连通块
        if(a != b){
            p[a] = b;
            res += w;
            cnt ++;
        }
    }

    return 0;
}