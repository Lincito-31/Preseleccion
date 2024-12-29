#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a,b,c;
bool cmp(pair<ll,pair<ll,ll>> x,pair<ll,pair<ll,ll>> y){
    if(x.first==y.first){
        return x.second.first>y.second.first;
    }
    return x.first<y.first;
}
int main(){
    scanf("%d",&n);
    vector<pair<ll,pair<ll,ll>>> nums(n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        nums[i]={b,{a,c}};
    }
    sort(nums.begin(),nums.end(),cmp);
    map<ll,ll> dp;
    dp[0]=0;
    for(int i=0;i<n;i++){
        auto p=dp.lower_bound(nums[i].second.first);
        p--;
        auto q=dp.upper_bound(nums[i].first);
        q--;
        dp[nums[i].first]=max(q->second,p->second+nums[i].second.second);
    }
    printf("%lld",dp[nums.back().first]);
}