#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int N,Q,E,S,a,b,w;
vector<bool> shop;
vector<ll> dp;
vector<pair<ll,ll>> lista;
vector<vector<pair<ll,ll>>> graph;
vector<vector<ll>> padre,dist,resp;
vector<int> alt;
void solve(int now,int ante){
    resp[now][0]=dp[padre[now][0]]+dist[now][0];
    for(int i=1;i<20;i++){
        resp[now][i]=min(resp[now][i-1],resp[padre[now][i-1]][i-1]+dist[now][i-1]);
    }
    for(auto u:graph[now]){
        if(u.first==ante){
            continue;
        }
        solve(u.first,now);
    }
}
ll dfs(int now,int ante){
    if(shop[now]){
        dp[now]=0;
    }
    for(int i=1;i<20;i++){
        padre[now][i]=padre[padre[now][i-1]][i-1];
        dist[now][i]=dist[now][i-1]+dist[padre[now][i-1]][i-1];
    }
    for(auto u:graph[now]){
        if(u.first==ante){
            continue;
        }
        alt[u.first]=alt[now]+1;
        padre[u.first][0]=now;
        dist[u.first][0]=u.second;
        dp[now]=min(dp[now],dfs(u.first,now)+u.second);
    }
    return dp[now];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> S >> Q >> E;
    graph.resize(N);
    shop.resize(N);
    alt.resize(N);
    dp.assign(N,1e18);
    padre.assign(N,vector<ll>(20));
    lista.resize(N);
    dist=resp=padre;
    for(int i=1;i<N;i++){
        cin >> a >> b >> w;
        graph[--a].push_back({--b,w});
        graph[b].push_back({a,w});
        lista[i-1]={a,b};
    }
    while(S--){
        cin >> a;
        shop[--a]=true;
    }
    alt[--E]=0;
    padre[E][0]=E;
    dfs(E,-1);
    solve(E,-1);
    while(Q--){
        cin >> a >> b;
        int nododesa;
        a--;
        if(alt[lista[a].first]<alt[lista[a].second]){
            nododesa=lista[a].second;
        }else{
            nododesa=lista[a].first;
        }
        int x=--b;
        int y=nododesa;
        if(alt[x]<alt[y]){
            cout << "escaped\n";
            continue;
        }
        int dif=alt[x]-alt[y];
        for(int i=20;i>=0;i--){
            if(dif&(1<<i)){
                x=padre[x][i];
            }
        }
        if(x==y){
            //no se escapa
            ll op2=1e18;
            x=b;
            ll op1=dp[x];
            ll tempdist=0;
            for(int i=20;i>=0;i--){
                if(dif&(1<<i)){
                    op2=min(op2,tempdist+resp[x][i]);
                    tempdist+=dist[x][i];
                    x=padre[x][i];
                }
            }
            if(min(op1,op2)==1e18){
                cout << "oo\n";
            }else{
                cout << min(op1,op2) << "\n";
            }
        }else{
            cout << "escaped\n";
        }
    }
}