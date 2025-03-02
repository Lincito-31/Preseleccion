#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,a;
//dp[x][y]=minima cantidad de usar 'y' cambios hasta la posicion x;
ll dp[101][501];
ll building[101];
ll calc(ll x,ll y){
    ll cant=0;
    ll now=building[x]/(y+1);
    ll mod=building[x]%(y+1);
    // hay mod con (now+1) y (y+1)-mod con now
    ll res=mod*(now+1)*(now+2)/2;
    res+=(y+1-mod)*(now)*(now+1)/2;
    return res;
}
ll solve(ll x,ll y){
    if(x<0){
        return 0;
    }
    if(dp[x][y]!=1e18){
        return dp[x][y];
    }
    for(ll i=0;i<=y;i++){
        dp[x][y]=min(dp[x][y],solve(x-1,i)+calc(x,y-i));
    }
    return dp[x][y];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0;i<=100;i++){
        building[i]=0;
        for(int j=0;j<=500;j++){
            dp[i][j]=1e18;
        }
    }
    for(ll i=0;i<n;i++){
        cin >> a;
        building[--a]++;
    }
    cout << solve(m-1,k);
}