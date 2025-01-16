#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
long long x;
int main(){
    scanf("%d",&n);
    vector<ll> posicion(n);
    vector<ll> velocidad(n);
    for(int i=0;i<n;i++){
        scanf("%lld",&posicion[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&velocidad[i]);
    }
    ll l=1,r=1e9;
    while(l<r){
        ll mid=(l+r)/2;
        ll limiteizquierda=-1,limitederecha=1e18;
        for(int i=0;i<n;i++){
            ll limiteiznow=posicion[i]-velocidad[i]*mid;
            ll limitedenow=posicion[i]+velocidad[i]*mid;
            limiteizquierda=max(limiteiznow,limiteizquierda);
            limitederecha=min(limitedenow,limitederecha);
        }
        if(limitederecha>=limiteizquierda){
            //posible
            r=mid;
        }else{
            l=mid+1;
        }
    }
    double iz=l-1,de=l;
    int con=0;
    while(con<64){
        double mid=(iz+de)/2;
        double limiteizquierda=-1,limitederecha=1e18;
        for(int i=0;i<n;i++){
            double limiteiznow=(double)posicion[i]-(double)velocidad[i]*mid;
            double limitedenow=(double)posicion[i]+(double)velocidad[i]*mid;
            limiteizquierda=max(limiteiznow,limiteizquierda);
            limitederecha=min(limitedenow,limitederecha);
        }
        if(limitederecha>=limiteizquierda){
            //posible
            de=mid;
        }else{
            iz=mid;
        }
        con++;
    }
    printf("%.12lf",iz);
}