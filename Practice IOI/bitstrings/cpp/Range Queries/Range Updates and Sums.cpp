#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct SEGMTENTTREE{
    ll tam;
    vector<ll> arbol,nums;
    vector<pair<ll,ll>> lazy;
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
    void apply_lazy(ll node,ll l,ll r,ll tipo,ll val){
        if(tipo==0){
            return;
        }
        if(tipo==1){
            arbol[node]+=(r-l+1)*val;
            if(lazy[node].first==1){
                lazy[node].second+=val;
            }else if(lazy[node].first==2){
                lazy[node].second+=val;
            }else{
                lazy[node]={tipo,val};
            }
        }else{
            arbol[node]=(r-l+1)*val;
            lazy[node]={2,val};
        }
    }
    void push_down(ll node,ll l,ll r){
        if(l==r){
            lazy[node]={0,0};
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        apply_lazy(hiji,l,mid,lazy[node].first,lazy[node].second);
        apply_lazy(hijd,mid+1,r,lazy[node].first,lazy[node].second);
        lazy[node]={0,0};
    }
    void update(ll node,ll l,ll r,ll i,ll j,ll tipo,ll val){
        push_down(node,l,r);
        if(r<i || j<l){
            return;
        }else if(i<=l && r<=j){
            apply_lazy(node,l,r,tipo,val);
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        update(hiji,l,mid,i,j,tipo,val);
        update(hijd,mid+1,r,i,j,tipo,val);
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
ll n,q;
vector<ll> nums;
ll t,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    nums.resize(n);
    for(ll i=0;i<n;i++){
        cin >> nums[i];
    }
    SEGMTENTTREE primer(nums);
    while(q--){
        cin >> t;
        if(t==1){
            cin >> a >> b >> c;
            primer.update(0,0,n-1,a-1,b-1,1,c);
        }else if(t==2){
            cin >> a >> b >> c;
            primer.update(0,0,n-1,a-1,b-1,2,c);
        }else{
            cin >> a >> b;
            cout << primer.query(0,0,n-1,a-1,b-1) << '\n';
        }
    }
}