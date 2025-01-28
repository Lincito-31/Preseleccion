#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,w;
vector<int> dp(1e6+1,0);
int main(){
    freopen("talent.in","r",stdin);
    freopen("talent.out","w",stdout);
    scanf("%d%d",&n,&w);
    vector<pair<int,int>> cows(n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&cows[i].first,&cows[i].second);
    }
    sort(ALL(cows));
    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=1e6;j>0;j--){
            if(j-cows[i].first<0){
                continue;
            }
            if(dp[j-cows[i].first]==0 && j-cows[i].first!=0){
                continue;
            }
            dp[j]=max(dp[j],dp[j-cows[i].first]+cows[i].second);
            if(j>=w){
                maxi=max(maxi,dp[j]*1000/j);
            }
        }
    }
    printf("%d",maxi);
}