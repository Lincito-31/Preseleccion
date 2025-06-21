#include <bits/stdc++.h>
using namespace std;
int n,r,x;
bitset<100> used;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> r;
    if(n==r){
        cout << "too late";
        return 0;
    }
    n=0;
    while(r--){
        cin >> x;
        used[--x]=1;
    }
    while(used[n++]);
    cout << n;
}