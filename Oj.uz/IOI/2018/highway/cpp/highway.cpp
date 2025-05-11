#include "highway.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
vector<vector<pair<int,int>>> grafo;
vector<int> dist1,dist2,aske,corres,indice,final;
vector<int> vv,uu;
int n,m,ahora;
ll res,a,b;
int bs2(){
  int iz=-1,de=ahora-1;
  while(iz<de){
    int mid=(iz+de+1)>>1;
    for(int i=0;i<m;i++){
      if(corres[i]>=mid){
        aske[i]=1;
      }else{
        aske[i]=0;
      }
    }
    if(ask(aske)!=res){
      iz=mid;
    }else{
      de=mid-1;
    }
  }
  return iz;
}
void find_pair(int N,vector<int> U,vector<int> V, int A, int B){
  a=A;b=B;n=N;
  m=U.size();
  grafo.resize(n);
  vv=V;uu=U;
  dist1.assign(n,-1);
  dist2=dist1;
  for(int i=0;i<m;i++){
    grafo[U[i]].push_back({V[i],i});
    grafo[V[i]].push_back({U[i],i});
  }
  aske.assign(m,0);
  res=ask(aske);
  int iz=0,de=m-1;
  while(iz<de){
    int mid=(iz+de)>>1;
    for(int i=0;i<m;i++){
      if(i<=mid){
        aske[i]=1;
      }else{
        aske[i]=0;
      }
    }
    if(ask(aske)==res){
      iz=mid+1;
    }else{
      de=mid;
    }
  }
  int x=U[iz],y=V[iz];
  dist1[x]=0;
  dist2[y]=0;
  queue<int> bfs;
  bfs.push(x);
  while(!bfs.empty()){
    int top=bfs.front();bfs.pop();
    for(auto u:grafo[top]){
      if(dist1[u.first]!=-1){
        continue;
      }
      dist1[u.first]=dist1[top]+1;
      bfs.push(u.first);
    }
  }
  bfs.push(y);
  while(!bfs.empty()){
    int top=bfs.front();bfs.pop();
    for(auto u:grafo[top]){
      if(dist2[u.first]!=-1){
        continue;
      }
      dist2[u.first]=dist2[top]+1;
      bfs.push(u.first);
    }
  }
  corres.assign(m,-1);
  indice.assign(n,0);
  final.assign(n,-1);
  final[x]=0;
  ahora=0;
  bfs.push(x);
  while(!bfs.empty()){
    int top=bfs.front();bfs.pop();
    for(auto u:grafo[top]){
      if(dist1[u.first]<dist2[u.first]){
        if(final[u.first]==-1){
          final[u.first]=final[top]+1;
          indice[ahora]=u.first;
          corres[u.second]=ahora++;
          bfs.push(u.first);
        }else if(final[u.first]==final[top]+1){
          corres[u.second]=n;
        }
      }else if(u.second!=iz){
        corres[u.second]=n;
      }
    }
  }
  int i=bs2();
  if(i==-1){
    i=x;
  }else{
    i=indice[i];
  }
  corres.assign(m,-1);
  indice.assign(n,0);
  final.assign(n,-1);
  final[y]=0;
  ahora=0;
  bfs.push(y);
  while(!bfs.empty()){
    int top=bfs.front();bfs.pop();
    for(auto u:grafo[top]){
      if(dist2[u.first]<dist1[u.first]){
        if(final[u.first]==-1){
          final[u.first]=final[top]+1;
          indice[ahora]=u.first;
          corres[u.second]=ahora++;
          bfs.push(u.first);
        }else if(final[u.first]==final[top]+1){
          corres[u.second]=n;
        }
      }else if(u.second!=iz){
        corres[u.second]=n;
      }
    }
  }
  int j=bs2();
  if(j==-1){
    j=y;
  }else{
    j=indice[j];
  }
  answer(i,j);
}