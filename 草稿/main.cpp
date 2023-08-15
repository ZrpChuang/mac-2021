#include <iostream>
using namespace std;
int main(void)
{
    int a,b,n;
    cin >> a >> b >> n;

    int res = 1;
    int num = a;

    while(num < n){
        if(res%7 >=1 && res%7<=5){
            res ++;
            num += a;
        }
        else {
            res++;
            num += b;
        }
    }

    cout << res;
    // 请在此输入您的代码
    return 0;
}