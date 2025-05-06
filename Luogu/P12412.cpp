#include <bits/stdc++.h>
using namespace std;
int n,k,a,s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    while(n--){
        cin >> a;
        s+=(k-a);
    }
    s=k-s;
    s=max(s,0);
    cout << s;
}