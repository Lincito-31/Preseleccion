#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,q,b;
vector<vector<bool>> mat,visited;
bool fill(int x,int y){
    if(x==n && y==m){
        return true;
    }
    if(x<=0 || y<=0 || x>n || y>m){
        return false;
    }
    if(visited[x][y]){
        return false;
    }
    visited[x][y]=true;
    if(fill(x-1,y) || fill(x,y-1) || fill(x+1,y) || fill(x,y+1)){
        return true;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    mat.assign(n+2,vector<bool>(m+2));
    //del top,del botton
    vector<vector<pair<int,int>>> dp(n+2,vector<pair<int,int>>(m+2,{1e9,1e9}));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a;
            if(a){
                mat[i][j]=true;
            }
        }
    }
    cin >> q;
    while(q--){
        cin >> a >> b;
        mat[a][b]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                visited.assign(n+2,vector<bool>(m+2));
                if(fill(0,0)){
                    cout << "1\n";
                }else{
                    cout << "0\n";
                    mat[i][j]=false;
                }
            }
        }
    }
    
}
/*
2 5
0 0 0 0 0
0 0 0 1 0
2
1 2
2 2
*/