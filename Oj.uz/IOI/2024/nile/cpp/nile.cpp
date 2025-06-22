#include "nile.h"
#include <bits/stdc++.h>
#define ALL(x) 
using namespace std;
typedef long long ll;
int N;
vector<ll> dp;
vector<vector<int>> artifact;
vector<long long> calculate_costs(vector<int> W,vector<int> A,vector<int> B,vector<int> E) {
  int Q = (int)E.size();
  N=W.size();
  artifact.resize(N);
  for(int i=0;i<N;i++){
    artifact[i]={W[i],A[i],B[i]};
  }
  sort
}
