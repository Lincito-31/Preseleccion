#include <bits/stdc++.h>
using namespace std;
int r,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> r >> c;
    cout << fixed << setprecision(6) << (double)100*((r-c)*(r-c))/(r*r) << '\n';
}