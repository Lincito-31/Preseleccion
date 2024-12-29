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
map<ll,map<ll,ll>> dp;
map<ll,map<ll,ll>> dp_2;
ll cant(ll leng){
    if(leng<k){
        return 0;
    }
    if(leng==1){
        return 1;
    }
    if(dp_2[leng][k]!=0){
        return dp_2[leng][k];
    }
    int m=(leng+1)/2,r=leng;
    if((leng)%2==0){
        dp_2[leng][k]+=cant(m)+cant(r-m);
    }else{
        dp_2[leng][k]+=1+cant(m-1)+cant(r-m);
    }
    return dp_2[leng][k];
}
ll calc(ll leng){
    if(leng<k){
        return 0;
    }
    if(leng==1){
        return 1;
    }
    if(dp[leng][k]!=0){
        return dp[leng][k];
    }
    int m=(leng+1)/2,r=leng;
    if((leng)%2==0){
        dp[leng][k]+=calc(m)+m*cant(r-m)+calc(r-m);
    }else{
        dp[leng][k]+=m+calc(m-1)+m*cant(r-m)+calc(r-m);
    }
    return dp[leng][k];
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        printf("%lld\n",calc(n));
    }
}
