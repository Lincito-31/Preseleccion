#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,k,nums[100];
vector<int> dp(1e6+1,1e9);
/*int calc(int x){
    if(dp[x]!=1e9){
        return dp[x];
    }
    for(int i=0;i<n;i++){
        if(x-nums[i]>=0){
            dp[x]=min(calc(x-nums[i])+1,dp[x]);
        }
    }
    return dp[x];
}*/
int main(){
    queue<int> bfs;
    dp[0]=0;
    scanf("%d%d",&n,&k);
    bfs.push(0);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    //printf("%d",calc(k)==1e9?-1:calc(k));
    while(!bfs.empty()){
        int now=bfs.front();
        bfs.pop();
        if(now>=k){
            continue;
        }
        for(int i=0;i<n;i++){
            if(now+nums[i]>k){
                continue;
            }
            if(dp[now+nums[i]]>dp[now]+1){
                dp[now+nums[i]]=dp[now]+1;
                bfs.push(now+nums[i]);
            }
        }
    }
    if(dp[k]==1e9){
        printf("-1");
    }else{
        printf("%d",dp[k]);
    }
}