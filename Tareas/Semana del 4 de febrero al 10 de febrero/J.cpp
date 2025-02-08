#include <bits/stdc++.h>
#define lsOne(x) (x)&-(x)
#define MOD 1000000007
#define MOD2 1000000009
using namespace std;
typedef long long ll;
ll t,n,ant,now;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> ant;
        vector<vector<ll>> res;
        bool xd=true;
        for(ll i=1;i<n;i++){
            cin >> now;
            ll mini=min(ant,now);
            if(xd){
                res.push_back({i,i+1,MOD,mini});
                ant=mini;
            }else{
                res.push_back({i,i+1,MOD2,mini});
                ant=mini;
            }
            xd=!xd;
        }
        cout << res.size() << "\n";
        for(auto u:res){
            cout << u[0] << " " << u[1] << " " << u[2] << " " << u[3] << "\n";
        }
    }
}