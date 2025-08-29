#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,a,b,c;
// suma todo, maximo,maximol,maximor
struct segmenttree{
    ll N;
    vector<ll> num;
    vector<vector<ll>> seg;
    void build(ll node,ll l,ll r){
        if(l==r){
            seg[node]={num[l],max(num[l],0ll),num[l],num[l]};
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        build(hiji,l,mid);
        build(hijd,mid+1,r);
        seg[node][0]=seg[hiji][0]+seg[hijd][0];
        seg[node][1]=max({seg[hiji][1],seg[hijd][1],seg[hiji][3]+seg[hijd][2]});
        seg[node][2]=max(seg[hiji][2],seg[hiji][0]+seg[hijd][2]);
        seg[node][3]=max(seg[hijd][3],seg[hijd][0]+seg[hiji][3]);
    }
    void update(ll node,ll l,ll r,ll pos,ll val){
        if(l==r){
            seg[node]={val,max(val,0ll),val,val};
            return;
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        if(pos<=mid){
            update(hiji,l,mid,pos,val);
        }else{
            update(hijd,mid+1,r,pos,val);
        }
        seg[node][0]=seg[hiji][0]+seg[hijd][0];
        seg[node][1]=max({seg[hiji][1],seg[hijd][1],seg[hiji][3]+seg[hijd][2]});
        seg[node][2]=max(seg[hiji][2],seg[hiji][0]+seg[hijd][2]);
        seg[node][3]=max(seg[hijd][3],seg[hijd][0]+seg[hiji][3]);
    }
    vector<ll> query(ll node,ll l,ll r,ll i,ll j){
        if(j<l || r<i){
            vector<ll> retorno(4,-1e18);
            return retorno;
        }else if(i<=l && r<=j){
            return seg[node];
        }
        ll mid=(l+r)>>1,hiji=2*node+1,hijd=2*node+2;
        vector<ll> iz=query(hiji,l,mid,i,j),de=query(hijd,mid+1,r,i,j);
        vector<ll> res(4);
        res[0]=iz[0]+de[0];
        res[1]=max({iz[1],iz[1],iz[3]+de[2]});
        res[2]=max(iz[2],iz[0]+de[2]);
        res[3]=max(de[3],de[0]+iz[3]);
        return res;
    }
    segmenttree(vector<ll> x){
        N=x.size();
        num=x;
        seg.assign(4*N+5,vector<ll>(4));
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
    segmenttree res(nums);
    while(q--){
        cin >> a >> b;
        res.update(0,0,n-1,a-1,b);
        cout << res.query(0,0,n-1,0,n-1)[1] << '\n';
    }
}