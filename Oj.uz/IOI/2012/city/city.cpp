#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
vector<pair<int,int>> puntos;
int minix=2e9,miniy=2e9;
bool mat[2001][2001];
int DistanceSum(int N, int *X, int *Y){
  puntos.resize(N);
  for(int i=0;i<N;i++){
    puntos[i]={X[i],Y[i]};
    minix=min(minix,X[i]);
    miniy=min(miniy,Y[i]);
  }
  minix--;
  miniy--;
  for(int i=0;i<N;i++){
    puntos[i].first-=minix;
    puntos[i].second-=miniy;
  }
  return N;

}
