#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
ll t,n;
vll nums1,nums2,segment;
void update(ll node,ll l,ll r,ll posi,ll val){
    if(l==r){
        segment[node]+=val;
        return;
    }
    ll mid=(l+r)>>1;
    ll hiji=2*node+1,hijd=2*node+2;
    if(mid>=posi){
        update(hiji,l,mid,posi,val);
    }else{
        update(hijd,mid+1,r,posi,val);
    }
    segment[node]=segment[hiji]+segment[hijd];
    return;
}
ll calc(ll node,ll l,ll r,ll i,ll j){
    if(i<=l && r<=j){
        return segment[node];
    }
    if(r<i || j<l){
        return 0;
    }
    ll mid=(l+r)>>1;
    ll hiji=2*node+1,hijd=2*node+2;
    ll iz=calc(hiji,l,mid,i,j);
    ll de=calc(hijd,mid+1,r,i,j);
    return iz+de;
}
int main(){
    scanf("%lld",&t);
    while(t--){
        bool xd=true;
        scanf("%lld",&n);
        nums1.resize(n+1);
        nums2.resize(n+1);
        segment.assign(4*n+5,0);
        map<ll,ll> con;
        for(ll i=0;i<n;i++){
            scanf("%lld",&nums2[i]);
            con[nums2[i]]=i;
        }
        for(ll i=0;i<n;i++){
            scanf("%lld",&nums1[i]);
            if(con.count(nums1[i])==0){
                xd=false;
            }
        }
        ll contador=0;
        for(ll i=0;i<n-2;i++){
            ll cantimovll=0;
            cantimovll+=con[nums1[i]]-i;
            cantimovll+=calc(0,0,n,0,con[nums1[i]]);
            update(0,0,n,0,1);
            update(0,0,n,con[nums1[i]],-1);
            contador+=cantimovll;
        }
        if(contador%2==1){
            swap(nums1[n-1],nums1[n-2]);
        }
        if(con[nums1[n-2]]>con[nums1[n-1]]){
            xd=false;
        }
        if(xd){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
}