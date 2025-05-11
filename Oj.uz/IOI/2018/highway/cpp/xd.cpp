#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
vector<vector<pair<int,int>>> grafo;
vector<int> dist1,dist2,aske,corres,indice,final;
vector<int> vv,uu;
int n,m,ahora;
ll res,a,b;
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
    void answer(int s, int t) {
      if (answered) {
        wrong_answer("answered not exactly once");
      }
    
      if (!((s == S && t == T) || (s == T && t == S))) {
        wrong_pair = true;
      }
    
      answered = true;
    }
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