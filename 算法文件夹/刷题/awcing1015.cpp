#include<iostream>
using namespace std;

const int R = 110;
const int C = 110;
long dp[R][C];

int main(void){
    int t;
    cin >> t;
    
    int row,col;
    
    while(t --){
        cin >> row >> col;
        for(int i = 0 ;i < row ;i ++ )
            for(int j = 0;j < col;j ++)
                cin >> dp[i][j];
        
        
        
        for(int i = row - 1;i >= 0;i -- ){
            for(int j = col - 1;j >=0 ;j --){
                if(i + 1 < row && j + 1 <col) dp[i][j] += max(dp[i + 1][j],dp[i][j + 1]);
                else if(i + 1 < row && j + 1 >= col ) dp[i][j] += dp[i + 1][j];
                else if(j + 1 < col && i + 1 >= row ) dp[i][j] += dp[i][j + 1];
            }
        }
        // for(int i = 0 ;i < row;i ++){
        //     for(int j = 0;j < col;j ++){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        cout << dp[0][0] << endl;
    }
    return 0;
}