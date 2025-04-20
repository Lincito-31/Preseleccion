#include <bits/stdc++.h>
using namespace std;
int n,m,q,a,b,d;
vector<pair<int,int>> st;
vector<vector<int>> graph;
vector<pair<int,int>> lista;
void build(int node,int l,int r){
    if(l==r){
        st[node]={l,r};
        return;
    }
    int hiji=(node<<1)+1,hijd=(node<<1)+2,mid=(l+r)>>1;
    build(hiji,l,mid);
    build(hijd,mid+1,r);
}
void update(int node,int l,int r,int pos,int val){
    if(l==r){
        st[node]=val;
        return;
    }
    int mid=(l+r)>>1,hiji=(node<<1)+1,hijd=(node<<1)+2;
    if(pos<=mid){
        update(hiji,l,mid,pos,val);
    }else{
        update(hijd,mid+1,r,pos,val);
    }
    st[node]=max(st[hiji],st[hijd]);
}
int query(int node,int l,int r,int i ,int j){
    if(r<i || j<l){
        return 0;
    }
    if(i<=l && r<=j){
        return st[node];
    }
    int mid=(l+r)>>1,hiji=(node<<1)+1,hijd=(node<<1)+2;
    return max(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    lista.resize(n-1);
    graph.resize(n);
    st.resize(4*n);
    build(0,0,n-1);
    for(int i=0;i<n-1;i++){
        cin >> a >> b;
        lista[i]={--a,--b};
    }
    vector<int> dd(m);
    for(int i=0;i<n;i++){

    }
    for(int i=0;i<m;i++){
        cin >> d;
        dd[i]=d;
    }
    for(int i=0;i<n;i++){
        vector<bool> used(n);
        for(int j=0;j<m;j++){

        }
    }
}