#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t,k,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> t >> k >> d;
    cout << ((1+(int)(d/t))*k>=n?"NO":"YES");
}