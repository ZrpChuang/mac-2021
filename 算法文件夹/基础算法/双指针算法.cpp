#include<iostream>
using namespace std;

const int N = 1e5+10;

int q[N],s[N];//用一个桶

//双指针算法，核心思想是，把两重循环压缩成一重循环，为什么，因为j的循环不需要刷新啊，
//不需要重零开始，所以后一重循环就省略了

int main(){
    int n;
    cin >> n;
    
    for(int i = 0;i < n;i ++) cin >> q[i];
    
    int res = 0;
    
    for(int i = 0,j = 0;i < n; i++){
        s[q[i]] ++;//桶排序思想，太浪费空间了
        while(s[q[i]] > 1 && j < i){
            s[q[j]] --;
            j ++;
        }
        
        res = max(res,i - j + 1);
    }
    
    cout << res;
    
    return 0;
}


// #include<iostream>
// //双指针算法的应用
// using namespace std;

// const int N = 1e5 + 10;

// long long a[N],b[N];

// int main(void){
//     int n,m;
    
//     cin >>n >> m;
    
//     for(int i = 0;i < n;i ++) cin >> a[i];
//     for(int i = 0;i < m;i ++) cin >> b[i];
    
//     int i = 0,j = 0;
    
//     for(int j = 0;j < m;j ++){
//         if(a[i] == b[j]){
//             i ++;
//             if(i >= n) break;
//         }
//     }
    
//     if(i == n ) cout << "Yes";
//     else cout << "No";
    
//     return 0;
// }