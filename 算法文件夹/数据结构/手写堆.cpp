#include <iostream>
using namespace std;
const int N = 100010;
int heap[N];//小顶堆
int n,m;
int sizex;

// 堆的性质：每个节点都大于他的儿子


// void down(int x){//堆只有一个操作，这个操作是递归进行的
//     int t = x;//先让t = x
    
//     //保证操作不超出数组长度 
//     //左孩子是2x，右边孩子是2x+1
//     if(2 * x <= sizex && heap[2 * x] < heap[t] ) t = 2 * x;
//     if(2 * x  + 1 <= sizex && heap[2 * x + 1] < heap[t] ) t = 2 * x + 1;

//     if(t != x){
//         swap(heap[x],heap[t]);
//         down(t);//递归进行
//     }
// }

void down(int x){
    int t = x;
    if(2 * x < sizex && heap[2 * x] < heap[t] ) t = 2 * x;
    if(2 * x + 1 < sizex && heap[2 * x + 1] < heap[t]) t = 2 * x + 1;

    if( t != x){
        swap(heap[x],heap[t]);
        down(t);
    }
}


int main(void){
    cin >> n >> m;
    sizex = n;
    for(int i = 1;i <= n; i ++ ) {
        cin >> heap[i];
    }
    
    for(int i = n/2; i >= 1; i --) down(i);
    
    while( m -- ){
        cout << heap[1] << ' ';
        heap[1] = heap[sizex --];
        down(1);
    }
    
    return 0;
}

/*
    技巧：首先用数组的形式进行存储
    进行down操作的时候非常巧妙
    每次换上一个

记住几个东西；
1.堆的性质是什么：每一个节点，都大于他的两个儿子
2.怎么建立，从n/2开始执行一个操作，使其满足性质

*/