#include "mosaic.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
bitset<5001> mat[5001];
ll psum[5001][5001];
int N,Q;
vll mosaic(vi X, vi Y,vi T, vi B,vi L, vi R){
  N=X.size();
  for(int i=0;i<N;i++){
    mat[1][i+1]=1-X[i];
    mat[i+1][1]=1-Y[i];
  }
  for(int i=2;i<=N;i++){
    for(int j=2;j<=N;j++){
      mat[i][j]=!(mat[i][j-1]&mat[i-1][j]);
    }
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+(mat[i][j]==0);
    }
  }
  vll C(Q=T.size(), 0);
  for(int i=0;i<Q;i++){
    C[i]=psum[B[i]+1][R[i]+1]-psum[B[i]+1][L[i]]-psum[T[i]][R[i]+1]+psum[T[i]][L[i]];
  }
  return C;
}
int main() {
  int N;
  assert(1 == scanf("%d", &N));
  std::vector<int> X(N), Y(N);
  for (int i = 0; i < N; i++)
    assert(1 == scanf("%d", &X[i]));
  for (int i = 0; i < N; i++)
    assert(1 == scanf("%d", &Y[i]));
  int Q;
  assert(1 == scanf("%d", &Q));
  std::vector<int> T(Q), B(Q), L(Q), R(Q);
  for (int k = 0; k < Q; k++)
    assert(4 == scanf("%d%d%d%d", &T[k], &B[k], &L[k], &R[k]));
  fclose(stdin);

  std::vector<long long> C = mosaic(X, Y, T, B, L, R);

  int S = (int)C.size();
  for (int k = 0; k < S; k++)
    printf("%lld\n", C[k]);
  fclose(stdout);

  return 0;
}
