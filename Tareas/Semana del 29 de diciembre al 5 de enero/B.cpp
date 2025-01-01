#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int precalc[1000000],mini=1e9;
ll n;
int main(){
    for(int i=0;i<10;i++){
        precalc[i]=i;
    }
    for(int i=10;i<100;i++){
        precalc[i]=i/10+precalc[i%10];
    }
    for(int i=100;i<1000;i++){
        precalc[i]=i/100+precalc[i%100];
    }
    for(int i=1000;i<10000;i++){
        precalc[i]=i/1000+precalc[i%1000];
    }
    for(int i=10000;i<100000;i++){
        precalc[i]=i/10000+precalc[i%10000];
    }
    for(int i=100000;i<1000000;i++){
        precalc[i]=i/100000+precalc[i%100000];
    }
    scanf("%lld",&n);
    while(!(n&(1<<0))){
        n=n>>1;
    }
    while(n%5==0){
        n/=5;
    }
    for(int i=1;i<1e8;i+=2){
        ll now=i*n;
        int l=now%10;
        now/=10;
        mini=min(mini,precalc[now/1000000]+precalc[now%1000000]+l);
    }
    printf("%d",mini);
}