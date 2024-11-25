#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
ll gcd(ll x,ll y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);
}
int main(){
    while(scanf("%lld%lld",&a,&b)!=EOF){
        ll supa=a-1,supb=b-1;
        ll mcd=gcd(supa,supb);
        supa/=mcd;
        supb/=mcd;
        ll res=supa*b;
        supa++;
        supb++;
        ll conx1=0,cony1=0,conx2=0,cony2=0;
        conx1+=supa/2;
        if(supa%2==0){
            conx1--;
        }
        cony1+=supb/2;
        res-=conx1*cony1;
        if(supa%2==0){
            conx2=conx1;
        }else{
            conx2=conx1-1;
        }
        if(supb%2==0){
            cony2=cony1;
        }else{
            cony2=cony1+1;
        }
        res-=conx2*cony2;
        res=a*b-res;
        printf("%lld\n",res);
    }
}