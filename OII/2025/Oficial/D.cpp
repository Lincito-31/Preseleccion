#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,a,b,c;
ll suma,con,temp;
vector<pair<ll,ll>> graph[10000];
map<ll,ll> cant;
ll val[10000],padre[10000],deg[10000];
void dfss(ll now,ll ante){
    for(auto u:graph[now]){
        if(u.first!=ante){
            val[u.first]=u.second;
            padre[u.first]=now;
            dfss(u.first,now);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i=1;i<n;i++){
        cin >> a >> b >> c;
        graph[--a].push_back({--b,c});
        graph[b].push_back({a,c});
        deg[a]++;
        deg[b]++;
    }
    deg[0]++;
    dfss(0,-1);
    stack<pair<ll,ll>> dfs;
    vector<ll> vec;
    dfs.push({0,-1});
    while(!dfs.empty()){
        cant.clear();
        pair<ll,ll> x=dfs.top();
        dfs.pop();
        vec.push_back(x.first);
        suma+=val[x.first];
        temp=0;
        for(ll i=0;i<vec.size()-1;i++){
            temp+=val[vec[i]];
            con+=cant[2*temp-suma];
            cant[temp]++;
        }
        for(auto u:graph[x.first]){
            if(u.first!=x.second){
                dfs.push({u.first,x.first});
            }
        }
        while(vec.size()>0 && deg[vec.back()]==1){
            deg[padre[vec.back()]]--;
            suma-=val[vec.back()];
            vec.pop_back();
        }
    }
    cout << con;
}