#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define MOD 1000000007
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll t=1,n,k;
vll pot(2e5+5);
int main(){
    scanf("%lld",&t);
    pot[1]=1;
    for(int i=2;i<60;i++){
        pot[i]=pot[i-1]<<1;
    }
    for(int i=60;i<2e5+5;i++){
        pot[i]=pot[i-1];
    }
    while(t--){
        scanf("%lld%lld",&n,&k);
        if(k>pot[n]){
            printf("-1\n");
        }else{
            ll m=n;
            vi nums(n);
            int l=0,r=n-1;
            int now=1;
            while(l<r){
                if(k<=pot[n-1]){
                    nums[l]=now;
                    l++;
                }else{
                    nums[r]=now;
                    r--;
                    k-=pot[n-1];
                }
                n--;
                now++;
            }
            for(int i=0;i<m;i++){
                if(nums[i]==0){
                    printf("%lld ",m);
                    continue;
                }
                printf("%d ",nums[i]);
            }
            printf("\n");
        }
    }
}