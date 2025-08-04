#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
vector<ll> nums;
pair<ll,ll> solve(ll penal){
    pair<ll,ll> dp[n][2];
    dp[0][0]={0,0};
    dp[0][1]={nums[0]-penal,1};
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        pair<ll,ll> op1={dp[i-1][0].first+nums[i]-penal,dp[i-1][0].second+1};
        pair<ll,ll> op2={dp[i-1][1].first+nums[i],dp[i-1][1].second};
        dp[i][1]=max(op1,op2);
    }
    return max(dp[n-1][0],dp[n-1][1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    nums.resize(n);
    for(ll i=0;i<n;i++){
        cin >> nums[i];
    }
    ll l=0,r=1e18;
    while(l<r){
        ll mid=(l+r+1)>>1;
        // mayor mid=menor k
        if(solve(mid).second>=k){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    pair<ll,ll> res=solve(l);
    cout << res.first+k*l;
}