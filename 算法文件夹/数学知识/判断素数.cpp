#include<iostream>
using namespace std;

bool check(int num){
    if(num == 1) return false;
    for(int i = 2;i <= num/i;i ++){//这里有一个遍历的技巧
        if(num % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    
    while(n --){
        int num;
        cin >> num;
        if(check(num)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}