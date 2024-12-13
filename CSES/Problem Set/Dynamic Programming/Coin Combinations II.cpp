#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,k,a;
int main(){
    scanf("%lld%lld",&n,&k);
    map<int,int> dif;
    vector<ll> nums;
    for(ll i=0;i<n;i++){
        scanf("%lld",&a);
        dif[a]++;
    }
    for(auto u:dif){
        nums.push_back(u.first);
    }
    sort(nums.begin(),nums.end());
    vector<ll> dp(k+1,0);
    dp[0]=1;
    for(auto coin:nums){
        for(int j=0;j<k;j++){
            if(coin+j>k){
                break;
            }
            dp[coin+j]+=dp[j];
            dp[coin+j]%=MOD;
        }
    }
    printf("%lld",dp[k]);
}