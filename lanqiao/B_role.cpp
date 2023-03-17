#include <iostream>
using namespace std;

long a[10];

int main() {

    for(int i = 0;i < 10;i ++)
        a[i] = 2021;
    int flag = 1;
    long ct = 0;
    int res;

    while(flag){
        ct ++;
        int temp = ct;//temp需要被处理
        while(temp > 0 && flag){
            int left = temp % 10;
            temp = temp / 10;
            a[left] --;
            if(a[left] <= 0) {
                flag = false;
                res = ct - 1;
            }
        }
    }
    cout << res;


    return 0;
}



//
//int main(void){
//    int n = 20,m = 21;
//
//    int ct = 0;
//
//    ct =  m + n;
//
//    for(int i  = 1;i < m;i ++){
//        ct += n * ( (n-1) * (m - i));
//    }
//
//    cout << ct;
//
//    return 0;
//}