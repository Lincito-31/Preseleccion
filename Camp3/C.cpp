#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int main(){
    cin >> n >> k;
    k++;
    vector<ll> llamas(n+1),psum(n+1);
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,1e18));
    for(int i=1;i<=n;i++){
        cin >> llamas[i];
        psum[i]=psum[i-1]+llamas[i];
    }
    dp[0][0]=0;
    for(int l=1;l<=k;l++){
        dp[0][l]=0;
        for(int i=1;i<=n;i++){
            ll maxi=0;
            for(int j=i;j>0;j--){
                if(maxi>=llamas[j]){
                    dp[i][l]=min(dp[j-1][l-1]+(i-j+1)*maxi-(psum[i]-psum[j-1]),dp[i][l]);
                }else{
                    maxi=llamas[j];
                    dp[i][l]=min(dp[j-1][l-1]+(i-j+1)*maxi-(psum[i]-psum[j-1]),dp[i][l]);
                }
            }
            //cout << dp[i][l] << " ";
        }
        //cout << endl;
    }
    cout << dp[n][k];
}
/*
6 2
7 9 8 2 3 2

3

8 2
1 2 3 2 1 2 3 4

5
*/