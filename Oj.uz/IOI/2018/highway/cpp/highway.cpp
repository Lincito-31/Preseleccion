#include "highway.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
vector<bool> visited1,visited2,bfstree1,bfstree2;
vector<vector<pair<int,int>>> grafo;
vector<int> dist1,dist2,aske;
vector<pair<int,int>> padre1,padre2;
vector<int> vv,uu;
int n,m,global;
ll res,a,b;
void dfs(int now,int ante){
  for(auto u:grafo[now]){
    if(u.first==ante){
      continue;
    }
    padre2[u.first].first=now;
    padre2[u.first].second=u.second;
    dist2[u.first]=dist2[now]+1;
    dfs(u.first,now);
  }
}
int bs2(int xx,int ante){
  dist2.assign(n,-1);
  padre2.assign(n,{-1,-1});
  dist2[xx]=0;
  padre2[xx]={xx,-1};
  dfs(xx,ante);
  int con=0,con1=0;
  vector<int> aske111(aske),second(aske),nue,cop;
  for(int i=0;i<n;i++){
    if(dist2[i]>0){
      aske111[padre2[i].second]=0;
      nue.push_back(dist2[i]);
    }
    if(dist2[i]==0){
      nue.push_back(dist2[i]);
    }
  }
  if(nue.empty()){
    return xx;
  }
  sort(ALL(nue));
  cop.push_back(nue[0]);
  for(int i=1;i<nue.size();i++){
    if(nue[i]!=cop.back()){
      cop.push_back(nue[i]);
    }
  }
  nue=cop;
  ll noo=res;
  int iz=0,de=nue.size()-1;
  while(iz<de){
    int mid=(iz+de+1)>>1;
    for(int i=0;i<n;i++){
      if(dist2[i]==nue[mid]){
        second[padre2[i].second]=0;
      }
    }
    if(ask(second)==noo){
      for(int i=0;i<n;i++){
        if(dist2[i]==nue[mid]){
          second[padre2[i].second]=1;
        }
      }
      de=mid-1;
    }else{
      for(int i=0;i<n;i++){
        if(dist2[i]==nue[mid]){
          second[padre2[i].second]=1;
        }
      }
      iz=mid;
    }
  }
  ll ressss=nue[iz];
  ll resnow=res-ressss*(b-a);
  if(ressss==0){
    return xx;
  }
  vector<int> posibilidades;
  for(int i=0;i<n;i++){
    if(dist2[i]==ressss){
      posibilidades.push_back(i);
    }
  }
  iz=0,de=posibilidades.size()-1;
  while(iz<de){
    int mid=(iz+de)>>1;
    for(int i=iz;i<=mid;i++){
      aske111[padre2[posibilidades[i]].second]=1;
    }
    if(ask(aske111)!=resnow){
      for(int i=iz;i<=mid;i++){
        aske111[padre2[posibilidades[i]].second]=0;
      }
      de=mid;
    }else{
      iz=mid+1;
    }
  }
  return posibilidades[iz];
}
void find_pair(int N,vector<int> U,vector<int> V, int A, int B){
  a=A;b=B;n=N;
  m=U.size();
  grafo.resize(n);
  vv=V;uu=U;
  dist1.assign(n,-1);
  padre1.assign(n,{-1,-1});
  visited1.assign(n,false);
  bfstree1.assign(m,false);
  bfstree2=bfstree1;
  visited2=visited1;
  dist2=dist1;
  padre2=padre1;
  for(int i=0;i<m;i++){
    grafo[U[i]].push_back({V[i],i});
    grafo[V[i]].push_back({U[i],i});
  }
  aske.assign(m,0);
  res=ask(aske);
  int iz=0,de=m-1;
  while(iz<de){
    int mid=(iz+de)>>1;
    for(int i=iz;i<=mid;i++){
      aske[i]=1;
    }
    if(ask(aske)==res){
      iz=mid+1;
    }else{
      for(int i=iz;i<=mid;i++){
        aske[i]=0;
      }
      de=mid;
    }
  }
  int x=U[iz],y=V[iz];
  global=iz;
  aske.assign(m,1);
  aske[iz]=0;
  res/=a;
  res*=b;
  res+=-b+a;
  queue<int> bfs;
  bfs.push(x);
  dist1[x]=0;
  visited1[x]=true;
  bfs.push(y);
  dist1[y]=0;
  visited1[y]=true;
  while(!bfs.empty()){
    int now=bfs.front();
    bfs.pop();
    for(auto u:grafo[now]){
      if(visited1[u.first]){
        continue;
      }
      visited1[u.first]=true;
      dist1[u.first]=dist1[now]+1;
      padre1[u.first]={now,u.second};
      bfstree1[u.second]=true;
      bfs.push(u.first);
    }
  }
  grafo.clear();
  grafo.resize(n);
  for(int i=0;i<m;i++){
    if(bfstree1[i]){
      grafo[U[i]].push_back({V[i],i});
      grafo[V[i]].push_back({U[i],i});
    }
  }
  int i=bs2(x,y),j=bs2(y,x);
  answer(i,j);
}