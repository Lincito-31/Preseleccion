#include <bits/stdc++.h>
using namespace std;
int n,a,b,m;
vector<pair<int,int>> graph[200000];
bool visited[200000],usededge[200000];
vector<pair<int,int>> res;
int outdeg[200000];
void dfs(int now,int ante){
    visited[now]=true;
    for(auto u:graph[now]){
        if(u.first==ante || usededge[u.second]){
            continue;
        }
        if(visited[u.first]){
            res.push_back({now,u.first});
            //cout << now << ' ' << u.first << '\n';
            outdeg[now]++;
            usededge[u.second]=true;
            continue;
        }
        dfs(u.first,now);
        if(outdeg[u.first]%2){
            outdeg[u.first]++;
            res.push_back({u.first,now});
            usededge[u.second]=true;
            //cout << u.first << ' ' << now << '\n';
        }else{
            outdeg[now]++;
            res.push_back({now,u.first});
            usededge[u.second]=true;
            //cout << now << ' ' << u.first << '\n';
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[--a].push_back({--b,i});
        graph[b].push_back({a,i});
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,-1);
            if(outdeg[i]%2){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for(auto u:res){
        cout << u.first+1 << ' ' << u.second+1 << '\n';
    }
}