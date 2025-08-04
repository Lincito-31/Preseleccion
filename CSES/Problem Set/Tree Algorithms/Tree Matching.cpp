#include <bits/stdc++.h>
using namespace std;
int n,a,b;
vector<int> graph[200000];
int res[200000][2];
void dfs(int now,int ante){
    for(auto u:graph[now]){
        if(u!=ante){
            dfs(u,now);
            res[now][0]+=res[u][1];
        }
    }
    for(auto u:graph[now]){
        if(u!=ante){
            res[now][1]=max(res[now][1],res[now][0]-res[u][1]+res[u][0]+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(--n){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    cout << max(res[0][0],res[0][1]);
}