#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
ll n,q;
struct SEGMENTTREE{
    ll tam;
    vector<pair<ll,ll>> arbol,funciones;
    pair<ll,ll> merge(pair<ll,ll> x,pair<ll,ll> y){
        return {(x.first*y.first)%MOD,(x.first*y.second+x.second)%MOD};
    }
    void build(int node,int l,int r){
        if(l==r){
            arbol[node]=funciones[l];
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        arbol[node]=merge(arbol[hijd],arbol[hiji]);
    }
    pair<ll,ll> query(int node,int l,int r,int i,int j){
        if(r<i || j<l){
            return {1,0};
        }else if(i<=l && r<=j){
            return arbol[node];
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        return merge(query(hijd,mid+1,r,i,j),query(hiji,l,mid,i,j));
    }
    void update(int node,int l,int r,int pos,pair<ll,ll> val){
        if(l==r){
            arbol[node]=val;
            return;
        }
        int mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid){
            update(hiji,l,mid,pos,val);
        }else{
            update(hijd,mid+1,r,pos,val);
        }
        arbol[node]=merge(arbol[hijd],arbol[hiji]);
    }
    SEGMENTTREE(vector<pair<ll,ll>> x){
        funciones=x;
        arbol.resize(4*(tam=x.size())+5);
        build(0,0,tam-1);
    }
};
ll tipo,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<pair<ll,ll>> func(n);
    for(ll i=0;i<n;i++){
        cin >> func[i].first >> func[i].second;
    }
    SEGMENTTREE sol(func);
    while(q--){
        cin >> tipo >> a >> b >> c;
        if(tipo==0){
            sol.update(0,0,n-1,a,{b,c});
        }else{
            pair<ll,ll> funcion=sol.query(0,0,n-1,a,b-1);
            cout << (((funcion.first*c)%MOD+funcion.second)%MOD+MOD)%MOD << '\n';
        }
    }
}