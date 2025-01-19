#include <bits/stdc++.h>
using namespace std;
typedef __int128 lll;
void print(lll x) {
    if(x<0) {
        putchar('-');
        x=-x;
    }
    if(x>9)print(x / 10);
    putchar(x % 10 + '0');
}
int n,m,mat[80][80];
lll res=0,dp[80][80][80];
lll solve(int row,int l,int r,int ii){
    if(l>r){
        return 0;
    }
    if(dp[row][l][r]!=0){
        return dp[row][l][r];
    }
    return dp[row][l][r]=max(solve(row,l+1,r,ii+1)+(lll)mat[row][l]*(lll)pow(2,ii),solve(row,l,r-1,ii+1)+(lll)mat[row][r]*(lll)pow(2,ii));
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<80;i++){
        for(int j=0;j<80;j++){
            for(int k=0;k<80;k++){
                dp[i][j][k]=0;
            }
            mat[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
        res+=solve(i,0,m-1,1);
    }
    print(res);
}