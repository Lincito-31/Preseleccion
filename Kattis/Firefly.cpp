#include <bits/stdc++.h>
using namespace std;
int n,k,a,t,d[500001],u[500001];
int main(){
    scanf("%d%d",&n,&k);
    n=n>>1;
    t=n;
    while(n--){
        scanf("%d",&a);
        d[a]++;
        scanf("%d",&a);
        u[k-a+1]++;
    }
    a=1;
    n=1e9;
    while(k--){
        t-=u[k+1];
        t+=d[k];
        if(n>t){
            n=t;
            a=1;
        }else if(n==t){
            a++;
        }
    }
    printf("%d %d",n,a);
}