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
int t,n,r;
int main(){
    scanf("%d",&t);
    while(t--){
        int res=0;
        scanf("%d %d",&n,&r);
        r*=2;
        vi nums(n);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
            int can=nums[i]/2;
            can*=2;
            res+=can;
            r-=can;
            nums[i]%=2;
        }
        int queda=0;
        for(int i=0;i<n;i++){
            queda+=nums[i];
        }
        res+=min(r-queda,queda);
        printf("%d\n",res);
    }
}