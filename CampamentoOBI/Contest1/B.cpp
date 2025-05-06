#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<pair<int,int>> graph[n+1];
    vector<int> dist(n+1,1e9);
    vector<bool> visited(n);
    while(m--){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dist[0]=0;
    priority_queue<pair<int,int>> cola;
    cola.push({0,0});
    while(!cola.empty()){
        int top=cola.top().second;cola.pop();
        if(visited[top]){
            continue;
        }
        visited[top]=true;
        for(auto u:graph[top]){
            if(dist[top]+u.second<dist[u.first]){
                dist[u.first]=dist[top]+u.second;
                cola.push({-dist[u.first],u.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]==1e9){
            cout << -1 << ' ';
        }else{
            cout << dist[i] << ' ';
        }
    }
}