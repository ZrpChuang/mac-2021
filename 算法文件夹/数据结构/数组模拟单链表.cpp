#include <iostream>

using namespace std;

const int N = 100010;
int e[N],en[N];//设计0位置等价于NULL
int h,idx;

/*
    单链表的一些基本操作
*/
void init(){
    idx = 1;
    h = 0;
}

void add_to_head(int val){
    e[idx] = val;
    en[idx] = h;
    h = idx;
    idx ++;
}

void add(int k,int val){
    e[idx] = val;
    en[idx] = en[k];
    en[k] = idx;
    idx ++;
}

void delet(int k){
    if(k == 0){
        h = en[h];
    }
    else en[k] = en[en[k]];
}

int main(void){
    int m;
    cin >> m;
    int n = m;
    init();
    
    while(m --){
        char c;
        cin >> c;
        if(c == 'H'){
            //头部
            int val;
            cin >> val;
            add_to_head(val);
        }
        else if(c == 'I'){
            //插入
            int k,val;
            cin >> k >> val;
            add(k,val);
        }
        else if(c == 'D'){
            //删除
            int k;
            cin >> k;
            delet(k);
        }
    }
    
    while(h){
        cout << e[h] << ' ';
        h = en[h];
    }
    
    return 0;
}