#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 998244353
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
ll t=1,n,k;
ll bigmod(ll base, ll power){
    ll p=1;
    while(power>0){
        if(power%2){
            p*=base;
            p%=MOD;
        }
        power/=2;
        base*=base;
        base%=MOD;
    }
    return p;
}
ll combi(ll x,ll y){
    ll arri=1,ab=1;
    for(ll i=0;i<y;i++){
        arri*=x-i;
        arri%=MOD;
        ab*=i+1;
        ab%=MOD;
    }
    return (arri*bigmod(ab,MOD-2))%MOD;
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&k,&n);
        vector<vll> dp(k+1,vll(17,0));
        for(int i=2;i<=k;i++){
            dp[i][1]=1;
            for(int j=2;j<17;j++){
                for(int iii=2;iii*iii<=i;iii++){
                    if(iii*iii==i){
                        dp[i][j]+=dp[iii][j-1];
                    }else if(i%iii==0){
                        dp[i][j]+=dp[iii][j-1];
                        dp[i][j]+=dp[i/iii][j-1];
                    }
                }
            }
        }
        printf("%lld",n);
        for(int i=2;i<=k;i++){
            ll sum=0;
            for(int j=1;j<=16;j++){
                sum+=dp[i][j]*combi(n+1,j+1);
                sum%=MOD;
            }
            printf(" %lld",sum);
        }
        printf("\n");
    }
}
