#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int nums[300];
vector<vi> mat;
vector<vector<vi>> dp;
int t,l,n,m;
bool best(int x,int y,int pos){
    if(x>=n || y>=m || pos>=l){
        return false;
    }
    if(dp[pos][x][y]!=0){
        if(dp[pos][x][y]==1){
            return true;
        }else{
            return false;
        }
    }
    for(int ii=x;ii<n;ii++){
        for(int jj=y;jj<m;jj++){
            if(mat[ii][jj]==nums[pos]){
                if(!best(ii+1,jj+1,pos+1)){
                    dp[pos][x][y]=1;
                    return true;
                }
            }
        }
    }
    dp[pos][x][y]=2;
    return false;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&l,&n,&m);
        for(int i=0;i<l;i++){
            scanf("%d",&nums[i]);
        }
        mat.clear();
        mat.assign(n,vi(m,0));
        dp.clear();
        dp.assign(l,mat);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&mat[i][j]);
            }
        }
        if(best(0,0,0)==true){
            printf("T\n");
        }else{
            printf("N\n");
        }
    }
}
