#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p;
int main(){
    while(scanf("%lld%lld",&n,&p)!=EOF){
        printf("%lld\n",abs(n-p));
    }
}