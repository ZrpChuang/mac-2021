#include<iostream>
#include<vector>

using namespace std;

//n = 1e6


//数论两个重要的知识点
// 1.求整数的质数分解
// 2.根据整数的指数分解求欧拉函数，懂基本的容斥原理


const int N = 1e6 + 10;
bool status[N];//status == true cnt ++
int cnt,primes[N];

int main(void){
    int n = 21;
    int ulra = n;
    vector<int>  res;

    for(int i = 2;i <= n/i;i ++)
    {
        if(n % i == 0){
            res.push_back(i);
            ulra = ulra-ulra/i;
            while(n % i == 0) n /= i;
        }
        
    }
    if(n > 1) {
        ulra = ulra-ulra/n;
        res.push_back(n);
    }
    
    
    for(int i = 0;i < res.size();i ++)
        cout << res[i] << " ";
    
    cout << endl << ulra;

    return 0;
}