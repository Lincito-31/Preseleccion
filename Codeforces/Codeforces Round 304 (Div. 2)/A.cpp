#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> k >> n >> x;
    cout << max(k*x*(x+1)/2-n,0);
}