#include "wall.h"
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> st;
vector<int> valores;
void propagate(int node,int l,int r){
  if(l==r){
    valores[l]=max(valores[l],st[node].first);
    valores[l]=min(valores[l],st[node].second);
    st[node]={0,1e9};
    return;
  }
  int hiji=2*node+1,hijd=2*node+2;
  st[hiji].first=max(st[hiji].first,st[node].first);
  st[hiji].second=max(st[hiji].first,st[hiji].second);
  st[hiji].second=min(st[hiji].second,st[node].second);
  st[hiji].first=min(st[hiji].first,st[hiji].second);
  st[hijd].first=max(st[hijd].first,st[node].first);
  st[hijd].second=max(st[hijd].second,st[hijd].first);
  st[hijd].second=min(st[hijd].second,st[node].second);
  st[hijd].first=min(st[hijd].first,st[hijd].second);
  st[node]={0,1e9};
}
void update(int node,int l,int r,int i,int j,int val,int tipo){
  propagate(node,l,r);
  if(l>j || r<i){
    return;
  }
  if(i<=l && r<=j){
    if(tipo==1){
      st[node].first=val;
    }else{
      st[node].second=val;
    }
    return;
  }
  int mid=(l+r)>>1;
  update(2*node+1,l,mid,i,j,val,tipo);
  update(2*node+2,mid+1,r,i,j,val,tipo);
}
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  st.assign(4*n,{0,1e9});
  valores.resize(n);
  for(int i=0;i<k;i++){
    update(0,0,n-1,left[i],right[i],height[i],op[i]);
  }
  for(int i=0;i<n;i++){
    update(0,0,n-1,i,i,0,1);
  }
  for(int i=0;i<n;i++){
    finalHeight[i]=valores[i];
  }
  return;
}