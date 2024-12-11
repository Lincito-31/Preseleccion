#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,sum=0,res=0,a;
map<ll,ll> con;
int main(){
    scanf("%lld%lld",&n,&q);
    con[0]++;
    while(n--){
        scanf("%lld",&a);
        sum+=a;
        res+=con[sum-q];
        con[sum]++;
    }
    printf("%lld",res);
}