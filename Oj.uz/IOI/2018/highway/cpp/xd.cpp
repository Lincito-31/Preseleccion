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
namespace {

    constexpr int MAX_NUM_CALLS = 100;
    constexpr long long INF = 1LL << 61;
    
    int N, M, A, B, S, T;
    std::vector<int> U, V;
    std::vector<std::vector<std::pair<int, int>>> graph;
    
    bool answered, wrong_pair;
    int num_calls;
    
    int read_int() {
      int x;
      if (scanf("%d", &x) != 1) {
        fprintf(stderr, "Error while reading input\n");
        exit(1);
      }
      return x;
    }
    
    void wrong_answer(const char *MSG) {
      printf("Wrong Answer: %s\n", MSG);
      exit(0);
    }
    
    }  // namespace
    
    long long ask(const std::vector<int> &w) {
      if (++num_calls > MAX_NUM_CALLS) {
        wrong_answer("more than 100 calls to ask");
      }
      if (w.size() != (size_t)M) {
        wrong_answer("w is invalid");
      }
      for (size_t i = 0; i < w.size(); ++i) {
        if (!(w[i] == 0 || w[i] == 1)) {
          wrong_answer("w is invalid");
        }
      }
    
      std::vector<bool> visited(N, false);
      std::vector<long long> current_dist(N, INF);
      std::queue<int> qa, qb;
      qa.push(S);
      current_dist[S] = 0;
      while (!qa.empty() || !qb.empty()) {
        int v;
        if (qb.empty() ||
            (!qa.empty() && current_dist[qa.front()] <= current_dist[qb.front()])) {
          v = qa.front();
          qa.pop();
        } else {
          v = qb.front();
          qb.pop();
        }
        if (visited[v]) {
          continue;
        }
        visited[v] = true;
        long long d = current_dist[v];
        if (v == T) {
          return d;
        }
        for (auto e : graph[v]) {
          int vv = e.first;
          int ei = e.second;
          if (!visited[vv]) {
            if (w[ei] == 0) {
              if (current_dist[vv] > d + A) {
                current_dist[vv] = d + A;
                qa.push(vv);
              }
            } else {
              if (current_dist[vv] > d + B) {
                current_dist[vv] = d + B;
                qb.push(vv);
              }
            }
          }
        }
      }
      return -1;
    }
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
  /*dist[xx]=0;
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
      //for(de=mid;de>=1 && dist[de]==dist[de+1];de--){}
      //de--;
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
  }*/
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
    void answer(int s, int t) {
      if (answered) {
        wrong_answer("answered not exactly once");
      }
    
      if (!((s == S && t == T) || (s == T && t == S))) {
        wrong_pair = true;
      }
    
      answered = true;
    }
    
    int main() {
      N = read_int();
      M = read_int();
      A = read_int();
      B = read_int();
      S = read_int();
      T = read_int();
      U.resize(M);
      V.resize(M);
      graph.assign(N, std::vector<std::pair<int, int>>());
      for (int i = 0; i < M; ++i) {
        U[i] = read_int();
        V[i] = read_int();
        graph[U[i]].push_back({V[i], i});
        graph[V[i]].push_back({U[i], i});
      }
    
      answered = false;
      wrong_pair = false;
      num_calls = 0;
      find_pair(N, U, V, A, B);
      if (!answered) {
        wrong_answer("answered not exactly once");
      }
      if (wrong_pair) {
        wrong_answer("{s, t} is wrong");
      }
      printf("Accepted: %d\n", num_calls);
      return 0;
    }
    