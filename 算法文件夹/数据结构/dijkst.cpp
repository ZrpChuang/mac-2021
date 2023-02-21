#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;
int g[N][N];
int dist[N];
bool status[N];
int n,m;


int Dijkst(){
    memset(dist,0x3f,sizeof(dist));
    dist[1] = 0;
    
    for(int k = 0;k < n - 1; k ++){
        int greedy = -1;
        for(int i = 1;i <= n;i ++){
            if(!status[i] && (greedy == -1 || dist[greedy] > dist[i])){
                greedy = i;
            }
        }
        
        for(int i = 1;i <= n;i ++){
            dist[i] = min(dist[i] , dist[greedy] + g[greedy][i]);
        }
        
        status[greedy] = true;
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main(void){
    cin >> n >> m;
    memset(g,0x3f,sizeof(g));
    
    while(m --){
        int x,y,z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y],z);
    }
    
    int t = Dijkst();
    
    cout << t << endl;
    
    return 0;
}