#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
vector<ll> graph[200000];
ll hiji[200000],sum[200000],res[200000];
void dfs(ll now,ll ante){
    hiji[now]=1;
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        dfs(u,now);
        hiji[now]+=hiji[u];
        sum[now]+=sum[u];
        sum[now]+=hiji[u];
    }
}
void reroot(ll now,ll ante){
    res[now]=sum[now];
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        ll tempsumnow=sum[now];
        ll tempsumu=sum[u];
        ll temphijinow=hiji[now];
        ll temphijiu=hiji[u];
        sum[now]-=sum[u];
        sum[now]-=hiji[u];
        hiji[now]-=hiji[u];
        hiji[u]+=hiji[now];
        sum[u]+=sum[now];
        sum[u]+=hiji[now];
        reroot(u,now);
        sum[now]=tempsumnow;
        sum[u]=tempsumu;
        hiji[now]=temphijinow;
        hiji[u]=temphijiu;
    }
}
int main(){
    cin >> n;
    for(ll i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    reroot(0,-1);
    for(ll i=0;i<n;i++){
        cout << res[i] << ' ';
    }
}