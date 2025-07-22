#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,m;
// empieza en i termina e j con k unlock
int nums[101];
ll dp[2][101][10001],suma;
//cantidad hasta pos con suma x
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(nums,nums+n);
    dp[0][0][5000]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-i;j++){
            for(int k=0;k<=5000+m;k++){
                if(dp[0][j][k]==0){
                    continue;
                }
                dp[1][j][k]+=dp[0][j][k];
                dp[1][j][k]%=MOD;
                if(j<=n-i-1){
                    dp[1][j][k]+=j*dp[0][j][k];
                    dp[1][j][k]%=MOD;
                }
                if(j-1>=0 && k+nums[i]<=5000+m){
                    dp[1][j-1][k+nums[i]]+=j*dp[0][j][k];
                    dp[1][j-1][k+nums[i]]%=MOD;
                }
                if(j+1<=n-1-i){
                    dp[1][j+1][k-nums[i]]+=dp[0][j][k];
                    dp[1][j+1][k-nums[i]]%=MOD;
                }
            }
        }
        for(int j=0;j<=n-i-1;j++){
            for(int k=0;k<=5000+m;k++){
                dp[0][j][k]=dp[1][j][k];
                dp[1][j][k]=0;
            }
        }
    }
    for(int i=5000;i<=5000+m;i++){
        suma+=dp[0][0][i];
        suma%=MOD;
    }
    cout << suma;
}