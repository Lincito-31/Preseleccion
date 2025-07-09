#include <bits/stdc++.h>
using namespace std;
int g,m,n,t,combi[31][31],nums[30],dp[31][31][10001];
// dp[x][y][z] la cantidad de formas que puedo formar z usando exactamente y cosas hasta la posicion x
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<=30;i++){
        combi[i][0]=combi[i][i]=1;
        for(int j=1;j<i;j++){
            combi[i][j]=combi[i-1][j]+combi[i-1][j-1];
        }
    }
    cin >> g;
    for(int k=1;k<=g;k++){
        cin >> m;
        for(int i=0;i<m;i++){
            cin >> nums[i];
        }
        cin >> n >> t;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                for(int l=0;l<=t;l++){
                    dp[i][j][l]=0;
                }
            }
        }
        dp[0][0][0]++;
        for(int i=1;i<=m;i++){
            for(int j=0;j<=n;j++){
                for(int l=t;l>=0;l--){
                    dp[i][j][l]+=dp[i-1][j][l];
                    if(j>0 && l>=nums[i-1]){
                        dp[i][j][l]+=dp[i-1][j-1][l-nums[i-1]];
                    }
                }
            }
        }
        cout << "Game " << k << " -- " << dp[m][n][t] << " : " << combi[m][n]-dp[m][n][t] << '\n';
    }
}