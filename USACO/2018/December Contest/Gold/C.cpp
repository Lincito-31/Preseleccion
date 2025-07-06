#include <bits/stdc++.h>
using namespace std;
int N,K;
int main(){
    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w",stdout);
    scanf("%d %d",&N,&K);
    vector<long long> nums(N);
    vector<long long> dp(N,0);
    for(int i=0;i<N;i++){
        scanf("%lld",&nums[i]);
    }
    dp[0]=nums[0];
    for(int i=1;i<N;i++){
        long long maxi=nums[i];
        for(int j=0;j<K;j++){
            int l=i-j;
            if(l<0){
                break;
            }
            maxi=max(maxi,nums[l]);
            dp[i]=max(dp[i],(l==0?0:dp[l-1])+(j+1)*maxi);
        }
    }
    printf("%lld",dp.back());
}