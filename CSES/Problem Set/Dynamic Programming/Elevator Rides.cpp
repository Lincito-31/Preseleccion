#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,m,nums[20];
// hasta el hombre "pos" con el "conjunto" usado
pair<int,int> dp[1<<20];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    for(int i=0;i<(1<<n);i++){
        dp[i]={1e9,1e9};
    }
    dp[0]={1,0};
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(!(i&(1<<j))){
                int numrid,numele;
                if(dp[i].second+nums[j]<=m){
                    numele=dp[i].second+nums[j];
                    numrid=dp[i].first;
                }else{
                    numrid=dp[i].first+1;
                    numele=nums[j];
                }
                dp[i|(1<<j)]=min(dp[i|(1<<j)],{numrid,numele});
            }
        }
    }
    cout << dp[(1<<n)-1].first;
}