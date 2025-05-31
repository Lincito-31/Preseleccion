#include "wall.h"
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> st;
// max,min
void update(int node,int l,int r,int i,int j,int val,int type){
  if(r<i || j<l){
    return;
  }
  if(i<=l && r<=j){
    if(type==1){
      if(val>st[node].first){
        st[node].first=val;
        if(st[node].second<val){
          st[node].second=val;
        }
      }
    }else{
      if(val<st[node].second){
        st[node].second=val;
        if(st[node].first>val){
          st[node].first=val;
        }
      }
    }
    return;
  }
  int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
  if(st[node].first!=-1){
    update(hiji,l,mid,l,l,st[node].first,1);
    update(hijd,mid+1,r,r,r,st[node].first,1);
  }
  if(st[node].second!=-1){
    update(hiji,l,mid,l,l,st[node].second,2);
    update(hijd,mid+1,r,r,r,st[node].second,2);
  }
  st[node]={-1,-1};
  update(hiji,l,mid,i,j,val,type);
  update(hijd,mid+1,r,i,j,val,type);
}
int query(int node,int l,int r,int pos){
  if(l==r){
    return max({st[node].first,st[node].second,0});
  }
  int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
  if(st[node].first!=-1){
    update(hiji,l,mid,l,l,st[node].first,1);
    update(hijd,mid+1,r,r,r,st[node].first,1);
  }
  if(st[node].second!=-1){
    update(hiji,l,mid,l,l,st[node].second,2);
    update(hijd,mid+1,r,r,r,st[node].second,2);
  }
  st[node]={-1,-1};
  if(pos<=mid){
    return query(hiji,l,mid,pos);
  }else{
    return query(hijd,mid+1,r,pos);
  }
}
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  st.assign(4*n,{-1,-1});
  for(int i=0;i<k;i++){
    update(0,0,n-1,left[i],right[i],height[i],op[i]);
  }
  for(int i=0;i<n;i++){
    finalHeight[i]=query(0,0,n-1,i);
  }
  return;
}

