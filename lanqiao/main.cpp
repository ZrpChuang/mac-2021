#include <iostream>
#include<cmath>
using namespace std;


int main(void){
//
//    int n =  2021041820210418;
    int n = 20;
    int cnt = 3;
    int sq_n = sqrt(n);

    for(int i = 2; i <= sq_n;i ++){
        if((n / i) * i == n){
            int a = i;
            int b = n/i;
            if(a == b) {
                cnt += 3;
                break;
            }
            else if(a != b){
                if(a == 1) cnt += 3;
                else {
                    cnt += 6;
                }
            }


            for(int j = 2;j <= sqrt(a);j ++)//检测第一个数是否可以拆分，并且找到所有拆分方式
                if((a / j) * j == a){
                    int c = j;
                    int a1 = a /j;
                    //a1 b c//b是最大的
                    if(a1 == c){
                        cnt += 3;
                    }
                    else {
                        cnt += 6;
                    }
                }

            for(int k = 2;k <= sqrt(b);k ++){
                if((b / k) * k == b){
                    int c = k;
                    int b1 = b / k;
                    if(a == b1 && b1 == c) cnt += 1;
                    else if(a == b1 || b1 == c || 1 == c) cnt += 3;
                    else cnt += 6;
                }
            }
        }

    }
    cout << "the res is:" << cnt << endl;

    return 0;
}


