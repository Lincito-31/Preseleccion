#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
ll n,t,k;
ll bigmod(ll base,ll power) {
    ll res=1;
    ll p=base%MOD;
    while(power>0){
        if (power%2==1) {
            res=((res%MOD)*(p%MOD))%MOD;
        }
        power/=2;
        p=((p%MOD)*(p%MOD))%MOD;
    }
    return res;
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        ll temp=bigmod(bigmod(2,n-1),k);
        printf("%lld\n",temp);
    }
}