#include <bits/stdc++.h>
using namespace std;
int max_quesitos(int N, int M, vector<vector<int>> C){
  int dp[N][M];
  dp[0][0]=C[0][0];
  for(int i=1;i<N;i++){
    dp[i][0]=dp[i-1][0]+C[i][0];
  }
  for(int i=0;i<M;i++){
    dp[0][i]=dp[0][i-1]+C[0][i];
  }
  for(int i=1;i<N;i++){
    for(int j=1;j<M;j++){
      dp[i][j]=max(dp[i-1][j],dp[i][j-1])+C[i][j];
    }
  }
  // CÓDIGO AQUÍ
  return dp[N-1][M-1];
}
