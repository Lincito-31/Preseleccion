#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int N,Q;
vector<vi> artifact;
vll res;
vll calculate_costs(vi W,vi A,vi B,vi E) {
  Q=E.size();
  N=W.size();
  res.resize(Q);
  artifact.resize(N);
  for(int i=0;i<N;i++){
    artifact[i]={W[i],A[i],B[i]};
  }
  sort(ALL(artifact));
  for(int i=0;i<Q;i++){
    int iz=0;
    res[i]+=artifact[0][2];
    for(int j=1;j<N;j++){
      res[i]+=artifact[j][2];
      if(artifact[j][0]-artifact[j-1][0]>E[i]){
        //iz al j-1;
        if((j-iz)%2){
          int mini=1e9;
          for(int k=iz;k<=j-1;k++){
            if((k-iz)%2){
              if(artifact[k+1][0]-artifact[k-1][0]<=E[i]){
                mini=min(mini,artifact[k][1]-artifact[k][2]);
              }
            }else{
              mini=min(mini,artifact[k][1]-artifact[k][2]);
            }
          }
          res[i]+=mini;
        }
        iz=j;
      }
    }
    int j=N;
    if((j-iz)%2){
      int mini=1e9;
      for(int k=iz;k<=j-1;k++){
        if((k-iz)%2){
          if(artifact[k+1][0]-artifact[k-1][0]<=E[i]){
            mini=min(mini,artifact[k][1]-artifact[k][2]);
          }
        }else{
          mini=min(mini,artifact[k][1]-artifact[k][2]);
        }
      }
      res[i]+=mini;
    }
  }
  return res;
}

int main() {
  int N;
  assert(1 == scanf("%d", &N));
  std::vector<int> W(N), A(N), B(N);
  for (int i = 0; i < N; i++)
    assert(3 == scanf("%d%d%d", &W[i], &A[i], &B[i]));
  int Q;
  assert(1 == scanf("%d", &Q));
  std::vector<int> E(Q);
  for (int j = 0; j < Q; j++)
    assert(1 == scanf("%d", &E[j]));
  fclose(stdin);

  std::vector<long long> R = calculate_costs(W, A, B, E);

  int S = (int)R.size();
  for (int j = 0; j < S; j++)
    printf("%lld\n", R[j]);
  fclose(stdout);

  return 0;
}