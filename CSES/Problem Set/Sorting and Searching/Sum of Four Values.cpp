#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x;
int main(){
    scanf("%lld%lld",&n,&x);
    vector<pair<ll,ll>> nums(n);
    for(ll i=0;i<n;i++){
        scanf("%lld",&nums[i].first);
        nums[i].second=i+1;
    }
    sort(nums.begin(),nums.end());
    bool xd=false;
    ll maxi=nums.back().first;
    for(ll i=0;i<n-3&&!xd;i++){
        ll target1=x-nums[i].first;
        if(target1<3*nums[i].first){
            break;
        }
        if(target1>3*maxi){
            continue;
        }
        for(ll j=i+1;j<n-2&&!xd;j++){
            ll target2=target1-nums[j].first;
            if(target2<2*nums[j].first){
                break;
            }
            if(target2>2*maxi){
                continue;
            }
            ll r=n-1;
            for(ll k=j+1;k<n-1&&!xd;k++){
                ll target3=target2-nums[k].first;
                if(target3<nums[j].first){
                    break;
                }
                if(target3>maxi){
                    continue;
                }
                while(nums[r].first>target3){
                    r--;
                }
                if(r<=k){
                    break;
                }
                if(nums[r].first==target3){
                    xd=true;
                    printf("%lld %lld %lld %lld",nums[i].second,nums[j].second,nums[k].second,nums[r].second);
                    break;
                }
            }
        }
    }
    if(!xd){
        printf("IMPOSSIBLE");
    }
}