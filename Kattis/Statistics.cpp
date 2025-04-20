#include <bits/stdc++.h>
using namespace std;
int t,a,con=1;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> t){
        int maxi=-1e9,mini=1e9;
        while(t--){
            cin >> a;
            maxi=max(maxi,a);
            mini=min(mini,a);
        }
        cout << "Case " << con++ << ": " << mini << ' ' << maxi << ' ' << maxi-mini << '\n';
    }
}