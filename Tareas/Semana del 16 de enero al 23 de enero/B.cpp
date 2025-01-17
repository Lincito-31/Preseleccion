#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
vector<vector<ll>> graph;
ll degree[300000];
int solve(ll now,ll cantitrab,ll cadadia,ll dia){
    while(degree[now]-1>cantitrab){
        cadadia++;
        cantitrab+=dia;
    }
    for(auto u:graph[now]){
        if(!solve(u,now,cantitrab-(degree[now]-1)+cadadia,cadadia)){
            return false;
        }
    }
    
}
int main(){
    scanf("%lld",&n);
    graph.resize(n);
    ll l=0,r=n;
    while(--n){
        scanf("%lld%lld",&a,&b);
        a--;b--;
        degree[a]++;degree[b]++;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    degree[0]++;
    ll l=solve(0,0,0,1);
    printf("%lld",l);
}