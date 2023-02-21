#include <iostream>
using namespace std;
const int N = 100010;
int heap[N];//小顶堆
int n,m;
int sizex;
void down(int x){
    int t = x;//先让t = x
    if(2 * x <= sizex && heap[2 * x] < heap[t] ) t = 2 * x;
    if(2 * x  + 1 <= sizex && heap[2 * x + 1] < heap[t] ) t = 2 * x + 1;
    if(t != x){
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

*/