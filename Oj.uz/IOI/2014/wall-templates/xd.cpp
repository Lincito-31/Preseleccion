#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> st;
void update(int node,int l,int r,int i,int j,int val,int type){
    if(val==-1){
        return;
    }
    if(i==l && r==j){
        if(type==1){
            st[node].first=max(st[node].first,val);
            st[node].second=max(st[node].first,st[node].second);
            /*if(val>st[node].first){
                st[node].first=val;
                if(st[node].second<val){
                    st[node].second=val;
                }
            }*/
        }else{
            st[node].second=min(st[node].second,val);
            st[node].first=min(st[node].first,st[node].second);
            /*if(val<st[node].second){
                st[node].second=val;
                if(st[node].first>val){
                    st[node].first=val;
                }
            }*/
        }
        return;
    }
    int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
    update(hiji,l,mid,l,mid,st[node].first,1);
    update(hijd,mid+1,r,mid+1,r,st[node].first,1);
    update(hiji,l,mid,l,mid,st[node].second,2);
    update(hijd,mid+1,r,mid+1,r,st[node].second,2);
    st[node]={-1,-1};
    if(j<=mid){
        update(hiji,l,mid,i,j,val,type);
    }else if(mid+1<=i){
        update(hijd,mid+1,r,i,j,val,type);
    }else{
        update(hiji,l,mid,i,mid,val,type);
        update(hijd,mid+1,r,mid+1,j,val,type);
    }
    /*if(i<=mid){
        update(hiji,l,mid,i,min(mid,j),val,type);
    }
    if(j>mid){
        update(hijd,mid+1,r,max(mid+1,i),j,val,type);
    }*/
}
void update2(int node,int l,int r,int val,int type){
    if(type==1){
        st[node].first=max(st[node].first,val);
        st[node].second=max(st[node].first,st[node].second);
    }else{
        st[node].second=min(st[node].second,val);
        st[node].first=min(st[node].first,st[node].second);
    }
    if(type==1){
        st[node].first=max(st[node].first,val);
        st[node].second=max(st[node].first,st[node].second);
    }else{
        st[node].second=min(st[node].second,val);
        st[node].first=min(st[node].first,st[node].second);
    }
    if(l==r){
        return;
    }
    int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
    update2(hiji,l,mid,st[node].first,1);
    update2(hijd,mid+1,r,st[node].first,1);
    update2(hiji,l,mid,st[node].second,2);
    update2(hijd,mid+1,r,st[node].second,2);
    st[node]={-1,-1};
}
int query(int node,int l,int r,int pos){
    if(l==r){
        return max(st[node].first,0);
    }
    int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
    if(pos<=mid){
        return query(hiji,l,mid,pos);
    }else{
        return query(hijd,mid+1,r,pos);
    }
}
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
  st.assign(5*n,{-1,-1});
  for(int i=0;i<k;i++){
    update(0,0,n-1,left[i],right[i],height[i],op[i]);
  }
  update2(0,0,n-1,0,1);
  for(int i=0;i<n;i++){
    finalHeight[i]=query(0,0,n-1,i);
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
