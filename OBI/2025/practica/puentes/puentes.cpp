#include <bits/stdc++.h>
using namespace std;
int n,m,con,tiempo,a,b;
vector<int> graph[100005];
pair<int,int> timee[100005];
bool visited[100005];
void dfs(int now,int ante){
    visited[now]=true;
    timee[now].second=timee[now].first=++tiempo;
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        if(visited[u]){
            timee[now].second=min(timee[now].second,timee[u].first);
        }else{
            dfs(u,now);
            timee[now].second=min(timee[now].second,timee[u].second);
            if(timee[now].first<timee[u].second){
                con++;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(visited[i]){
            continue;
        }
        dfs(i,-1);
    }
    cout << con;
}