#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef pair<int,int> pii;
ll t,n,x,a;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&x);
        ll maxi=0,sum=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&a);
            sum+=a;
            maxi=max(maxi,a);
        }
        sum=(sum-1)/x+1;
        printf("%lld\n",max(maxi,sum));
    }
}