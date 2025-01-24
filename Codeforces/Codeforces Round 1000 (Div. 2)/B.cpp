#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
ll t=1,n,l,r;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&l,&r);
        l--;
        r--;
        vll nums(n);
        for(ll i=0;i<n;i++){
            scanf("%lld",&nums[i]);
        }
        vll need(r-l+1);
        for(ll i=l;i<=r;i++){
            need[i-l]=nums[i];
        }
        vll cop=need;
        for(ll i=0;i<l;i++){
            need.push_back(nums[i]);
        }
        for(ll i=r+1;i<n;i++){
            cop.push_back(nums[i]);
        }
        sort(ALL(need));
        sort(ALL(cop));
        ll temp=0,temp2=0;
        for(int i=0;i<r-l+1;i++){
            temp+=need[i];
        }
        for(int i=0;i<r-l+1;i++){
            temp2+=cop[i];
        }
        printf("%lld\n",min(temp,temp2));
    }
}
