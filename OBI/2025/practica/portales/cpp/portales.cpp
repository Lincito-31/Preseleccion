#include "portales.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> portales_magicos(int N,vector<int> P) {
  vector<int> result(N);
  set<int> nums={-1};
  for(int i=0;i<N;i++){
    auto p=nums.lower_bound(P[i]);
    p--;
    result[i]=*p;
    nums.insert(P[i]);
  }
  return result;
}
