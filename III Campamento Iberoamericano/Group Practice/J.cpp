#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int n,con=0,k;
int main(){
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    scanf("%d%d",&n,&k);
    vector<char> hps(n);
    for(int i=0;i<n;i++){
        scanf(" %c",&hps[i]);
    }
    int dp[n][k+1][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            for(int k=0;k<3;k++){
                dp[i][j][k]=0;
            }
        }
    }
    dp[0][k][0]=(hps[0]=='H'?1:0);
    dp[0][k][1]=(hps[0]=='P'?1:0);
    dp[0][k][2]=(hps[0]=='S'?1:0);
    for(int i=1;i<n;i++){
        dp[i][k][0]=dp[i-1][k][0]+(hps[i]=='H'?1:0);
        dp[i][k][1]=dp[i-1][k][1]+(hps[i]=='P'?1:0);
        dp[i][k][2]=dp[i-1][k][2]+(hps[i]=='S'?1:0);
    }
    for(int j=k-1;j>=0;j--){
        dp[0][j][0]=dp[0][j+1][0];
        dp[0][j][1]=dp[0][j+1][1];
        dp[0][j][2]=dp[0][j+1][2];
    }
    for(int i=1;i<n;i++){
        for(int j=k-1;j>=0;j--){
            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j+1][1])+(hps[i]=='H'?1:0);
            dp[i][j][0]=max(dp[i][j][0],dp[i-1][j+1][2]+(hps[i]=='H'?1:0));
            dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j+1][0])+(hps[i]=='P'?1:0);
            dp[i][j][1]=max(dp[i][j][1],dp[i-1][j+1][2]+(hps[i]=='P'?1:0));
            dp[i][j][2]=max(dp[i-1][j][2],dp[i-1][j+1][1])+(hps[i]=='S'?1:0);
            dp[i][j][2]=max(dp[i][j][2],dp[i-1][j+1][0]+(hps[i]=='S'?1:0));
        }
    }
    con=max(dp[n-1][0][0],max(dp[n-1][0][1],dp[n-1][0][2]));
    printf("%d",con);
}