#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
vector<vector<int>> graph;
vector<ll> val;
vector<pair<ll,ll>> dp;
//tamaño,resp;
ll maxi=0;
void dfs(int now,int ante){
    dp[now].first=val[now];
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        dfs(u,now);
        dp[now].first+=dp[u].first;
        dp[now].second+=dp[u].second;
    }
    dp[now].second+=dp[now].first;
}
void change(int now,int ante){
    maxi=max(maxi,dp[now].second);
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        //intercambiar
        pair<ll,ll> temp=dp[u];
        dp[now].first-=dp[u].first;
        dp[now].second-=(dp[u].first+dp[u].second);
        dp[u].first+=dp[now].first;
        dp[u].second+=dp[now].second+dp[now].first;
        change(u,now);
        //volver
        dp[now].first+=temp.first;
        dp[now].second+=(temp.first+temp.second);
        dp[u]=temp;
    }
}
int main(){
    cin >> n;
    graph.resize(n);
    val.resize(n);
    dp.resize(n);
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    dfs(0,-1);
    change(0,-1);
    cout << maxi;
}
/*
2
1 2
1 2

5

4
1 2
1 3
3 4
2 3 2 1

23
*/