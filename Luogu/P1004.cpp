#include <bits/stdc++.h>
using namespace std;
int N,a,b,v;
vector<vector<int>> nums;
vector<vector<vector<vector<int>>>> dp;
int main(){
    scanf("%d",&N);
    nums.assign(N+1,vector<int>(N+1,0));
    vector<vector<vector<int>>> temp(N+1,nums);
    dp.assign(N+1,temp);
    while(scanf("%d%d%d",&a,&b,&v),(a!=0)&&(b!=0)&&(v!=0)){
        nums[a][b]=v;
    }
    for(int x1=1;x1<=N;x1++){
        for(int y1=1;y1<=N;y1++){
            for(int x2=1;x2<=N;x2++){
                for(int y2=1;y2<=N;y2++){
                    if(x1==x2 && y1==y2){
                        int op1=dp[x1-1][y1][x2-1][y2]+nums[x1][y1];
                        int op2=dp[x1][y1-1][x2-1][y2]+nums[x1][y1];
                        int op3=dp[x1-1][y1][x2][y2-1]+nums[x1][y1];
                        int op4=dp[x1][y1-1][x2][y2-1]+nums[x1][y1];
                        dp[x1][y1][x2][y2]=max(max(op1,op2),max(op3,op4));
                    }else{
                        int op1=dp[x1-1][y1][x2-1][y2]+nums[x1][y1]+nums[x2][y2];
                        int op2=dp[x1][y1-1][x2-1][y2]+nums[x1][y1]+nums[x2][y2];
                        int op3=dp[x1-1][y1][x2][y2-1]+nums[x1][y1]+nums[x2][y2];
                        int op4=dp[x1][y1-1][x2][y2-1]+nums[x1][y1]+nums[x2][y2];
                        dp[x1][y1][x2][y2]=max(max(op1,op2),max(op3,op4));
                    }
                }
            }
        }
    }
    printf("%d",dp[N][N][N][N]);
}