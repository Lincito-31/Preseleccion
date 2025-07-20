#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,x,y;
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e&1){
            p*=b;
            p%=MOD;
        }
        b*=b;
        b%=MOD;
        e>>=1;
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> x >> y;
        cout << bigmod(x,y) << '\n';
    }
}