#include <bits/stdc++.h>
using namespace std;
int n,q,a,b,c;
struct segment{
    int N;
    vector<int> aa,st;
    void build(int node,int l,int r){
        if(l==r){
            st[node]=aa[l];
            return;
        }
        int hiji=(node<<1)+1,hijd=(node<<1)+2,mid=(l+r)>>1;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=min(st[hiji],st[hijd]);
    }
    void update(int node,int l,int r,int pos,int val){
        if(l==r){
            st[node]=val;
            return;
        }
        int hiji=(node<<1)+1,hijd=(node<<1)+2,mid=(l+r)>>1;
        if(pos<=mid){
            update(hiji,l,mid,pos,val);
        }else{
            update(hijd,mid+1,r,pos,val);
        }
        st[node]=min(st[hiji],st[hijd]);
    }
    int query(int node,int l,int r,int i,int j){
        if(r<i || j<l){
            return 1e9;
        }
        if(i<=l && r<=j){
            return st[node];
        }
        int hiji=(node<<1)+1,hijd=(node<<1)+2,mid=(l+r)>>1;
        return min(query(hiji,l,mid,i,j),query(hijd,mid+1,r,i,j));
    }
    void init(vector<int> A){
        aa=A;
        N=aa.size();
        st.resize(4*N+5);
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
    segment ST;
    ST.init(nums);
    while(q--){
        cin >> a >> b >> c;
        if(a==1){
            ST.update(0,0,n-1,--b,c);
        }else{
            cout << ST.query(0,0,n-1,--b,--c) << '\n';
        }
    }
}