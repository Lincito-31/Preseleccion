#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> llset;
int t=1,n,b;
ll sum,pref,a;
vector<vi> graph;
vll alt,contaalt;
ll dfs(int now,int ante){
    ll cant_hij=0;
    for(auto u:graph[now]){
        if(u!=ante){
            contaalt[alt[u]=alt[now]+1]++;
            sum-=(a=dfs(u,now))*cant_hij*2*alt[now];
            cant_hij+=a;
        }
    }
    if(alt[now]!=0){
        sum-=(2*alt[now]-1)*cant_hij;
    }
    return ++cant_hij;
}
int main(){
    FASTIO;
    cin >> t;
    while(t--){
        sum=pref=0;
        graph.clear();
        alt.clear();
        cin >> n;
        graph.resize(n);
        alt.resize(n);
        contaalt=alt;
        for(int i=1;i<n;i++){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        dfs(0,-1);
        for(int i=n-1;i>=1;i--){
            sum+=(2*i-1)*(contaalt[i]*pref+contaalt[i]*(contaalt[i]-1)/2);
            pref+=contaalt[i];
        }
        cout << sum << '\n';
    }
}
