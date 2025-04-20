#include <bits/stdc++.h>
using namespace std;
int n,x;
int main(){
    cin >> n;
    vector<int> rock(n),dp(n);
    for(int i=0;i<n;i++){
        cin >> rock[i];
    }
    dp[0]=0;
    dp[1]=abs(rock[1]-rock[0]);
    for(int i=2;i<n;i++){
        dp[i]=min(dp[i-1]+abs(rock[i]-rock[i-1]),dp[i-2]+abs(rock[i]-rock[i-2]));
    }
    cout << dp[n-1];
}
/*
4
10 30 40 20
30
*/