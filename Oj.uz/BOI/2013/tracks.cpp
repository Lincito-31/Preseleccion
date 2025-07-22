#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,m,maxi;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    char mat[n+2][m+2];
    int dist[n+2][m+2];
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            dist[i][j]=1e9;
            mat[i][j]='.';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
        }
    }
    dist[1][1]=1;
    deque<pair<int,int>> bfs;
    bfs.push_back({1,1});
    while(!bfs.empty()){
        pair<int,int> top=bfs.front();
        bfs.pop_front();
        int i=top.first,j=top.second;
        if(mat[i-1][j]!='.'){
            int wei;
            if(mat[i-1][j]==mat[i][j]){
                wei=0;
            }else{
                wei=1;
            }
            if(dist[i-1][j]>dist[i][j]+wei){
                dist[i-1][j]=dist[i][j]+wei;
                if(wei){
                    bfs.push_back({i-1,j});
                }else{
                    bfs.push_front({i-1,j});
                }
            }
        }
        if(mat[i+1][j]!='.'){
            int wei;
            if(mat[i+1][j]==mat[i][j]){
                wei=0;
            }else{
                wei=1;
            }
            if(dist[i+1][j]>dist[i][j]+wei){
                dist[i+1][j]=dist[i][j]+wei;
                if(wei){
                    bfs.push_back({i+1,j});
                }else{
                    bfs.push_front({i+1,j});
                }
            }
        }
        if(mat[i][j-1]!='.'){
            int wei;
            if(mat[i][j-1]==mat[i][j]){
                wei=0;
            }else{
                wei=1;
            }
            if(dist[i][j-1]>dist[i][j]+wei){
                dist[i][j-1]=dist[i][j]+wei;
                if(wei){
                    bfs.push_back({i,j-1});
                }else{
                    bfs.push_front({i,j-1});
                }
            }
        }
        if(mat[i][j+1]!='.'){
            int wei;
            if(mat[i][j+1]==mat[i][j]){
                wei=0;
            }else{
                wei=1;
            }
            if(dist[i][j+1]>dist[i][j]+wei){
                dist[i][j+1]=dist[i][j]+wei;
                if(wei){
                    bfs.push_back({i,j+1});
                }else{
                    bfs.push_front({i,j+1});
                }
            }
        }
    }
    dist[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mat[i][j]!='.'){
                maxi=max(maxi,dist[i][j]);
            }
        }
    }
    cout << maxi;
}