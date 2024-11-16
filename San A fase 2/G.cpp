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
ll n,D;
int main(){
    scanf("%lld %lld",&n,&D);
    vll nums(n);
    for(ll i=0;i<n;i++){
        scanf("%lld",&nums[i]);
    }
    sort(REV(nums));
    ll x=nums[0];
    ll y=nums[1];
    ll a=x+y;
    ll con=D/a;
    con*=2;
    D%=a;
    if(D>0){
        D-=x;
        con++;
    }
    if(D>0){
        D-=y;
        con++;
    }
    printf("%lld",con);
}