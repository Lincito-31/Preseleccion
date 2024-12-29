#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
ll t,n,m,a,b,c;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        vector<vpll> graph(n);
        vll slowness(n);
        while(m--){
            scanf("%lld%lld%lld",&a,&b,&c);
            a--;b--;
            graph[a].push_back({b,c});
            graph[b].push_back({a,c});
        }
        for(int i=0;i<n;i++){
            scanf("%lld",&slowness[i]);
        }
        vector<vll> time(n,vll(n,1e18));
        time[0][0]=0;
        priority_queue<vll> dijk;
        dijk.push({0,0,0});
        while(!dijk.empty()){
            vll top=dijk.top();
            dijk.pop();
            ll tiempo=-top[0],nodo=top[1],bici=top[2];
            for(auto u:graph[nodo]){
                if(tiempo+u.second*slowness[bici]<time[u.first][bici]){
                    time[u.first][bici]=tiempo+u.second*slowness[bici];
                    if(slowness[bici]<=slowness[u.first]){
                        dijk.push({-time[u.first][bici],u.first,bici});
                    }else{
                        dijk.push({-time[u.first][bici],u.first,u.first});
                    }
                }
            }
        }
        ll mini=1e18;
        for(auto u:time.back()){
            mini=min(u,mini);
        }
        printf("%lld\n",mini);
    }
}