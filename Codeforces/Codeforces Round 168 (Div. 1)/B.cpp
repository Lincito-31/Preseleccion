#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b,maxi=0,mini=0;
vector<vector<ll>> graph;
vector<ll> val;
vector<pair<ll,ll>> dp;
pair<ll,ll> operator +(pair<ll,ll> x,pair<ll,ll> y){
    return make_pair(max(x.first,y.first),max(x.second,y.second));
}
pair<ll,ll> dfs(int now,int ante){
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        dp[now]=dp[now]+dfs(u,now);
    }
    val[now]+=+dp[now].first-dp[now].second;
    if(val[now]>0){
        dp[now].second+=val[now];
    }else{
        dp[now].first-=val[now];
    }
    maxi=max(maxi,dp[now].first);
    mini=max(mini,dp[now].second);
    return dp[now];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    graph.resize(n);
    val.resize(n);
    dp.assign(n,{0,0});
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        cin >> val[i];
    }
    dfs(0,-1);
    cout << (ll)(maxi+mini);
}