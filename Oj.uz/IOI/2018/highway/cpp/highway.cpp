#include "highway.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
vector<vector<pair<int,int>>> grafo;
vector<int> dist;
vector<pair<int,int>> padre;
int n,m;
ll res,nue=0,a,b;
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
int bs(int xx,int ante){
  dist.assign(n,-1);
  padre.assign(n,{-1,-1});
  dist[xx]=0;
  padre[xx]={xx,-1};
  dfs(xx,ante);
  vector<int> nuesort;
  for(int i=0;i<n;i++){
    if(dist[i]!=-1){
      nuesort.push_back(dist[i]);
    }
  }
  sort(ALL(nuesort));
  int nn=nuesort.size();
  int iz=0,de=nn-1,con=0,con1=0;
  while(iz<de){
    vector<int> aske(m,0);
    int mid=(iz+de+1)>>1;
    for(int i=0;i<n;i++){
      if(dist[i]==nuesort[mid]){
        aske[padre[i].second]=1;
      }
    }
    if(res==ask(aske)){
      //mas corto;
      de=mid-1;
      /*for(de=mid;de>=1 && dist[de]==dist[de+1];de--){}
      de--;*/
    }else{
      //tal vez mas largo
      iz=mid;
      //for(iz=mid;iz<nn-1 &&dist[iz]==dist[iz+1];iz++){}
    }
  }
  if(dist[iz]==0){
    return xx;
  }
  vector<int> aske(m,0),second;
  for(int i=0;i<n;i++){
    if(dist[i]==dist[iz]){
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
    nue=ask(second);
    if(nue==resnow){
      resnow=nue;
      aske=second;
      con=con1;
    }else{
      for(int i=0;i<m;i++){
        if(second[i]){
          aske[i]=0;
        }
      }
      con-=con1;
    }
  }
  return 0;
  /*for(int i=0;i<m;i++){
    if(aske[i]){
      for(int j=0;j<n;j++){
        if(padre[j].second==i){
          return j;
        }
      }
    }
  }*/
}
void find_pair(int N,vector<int> U,vector<int> V, int A, int B){
  a=a;b=b;n=N;
  m=U.size();
  grafo.clear();
  grafo.resize(n);
  dist.assign(n,-1);
  padre.assign(n,{-1,-1});
  for(int i=0;i<m;i++){
    grafo[U[i]].push_back({V[i],i});
    grafo[V[i]].push_back({U[i],i});
  }
  vector<int> aske(m,0);
  res=ask(aske);
  int iz=0,de=m-1;
  while(iz<de){
    int mid=(iz+de)>>1;
    for(int i=iz;i<=mid;i++){
      aske[i]=1;
    }
    if(ask(aske)==res){
      for(int i=iz;i<=mid;i++){
        aske[i]=0;
      }
      iz=mid+1;
    }else{
      for(int i=iz;i<=mid;i++){
        aske[i]=0;
      }
      de=mid;
    }
  }
  dist[0]=0;
  padre[0]={0,0};
  dfs(0,-1);
  int x,y;
  for(int i=0;i<n;i++){
    if(padre[i].second==iz){
      x=i;
      y=padre[i].first;
    }
  }
  answer(bs(x,y),bs(y,x));
}
