#include "insects.h"
#include <bits/stdc++.h>
using namespace std;
bool visited[2000],es_indep[2000];
vector<int> indep;
vector<pair<int,int>> rango;
int suma[2000],n,mini=1e9;
void solve(int x,int y){
  if(x==y){
    return;
  }
  int mid=(x+y)>>1;
  for(int i=mid+1;i<=y;i++){
    move_outside(indep[i]);
  }
  for(int i=0;i<n;i++){
    if(es_indep[i]){
      continue;
    }
    if(rango[i]==make_pair(x,y)){
      move_inside(i);
      if(press_button()==1){
        rango[i]={mid+1,y};
      }else{
        rango[i]={x,mid};
      }
      move_outside(i);
    }
  }
  solve(x,mid);
  for(int i=x;i<=mid;i++){
    move_outside(indep[i]);
  }
  for(int i=mid+1;i<=y;i++){
    move_inside(indep[i]);
  }
  solve(mid+1,y);
}
int min_cardinality(int N){
  n=N;
  for(int i=0;i<N;i++){
    move_inside(i);
    if(press_button()==1){
      indep.push_back(i);
      es_indep[i]=true;
      suma[indep.size()-1]++;
    }else{
      move_outside(i);
    }
  }
  rango.assign(N,{0,indep.size()-1});
  solve(0,indep.size()-1);
  for(int i=0;i<n;i++){
    if(!es_indep[i]){
      suma[rango[i].first]++;
    }
  }
  for(int i=0;i<2000;i++){
    if(suma[i]==0){
      break;
    }
    mini=min(mini,suma[i]);
  }
  return mini;
}
