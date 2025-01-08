#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> piiset;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> llset;
ll n;
ll can=0;
int main(){
    freopen("haircut.in","r",stdin);
    freopen("haircut.out","w",stdout);
    scanf("%lld",&n);
    ll res[n+5];
    ll nums[n+5];
    vector<ll> con[n+5];
    piiset conj;
    llset ord;
    for(ll i=0;i<n;i++){
        scanf("%lld",&nums[i]);
        con[nums[i]].push_back(i);
        can+=i-(ll)conj.order_of_key(make_pair(nums[i],1e9));
        conj.insert({nums[i],i});
    }
    for(int j=con[n].size()-1;j>=0;j--){
        can-=(ll)ord.order_of_key(con[n][j]);
        ord.insert(con[n][j]);
    }
    for(ll i=n-1;i>=0;i--){
        for(ll j=con[i].size()-1;j>=0;j--){
            can-=(ll)ord.order_of_key(con[i][j]);
            ord.insert(con[i][j]);
        }
        res[i]=can;
    }
    for(ll i=0;i<n;i++){
        printf("%lld\n",res[i]);
    }
}