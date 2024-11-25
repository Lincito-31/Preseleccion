#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll x;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&x);
        ll y=sqrt(2*x);
        y-=1;
        while(y*(y+1)/2<x){
            y++;
        }
        if(y*(y+1)==2*x){
            printf("0\n");
        }else{
            printf("1\n");
        }
    }
}