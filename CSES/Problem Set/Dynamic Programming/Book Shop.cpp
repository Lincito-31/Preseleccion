#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n,k,dp[1001];
pair<int,int> books[1001];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&books[i].first);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&books[i].second);
    }
    for(int i=0;i<=k;i++){
        dp[i]=0;
    }
    for(int i=1;i<=k;i++){
        
    }
    printf("%d",dp[k]);
}