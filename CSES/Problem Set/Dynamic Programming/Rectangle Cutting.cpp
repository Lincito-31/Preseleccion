#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,m,dp[501][501];
int calc(int x,int y){
    if(dp[x][y]!=1e9){
        return dp[x][y];
    }
    for(int i=1;i<x;i++){
        dp[x][y]=min(dp[x][y],calc(i,y)+calc(x-i,y)+1);
    }
    for(int i=1;i<y;i++){
        dp[x][y]=min(dp[x][y],calc(x,i)+calc(x,y-i)+1);
    }
    return dp[x][y];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=1e9;
            if(i==j){
                dp[i][j]=0;
            }
        }
    }
    printf("%d",calc(n,m));
}