#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,a;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&a);
        a*=2;
        ll b=sqrt(a);
        while(b*(b+1)<a){
            b++;
        }
        while(b*(b+1)>a){
            b--;
        }
        printf("%lld\n",b);
    }
}