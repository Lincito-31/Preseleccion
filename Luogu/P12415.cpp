#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,m,sum;
//dp[i][j]=estoy en row i y me falta poner j;
vector<vector<ll>> dp(81,vector<ll>(6561,-1));
ll combi[81][81];
ll bigpower(ll b, ll e){
    ll p=1;
    while(e>0){
        if(e%2){
            p*=b;
            p%=MOD;
        }
        b*=b;
        b%=MOD;
        e/=2;
    }
    return p;
}
ll solve(ll row,ll queda){
    if(row<=0 || queda<=0){
        return 0;
    }
    if(queda==1){
        return m;
    }
    if(dp[row][queda]!=-1){
        return dp[row][queda];
    }
    dp[row][queda]=0;
    for(int i=min(queda,m);i>=0;i--){
        dp[row][queda]+=(((combi[m][i]*solve(row-1,queda-i))%MOD)*bigpower(queda-i,i))%MOD;
        dp[row][queda]%=MOD;
    }
    return dp[row][queda];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<=80;i++){
        combi[i][0]=combi[i][i]=1;
        for(int j=1;j<i;j++){
            combi[i][j]=combi[i-1][j-1]+combi[i-1][j];
            combi[i][j]%=MOD;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n*m;j++){
            sum+=solve(i,j);
            sum%=MOD;
        }
    }
    cout << sum;
}