#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
vector<vector<ll>> graph;
ll degree[300000];
bool solve(ll now,ll ante,ll cantitrab,ll cadadia){
    if(degree[now]-1>cantitrab){
        return false;
    }
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        if(!solve(u,now,cantitrab-(degree[now]-1)+cadadia,cadadia)){
            return false;
        }
    }
    return true;
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
    while(l<r){
        ll mid=(l+r)>>1;
        if(solve(0,-1,mid,mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%lld",l);
}