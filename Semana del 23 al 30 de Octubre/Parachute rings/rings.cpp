#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,inde_t4=0,inde_t3=0;
vector<vector<int>> gra;
set<int> ciclos;
set<int> t3,t4;
ll res=-1;
vector<int> dsu;
vector<bool> visited;
bool cambio=false,xd=false;
int find(int a){
  if(dsu[a]==a){
    return a;
  }
  return dsu[a]=find(dsu[a]);
}
bool unir(int a, int b){
  a=find(a);b=find(b);
  if(a==b){
    return false;
  }
  if(ciclos.find(a)==ciclos.end()){
    dsu[a]=b;
  }else{
    dsu[b]=a;
  }
  return true;
}

void Init(int N_) {
  N=N_;
  dsu.resize(N);
  for(int i=0;i<N;i++){
    dsu[i]=i;
  }
  gra.resize(N);
  res=N;
}
void Link(int A, int B) {
  if(!unir(A,B)){
    ciclos.insert(find(A));
    cambio=true;
  }
  gra[A].push_back(B);
  if(gra[A].size()>=3){
    t3.insert(A);
    inde_t3=A;
    cambio=true;
  }
  if(gra[A].size()>=4){
    inde_t4=A;
    t4.insert(A);
    cambio=true;
  }
  gra[B].push_back(A);
  if(gra[B].size()>=3){
    t3.insert(B);
    inde_t3=B;
    cambio=true;
  }
  if(gra[B].size()>=4){
    inde_t4=B;
    t4.insert(B);
    cambio=true;
  }
}
void dfs(int now,int nooo,int ante){
  int conta=0;
  if(xd){
    return;
  }
  if(visited[now]){
    xd=true;
    return;
  }
  visited[now]=true;
  for(auto u:gra[now]){
    if(u==nooo || u==ante){
      continue;
    }
    dfs(u,nooo,now);
    conta++;
    if(conta>1){
      xd=true;
    }
    if(xd){
      return;
    }
  }
}
int CountCritical(){
  if(!cambio || res==0){
    // no paso nada
  }else if(t4.size()>=2){
    res=0;
  }/*else if(t3.size()>=5){
    res=0;
  }*/else if(ciclos.size()>=2){
    res=0;
  }else if(t4.size()==1){
    // si quito inde_t4 es un chain?
    xd=false;
    res=1;
    visited.assign(N,false);
    for(int i=0;i<N;i++){
      if(visited[i] || i==inde_t4){
        continue;
      }
      if(gra[i].size()==1){
        dfs(i,inde_t4,-1);
      }else if(gra[i].size()==2){
        if(gra[i][0]==inde_t4 || gra[i][1]==inde_t4){
          dfs(i,inde_t4,-1);
        }
      }
      if(xd){
        res=0;
        break;
      }
    }
    if(!xd){
      for(int i=0;i<N;i++){
        if(visited[i] || i==inde_t4 || dsu[i]==i){
          continue;
        }else{
          xd=true;
          res--;
          break;
        }
      }
    }
  }else if(t3.size()>=1){
    // si quito el inde_3 o sus vecinos sera un chain?
    xd=false;
    visited.assign(N,false);
    res=4;
    for(int i=0;i<N;i++){
      if(visited[i] || i==inde_t3){
        continue;
      }
      if(gra[i].size()==1){
        dfs(i,inde_t3,-1);
      }else if(gra[i].size()==2){
        if(gra[i][0]==inde_t3 || gra[i][1]==inde_t3){
          dfs(i,inde_t3,-1);
        }
      }
      if(xd){
        res--;
        break;
      }
    }
    if(!xd){
      for(int i=0;i<N;i++){
        if(visited[i] || i==inde_t3 || dsu[i]==i){
          continue;
        }else{
          xd=true;
          res--;
          break;
        }
      }
    }
    for(auto uu:gra[inde_t3]){
      xd=false;
      visited.assign(N,false);
      for(int i=0;i<N;i++){
        if(visited[i] || i==uu){
          continue;
        }
        if(gra[i].size()==1){
          dfs(i,uu,-1);
        }else if(gra[i].size()==2){
          if(gra[i][0]==uu || gra[i][1]==uu){
            dfs(i,uu,-1);
          }
        }
        if(xd){
          res--;
          break;
        }
      }
      if(!xd){
        for(int i=0;i<N;i++){
          if(visited[i] || i==uu || dsu[i]==i){
            continue;
          }else{
            xd=true;
            res--;
            break;
          }
        }
      }
    }
  }else if(ciclos.size()==1){
    //cuantos elementos pertenecen a este ciclo?
    int com=*ciclos.begin(),cont=0;
    for(int i=0;i<N;i++){
      if(find(i)==com){
        cont++;
      }
    }
    res=cont;
  }
  cambio=false;
  return res;
}