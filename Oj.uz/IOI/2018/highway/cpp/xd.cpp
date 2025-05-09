#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
vector<bool> visited1,visited2,bfstree1,bfstree2;
vector<vector<pair<int,int>>> grafo;
vector<int> dist1,dist2,aske;
vector<pair<int,int>> padre1,padre2;
vector<int> vv,uu;
int n,m;
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
      vector<int> aske111(aske),second;
      for(int i=0;i<n;i++){
        if(dist2[i]>0){
          aske111[padre2[i].second]=0;
        }
      }
      ll ressss=(res-ask(aske111))/(b-a);
      if(ressss==0){
        return xx;
      }
      vector<int> posibilidades;
      for(int i=0;i<n;i++){
        if(dist2[i]==ressss){
          posibilidades.push_back(i);
        }
      }
      ll resnow=res;
      int iz=0,de=posibilidades.size()-1;
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
      if(padre2[vv[posibilidades[iz]]].first==uu[posibilidades[iz]]){
        return vv[posibilidades[iz]];
      }else{
        return uu[posibilidades[iz]];
      }
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