#include<iostream>
#include<string.h>//内存拷贝

using namespace std;

char g[5][5],backup[5][5];//读入棋盘数据


void turnoff(int row,int col){//连锁反应操作
    //操作上下左右
    
    //原本位置
    g[row][col]=g[row][col]^1;
    if(row-1>=0) g[row-1][col]=g[row-1][col]^1;//左
    if(row+1<5) g[row+1][col]=g[row+1][col]^1;
    if(col-1>=0) g[row][col-1]=g[row][col-1]^1;
    if(col+1<5) g[row][col+1]=g[row][col+1]^1;
    
    return;
}

int main(void){
    int n;//表示共有多少组的数据
    
    cin>>n;//读入需要一共进行多少次的游戏
    
    while(n--){//一次循环做完一个棋盘
        for(int i = 0;i<5;i++) cin>>g[i];//读入棋盘
        
        int grady=9;//贪心选择
        
        for(int i = 0; i < 32; i ++ ){
            //枚举第一行 按与不按的情况
            int count = 0;//计数
        
            memcpy(backup,g,sizeof(g));//备份矩阵
            
            for(int j = 0; j < 5 ; j++){//先对第一行进行操作
                if(i>>j &1) {//位运算技巧的体现
                    count++;
                    turnoff(0,j);
                }
            }
            
            for(int i = 0 ; i < 4 ; i ++ ){
                for(int j = 0; j < 5; j ++ ){
                    if(g[i][j] == '0' ){
                        turnoff(i+1,j);
                        count ++;
                    }
                }
            }
            
            int flag = 0;//判断本次枚举是否有效
            for(int i = 0; i < 5; i ++ )
            if(g[4][i] == '0') flag = 1;
        
            if(!flag) grady = min(grady,count);//更新本次操作的枚举
            
            memcpy(g,backup,sizeof(g));//恢复现场
        }
        
        if(grady <= 6) cout << grady << endl;
        else cout << -1 << endl;
        
    }//一次循环做完一个棋盘
    
    
    
    
    return 0;
}