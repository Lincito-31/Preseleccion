#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ALL(x) x.begin(),x.end()
#define lsone(x) (x)&(-x)
ll n,q,a,b,c,id;
vector<vector<ll>> val;
// id, valor y tamaños del subtree;
vector<vector<int>> graph;
struct BIT{
    vector<ll> fenwick;
    ll N;
    BIT(ll n){
        N=n;
        fenwick.resize(N+1);
    }
    void update(ll x,ll val){
        while(x<=N){
            fenwick[x]+=val;
            x+=lsone(x);
        }
    }
    ll sum(ll x){
        ll suma=0;
        while(x>0){
            suma+=fenwick[x];
            x-=lsone(x);
        }
        return suma;
    }
};
void dfs(int now,int ante){
    val[now][0]=++id;
    for(auto u:graph[now]){
        if(u!=ante){
            dfs(u,now);
            val[now][2]+=val[u][2];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    val.assign(n+1,{0,0,1});
    graph.resize(n+1);
    BIT fenwick(n+1);
    for(int i=1;i<=n;i++){
        cin >> val[i][1];
    }
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        fenwick.update(val[i][0],val[i][1]);
    }
    while(q--){
        cin >> a;
        if(a==1){
            cin >> b >> c;
            fenwick.update(val[b][0],c-val[b][1]);
            val[b][1]=c;
        }else{
            cin >> b;
            cout << fenwick.sum(val[b][0]+val[b][2]-1)-fenwick.sum(val[b][0]-1) << '\n';
        }
    }
}