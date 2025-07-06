#include <bits/stdc++.h>
using namespace std;
int n,m,q,a,b,c;
vector<int> dist[100000][11];
bitset<100000> visited;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<int> graph[n],colors(n);
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        visited=0;
        visited[i]=1;
        queue<pair<int,int>> bfs;
        bfs.push({i,0});
        while(!bfs.empty()){
            pair<int,int> top=bfs.front();
            bfs.pop();
            dist[i][top.second].push_back(top.first);
            for(auto u:graph[top.first]){
                if(!visited[u] && top.second+1<=10){
                    visited[u]=true;
                    bfs.push({u,top.second+1});
                }
            }
        }
    }
}