#include <bits/stdc++.h>
#include "crocodile.h"
using namespace std;
typedef long long ll;
int travel_plan(int N,int M,int R[][2],int L[],int K,int P[]){
  vector<pair<ll,ll>> graph[N];
  vector<pair<ll,ll>> dist(N,{1e18,1e18});
  for(ll i=0;i<M;i++){
    graph[R[i][0]].push_back({R[i][1],L[i]});
    graph[R[i][1]].push_back({R[i][0],L[i]});
  }
  vector<bool> visited(N,false);
  priority_queue<pair<int,int>> dijs;
  for(int i=0;i<K;i++){
    dist[P[i]]={0,0};
    dijs.push({0,P[i]});
  }
  while(!dijs.empty()){
    ll x=dijs.top().second;
    dijs.pop();
    if(visited[x]){
      continue;
    }
    visited[x]=true;
    for(auto u:graph[x]){
      if(dist[u.first].first==1e18){
        dist[u.first].first=dist[x].second+u.second;
      }else if(dist[u.first].second==1e18){
        if(dist[u.first].first>dist[x].second+u.second){
          dist[u.first].second=dist[u.first].first;
          dist[u.first].first=dist[x].second+u.second;
        }else{
          dist[u.first].second=dist[x].second+u.second;
        }
        dijs.push({-dist[u.first].second,u.first});
        // enviar
      }else{
        if(dist[u.first].first>dist[x].second+u.second){
          dist[u.first].second=dist[u.first].first;
          dist[u.first].first=dist[x].second+u.second;
        }else if(dist[u.first].second>dist[x].second+u.second){
          dist[u.first].second=dist[x].second+u.second;
        }else{
          continue;
        }
        dijs.push({-dist[u.first].second,u.first});
        // enviar
      }
    }
  }
  return dist[0].second;
}