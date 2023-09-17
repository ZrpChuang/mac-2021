#include<iostream>
#include<queue>
using namespace std;
//写一个邻接矩阵版本

typedef pair<int,int> PII;//队列里面的元素应该放这个东西

const int N = 100;

int g[N][N];
int dist[N];
bool status[N];

int h[N];

//下面三个节点采用的是同步的，
int ne[N];
int e[N];
int idx;
int w[N];

int dijkstra(int n,int s,int d){//为什么这个地方dist数组需要从1开始呢，因为传过来一般说的是第几个点
    
    //初始化
    memset(dist,0x3f,sizeof dist);
    priority_queue<PII,vector<PII>,greater<PII> > heap;//定义优先队列
    heap.push({0,s});

    while(heap.size()){
        PII t = heap.top();
        heap.pop();

        //t取出来的是一对东西，其中first是distance

        int dis = t.first;
        int ver = t.second;

        for(int i = 1;i <= n;i ++){

        }
    }
    

    return dist[d];
}



int main(void){
    int n,s;//n表示的是有多少个点，s表示的是原点

    cin >> n >> s;

    int res = dijkstra(n,s);

    return 0;
}