#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,k,nums[100];
int main(){
    scanf("%lld%lld",&n,&k);
    for(ll i=0;i<n;i++){
        scanf("%lld",&nums[i]);
    }
    vector<ll> dp(k+1,0);
    dp[0]=1;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            if(i+nums[j]>k){
                continue;
            }
            dp[i+nums[j]]+=dp[i];
            dp[i+nums[j]]%=MOD;
        }
    }
    printf("%lld",dp[k]);
}