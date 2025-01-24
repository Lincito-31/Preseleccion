#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
vector<vector<ll>> graph;
vector<ll> degree;
vector<vector<ll>> dp;
ll solve(ll now,ll cantiadja,ll dia,ll res,ll ante){
    if(dia>=n){
        return res;
    }
    if(dp[now][dia]!=-1e9){
        return dp[now][dia];
    }
    res=max(res,((cantiadja-1)/dia)+1);
    for(auto u:graph[now]){
        if(u==ante){
            res=max(solve(u,cantiadja,dia+1,res,now),res);
        }else{
            res=max(solve(u,cantiadja+degree[u]-1,dia+1,res,now),res);
        }
    }
    return dp[now][dia]=res;
}
int main(){
    scanf("%lld",&n);
    graph.resize(n);
    dp.assign(n,vector<ll>(n,-1e9));
    degree.assign(n,0);
    for(int i=1;i<n;i++){
        scanf("%lld%lld",&a,&b);
        a--;b--;
        degree[a]++;degree[b]++;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    printf("%lld",solve(0,degree[0],1,0,-1));
}