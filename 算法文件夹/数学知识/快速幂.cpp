#include<iostream>
#include<vector>

using namespace std;

//快速幂函
//解决的问题是：
// 快速的把a的k的方modp计算出来

// 朴素做法的时间复杂度：O（n）

// 有话之后的做法是：log k

// 关键思想：

// 如果正常的计算一个数字的k次方，明显是需要O（K）就可以解决，因为直接乘以k次就可以解决了

// 但是，利用k可以转换成二进制的写法，就是，任何一个k，必然可以a12^1+a22^2+a32^3......ai2i....这种形式



int qmi(int a,int k,int p){
    int res = 1;
    int t = a;

    while(k){
        if(k & 1) res = res * t % p;
        t = t * t % p;//生成的技巧
        k >>= 1;
    }

    return res;
}

int qmii(int m, int k, int p)
{
    int res = 1 % p, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}

int main(void){
    cout << qmi(3,2,5);

    return 0;
}