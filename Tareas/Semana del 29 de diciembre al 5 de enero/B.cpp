#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll calc(ll x){
    ll sum=0;
    while(x>0){
        sum+=x%10;
        x/=10;
    }
    return sum;
}
int main(){
    scanf("%lld",&n);
    while(n%2==0){
        n/=2;
    }
    while(n%5==0){
        n/=5;
    }
    ll mini=1e9;
    for(int i=1;i<=3e7;i++){
        mini=min(mini,calc(n*i));
    }
    printf("%lld",mini);
}