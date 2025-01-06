#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll n,l=0,r=1e18;
ll cant(ll x){
    ll digit=0,canti=0,cop=x,digitante=0;
    while(cop>0){
        cop/=10;
        digit++;
    }
    cop=x;
    for(ll i=digit-1;i>=0;i--){
        ll pot=(ll)pow(10,i);
        ll diginow=cop/pot;
        cop%=pot;
        if(diginow==0){
            canti+=digitante*pot;
        }else if(diginow==1){
            canti+=digitante*pot+x%pot+1;
        }else{
            canti+=(digitante+1)*pot;
        }
        digitante*=10;
        digitante+=diginow;
    }
    return canti;
}
int main(){
    scanf("%lld",&n);
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(cant(mid)<=n){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    printf("%lld",l);
}