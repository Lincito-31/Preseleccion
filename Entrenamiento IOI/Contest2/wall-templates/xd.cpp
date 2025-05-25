#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
int N,tiempo=-1e9;
vector<pair<int,int>> segmentres;
vector<pair<int,int>> lazy[2]; // valor,tiempo
void propagate(int node,int l,int r){
  if(lazy[0][node].first!=-1 && lazy[1][node].first!=-1 && lazy[0][node].first>lazy[1][node].first){
    if(lazy[0][node].second<lazy[1][node].second){
      lazy[0][node].first=lazy[1][node].first;
    }else{
      lazy[1][node].first=lazy[0][node].first;
    }
  }
  if(l==r){
    if(lazy[0][node].first!=-1){
      if(segmentres[node].first<=lazy[0][node].first){
        segmentres[node].first=lazy[0][node].first;
      }
      segmentres[node].second=lazy[0][node].first;
    }
    if(lazy[1][node].first!=-1){
      if(segmentres[node].second>=lazy[1][node].first){
        segmentres[node].second=lazy[1][node].first;
      }
      segmentres[node].first=lazy[1][node].first;
    }
    return;
  }
  int hiji=2*node+1,hijd=2*node+2;
  if(lazy[0][node].first!=-1){
    if(segmentres[node].first<=lazy[0][node].first){
      segmentres[node].first=lazy[0][node].first;
    }
    segmentres[node].second=lazy[0][node].first;
    if(lazy[0][hiji].first<=lazy[0][node].first){
      lazy[0][hiji].first=lazy[0][node].first;
      lazy[0][hiji].second=tiempo++;
    }
    if(lazy[0][hijd].first<=lazy[0][node].first){
      lazy[0][hijd].first=lazy[0][node].first;
      lazy[0][hijd].second=tiempo++;
    }
  }
  if(lazy[1][node].first!=-1){
    if(segmentres[node].second>=lazy[1][node].first){
      segmentres[node].second=lazy[1][node].first;
    }
    segmentres[node].first=lazy[1][node].first;
    if(lazy[1][hiji].first>=lazy[1][node].first){
      lazy[1][hiji].first=lazy[1][node].first;
      lazy[1][hiji].second=tiempo++;
    }
    if(lazy[1][hijd].first>=lazy[1][node].first){
      lazy[1][hijd].first=lazy[1][node].first;
      lazy[1][hijd].second=tiempo++;
    }
  }
  lazy[0][node].first=lazy[1][node].first=-1;
}
pair<int,int> query(int node,int l,int r,int i,int j){
  propagate(node,l,r);
  if(j<l || r<i){
    return {-1e9,1e9};
  }
  if(i<=l && r<=j){
    return segmentres[node];
  }
  int hiji=2*node+1,hijd=2*node+2,mid=(l+r)>>1;
  pair<int,int> fir=query(hiji,l,mid,i,j),sec=query(hijd,mid+1,r,i,j);
  return {max(fir.first,sec.first),min(fir.second,sec.second)};
}
void update(int node,int l,int r,int i,int j,int val,int tipo){
  propagate(node,l,r);
  if(j<l || r<i){
    return;
  }
  int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
  if(i<=l && r<=j){
    pair<int,int> ans=query(node,l,r,i,j);
    if(tipo==1){
      if(ans.first<=val){
        lazy[0][node].first=val;
        lazy[0][node].second=tiempo++;
        propagate(node,l,r);
        return;
      }
    }else{
      if(ans.second>=val){
        lazy[1][node].first=val;
        lazy[1][node].second=tiempo++;
        propagate(node,l,r);
        return;
      }
    }
  }
  update(hiji,l,mid,i,j,val,tipo);
  update(hijd,mid+1,r,i,j,val,tipo);
  segmentres[node].first=max(segmentres[hiji].first,segmentres[hijd].first);
  segmentres[node].second=min(segmentres[hiji].second,segmentres[hijd].second);
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  N=n;
  segmentres.assign(4*n+5,{0,0});
  lazy[0].assign(4*n+5,{-1,tiempo});
  lazy[1]=lazy[0];
  for(int i=0;i<k;i++){
    update(0,0,n-1,left[i],right[i],height[i],op[i]);
  }
  for(int i=0;i<n;i++){
    finalHeight[i]=query(0,0,n-1,i,i).first;
  }
  for(int i=0;i<2*n;i++){
    if(lazy[0][i].first!=-1){
      cout << lazy[0][i].first << " ";
    }
    if(lazy[1][i].first!=-1){
      cout << lazy[1][i].first << " ";
    }
  }
  return;
}
int main()
{
  int n;
  int k;

  int i, j;  
  int status = 0;

  status = scanf("%d%d", &n, &k);
  assert(status == 2);

  int* op = (int*)calloc(sizeof(int), k);
  int* left = (int*)calloc(sizeof(int), k);
  int* right = (int*)calloc(sizeof(int), k);
  int* height = (int*)calloc(sizeof(int), k);
  int* finalHeight = (int*)calloc(sizeof(int), n);

  for (i = 0; i < k; i++){
    status = scanf("%d%d%d%d", &op[i], &left[i], &right[i], &height[i]);
    assert(status == 4);
  }

  buildWall(n, k, op, left, right, height, finalHeight);

  for (j = 0; j < n; j++)
    printf("%d\n", finalHeight[j]);
  
  return 0;
}
