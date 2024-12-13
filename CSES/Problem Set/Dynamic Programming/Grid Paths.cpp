#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n;
char x;
int main(){
    scanf("%d",&n);
    int dp[n+1][n+1];
    char mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
            scanf(" %c",&mat[i][j]);
        }
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]=='*'){
                dp[i][j]=0;
                continue;
            }
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=MOD;
            dp[i][j+1]+=dp[i][j];
            dp[i][j+1]%=MOD;
        }
    }
    printf("%d",dp[n-1][n-1]);
}