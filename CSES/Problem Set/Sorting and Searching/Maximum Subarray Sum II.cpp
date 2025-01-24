#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b,maxi=-1e18;
int main(){
    scanf("%lld%lld%lld",&n,&a,&b);
    vector<ll> nums(n+1),psum(n+1);
    multiset<ll> posi;
    for(ll i=1;i<=n;i++){
        scanf("%lld",&nums[i]);
        psum[i]=psum[i-1]+nums[i];
        if(i-a>=0){
            posi.insert(psum[i-a]);
        }
        if(i-b-1>=0){
            posi.erase(posi.find(psum[i-b-1]));
        }
        if(!posi.empty()){
            maxi=max(maxi,psum[i]-*posi.begin());
        }
    }
    printf("%lld",maxi);
}