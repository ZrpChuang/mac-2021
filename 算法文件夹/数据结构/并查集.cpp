#include<iostream>
//并查集其实是两棵树
using namespace std;

int set[100000];

int findroot(int a){
    if(set[a] != a) set[a] = findroot(set[a]);//这里做了一个状态压缩，神来之笔
    return set[a];
}//神来之笔

int main(void){
    int m,n;
    cin >> n >> m;
    
    for(int i = 1;i <= n;i ++ ) set[i] = i;//每个元素一个集合
    
    while(m -- ){
        char c;
        int a,b;
        cin >> c >> a >> b;
        if(c == 'M') set[findroot(b)] = findroot(a);
        else if(c == 'Q'){
            if(findroot(a) == findroot(b)) puts("Yes");
            else puts("No");
        }
    }
    
    return 0;
}

//并查集总结：
//实际上是用树来表示两个集合，能够满足需求
//          1.合并集合
//          2.快速确两个元素是不是同一个集合

//神来之笔，路经压缩！！