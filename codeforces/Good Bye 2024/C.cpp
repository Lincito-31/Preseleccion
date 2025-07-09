//Lincito_31 is my main account
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end();
#define REV(x) x.rbegin(),x.rend();
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll t=1,n,k;
pair<ll,ll> solve(ll n){
    pair<ll,ll> res={0,0};
    if(n<k){
        return res;
    }
    if(n%2){
        res.first+=(n+1)/2;
        res.second++;
    }
    pair<ll,ll> x=solve(n/2);
    res.first+=2*x.first+((n+1)/2)*x.second;
    res.second+=2*x.second;
    return res;
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        printf("%lld\n",solve(n).first);
    }
}
