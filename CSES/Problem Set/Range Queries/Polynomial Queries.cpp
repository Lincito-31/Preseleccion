#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct SEGMTENTTREE{
    ll tam;
    vector<ll> arbol,lazy,nums;
    void build(ll node,ll l,ll r){
        if(l==r){
            arbol[node]=nums[l];
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        arbol[node]=arbol[hiji]+arbol[hijd];
    }
    void apply_lazy(ll node,ll l,ll r,ll val){
        arbol[node]+=(ll)(r-l+1)*val;
        lazy[node]+=val;
    }
    void push_down(ll node,ll l,ll r){
        if(l==r){
            lazy[node]=0;
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        apply_lazy(hiji,l,mid,lazy[node]);
        apply_lazy(hijd,mid+1,r,lazy[node]);
        lazy[node]=0;
    }
    void update(ll node,ll l,ll r,ll i,ll j,ll val){
        push_down(node,l,r);
        if(r<i || j<l){
            return;
        }else if(i<=l && r<=j){
            apply_lazy(node,l,r,val);
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        update(hiji,l,mid,i,j,val);
        update(hijd,mid+1,r,i,j,val);
        arbol[node]=arbol[hiji]+arbol[hijd];
        return;
    }
    ll query(ll node,ll l,ll r,ll i,ll j){
        push_down(node,l,r);
        if(r<i || j<l){
            return 0;
        }else if(i<=l && r<=j){
            return arbol[node];
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return query(hiji,l,mid,i,j)+query(hijd,mid+1,r,i,j);
    }
    SEGMTENTTREE(vector<ll> x){
        nums=x;
        tam=x.size();
        arbol.resize(4*tam);
        lazy.resize(4*tam);
        build(0,0,tam-1);
    }
};
struct SEGMTENTTREE2{
    ll tam;
    vector<ll> arbol,lazy;
    void apply_lazy(ll node,ll l,ll r,ll xd){
        arbol[node]+=xd*(ll)(l+r)*(ll)(r-l+1)/2;
        lazy[node]+=xd;
    }
    void push_down(ll node,ll l,ll r){
        if(l==r){
            lazy[node]=0;
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        apply_lazy(hiji,l,mid,lazy[node]);
        apply_lazy(hijd,mid+1,r,lazy[node]);
        lazy[node]=0;
    }
    void update(ll node,ll l,ll r,ll i,ll j,ll val){
        push_down(node,l,r);
        if(r<i || j<l){
            return;
        }else if(i<=l && r<=j){
            apply_lazy(node,l,r,val);
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        update(hiji,l,mid,i,j,val);
        update(hijd,mid+1,r,i,j,val);
        arbol[node]=arbol[hiji]+arbol[hijd];
        return;
    }
    ll query(ll node,ll l,ll r,ll i,ll j){
        push_down(node,l,r);
        if(r<i || j<l){
            return 0;
        }else if(i<=l && r<=j){
            return arbol[node];
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return query(hiji,l,mid,i,j)+query(hijd,mid+1,r,i,j);
    }
    SEGMTENTTREE2(ll n){
        tam=n;
        arbol.resize(4*tam);
        lazy.resize(4*tam);
    }
};
ll n,q;
vector<ll> nums;
ll t,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    nums.resize(n);
    for(ll i=0;i<n;i++){
        cin >> nums[i];
    }
    SEGMTENTTREE primer(nums);
    SEGMTENTTREE2 segundo(n);
    while(q--){
        cin >> t >> a >> b;
        if(t==1){
            primer.update(0ll,1ll,n,a,b,-(a-1));
            segundo.update(0ll,1ll,n,a,b,1ll);
        }else{
            cout << primer.query(0ll,1ll,n,a,b)+segundo.query(0ll,1ll,n,a,b) << '\n';
        }
    }
}