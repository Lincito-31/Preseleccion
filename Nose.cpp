#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,k,nums[100],dp[1000001];
int main(){
    dp[0]=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    for(int i=1;i<=k;i++){
        dp[i]=1e9;
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i-nums[j]>=0){
                dp[i]=min(dp[i],dp[i-nums[j]]+1);
            }
        }
    }
    int con=0;
    for(int i=1;i<=k;i++){
        int greedy=i/25;
        int a=i;
        a%=25;
        greedy+=a/10;
        a%=10;
        greedy+=a;
        if(greedy==dp[i]){
            con++;
        }
    }
    cout << con;
}