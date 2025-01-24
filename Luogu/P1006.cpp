#include <bits/stdc++.h>
using namespace std;
int n,m;
int mat[51][51],dp[51][51][51][51];
int solve(int x1,int y1,int x2,int y2){
    if((x1==1)&&(x2==1)&&(y1==1)&&(y2==1)){
        return 0;
    }
    if((x1==x2)&&(y1==y2)&&!(x1==n&&y1==m)){
        return -1e5;
    }
    if(x1<1 || y1<1 || x2<1 || y2<1){
        return -1e5;
    }
    if(dp[x1][y1][x2][y2]!=-1e5){
        return dp[x1][y1][x2][y2];
    }
    return dp[x1][y1][x2][y2]=max(max(solve(x1-1,y1,x2-1,y2),solve(x1,y1-1,x2-1,y2)),max(solve(x1-1,y1,x2,y2-1),solve(x1,y1-1,x2,y2-1)))+mat[x1][y1]+mat[x2][y2];
}
int main(){
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            for(int k=0;k<51;k++){
                for(int l=0;l<51;l++){
                    dp[i][j][k][l]=-1e5;
                }
            }
        }
    }
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    printf("%d",solve(n,m,n,m));
}