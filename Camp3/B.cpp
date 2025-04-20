#include <bits/stdc++.h>
using namespace std;
int n,x;
int main(){
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin >> coins[i];
    }
    sort(coins.begin(),coins.end());
    vector<int> dp(x+1);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=x;j++){
            if(coins[i]+j<=x){
                dp[coins[i]+j]+=dp[j];
            }
        }
    }
    cout << dp[x];
}
/*
3 9
2 3 5

3
*/