#include "doll.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
vector<vector<int>> graph;
vector<int> to;
int swit=1,nextava=1;
vector<pair<int,int>> to_swit;
ll potencia(ll x,ll y){
  ll res=1;
  for(int i=0;i<y;i++){
    res*=x;
  }
  return res;
}
void create_circuit(int M,vector<int>A){
  int N=A.size();
  graph.resize(M+1);
  to.resize(M+1);
  to[0]=A[0];
  graph[0].push_back(A[0]);
  for(int i=0;i<N-1;i++){
    graph[A[i]].push_back(A[i+1]);
  }
  graph[A[N-1]].push_back(0);
  // u¿crear uno vacio
  to_swit.push_back({0,0});
  for(int i=0;i<=M;i++){
    if(graph[i].size()==1){
      to[i]=graph[i][0];
    }else if(graph[i].size()>1){
      //usar switch
      //asegurar que cada uno use una cantidad par;
      int tam=log2(graph[i].size()-1)+1;
      ll power=potencia(2,tam);
      reverse(ALL(graph[i]));
      while(graph[i].size()<power){
        graph[i].push_back(-swit);
      }
      reverse(ALL(graph[i]));
      to[i]=-swit;
      nextava++;
      queue<pair<int,int>> bfs1;
      //la distancia, suma de bit
      bfs1.push({0,0});
      while(!bfs1.empty()){
        pair<int,int> top=bfs1.front();
        bfs1.pop();
        if(top.first==tam-1){
          int primer=-swit,segundo=-swit;
          if(top.second<graph[i].size()){
            primer=graph[i][top.second];
          }
          if(top.second+(1<<top.first)<graph[i].size()){
            segundo=graph[i][top.second+(1<<top.first)];
          }
          to_swit.push_back({primer,segundo});
          // llego a la distancia;
        }else{
          to_swit.push_back({-(nextava),-(nextava+1)});
          nextava+=2;
          bfs1.push({top.first+1,top.second});
          bfs1.push({top.first+1,top.second+(1<<top.first)});
        }
        swit++;
      }
    }
  }
  for(int i=1;i<=to_swit.size();i++){
    if(to_swit[i].second==-i){
      swap(to_swit[i].second,to_swit[i].first);
    }
  }
  vector<int> x(to_swit.size()-1),y(to_swit.size()-1);
  for(int i=1;i<to_swit.size();i++){
    x[i-1]=to_swit[i].first;
    y[i-1]=to_swit[i].second;
  }
  answer(to,x,y);
}
