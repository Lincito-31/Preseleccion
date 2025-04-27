#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,maxi,a,res,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        res=-1e9;
        cin >> maxi;
        while(--n){
            cin >> a;
            res=max(maxi-a,res);
            maxi=max(maxi,a);
        }
        cout << res << '\n';
    }
}