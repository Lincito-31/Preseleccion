#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,res=1;
int main(){
    scanf("%lld",&x);
    ll i=1;
    for(;res!=x;i++){
        res*=i;
    }
    printf("%lld",i-1);
}