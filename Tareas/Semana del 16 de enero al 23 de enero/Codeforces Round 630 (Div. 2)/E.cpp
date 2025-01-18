#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 998244353
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
ll n,m,l,r;
ll bigmod(ll x,ll y){
    ll p=1;
    x%=MOD;
    while(y>0){
        if(y%2==1){
            p*=x;
            p%=MOD;
        }
        x=x*x;
        x%=MOD;
        y/=2;
    }
    return p;
}
int main(){
    scanf("%lld%lld%lld%lld",&n,&m,&l,&r);
    r-=l;
    ll longitud=(r+1)>>1;
    ll cantidadpares=longitud,cantidadimpares=longitud,res=0;
    ll tot=n*m;
    if(r%2==0){
        cantidadpares++;
    }
    // solo en el caso de que la cantidadimpares y la cantidadpares son ambos impares;
    if(tot%2==0){
        res=bigmod(cantidadimpares+cantidadpares,tot)+bigmod(cantidadpares-cantidadimpares,tot);
        res%=MOD;
        res*=bigmod(2,MOD-2);
    }else{
        res=bigmod(cantidadimpares+cantidadpares,tot);
    }
    res%=MOD;
    printf("%lld",res);
}