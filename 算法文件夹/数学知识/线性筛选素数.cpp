#include<iostream>

using namespace std;

//n = 1e6

const int N = 1e6 + 10;
bool status[N];//status == true cnt ++
int cnt,primes[N];

int main(void){
    int n;
    cin >> n;
    
    for(int i = 2;i <= n;i ++){
        if(!status[i]) primes[cnt ++] = i;//1.计数 2.存储
        for(int j = 0 ; primes[j] <= n / i;j ++){
            status[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
            //精髓
            //1.这个算法之所以是线性的核心是：
            //每一个和数只被筛选一次，比如：7*14结束后，不会有8*14，因为与7*16等价
            //2.所以当不互素的时候截断
        }
    }
    
    cout << cnt;
    
    return 0;
}