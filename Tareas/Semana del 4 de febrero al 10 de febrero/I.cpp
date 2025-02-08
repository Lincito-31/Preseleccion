#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
ll raiz(ll x){
    ll l=1,r=1e6;
    while(l<r){
        ll mid=(l+r)>>1;
        if(mid*mid>=x){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return l;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        if(n==1){
            cout << "NO\n";
            continue;
        }
        ll x=raiz(n);
        if(x*x==n){
            bool xd=true;
            for(ll i=2;i*i<=x;i++){
                if(x%i==0){
                    xd=false;
                    break;
                }
            }
            if(xd){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            cout << "NO\n";
        }
    }
}