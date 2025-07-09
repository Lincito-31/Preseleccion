#include "ricehub.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int besthub(int R, int L, int X[], long long B)
{
  vll psum(R+1);
  psum[0]=0;
  psum[1]=X[0];
  for(int i=2;i<=R;i++){
    psum[i]=psum[i-1]+X[i-1];
  }
  int iz=0,de=0;
  int can=1;
  bool xd=false;
  while(iz<R && !xd){
    de=max(de,iz);
    int mid=(iz+de)/2;
    ll sum=(ll)((ll)X[mid]*(mid-iz)-(ll)(psum[mid]-psum[iz]));
    sum+=(ll)((ll)psum[de+1]-(ll)psum[mid+1]-(ll)X[mid]*(de-mid));
    while(sum<=B){
      de++;
      if(de>=R){
        xd=true;
        break;
      }
      mid=(iz+de)/2;
      sum=(ll)((ll)X[mid]*(mid-iz)-(ll)(psum[mid]-psum[iz]));
      sum+=(ll)((ll)psum[de+1]-(ll)psum[mid+1]-(ll)X[mid]*(de-mid));
    }
    can=max(can,de-iz);
    //cout << iz << " " << de << endl;
    iz++;
  }
  return can;
}