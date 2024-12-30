#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
ll n;
int main(){ 
    scanf("%lld",&n); 
    ll l=1,r=1e12;
    ll need=(n*n-1)>>1;
    while(l<r){
        ll mid=(l+r)>>1;
        ll now=0;
        for(int i=1;i<=n;i++){
            now+=min(mid/i,n);
        }
        now--;
        if(now>=need){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%lld",l);
}