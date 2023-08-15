#include<iostream>
#include<algorithm>
using namespace std;
const int n=21;
long long dp[(1<<n)][n]={0};
int mp[21][21];
int gcd(int x,int y)
{
    return !y?x:gcd(y,x%y);
}//最大公约数的写法
int main(){
    int maxn=(1<<n)-1;

    // 连接矩阵
    for(int i=0;i<21;i++){
        for(int j=0;j<21;j++){
            if(i!=j&&gcd(i+1,j+1)==1)mp[i][j]=mp[j][i]=1;
        }
    }
    // 初始化
    dp[1][0]=1;
    // 遍历所有的状态
    for(int i=0;i<=maxn;i++){
        // 当前位置
        if(i&1)
            for(int j=0;j<n;j++){
                // 状态必须包含当前位置
                if(((1<<j)&i)){
                    // 之前有哪些状态
                    for(int k=0;k<21;k++){
                        // 之前有的状态
                        if(mp[k][j])
                            if(k!=j&&((1<<k)&i)){
                                // 更新dp
                                dp[i][j]+=dp[(i&(~(1<<j)))][k];
                            }
                    }
                }
            }
    }


    long long ans=0;
    for(int i=1;i<n;i++)
        if(mp[0][i])
            ans+=dp[maxn][i];
    cout<<ans;
}
//#include <iostream>
//using namespace std;
//int g[22][22];
//long long cnt;
//int arry[22] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
//
//int gcd(int x,int y)
//{
//    return !y?x:gcd(y,x%y);
//}//最大公约数的写法
//
//void swap(int i,int j){
//    if (i == j) return;
//    int temp = arry[i];
//    arry[i] = arry[j];
//    arry[j] = temp;
//    return;
//}
//
//void Hamiton(int place)
//{
//    if(place < 1) return;
//
//    cout << "现在的place="<< place<< ",cnt="<< cnt << endl;
//
//    if(place >= 21){
//        if(g[arry[20]][arry[21]] && g[arry[1]][arry[21]]){
//            cnt = cnt + 1;
//            for(int i = 1;i <=21;i ++){
//                cout << arry[i] << " ";
//            }
//            cout << endl;
//        }
//        return;
//    }
//
//    if(place > 1){
//        if(g[arry[place-1]][arry[place]] == 0) return;
//    }
//
//    for(int i = place + 1;i <= 21;i ++){
//        swap(place + 1,i);
//        Hamiton(place + 1);
//        swap(place + 1,i);
//    }
//
//    return;
//}
//
//int main()
//{
//    cnt = 0;
//    for(int i=1;i <= 21;i ++){
//        for(int j = i + 1;j <= 21;j ++){
//            if(gcd(i,j) == 1){
//                g[i][j] = g[j][i] = 1;
//            }
//            else{
//                g[i][j] = g[j][i] = 0;
//            }
//        }
//    }
//
//    Hamiton(1);
//    cout << cnt << endl;
//    // 请在此输入您的代码
//    return 0;
//}
//
//
////#include <iostream>
////#include<cmath>
////using namespace std;
////
////
////int main(void){
////
////    int n =  2021041820210418;
////    int n = 20;
////    int cnt = 3;
////    int sq_n = sqrt(n);
////
////    for(int i = 2; i <= sq_n;i ++){
////        if((n / i) * i == n){
////            int a = i;
////            int b = n/i;
////            if(a == b) {
////                cnt += 3;
////                break;
////            }
////            else if(a != b){
////                if(a == 1) cnt += 3;
////                else {
////                    cnt += 6;
////                }
////            }
////
////
////            for(int j = 2;j <= sqrt(a);j ++)//检测第一个数是否可以拆分，并且找到所有拆分方式
////                if((a / j) * j == a){
////                    int c = j;
////                    int a1 = a /j;
////                    //a1 b c//b是最大的
////                    if(a1 == c){
////                        cnt += 3;
////                    }
////                    else {
////                        cnt += 6;
////                    }
////                }
////
////            for(int k = 2;k <= sqrt(b);k ++){
////                if((b / k) * k == b){
////                    int c = k;
////                    int b1 = b / k;
////                    if(a == b1 && b1 == c) cnt += 1;
////                    else if(a == b1 || b1 == c || 1 == c) cnt += 3;
////                    else cnt += 6;
////                }
////            }
////        }
////
////    }
////    cout << "the res is:" << cnt << endl;
////
////    return 0;
////}
////
//
