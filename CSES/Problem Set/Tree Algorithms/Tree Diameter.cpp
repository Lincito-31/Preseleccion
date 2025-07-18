#include <bits/stdc++.h>
using namespace std;
int n,a,b;
vector<int> graph[200000];
int dist[200000];
void dfs(int now,int ante){
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        dist[u]=dist[now]+1;
        dfs(u,now);
    }
}
int main(){
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    int maxi=0;
    for(int i=0;i<n;i++){
        if(dist[maxi]<dist[i]){
            maxi=i;
        }
    }
    for(int i=0;i<n;i++){
        dist[i]=0;
    }
    dfs(maxi,-1);
    maxi=0;
    for(int i=0;i<n;i++){
        if(dist[maxi]<dist[i]){
            maxi=i;
        }
    }
    cout << dist[maxi];
}