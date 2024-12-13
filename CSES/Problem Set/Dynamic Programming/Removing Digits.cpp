#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n;
vi dp(1000001,1e9);
int main(){
    dp[0]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int j=i;
        while(j>0){
            if(j%10){
                dp[i]=min(dp[i],dp[i-j%10]+1);
            }
            j/=10;
        }
    }
    printf("%d",dp[n]);
}