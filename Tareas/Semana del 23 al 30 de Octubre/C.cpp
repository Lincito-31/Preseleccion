//https://codeforces.com/contest/699/problem/C
#include <bits/stdc++.h>
using namespace std;
int n;
/*
b=
0:none
1:contest
2:gym
*/
vector<int> nums(100);
vector<vector<int>> dp(100,vector<int>(3,1e9));
int calc(int now,int mode){
    if(now==n){
        return 0;
    }
    if(dp[now][mode]!=1e9){
        return dp[now][mode];
    }
    if(mode==0){
        if(nums[now]==0){
            dp[now][mode]=1+calc(now+1,0);
        }else if(nums[now]==1){
            dp[now][mode]=calc(now+1,1);
        }else if(nums[now]==2){
            dp[now][mode]=calc(now+1,2);
        }else{
            dp[now][mode]=min(calc(now+1,1),calc(now+1,2));
        }
    }else if(mode==1){
        if(nums[now]==0 || nums[now]==1){
            dp[now][mode]=1+calc(now+1,0);
        }else if(nums[now]==2){
            dp[now][mode]=calc(now+1,2);
        }else{
            dp[now][mode]=min(1+calc(now+1,0),calc(now+1,2));
        }
    }else{
        if(nums[now]==0 || nums[now]==2){
            dp[now][mode]=1+calc(now+1,0);
        }else if(nums[now]==1){
            dp[now][mode]=calc(now+1,1);
        }else{
            dp[now][mode]=min(1+calc(now+1,0),calc(now+1,1));
        }
    }
    return dp[now][mode];
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    printf("%d",calc(0,0));
}