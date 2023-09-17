#include<iostream>
using namespace std;

// void quick_sort(int q[], int l, int r)
// {
//     if (l >= r) return;

//     int i = l - 1, j = r + 1, x = q[(l + r) / 2];
//     while (i < j)
//     {//这种快速排序的思路和普通版本的快速排序还是有些不一样的
//         do i ++ ; while (q[i] < x);
//         do j -- ; while (q[j] > x);
//         if (i < j) swap(q[i], q[j]);
//     }
//     quick_sort(q, l, j), quick_sort(q, j + 1, r);
// }

void quick_sort(int q[],int l,int r){
    int i = l - 1,j = r + 1,x = q[(l + r)/2];

    while(i < j){
        do i ++; while(q[i] < x);
        do j --; while(q[j] > x);
        if(i < j) swap(q[i],q[j]);
    }

    quick_sort(q,l,j);
    quick_sort(q,j + 1,r);
}




// 1 2 9 4 4 4 4 4 4
// 4
void qsort(int q[],int l,int r){

    int i = l - 1;//需要先把左右指针重新赋值
    int j = r + 1;
    int x = q[l + r >> 1];

    while (i < j){
        do i ++; while(q[i] < x);
        do j --; while(q[j] > x);//这里我考虑了一个特例，就好像上面我写的9一样，卡在9
        //这个时候其实会发现，j会下降到i - 1的地方，也就是说这个算法最后其实并不是i == j的
        if(i < j) swap(q[i],q[j]); 
    }
    qsort(q,l,j);
    qsort(q,j + 1,r);

    return;
}




int main(void){
    int arry[10] = {1,2,5,3,8,6,1,0,3,2};

    qsort(arry,0,9);
    for(int i = 0;i < 10;i ++){
        cout << arry[i] << " ";
    }
    
    return 0;
}