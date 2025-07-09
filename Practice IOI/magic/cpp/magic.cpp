#include "magic.h"
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi Alicia(vi P) {
  int N = (int)P.size();
  for(int i=0;i<N;i++){
    if(P[i]==1){
      P[i]=-1;
    }
  }
  return P;
}
vi Beatriz(vi Q) {
  int N = (int)Q.size();
  for(int i=0;i<N;i++){
    if(Q[i]==-1){
      Q[i]=1;
    }
  }
  return Q;
}
