#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
int n,k;
int main(){
    scanf("%d %d",&n,&k);
    vi nums(k);
    for(int i=0;i<k;i++){
        scanf("%d",&nums[i]);
    }
    sort(REV(nums));
    ll res=0;
    for(int i=1;i<k;i++){
        res+=nums[i]-1+nums[i];
    }
    printf("%lld",res);
}