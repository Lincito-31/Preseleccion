#include <bits/stdc++.h>
using namespace std;
int n,a,b;
string st;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin >> n;
  int psum[n+1];psum[0]=0;
  for(int i=1;i<=n;i++){
    cin >> st;
    psum[i]=psum[i-1];
    psum[i]+=st=="no";
  }
  cin >> n;
  while(n--){
    cin >> a >> b;
    cout << ((psum[b]-psum[a-1])%2==0?"si\n":"no\n");
  }
}