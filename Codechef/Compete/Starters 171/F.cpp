#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
ll t=1,n,k;
ll bigmod(ll base, ll power){
    ll p=1;
    while(power>0){
        if(power%2==1){
            p*=base;
            p%=MOD;
        }
        base*=base;
        base%=MOD;
        power/=2;
    }
    return p;
}
ll inversemod(ll x){
    return bigmod(x,MOD-2);
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        vll nums(n);
        ll tot0=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&nums[i]);
            if(nums[i]==0){
                tot0++;
            }
        }
        bool posi=true;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                if(nums[n-i-1]==0 || nums[n-i-1]==nums[i]){
                    nums[n-i-1]=nums[i];
                }else{
                    posi=false;
                    break;
                }
            }
        }
        if(posi){
            ll nue0=0;
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    nue0++;
                }
            }
            // existe bigmod(k,(nue0+1)/2) palindromos
            // hay total bigmod(k,nue0) formas
            // hay (bigmod(k,nue0)-bigmod(k,(nue0+1)/2))/2 repetidos
            // quedan bigmod(k,tot0)-(bigmod(k,nue0)-bigmod(k,(nue0+1)/2))
            ll first=bigmod(k,nue0)-bigmod(k,(nue0+1)/2)+MOD;
            first%=MOD;
            ll second=first*inversemod(2);
            second%=MOD;
            ll res=bigmod(k,tot0)-second+MOD;
            res%=MOD;
            printf("%lld\n",res);
        }else{
            printf("%lld\n",bigmod(k,tot0));
        }
    }
}