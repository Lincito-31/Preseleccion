#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,t,m;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        vector<ll> nums(n);
        for(ll i=0;i<n;i++){
            scanf("%lld",&nums[i]);
            nums[i]%=m;
        }
        sort(ALL(nums));
        ll iz=0,de=n-1;
        ll mid=(iz+de)/2;
        ll ref=nums[mid];
        ll res=0;
        for(ll i=0;i<n;i++){
            res+=abs(nums[i]-ref);
        }
        ll fina=res;
        for(ll i=0;i<n;i++){
            nums.push_back(nums[i]+m);
            ll xx=mid-iz+1,yy=de-mid;
            iz++;
            de++;
            mid=(iz+de)/2;
            ll nuev=nums[mid];
            res+=(xx-yy)*(nuev-ref);
            res-=nuev-nums[iz-1];
            res+=nums[de]-nuev;
            ref=nuev;
            fina=min(fina,res);
        }
        printf("%lld\n",fina);
    }
}