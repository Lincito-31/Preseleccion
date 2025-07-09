#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=i;
    }
    for(int i=2;i<=n;i++){
        int x=i;
        for(int j=10;j<=100000;j*=10){
            int res=x%j;
            int ade=x/j;
            if(res<j/10){
                continue;
            }
            dp[i]=min(dp[i],dp[res]+dp[ade]);
        }
        for(int j=2;j*j<=x;j++){
            if(x%j==0){
                dp[i]=min(dp[i],dp[j]+dp[x/j]);
            }
        }
        for(int j=1;j<=i/2;j++){
            dp[i]=min(dp[i],dp[j]+dp[i-j]);
        }
    }
    cout << dp[n];
}