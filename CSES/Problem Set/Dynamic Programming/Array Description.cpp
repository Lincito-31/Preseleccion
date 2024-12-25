#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
ll n,k,dp[100001][101],arr[100001];
int main(){
    scanf("%lld%lld",&n,&k);
    scanf("%lld",&arr[0]);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<=k;j++){
            dp[i][j]=0;
        }
    }
    if(arr[0]){
        dp[0][arr[0]]=1;
    }else{
        for(ll i=1;i<=k;i++){
            dp[0][i]=1;
        }
    }
    for(ll i=1;i<n;i++){
        scanf("%lld",&arr[i]);
        if(arr[i]){
            if(arr[i]+1<=k){
                dp[i][arr[i]]+=dp[i-1][arr[i]+1];
            }
            dp[i][arr[i]]+=dp[i-1][arr[i]];
            if(arr[i]-1>=1){
                dp[i][arr[i]]+=dp[i-1][arr[i]-1];
            }
            dp[i][arr[i]]%=MOD;
        }else{
            for(ll j=1;j<=k;j++){
                if(j-1>=1){
                    dp[i][j]+=dp[i-1][j-1];
                }
                dp[i][j]+=dp[i-1][j];
                if(j+1<=k){
                    dp[i][j]+=dp[i-1][j+1];
                }
                dp[i][j]%=MOD;
            }
        }
    }
    ll sum=0;
    for(ll i=1;i<=k;i++){
        sum+=dp[n-1][i];
        sum%=MOD;
    }
    printf("%lld",sum);
}