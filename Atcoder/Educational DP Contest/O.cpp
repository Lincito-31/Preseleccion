#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,m,x;
// hasta el hombre "pos" con el "conjunto" usado
int mat[22],dp[2][1<<21];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> x;
            mat[i]|=x<<j;
        }
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int conjunto=0;conjunto<(1<<n);conjunto++){
            if(dp[0][conjunto]){
                for(int j=0;j<n;j++){
                    if((mat[i]&(1<<j)) && !(conjunto&(1<<j))){
                        dp[1][conjunto+(1<<j)]+=dp[0][conjunto];
                        dp[1][conjunto+(1<<j)]%=MOD;
                    }
                }
            }
        }
        for(int conjunto=0;conjunto<(1<<n);conjunto++){
            dp[0][conjunto]=dp[1][conjunto];
            dp[1][conjunto]=0;
        }
    }
    cout << dp[0][(1<<n)-1];
}