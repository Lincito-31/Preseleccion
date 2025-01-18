#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> nums;
vector<vector<int>> dp;
int solve(int x,int y){
    if(x>=y){
        return 1;
    }
    if(dp[x][y]!=1e9){
        return dp[x][y];
    }
    dp[x][y]=1+solve(x+1,y);
    if(nums[x]==nums[y]){
        dp[x][y]=min(dp[x][y],solve(x+1,y-1));
    }
    for(int i=x+1;i<y;i++){
        if(nums[i]==nums[x]){
            dp[x][y]=min(solve(x+1,i-1)+solve(i+1,y),dp[x][y]);
        }
    }
    return dp[x][y];
}
int main(){
    scanf("%d",&n);
    nums.resize(n);
    dp.assign(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    printf("%d",solve(0,n-1));
}