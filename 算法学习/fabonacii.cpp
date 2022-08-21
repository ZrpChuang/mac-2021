#include<iostream>
using namespace std;
int fabofunc(int n){
    int result;
    int a=1,b=1;
    for(int i=3;i<=n;i++){
        result=a+b;
        a=b;
        b=result;
    }
    return result;
}
int main(void){
    cout<<"please in put the num:";
    int n;
    cin>>n;
    int result = fabofunc(n);
    cout<<"the result is:"<<result<<endl;
    return 0;
}
