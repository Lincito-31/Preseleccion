#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int nums[n+1],dp[n+1];
    for(int i=1;i<=n;i++){
        cin >> nums[i];
        dp[i+1]=1e9;
    }
    dp[1]=0;
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i],dp[i-1]+abs(nums[i]-nums[i-1]));
        if(i>2){
            dp[i]=min(dp[i],dp[i-2]+abs(nums[i]-nums[i-2]));
        }
    }
    cout << dp[n];
}