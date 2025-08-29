#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct SEGMTENTTREE{
    ll tam;
    vector<ll> nums,lazy;
    vector<pair<ll,ll>> arbol;
    void build(ll node,ll l,ll r){
        if(l==r){
            arbol[node]={nums[l],nums[l]};
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        arbol[node].first=arbol[hiji].first+arbol[hijd].first;
        arbol[node].second=max(arbol[hiji].second,arbol[hiji].first+arbol[hijd].second);
    }
    // total sum, best prefixsum
    void update(ll node,ll l,ll r,ll pos,ll val){
        if(l==r){
            arbol[node]={val,val};
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid){
            update(hiji,l,mid,pos,val);
        }else{
            update(hijd,mid+1,r,pos,val);
        }
        arbol[node].first=arbol[hiji].first+arbol[hijd].first;
        arbol[node].second=max(arbol[hiji].second,arbol[hiji].first+arbol[hijd].second);
        return;
    }
    pair<ll,ll> query(ll node,ll l,ll r,ll i,ll j){
        if(r<i || j<l){
            return {0,0};
        }else if(i<=l && r<=j){
            return arbol[node];
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        // es mejor el prefix sum de izquierda? o el total sum de izquierda mas mejor prefixsum de derecha
        pair<ll,ll> iz=query(hiji,l,mid,i,j),de=query(hijd,mid+1,r,i,j);
        return {iz.first+de.first,max(iz.second,iz.first+de.second)};
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
ll t,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    nums.resize(n);
    for(ll i=0;i<n;i++){
        cin >> nums[i];
    }
    SEGMTENTTREE sol(nums);
    while(q--){
        cin >> t >> a >> b;
        if(t==1){
            sol.update(0,0,n-1,a-1,b);
        }else{
            cout << max(sol.query(0,0,n-1,a-1,b-1).second,0ll) << '\n';
        }
    }
}