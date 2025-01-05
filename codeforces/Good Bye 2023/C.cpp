#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        ll cantimp=0,sum=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&a);
            if(a%2==1){
                cantimp++;
            }
            sum+=a;
            ll cantipa=cantimp/3;
            ll res=sum-cantipa;
            if(cantimp%3==1 && i>0){
                res--;
            }
            printf("%lld ",res);
        }
        printf("\n");
    }
}