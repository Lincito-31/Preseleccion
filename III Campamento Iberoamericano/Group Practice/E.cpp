#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main(){
    scanf("%lld",&n);
    vector<ll> nums(n),psum(n),ssum(n);
    for(ll i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    psum[0]=0;
    ssum[n-1]=0;
    for(ll i=1;i<n;i++){
        psum[i]=max(psum[i-1]+nums[i-1]+1-nums[i],psum[i-1]);
    }
    for(ll i=n-2;i>=0;i--){
        ssum[i]=max(ssum[i+1]+nums[i+1]+1-nums[i],ssum[i+1]);
    }
    ll res=1e18;
    for(ll i=0;i<n;i++){
        res=min(res,max(psum[i],ssum[i]));
    }
    printf("%lld",res);
}