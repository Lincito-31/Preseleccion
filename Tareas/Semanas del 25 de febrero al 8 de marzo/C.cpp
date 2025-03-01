#include <bits/stdc++.h>
using namespace std;
int n,m,k,a;
//dp1[x][y]=minima cantidad de usar 'y' cambios en la posicion x;
//dp2[x][y]=minima cantidad de usar 'y' cambios hasta la posicion x;
long long dp1[101][501],dp[101][501];
int building[101];
long long calc(int x,int y){

}
long long solve(int x,int y){
    if(dp[x][y]!=1e18){
        return dp[x][y];
    }
    for(int i=0;i<=y;i++){
        dp[x][y]=min(dp[x][y],solve(x-1,i)+calc(x,y-i));
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    vector<int> bulding(m+1);
    for(int i=0;i<n;i++){
        cin >> a;
        bulding[a]++;
    }
    
}