#include "magic.h"
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
    lis.push_back(maxi);
    maxi=pad[maxi];
  }
  pertenece_lis[maxi]=true;
  lis.push_back(maxi);
  vector<int> retorno1=P;
  for(int i=0;i<n;i++){
    if(pertenece_lis[i]){
      retorno1[i]=-1;
    }
  }
  // calc lds
  vector<int> lds;
  vector<bool> pertenece_lds(n);
  dp[0]=1;
  pad[0]=0;
  for(int i=1;i<n;i++){
    dp[i]=1;
    pad[i]=i;
    for(int j=i-1;j>=0;j--){
      if(P[j]>P[i] && dp[i]<dp[j]+1){
        dp[i]=dp[j]+1;
        pad[i]=j;
      }
    }
  }
  maxi=n-1;
  for(int i=n-2;i>=0;i--){
    if(dp[i]>dp[maxi]){
      maxi=i;
    }
  }
  // a partir de maxi;
  while(maxi!=pad[maxi]){
    pertenece_lds[maxi]=true;
    lds.push_back(maxi);
    maxi=pad[maxi];
  }
  pertenece_lds[maxi]=true;
  lds.push_back(maxi);
  vector<int> retorno2=P;
  for(int i=0;i<n;i++){
    if(pertenece_lds[i]){
      retorno2[i]=-1;
    }
  }
  if(lis.size()>lds.size()){
    return retorno1;
  }else{
    return retorno2;
  }
}
vi Beatriz(vi Q) {
  int N=Q.size();
  vector<int> existe(N);
  for(int i=0;i<N;i++){
    if(Q[i]==-1){
      continue;
    }
    existe[Q[i]-1]=true;
  }
  vector<int> escondidos;
  for(int i=0;i<N;i++){
    if(!existe[i]){
      escondidos.push_back(i+1);
    }
  }
  vi candidato1=Q,candidato2=Q;
  int l=0;
  for(int i=0;i<N;i++){
    if(candidato1[i]==-1){
      candidato1[i]=escondidos[l++];
    }
  }
  l=0;
  for(int i=N-1;i>=0;i--){
    if(candidato2[i]==-1){
      candidato2[i]=escondidos[l++];
    }
  }
  vector<int> lis,dp(N),pad(N);
  vector<bool> pertenece_lis(N);
  dp[0]=1;
  pad[0]=0;
  for(int i=1;i<N;i++){
    dp[i]=1;
    pad[i]=i;
    for(int j=i-1;j>=0;j--){
      if(candidato1[j]<candidato1[i] && dp[i]<dp[j]+1){
        dp[i]=dp[j]+1;
        pad[i]=j;
      }
    }
  }
  int maxi=N-1;
  for(int i=N-2;i>=0;i--){
    if(dp[i]>dp[maxi]){
      maxi=i;
    }
  }
  // a partir de maxi;
  while(maxi!=pad[maxi]){
    pertenece_lis[maxi]=true;
    lis.push_back(maxi);
    maxi=pad[maxi];
  }
  pertenece_lis[maxi]=true;
  lis.push_back(maxi);
  vector<int> retorno1=candidato1;
  for(int i=0;i<N;i++){
    if(pertenece_lis[i]){
      retorno1[i]=-1;
    }
  }
  if(retorno1==Q){
    return candidato1;
  }else{
    return candidato2;
  }
}
/*int main(){
    vi aho=Beatriz(Alicia({1,3,2,4,6,5}));
    for(int i=0;i<6;i++){
        cout << aho[i] << ' ';
    }
}*/
