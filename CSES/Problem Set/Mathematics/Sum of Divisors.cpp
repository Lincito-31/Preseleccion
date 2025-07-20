#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,sum,now=1,last,temp;
ll bigmod(ll b,ll e){
    ll p=1;
    while(e){
        if(e%2){
            p*=b;
            p%=MOD;
        }
        b*=b;
        b%=MOD;
        e/=2;
    }
    return p;
}
ll sumar(ll l,ll r){
    return ((((r-l+1)%MOD)*((l+r)%MOD)%MOD)*bigmod(2,MOD-2))%MOD;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(now<=n){
        temp=n/now;
        last=n/temp;
        sum=(sum+temp*sumar(now,last))%MOD;
        now=last+1;
    }
    cout << sum;
}