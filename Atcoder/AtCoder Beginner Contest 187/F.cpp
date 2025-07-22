#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,m,a,b;
int mat[18],dp[1<<20];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        mat[i]|=1<<i;
    }
    while(m--){
        cin >> a >> b;
        a--;b--;
        mat[a]|=1<<b;
        mat[b]|=1<<a;
    }
    for(int i=0;i<(1<<n);i++){
        dp[i]=1e9;
        bool xd=true;
        for(int j=0;j<n && xd;j++){
            if(i&(1<<j)){
                for(int k=0;k<n && xd;k++){
                    if(i&(1<<k)){
                        if(!(mat[j]&(1<<k))){
                            xd=false;
                            break;
                        }
                    }
                }
            }
        }
        if(xd){
            dp[i]=1;
        }
    }
    for(int i=0;i<(1<<n);i++){
        if(dp[i]==1){
            continue;
        }
        for(int j=i;j!=0;j=(j-1)&i){
            int subset=i^j;
            dp[i]=min(dp[i],dp[subset]+dp[i-subset]);
        }
    }
    cout << dp[(1<<n)-1];
}