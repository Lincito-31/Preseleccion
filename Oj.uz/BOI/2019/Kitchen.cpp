#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[301],sum,dp[301][90001];
int solve(int x,int y){
    if(x<0 || y<0 || (x==0 && y>0)){
        return -1e9;
    }
    if(x==0){
        return 0;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    return dp[x][y]=max(solve(x-1,y),solve(x-1,y-a[x])+min(n,a[x]));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++){
        cin >> a[0];
        if(a[0]<k){
            cout << "Impossible";
            return 0;
        }
        sum+=a[0];
    }
    for(int i=1;i<=m;i++){
        cin >> a[i];
    }
    for(int j=sum;j<=90000;j++){
        for(int i=1;i<=m;i++){
            if(solve(i,j)>=n*k){
                cout << j-sum;
                return 0;
            }
        }
    }
    cout << "Impossible";
}