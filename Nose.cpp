#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1000001][2];
int main(){
  dp[0][0]=dp[0][1]=6;
  dp[1][0]=dp[0][1]=2;
  dp[2][0]=dp[0][1]=5;
  dp[3][0]=dp[0][1]=5;
  dp[4][0]=dp[0][1]=4;
  dp[5][0]=dp[0][1]=5;
  dp[6][0]=dp[0][1]=6;
  dp[7][0]=dp[0][1]=3;
  dp[8][0]=dp[0][1]=7;
  dp[9][0]=dp[0][1]=6;
  for(int i=10;i<100;i++){
    int a=i;
    dp[i][0]=0;
    dp[i][1]=0;
    while(a>0){
      dp[i][0]+=dp[a%10][0];
      a/=10;
    }
  }
}