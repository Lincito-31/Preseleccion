#include <bits/stdc++.h>
using namespace std;
long long s,n,a;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> n;
  for(int i=0;i<n-1;i++){
    cin >> a;
    s+=a;
  }
  cout << n*(n+1)/2-s;
}