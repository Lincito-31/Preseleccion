#include "highway.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
vector<vector<pair<int,int>>> grafo;
vector<int> dist;
vector<pair<int,int>> padre;
vector<int> vv,uu;
int n,m;
ll res,a,b;
void dfs(int now,int ante){
  for(auto u:grafo[now]){
    if(u.first==ante){
      continue;
    }
    padre[u.first].first=now;
    padre[u.first].second=u.second;
    dist[u.first]=dist[now]+1;
    dfs(u.first,now);
  }
}
int bs2(int xx,int ante){
  dist.assign(n,-1);
  padre.assign(n,{-1,-1});
  dist[xx]=0;
  padre[xx]={xx,-1};
  dfs(xx,ante);
  int con=0,con1=0;
  vector<int> aske(m,0),second;
  for(int i=0;i<n;i++){
    if(dist[i]>0){
      aske[padre[i].second]=1;
    }
  }
  ll ressss=(ask(aske)-res)/(b-a);
  if(ressss==0){
    return xx;
  }
  aske.assign(m,0);
  for(int i=0;i<n;i++){
    if(dist[i]==ressss){
      aske[padre[i].second]=1;
      con++;
    }
  }
  ll resnow=res-a+b;
  while(con>1){
    second=aske;
    con1=con;
    for(int i=0;i<m;i++){
      if(second[i] && con1>(con/2)){
        second[i]=0;
        con1--;
      }
    }
    if(ask(second)==resnow){
      aske=second;
      con=con1;
    }else{
      for(int i=0;i<m;i++){
        if(second[i]>0){
          aske[i]=0;
        }
      }
      con-=con1;
    }
  }
  for(int i=0;i<m;i++){
    if(aske[i]){
      if(padre[vv[i]].first==uu[i]){
        return vv[i];
      }else{
        return uu[i];
      }
    }
  }
}
void find_pair(int N,vector<int> U,vector<int> V, int A, int B){
  a=A;b=B;n=N;
  m=U.size();
  grafo.clear();
  grafo.resize(n);
  vv=V;
  uu=U;
  for(int i=0;i<m;i++){
    grafo[U[i]].push_back({V[i],i});
    grafo[V[i]].push_back({U[i],i});
  }
  vector<int> aske(m,0);
  res=ask(aske);
  int iz=0,de=m-1;
  while(iz<de){
    aske.assign(m,0);
    int mid=(iz+de)>>1;
    for(int i=iz;i<=mid;i++){
      aske[i]=1;
    }
    if(ask(aske)==res){
      iz=mid+1;
    }else{
      de=mid;
    }
  }
  int x=U[iz],y=V[iz];
  int i=bs2(x,y),j=bs2(y,x);
  answer(i,j);
}