#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
ll n,k,sum=0,con=0;
int main(){
    scanf("%lld %lld",&n,&k);
    vector<ll> nums(n);
    while(n--){
        scanf("%lld",&nums[n]);
    }
    sort(REV(nums));
    for(auto u:nums){
        if(sum>=k){
            break;
        }
        sum+=u;
        con++;
    }
    printf("%lld",con);
}