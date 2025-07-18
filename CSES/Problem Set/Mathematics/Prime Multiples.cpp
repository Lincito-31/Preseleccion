#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,k,sum;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    ll primes[k];
    for(int i=0;i<k;i++){
        cin >> primes[i];
    }
    long double comp=log10(1e18);
    for(int i=1;i<(1<<k);i++){
        bool xd=true;
        ll princi=1;
        for(int j=0;j<k;j++){
            if(i&(1<<j)){
                if((long double)log10(princi)+(long double)log10(primes[j])>comp){
                    xd=false;
                    break;
                }
                princi*=primes[j];
            }
        }
        if(!xd){
            continue;
        }
        if(__builtin_popcount(i)%2){
            sum+=n/princi;
        }else{
            sum-=n/princi;
        }
    }
    cout << sum;
}