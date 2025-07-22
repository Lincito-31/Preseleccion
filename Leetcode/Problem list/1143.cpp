#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n1,n2,dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        n1=text1.size();
        n2=text2.size();
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        return dp[n1][n2];
    }
};