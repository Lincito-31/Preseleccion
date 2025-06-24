#include "nile.h"
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int N,Q;
ll siosi;
vector<pair<int,int>> Eindice,segt,artifact;
vll res;
void propagate(){

}
void update(int node,int l,int r,int i,int j,pair<int,int> rango){
  propagate();
  if(j<l || r<i){
    return;
  }
  if(i<=l && r<=j){
    if(rango.first==segt[node].second+1){
      segt[node].second=rango.second;
    }else{
      //ciertas cosas;
      segt[node]=rango;
    }
    return;
  }
  int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
  update(hiji,l,mid,i,j,rango);
  update(hijd,mid+1,r,i,j,rango);
  //
}
vll calculate_costs(vi W,vi A,vi B,vi E) {
  Q=E.size();
  N=W.size();
  res.resize(Q);
  Eindice.resize(Q);
  artifact.resize(N);
  for(int i=0;i<N;i++){
    artifact[i]={W[i],A[i]-B[i]};
    siosi+=B[i];
  }
  for(int i=0;i<Q;i++){
    Eindice[i]={E[i],i};
  }
  sort(ALL(Eindice));
  sort(ALL(artifact));
  segt.assign(4*Q+5,{0,0});
  for(int i=1;i<N;i++){

  }
  return res;
}
