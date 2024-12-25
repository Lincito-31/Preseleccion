#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
int t,n,dp[5001][5001];
char a[5001],b[5001];
int main(){
    scanf("%s%s",a,b);
    string A(a),B(b);
    int n=A.size(),m=B.size();
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
            dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(A[i-1]!=B[j-1]));
        }
    }
    printf("%d",dp[n][m]);
}