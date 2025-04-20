#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,a,b,c;
struct segment{
    ll N;
    vector<ll> aa,st;
    void build(ll node,ll l,ll r){
        if(l==r){
            st[node]=aa[l];
            return;
        }
        ll hiji=(node<<1)+1,hijd=(node<<1)+2,mid=(l+r)>>1;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        st[node]=st[hiji]+st[hijd];
    }
    void update(ll node,ll l,ll r,ll pos,ll val){
        if(l==r){
            st[node]=val;
            return;
        }
        ll hiji=(node<<1)+1,hijd=(node<<1)+2,mid=(l+r)>>1;
        if(pos<=mid){
            update(hiji,l,mid,pos,val);
        }else{
            update(hijd,mid+1,r,pos,val);
        }
        st[node]=st[hiji]+st[hijd];
    }
    ll query(ll node,ll l,ll r,ll i,ll j){
        if(r<i || j<l){
            return 0;
        }
        if(i<=l && r<=j){
            return st[node];
        }
        ll hiji=(node<<1)+1,hijd=(node<<1)+2,mid=(l+r)>>1;
        return query(hiji,l,mid,i,j)+query(hijd,mid+1,r,i,j);
    }
    void init(vector<ll> A){
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
    vector<ll> nums(n);
    for(ll i=0;i<n;i++){
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