#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> ATRA;
vector<vector<ll>> dp;
ll maxi=0,N;
ll solve(ll dia, ll posicion){
    if(dia<=0 || posicion<0 || posicion>=N){
        return 0;
    }
    if(dp[dia][posicion]!=0){
        return dp[dia][posicion];
    }
    ll temp=ATRA[posicion];
    ATRA[posicion]=0;
    ll op1=temp+solve(dia-2,posicion-1);
    ll op3=temp+solve(dia-2,posicion+1);
    ATRA[posicion]=temp;
    ll op2=solve(dia-1,posicion-1);
    return dp[dia][posicion]=max(op1,max(op2,op3));
}
ll findMaxAttraction(int n,int start,int d,int attraction[]) {
    N=n;
    ATRA.resize(n);
    for(ll i=0;i<n;i++){
        ATRA[i]=attraction[i];
    }
    dp.assign(d+5,vector<ll>(n+5,0));
    return solve(d,start);
}

int main() {
    int n, start, d;
    int attraction[100000];
    int i, n_s;
    n_s = scanf("%d %d %d", &n, &start, &d);
    for (i = 0 ; i < n; ++i) {
	n_s = scanf("%d", &attraction[i]);
    }
    printf("%lld\n", findMaxAttraction(n, start, d,  attraction));
    return 0;
}
