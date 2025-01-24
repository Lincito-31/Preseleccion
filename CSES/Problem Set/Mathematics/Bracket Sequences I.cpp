#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,fact[1000001];
ll bigmod(ll base,ll power){
    ll p=1;
    while(power>0){
        if(power%2==1){
            p*=base;
            p%=MOD;
        }
        base*=base;
        base%=MOD;
        power/=2;
    }
    return p;
}
ll inversemod(ll x){
    return bigmod(x,MOD-2);
}
int main(){
    fact[0]=1;
    for(ll i=1;i<=1e6;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
    scanf("%lld",&n);
    if(n%2==1){
        printf("0");
        return 0;
    }
    n/=2;
    ll combi=fact[2*n]*inversemod((fact[n]*fact[n])%MOD);
    combi%=MOD;
    ll res=combi*inversemod(n+1);
    res%=MOD;
    printf("%lld",res);
}