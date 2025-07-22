#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ALL(x) x.begin(),x.end()
#define lsone(x) (x)&(-x)
ll n,q,a,b;
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
            seg[node]+=val;
            num[l]+=val;
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
map<ll,ll> last;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<ll> nums(n+1),resp(q);
    vector<vector<pair<ll,ll>>> queries(n+1);
    BIT res(n+1);
    for(ll i=1;i<=n;i++){
        cin >> nums[i];
    }
    for(int i=0;i<q;i++){
        cin >> a >> b;
        queries[a].push_back({b,i});
    }
    for(int i=n;i>=1;i--){
        if(last[nums[i]]!=0){
            res.update(last[nums[i]],-1);
        }
        last[nums[i]]=i;
        res.update(i,1);
        for(auto u:queries[i]){
            resp[u.second]=res.sum(u.first);
        }
    }
    for(int i=0;i<q;i++){
        cout << resp[i] << '\n';
    }
}