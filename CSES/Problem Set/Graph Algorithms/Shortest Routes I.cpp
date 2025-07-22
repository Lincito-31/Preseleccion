#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
ll n,m,a,b,q,c;
vector<pair<ll,ll>> graph[100000];
ll dist[100000];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c;
        graph[--a].push_back({--b,c});
    }
    for(ll j=0;j<n;j++){
        dist[j]=1e18;
    }
    dist[0]=0;
        priority_queue<pair<ll,ll>> dijs;
        dijs.push({0,0});
        while(!dijs.empty()){
            ll top=dijs.top().second;
            ll distan=-dijs.top().first;
            dijs.pop();
            if(dist[top]<distan){
                continue;
            }
            for(auto u:graph[top]){
                if(dist[u.first]>dist[top]+u.second){
                    dist[u.first]=dist[top]+u.second;
                    dijs.push({-dist[u.first],u.first});
                }
            }
        }
    for(ll i=0;i<n;i++){
        cout << dist[i] << ' ';
    }
}