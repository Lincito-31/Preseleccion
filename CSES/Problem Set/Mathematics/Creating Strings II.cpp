#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,fact[1000001];
int con[26];
string st;
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
ll inversemod(ll x){
    return bigmod(x,MOD-2,MOD);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    fact[0]=1;
    for(int i=1;i<=1e6;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
    cin >> st;
    n=st.size();
    for(int i=0;i<n;i++){
        con[st[i]-'a']++;
    }
    ll res=fact[n];
    for(int i=0;i<26;i++){
        res*=inversemod(fact[con[i]]);
        res%=MOD;
    }
    cout << res;
}