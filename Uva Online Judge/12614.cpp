#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,res,n,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int i=1;i<=t;i++){
        res=0;
        cout << "Case " << i << ": ";
        cin >> n;
        while(n--){
            cin >> a;
            res=max(res,a);
        }
        cout << res << '\n';
    }
}