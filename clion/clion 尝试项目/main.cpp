#include <iostream>

using namespace std;

const int N = 100010;

int s[N];//原始的数组
int temp[N];//保存每个长度尾部的数据

int main(void){
    int n;
    cin >> n;

    for(int i = 0; i < n; i ++) cin >> s[i];

    int len = 0;

    for(int i = 0; i < n; i ++){

        int l = 0,r = len;

        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(temp[mid] < s[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len,r + 1);
        temp[r + 1] = s[i];
    }

    cout << len;

    return 0;
}