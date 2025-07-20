#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,cantdiv7=1,cantdiv6=1,x,y,producdiv=1,sumdiv=1,nume=1,imagi=1;
bool xd=false;
ll bigmod(ll b,ll e,ll mod){
    b%=mod;
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
    for(int i=0;i<n;i++){
        cin >> x >> y;
        cantdiv7*=y+1;
        cantdiv7%=MOD;
        if(!xd && (y+1)%2==0){
            cantdiv6*=(y+1)/2;
            cantdiv6%=MOD-1;
            xd=true;
        }else{
            cantdiv6*=y+1;
            cantdiv6%=MOD-1;
        }
        imagi*=bigmod(x,y/2,MOD);
        imagi%=MOD;
        sumdiv*=((bigmod(x,y+1,MOD)-1)*bigmod(x-1,MOD-2,MOD))%MOD;
        sumdiv%=MOD;
        nume*=bigmod(x,y,MOD);
        nume%=MOD;
    }
    if(xd){
        producdiv=bigmod(nume,cantdiv6,MOD);
    }else{
        producdiv=bigmod(imagi,cantdiv6,MOD);
    }
    cout << cantdiv7 << ' ' << sumdiv << ' ' << producdiv;
}