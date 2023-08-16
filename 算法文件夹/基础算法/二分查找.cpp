//二分查找实际上是一个有点小麻烦的算法，涉及到的内容包括左右边界的问题

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int q[N];

int main(void){
    int n,t;

    cin >> n >> t;

    for(int i = 0;i < n;i ++) cin >> q[i];

    while(t--){
        int x;
        cin >> x;

        int l = 0,r = n-1;

        while(l < r){//找左边界
            int mid = l + r >> 1;
            if(q[mid] >= x) r = mid;
            else l = mid + 1;
        }

        if(q[l] != x){
            cout << -1 << " " << -1 << endl;
            continue;
        }
        else cout << l << " ";
        l = 0,r = n-1;

        while(l < r){
            int mid = l + r + 1 >> 1;
            if(q[mid] > x) r = mid - 1;
            else l = mid;
        }
        cout << l << endl;
    }

    return 0;
}
