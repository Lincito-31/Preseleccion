#include <bits/stdc++.h>
using namespace std;
int N,a,b,v;
vector<vector<int>> nums;
vector<vector<vector<vector<int>>>> dp;
int solve(int x1,int y1,int x2,int y2){
    dp[x1][y1][x2][y2]=
}
int main(){
    scanf("%d",&N);
    nums.assign(N+1,vector<int>(N+1,0));
    vector<vector<vector<int>>> temp(N+1,nums);
    dp.assign(N+1,temp);
    while(scanf("%d%d%d",&a,&b,&v),(a!=0)&&(b!=0)&&(v!=0)){
        nums[a][b]=v;
    }
    printf("%d",solve(N,N,N,N));
}