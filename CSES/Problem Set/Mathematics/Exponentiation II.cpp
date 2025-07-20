#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,x,z,y;
ll bigmod(ll b,ll e,ll mod){
    if(e==0){
        return 1;
    }else if(b==0){
        return 0;
    }
    ll p=1;
    while(e){
        if(e&1){
            p*=b;
            p%=mod;
        }
        b*=b;
        b%=mod;
        e>>=1;
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> x >> y >> z;
        ll temp=bigmod(y,z,MOD-1);
        cout << bigmod(x,temp,MOD) << '\n';
    }
}