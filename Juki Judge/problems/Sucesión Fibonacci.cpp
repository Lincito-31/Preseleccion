#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
long long fib[91];
long long psum[91];
int q,tip,a;
int main(){
    fib[0]=0;
    psum[0]=0;
    fib[1]=1;
    psum[1]=1;
    for(int i=2;i<91;i++){
        fib[i]=fib[i-1]+fib[i-2];
        psum[i]=psum[i-1]+fib[i];
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&tip);
        if(--tip){
            scanf("%d%d",&a,&tip);
            printf("%lld\n",psum[tip]-psum[(a-1)<=0?0:a-1]);
        }else{
            scanf("%d",&a);
            printf("%lld\n",fib[a]);
        }
    }
}