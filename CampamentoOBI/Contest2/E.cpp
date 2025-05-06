#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,S,Q,E,a,b,c;
vector<vector<pair<ll,ll>>> graph;
vector<pair<ll,ll>> lista;
vector<ll> alt,dp;
vector<vector<ll>> padre,dist,resp;
vector<bool> shop;
ll dfs(int now,int ante){
    for(int i=1;i<20;i++){
        padre[now][i]=padre[padre[now][i-1]][i-1];
        dist[now][i]=dist[now][i-1]+dist[padre[now][i-1]][i-1];
    }
    if(shop[now]){
        dp[now]=0;
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
void calc(int now,int ante){
    resp[now][0]=dp[padre[now][0]]+dist[now][0];
    for(int i=1;i<20;i++){
        resp[now][i]=min(resp[now][i-1],dist[now][i-1]+resp[padre[now][i-1]][i-1]);
    }
    for(auto u:graph[now]){
        if(u.first==ante){
            continue;
        }
        calc(u.first,now);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> S >> Q >> E;
    E--;
    graph.resize(N);
    lista.resize(N);
    shop.resize(N);
    alt.resize(N);
    dp.assign(N,1e18);
    padre.assign(N,vector<ll>(20));
    dist=resp=padre;
    for(int i=0;i<N-1;i++){
        cin >> a >> b >> c;
        lista[i]={--a,--b};
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    while(S--){
        cin >> a;
        shop[--a]=true;
    }
    padre[E][0]=E;
    dfs(E,-1);
    calc(E,-1);
    /*for(int i=0;i<N;i++){
        for(int j=0;j<5;j++){
            cout << padre[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(int i=0;i<N;i++){
        for(int j=0;j<5;j++){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(int i=0;i<N;i++){
        cout << dp[i] << ' ';
    }
    cout << '\n';
    for(int i=0;i<N;i++){
        for(int j=0;j<5;j++){
            cout << resp[i][j] << ' ';
        }
        cout << '\n';
    }*/
    while(Q--){
        cin >> a >> b;
        a--;
        ll desapar;
        if(alt[lista[a].first]<alt[lista[a].second]){
            desapar=lista[a].second;
        }else{
            desapar=lista[a].first;
        }
        ll x=--b;
        if(alt[x]<alt[desapar]){
            cout << "escaped\n";
        }else{
            ll diferen=alt[x]-alt[desapar];
            for(int i=20;i>=0;i--){
                if(diferen&(1<<i)){
                    x=padre[x][i];
                }
            }
            if(x!=desapar){
                cout << "escaped\n";
            }else{
                ll respue=dp[b],tempdist=0;
                x=b;
                for(int i=20;i>=0;i--){
                    if(diferen&(1<<i)){
                        respue=min(respue,tempdist+resp[x][i]);
                        tempdist+=dist[x][i];
                        x=padre[x][i];
                    }
                }
                if(respue==1e18){
                    cout << "oo\n";
                }else{
                    cout << respue << '\n';
                }
            }
        }
    }
}
/*
5 2 3 1
1 2 3
1 3 2
3 4 1
3 5 2
2
4
2 2
2 5
4 5

escaped
3
oo

*/