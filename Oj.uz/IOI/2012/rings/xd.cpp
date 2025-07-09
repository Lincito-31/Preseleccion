#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int N,canticriti,asegu=-1,deberia,target;
vector<int> degree,dsu,posibilidad,cantiposi;
vector<vector<int>> graph;
vector<pair<int,int>> unidos;
vector<int> nums_del_dfs;
vector<bool> visitado;
map<vector<int>,bool> examinado;
void dfs(int now,int ante){
  if(now==target){
    //procesar;
    vector<int> copia(nums_del_dfs);
    sort(ALL(copia));
    if(!examinado[copia]){
      examinado[copia]=true;
      for(int i=0;i<copia.size();i++){
        posibilidad[copia[i]]++;
        cantiposi[posibilidad[copia[i]]]++;
      }
      deberia++;
    }
    return;
  }
  for(auto u:graph[now]){
    if(u==ante || visitado[u]){
      continue;
    }
    nums_del_dfs.push_back(u);
    visitado[u]=true;
    dfs(u,now);
    nums_del_dfs.pop_back();
    visitado[u]=false;
  }
}
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
bool unite(int x,int y){
  if((x=find(x))==(y=find(y))){
    return false;
  }
  dsu[x]=y;
  return true;
}
void Init(int N_){
  deberia=0;
  cantiposi.clear();
  degree.clear();
  dsu.clear();
  graph.resize((canticriti=N=N_)+5);
  degree.resize(N+5);
  dsu.resize(N+5);
  cantiposi.resize(N+5);
  posibilidad.resize(N+5);
  cantiposi[0]=N;
  for(int i=0;i<N;i++){
    dsu[i]=i;
  }
}
void reinicar(){
  Init(N);
  for(auto u:unidos){
    if(u.first==asegu || u.second==asegu){
      continue;
    }
    degree[u.first]++;
    degree[u.second]++;
    graph[u.first].push_back(u.second);
    graph[u.second].push_back(u.first);
    if(degree[u.first]>2 || degree[u.second]>2 || !unite(u.first,u.second)){
      canticriti=0;
      return;
    }
  }
  canticriti=1;
}
void Link(int A,int B){
  if(canticriti==0){
    return;
  }
  if(asegu!=-1){
    if(asegu!=A && asegu!=B){
      degree[A]++;
      degree[B]++;
      if(degree[A]>2 || degree[B]>2 || !unite(A,B)){
        canticriti=0;
        return;
      }
    }
  }else{
    unidos.push_back({min(A,B),max(A,B)});
    degree[A]++;
    degree[B]++;
    graph[A].push_back(B);
    graph[B].push_back(A);
    if(!unite(A,B)){
      // hacer un BUEN dfs();
      visitado.clear();
      nums_del_dfs.clear();
      visitado.resize(N);
      nums_del_dfs.push_back(A);
      visitado[A]=true;
      target=B;
      dfs(A,B);
    }
    if(degree[A]>=4){
      posibilidad[A]++;
      cantiposi[posibilidad[A]]++;
      deberia++;
    }
    if(degree[B]>=4){
      posibilidad[B]++;
      cantiposi[posibilidad[B]]++;
      deberia++;
    }
    if(degree[A]==3){
      for(auto u:graph[A]){
        posibilidad[u]++;
        cantiposi[posibilidad[u]]++;
      }
      posibilidad[A]++;
      cantiposi[posibilidad[A]]++;
      deberia++;
    }
    if(degree[B]==3){
      for(auto u:graph[B]){
        posibilidad[u]++;
        cantiposi[posibilidad[u]]++;
      }
      posibilidad[B]++;
      cantiposi[posibilidad[B]]++;
      deberia++;
    }
    if(cantiposi[deberia]==1){
      for(int i=0;i<N;i++){
        if(posibilidad[i]==deberia){
          asegu=i;
          reinicar();
          return;
        }
      }
    }
    canticriti=cantiposi[deberia];
    return;
  }
}
int CountCritical(){return canticriti;}

#define inbuf_len 1 << 16
#define outbuf_len 1 << 16

void Init(int N);
int CountCritical();
void Link(int a, int b);

int main() {
  int tmp;

  /* Set input and output buffering */
  char *inbuf, *outbuf;
  inbuf = (char*) malloc(inbuf_len * sizeof(char));
  outbuf = (char*) malloc(outbuf_len * sizeof(char));
  tmp = setvbuf(stdin, inbuf, _IOFBF, inbuf_len);
  tmp = setvbuf(stdout, outbuf, _IOFBF, outbuf_len);

  int N, L;
  tmp = scanf("%d %d", &N, &L);
  assert(tmp == 2);
  Init(N);

  int i;
  for (i = 0; i < L; i++) {
    int A, B;
    tmp = scanf("%d", &A);
    if (A == -1) {
      int critical;
      critical = CountCritical();
      printf("%d\n", critical);
    } else {
      tmp = scanf("%d", &B);
      assert(tmp == 1);
      Link(A, B);
    }
  }

  return 0;

}
