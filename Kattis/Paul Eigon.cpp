#include <bits/stdc++.h>
using namespace std;
int n,p,o;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> p >> o;
    cout << (((p+o)/n)%2==0?"paul":"opponent");
}