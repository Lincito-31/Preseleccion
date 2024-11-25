#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ALL(x) x.begin(),x.end()
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef vector<int> vi;
typedef vector<pii> vii;
int n,t;
ll iz=0,de=1e18+1;
int nums[200005];
ll calc(ll x){
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=x/nums[i];
        if(sum>1e9){
            return sum;
        }
    }
    return sum;
}
int main(){
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    while(iz<de){
        ll mid=(iz+de)>>1;
        ll res=calc(mid);
        if(res>=t){
            de=mid;
        }else{
            iz=mid+1;
        }
    }
    printf("%lld",de);
}