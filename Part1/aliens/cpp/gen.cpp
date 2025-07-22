#include <bits/stdc++.h>
using namespace std;
int n,m,k,r,c;
int main(){
    // n m k;
    // n numbers
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    n=10;m=20;k=uniform_int_distribution<int> (1,10)(rng);
    cout << 10 << ' ' << 21 << ' ' << k << '\n';
    for(int i=0;i<n;i++){
        r=uniform_int_distribution<int> (0,20)(rng);
        c=uniform_int_distribution<int> (0,20)(rng);
        cout << r << ' ' << c << '\n';
    }
}