#include <bits/stdc++.h>
#define LsOne(x) (x)&(-x)
using namespace std;
typedef long long ll;
struct BIT{
    vector<ll> fewnwick;
    ll tam;
    void add(ll x,ll val){
        while(x<=tam){
            fewnwick[x]+=val;
            x+=LsOne(x);
        }
    }
    ll sum(ll x){
        ll suma=0;
        while(x>0){
            suma+=fewnwick[x];
            x-=LsOne(x);
        }
        return suma;
    }
    void resize(ll n){
        tam=n+2;
        fewnwick.resize(tam);
    }
};
struct RURQ{
    ll tam;
    BIT PURQ,RUPQ;
    void update(ll a,ll b,ll c){
        RUPQ.add(a,c);
        RUPQ.add(b+1,-c);
        PURQ.add(a,c*(a-1));
        PURQ.add(b+1,-c*b);
    }
    ll query(ll a,ll b){
        return (RUPQ.sum(b)*b-PURQ.sum(b))-(RUPQ.sum(a-1)*(a-1)-PURQ.sum(a-1));
    }
    RURQ(ll n){
        PURQ.resize(n);
        RUPQ.resize(n);
        tam=n+2;
    }
};
struct SEGMENTTREE{
    ll tam;
    vector<ll> lazy,arbol;
    void apply_lazy(ll node ,ll l,ll r,ll val){
        arbol[node]+=val*(r-l+1);
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
    SEGMENTTREE(ll n){
        tam=n;
        lazy.resize(4*tam);
        arbol.resize(4*tam);
    }
};
ll t,n,q,tipo,a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        SEGMENTTREE sol(n);
        while(q--){
            cin >> tipo;
            if(tipo==0){
                cin >> a >> b >> c;
                sol.update(0,0,n-1,--a,--b,c);
            }else{
                cin >> a >> b;
                cout << sol.query(0,0,n-1,--a,--b) << '\n';
            }
        }
    }
}