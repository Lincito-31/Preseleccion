#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
int t,n;
ll dp[1000001][2];
int main(){
    dp[1][0]=dp[1][1]=1;
    for(int i=2;i<=1e6;i++){
        dp[i][0]=4*dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0]+2*dp[i-1][1];
        dp[i][0]%=MOD;
        dp[i][1]%=MOD;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%lld\n",(dp[n][0]+dp[n][1])%MOD);
    }
}