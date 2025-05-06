#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    cin >> n >> k;
    vector<int> llamas(n),dp(n);
    for(int i=0;i<n;i++){
        cin >> llamas[i];
    }
    int maxi=0;
    for(int i=0;i<k;i++){
        maxi=max(maxi,llamas[i]);
        dp[i]=maxi*(i+1);
    }
    for(int i=k;i<n;i++){
        maxi=0;
        for(int j=0;j<k;j++){
            maxi=max(maxi,llamas[i-j]);
            dp[i]=max(dp[i-j-1]+maxi*(j+1),dp[i]);
        }
    }
    cout << dp[n-1];
}
/*
7 3
1
15
7
9
2
5
10

84
*/