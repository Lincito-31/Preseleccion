#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef long long ll;
typedef vector<ll> vll;
ll t,n,k;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
ll combi(ll n, ll a){
    if(a>n-a){
        a=n-a;
    }
    if(a==0){
        return 1;
    }
    vll numerador(a);
    for(ll i=0;i<a;i++){
        numerador[i]=n;
        n--;
    }
    for(ll i=2;i<=a;i++){
        ll cont=0;
        ll nue=i;
        while(nue!=1){
            ll mcd=gcd(nue,numerador[cont]);
            nue/=mcd;
            numerador[cont]/=mcd;
            cont++;
        }
    }
    ll res=1;
    for(ll i=0;i<a;i++){
        res*=numerador[i];
    }
    return res;
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&n,&k);
        n--;k--;
        ll res=combi(n,k);
        printf("%lld\n",res);
    }
}