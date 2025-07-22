#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lsone(x) x&(-x)
ll n,q,a,b,c;
struct segmenttree{
    ll N;
    vector<ll> num;
    vector<ll> seg;
    void build(ll node,ll l,ll r){
        if(l==r){
            seg[node]=num[l];
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        seg[node]=seg[hiji]+seg[hijd];
    }
    void update(ll node,ll l,ll r,ll pos,ll val){
        if(l==r){
            seg[node]=num[l]=val;
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid){
            update(hiji,l,mid,pos,val);
        }else{
            update(hijd,mid+1,r,pos,val);
        }
        seg[node]=seg[hiji]+seg[hijd];
    }
    ll query(ll node,ll l,ll r,ll i,ll j){
        if(j<l || r<i){
            return 0;
        }else if(i<=l && r<=j){
            return seg[node];
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return query(hiji,l,mid,i,j)+query(hijd,mid+1,r,i,j);
    }
    segmenttree(vector<ll> x){
        N=x.size();
        num=x;
        seg.resize(4*N+5);
        build(0,0,N-1);
    }
};
struct BIT{
    vector<ll> fenwick;
    ll N;
    BIT(ll n){
        N=n;
        fenwick.resize(N+1);
    }
    void update(ll x,ll val){
        while(x<=N){
            fenwick[x]+=val;
            x+=lsone(x);
        }
    }
    ll sum(ll x){
        ll suma=0;
        while(x>0){
            suma+=fenwick[x];
            x-=lsone(x);
        }
        return suma;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<ll> nums(n);
    BIT res(n);
    for(ll i=0;i<n;i++){
        cin >> nums[i];
        res.update(i+1,nums[i]);
    }
    //segmenttree res(nums);
    while(q--){
        cin >> a >> b >> c;
        if(a==1){
            //res.update(0,0,n-1,b-1,c);
            res.update(b,c-nums[b-1]);
            nums[b-1]=c;
        }else{
            cout << res.sum(c)-res.sum(b-1) << '\n';
        }
    }
}