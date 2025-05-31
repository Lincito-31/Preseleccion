#include <bits/stdc++.h>
using namespace std;
long long S,M;
string K;
long long residuo(){
    long long now=0;
    for(int i=0;i<K.size();i++){
        now*=10;
        now+=K[i]-48;
        now%=M;
    }
    return now;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> M >> S >> K;
  long long x=residuo();
  x+=S;
  x%=M;
  cout << x;
}