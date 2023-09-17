#include<iostream>
using namespace std;

// // 对于每个点k，开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
// int h[N], e[N], ne[N], idx;

// //这里实际上有每一个节点都有一个指针链

// //每一个节点实际上有两个信息，第一个信息就是next，另外一个节点表示的是b（也就是另外一条
// //边的位置）

// // 添加一条边a->b
// void add(int a, int b)
// {
//     e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
// }

// // 初始化
// idx = 0;
// memset(h, -1, sizeof h);


const int N = 110;

int h[N],e[N],ne[N],idx;

void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
    return;
}

int main(){
    idx = 0;
    memset(h,-1,sizeof(h));

    return 0;
}