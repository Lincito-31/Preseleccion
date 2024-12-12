#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,dp[1000001];
int main(){
    dp[1]=1;dp[2]=2;dp[3]=4;dp[4]=8;dp[5]=16;dp[6]=32;
    scanf("%d",&n);
    for(int i=7;i<=n;i++){
        for(int j=1;j<=6;j++){
            dp[i]+=dp[i-j];
            dp[i]%=MOD;
        }
    }
    printf("%d",dp[n]);
}