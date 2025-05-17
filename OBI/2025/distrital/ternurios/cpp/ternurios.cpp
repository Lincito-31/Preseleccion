#include <vector>

using namespace std;

int max_ternurios(int N, vector<int> T) {
  // CÓDIGO AQUÍ
  int dp[N];
  dp[1]=max(T[1],dp[0]=max(T[0],0));
  for(int i=2;i<N;i++){
    dp[i]=max(dp[i-1],dp[i-2]+max(0,T[i]));
  }
  return dp[N-1];
}
