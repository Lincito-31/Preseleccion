#include "werewolf.h"
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<vi> graph,sparsemaxi,sparsemini;
int n,m,q,timer;
vi pos,nums,res;
vector<bool> visited1,visited2;
void dfs(int now,int ante){
  pos[now]=timer++;
  for(auto u:graph[now]){
    if(u!=ante){
      dfs(u,now);
    }
  }
}
void dfs1(int now,int val){
  for(auto u:graph[now]){
    if(visited1[u]){
      continue;
    }
    if(u>=val){
      visited1[u]=true;
      dfs1(u,val);
    }
  }
}
void dfs2(int now,int val){
  for(auto u:graph[now]){
    if(visited2[u]){
      continue;
    }
    if(u<=val){
      visited2[u]=true;
      dfs2(u,val);
    }
  }
}
vi check_validity(int N,vi X,vi Y,vi S,vi E,vi L,vi R){
  n=N;
  m=X.size();
  q=S.size();
  graph.resize(n);
  pos.resize(n);
  nums.resize(n);
  res.assign(q,0);
  sparsemini.assign(n,vi(21,-1));
  for(int i=0;i<m;i++){
    graph[X[i]].push_back(Y[i]);
    graph[Y[i]].push_back(X[i]);
  }
  if(n<=3000 && m<=6000 && q<=3000){
    for(int i=0;i<q;i++){
      if(S[i]<L[i] || R[i]<E[i]){
        continue;
      }
      visited1.assign(n,false);
      visited2.assign(n,false);
      visited1[S[i]]=true;
      dfs1(S[i],L[i]);
      visited2[E[i]]=true;
      dfs2(E[i],R[i]);
      for(int j=0;j<n;j++){
        if(visited1[j] && visited2[j]){
          res[i]=1;
          break;
        }
      }
    }
  }else{
    for(int i=0;i<n;i++){
      if(graph[i].size()==1){
        dfs(i,-1);
        break;
      }
    }
    for(int i=0;i<n;i++){
      nums[pos[i]]=i;
    }
    for(int i=0;i<n;i++){
      sparsemini[i][0]=nums[i];
    }
    sparsemaxi=sparsemini;
    for(int j=1;j<=20;j++){
      for(int i=0;i<n;i++){
        if(i+(1<<(j-1))<n){
          sparsemaxi[i][j]=max(sparsemaxi[i][j-1],sparsemaxi[i+(1<<(j-1))][j-1]);
          sparsemini[i][j]=min(sparsemini[i][j-1],sparsemini[i+(1<<(j-1))][j-1]);
        }
      }
    }
    /*for(int j=0;j<5;j++){
      for(int i=0;i<n;i++){
        cout << sparsemaxi[i][j] << ' ';
      }
      cout << '\n';
    }*/
    for(int i=0;i<q;i++){
      if(S[i]<L[i] || R[i]<E[i]){
        continue;
      }
      int poshuma=pos[S[i]],poslobo=pos[E[i]];
      if(poshuma<poslobo){
        // humano ... lobo;
        // humano no menos que L[i];
        int posicion=poshuma;
        for(int j=20;j>0;j--){
          if(posicion+(1<<j)-1>=n){
            continue;
          }
          if(sparsemini[posicion][j]==-1){
            continue;
          }
          if(sparsemini[posicion][j]>=L[i]){
            posicion=posicion+(1<<j)-1;
            j++;
          }
        }
        int termina=poslobo;
        for(int j=20;j>0;j--){
          if(termina-(1<<j)+1<0){
            continue;
          }
          if(sparsemaxi[termina-(1<<j)+1][j]==-1){
            continue;
          }
          if(sparsemaxi[termina-(1<<j)+1][j]<=R[i]){
            termina=termina-(1<<(j))+1;
            j++;
          }
        }
        if(termina<=posicion){
          res[i]=1;
        }else{
          res[i]=0;
        }
      }else{
        // lobo ... humano
        int posicion=poslobo;
        for(int j=20;j>0;j--){
          if(posicion+(1<<j)-1>=n){
            continue;
          }
          if(sparsemaxi[posicion][j]==-1){
            continue;
          }
          if(sparsemaxi[posicion][j]<=R[i]){
            posicion=posicion+(1<<(j))-1;
            j++;
          }
        }
        int termina=poshuma;
        for(int j=20;j>0;j--){
          if(termina-(1<<j)+1<0){
            continue;
          }
          if(sparsemini[termina-(1<<j)+1][j]==-1){
            continue;
          }
          if(sparsemini[termina-(1<<j)+1][j]>=L[i]){
            termina=termina-(1<<j)+1;
            j++;
          }
        }
        if(termina<=posicion){
          res[i]=1;
        }else{
          res[i]=0;
        }
      }
    }
  }
  return res;
}
