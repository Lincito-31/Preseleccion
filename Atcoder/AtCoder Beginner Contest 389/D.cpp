#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r;
int main(){
    scanf("%lld",&r);
    ll i=1,j=1;
    while((2*j-1)*(2*j-1)+(2*i-1)*(2*i-1)<=4*r*r){
        j++;
    }
    ll ini=j-1;
    ll res=0;
    for(;i<=ini;i++){
        while((2*j-1)*(2*j-1)+(2*i-1)*(2*i-1)>4*r*r){
            j--;
        }
        res+=j;
    }
    ll fina=4*(ini-1);
    fina++;
    fina+=4*(res-2*ini+1);
    printf("%lld",fina);
}