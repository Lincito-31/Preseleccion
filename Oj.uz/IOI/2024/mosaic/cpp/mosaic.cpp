#include "mosaic.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef long long ll;
vll C;
bitset<5001> mat[5001];
ll psum[5001][5001];
bitset<200001> task33;
ll task333[200001] ;
int N,Q;
bool task3=true,task5=true;
vll mosaic(vi X, vi Y,vi T, vi B,vi L, vi R){
  C.resize(Q=T.size());
  N=X.size();
  for(int i=0;i<N;i++){
    if(!(X[i]==Y[i] && X[i]==0)){
      task5=false;
    }
    task33[i+1]=1-X[i];
    task333[i+1]=task333[i]+(task33[i+1]==0);
  }
  for(int i=0;i<Q;i++){
    if(!(T[i]==B[i] && T[i]==0)){
      task3=false;
      break;
    }
    C[i]=task333[R[i]+1]-task333[L[i]];
  }
  if(!task3){
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
    for(int i=0;i<Q;i++){
      C[i]=psum[B[i]+1][R[i]+1]-psum[B[i]+1][L[i]]-psum[T[i]][R[i]+1]+psum[T[i]][L[i]];
    }
  }
  return C;
}
