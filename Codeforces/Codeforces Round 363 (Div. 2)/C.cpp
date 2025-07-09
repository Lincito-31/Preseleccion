#include <bits/stdc++.h>
using namespace std;
int n,a[101],dp[101][3];
//1:code,2:gym,0:rest
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        dp[i][0]=min({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+1;
        if(a[i]==1 || a[i]==3){
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        }else{
            dp[i][1]=1e9;
        }
        if(a[i]==2 || a[i]==3){
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
        }else{
            dp[i][2]=1e9;
        }
    }
    cout << min({dp[n][0],dp[n][1],dp[n][2]});
}