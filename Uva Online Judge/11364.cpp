#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a,maxi,mini;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        maxi=0,mini=1e9;
        cin >> n;
        while(n--){
            cin >> a;
            maxi=max(maxi,a);
            mini=min(mini,a);
        }
        cout << 2*(maxi-mini) << '\n';
    }
}