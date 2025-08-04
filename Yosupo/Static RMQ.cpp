#include <bits/stdc++.h>
using namespace std;
int n,q,a,b,c;
struct segmenttree{
    int N;
    vector<int> num;
    vector<int> seg;
    void build(int node,int l,int r){
        if(l==r){
            seg[node]=num[l];
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        seg[node]=min(seg[hiji],seg[hijd]);
    }
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            seg[node]=num[l]=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid){
            update(hiji,l,mid,pos,val);
        }else{
            update(hijd,mid+1,r,pos,val);
        }
        seg[node]=min(seg[hiji],seg[hijd]);
    }
    int query(int node,int l,int r,int i,int j){
        if(j<l || r<i){
            return 1e9;
        }else if(i<=l && r<=j){
            return seg[node];
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return min(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    segmenttree(vector<int> x){
        N=x.size();
        num=x;
        seg.resize(4*N+5);
        build(0,0,N-1);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    segmenttree res(nums);
    while(q--){
        cin >> b >> c;
        cout << res.query(0,0,n-1,b,c-1) << '\n';
    }
}