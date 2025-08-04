#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi Alicia(vi P){
  // calc lis
  int n=P.size();
  vector<int> lis,dp(n),pad(n);
  vector<bool> pertenece_lis(n);
  dp[0]=1;
  pad[0]=0;
  for(int i=1;i<n;i++){
    dp[i]=1;
    pad[i]=i;
    for(int j=i-1;j>=0;j--){
      if(P[j]<P[i] && dp[i]<dp[j]+1){
        dp[i]=dp[j]+1;
        pad[i]=j;
      }
    }
  }
  int maxi=n-1;
  for(int i=n-2;i>=0;i--){
    if(dp[i]>dp[maxi]){
      maxi=i;
    }
  }
  // a partir de maxi;
  while(maxi!=pad[maxi]){
    pertenece_lis[maxi]=true;
    maxi=pad[maxi];
  }
  pertenece_lis[maxi]=true;
  vector<int> retorno=P;
  for(int i=0;i<n;i++){
    if(pertenece_lis[i]){
      retorno[i]=-1;
    }
  }
  return retorno;
}
int main(){
    vi aho=Alicia({1,3,2,4,0,9});
    for(int i=0;i<6;i++){
        cout << aho[i] << ' ';
    }
}