#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
ll n,nums[5000],dp[5001][5001];
ll calc(ll x, ll y){
    if(dp[x][y]!=-1e18){
        return dp[x][y];
    }
    ll length=y-x+1;
    if(length==0){
        return 0;
    }
    if((n-length)%2==0){
        dp[x][y]=max(nums[x]+calc(x+1,y),nums[y]+calc(x,y-1));
    }else{
        dp[x][y]=min(calc(x+1,y),calc(x,y-1));
    }
    return dp[x][y];
}
int main(){
    scanf("%lld",&n);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=-1e18;
        }
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&nums[i]);
    }
    printf("%lld",calc(0,n-1));
}