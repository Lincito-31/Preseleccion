#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll res=0;
char mapa[1005][1005];
bool visited[1005][1005];
void dfs(int x,int y){
    if(visited[x][y] || mapa[x][y]=='#'){
        return;
    }
    visited[x][y]=true;
    if(mapa[x][y]!='.' && mapa[x][y]!='S'){
        res+=mapa[x][y]-48;
    }
    if(mapa[x-1][y]=='T' || mapa[x+1][y]=='T' || mapa[x][y-1]=='T' || mapa[x][y+1]=='T'){
        // nada;
    }else{
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    while(cin >> n >> m){
        int x,y;
        res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> mapa[i][j];
                visited[i][j]=false;
                if(mapa[i][j]=='S'){
                    x=i;
                    y=j;
                }
            }
        }
        for(int i=0;i<=n+1;i++){
            mapa[i][0]=mapa[i][m+1]='#';
        }
        for(int i=0;i<=m+1;i++){
            mapa[0][i]=mapa[n+1][i]='#';
        }
        dfs(x,y);
        cout << res << "\n";
    }
}