#include <bits/stdc++.h>
using namespace std;
int N;
bool ciclo_xd=false;
int t3=0;
int t4=0;
int inde_t4=0;
set<int> inde_t3;
vector<vector<int>> gra;

vector<int> dsu;
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
  dsu[a]=b;
  return true;
}

void Init(int N_) {
  N=N_;
  dsu.resize(N);
  for(int i=0;i<N;i++){
    dsu[i]=i;
  }
  gra.resize(N);
}
void Link(int A, int B) {
  A--;B--;
  if(!unir(A,B)){
    ciclo_xd=true;
  }
  gra[A].push_back(B);
  if(gra[A].size()>=3){
    t3++;
    inde_t3.insert(A);
  }
  if(gra[A].size()>=4){
    inde_t4=A;
    t4++;
  }
  gra[B].push_back(A);
  if(gra[B].size()>=3){
    t3++;
    inde_t3.insert(B);
  }
  if(gra[B].size()>=4){
    inde_t4=B;
    t4++;
  }
}
void dfs(){

}
int CountCritical(){
  if(t4>=2){
    return 0;
  }
  if(t3>=5){
    return 0;
  }
  if(t4==1){
    // si quito inde_t4 es un chain?

  }else if(t3){

  }
  return N;
}
