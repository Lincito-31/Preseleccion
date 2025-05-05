#include "highway.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>> graph[90001];
vector<ll> dist(90001,0);
vector<pair<ll,ll>> padre(90001,{0,0});
void dfs(ll now,ll ante){
  for(auto u:graph[now]){
    if(u.first==ante){
      continue;
    }
    padre[u.first].first=now;
    padre[u.first].second=u.second;
    dist[u.first]=dist[now]+1;
  }
}
void find_pair(int N,vector<int> U,vector<int> V, int A, int B){
  ll M = U.size();
  for(ll i=0;i<M;i++){
    graph[U[i]].push_back({V[i],i});
    graph[V[i]].push_back({U[i],i});
  }
  dist[0]=0;
  padre[0]={0,0};
  dfs(0,-1);
  vector<int> aske(M,0);
  ll res=ask(aske);
  ll nue=0;
  for(ll i=1;i<N;i++){
    if(dist[i]==(ll)(res/A)){
      aske[padre[i].second]=1;
      nue=ask(aske);
      if(nue!=res){
        answer(0,i);
        return;
      }
    }
  }
}
