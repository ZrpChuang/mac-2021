#include<iostream>

using namespace std;

const int N = 100000;
int n;
int q[N];
int temp[N];
//简单写一下归并排序的思路

//直接就递归完成左右字数组的归并排序

//然后直接进行合并

多出来没有被合并的数组直接放在最后面
void merge_sort(int l,int r){
    if(l >= r) return;
    
    int mid = (l + r) >> 1;
    
    merge_sort(l,mid);
    merge_sort(mid + 1,r);
    
    int p1 = l,p2 = mid + 1;
    int t_p = l;//这个是temp数组的指针
    
    while(p1 <= mid && p2 <= r){
        if(q[p1] <= q[p2]) temp[t_p ++ ] = q[p1 ++];
        else temp[t_p ++ ] = q[p2 ++];
    } 
    
    while(p1 <= mid) temp[t_p ++ ] = q[p1 ++ ];
    while(p2 <= r) temp[t_p ++ ] = q[p2 ++ ];
    for(int i = l;i <= r;i ++ ) q[i] = temp[i];//拷贝进去
    
    return;
}




int main(void){
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> q[i];//读入
    
    merge_sort(0,n-1);
    
    for(int i = 0; i < n;i ++ ) cout << q[i]<<' ';
    
    return 0;
}