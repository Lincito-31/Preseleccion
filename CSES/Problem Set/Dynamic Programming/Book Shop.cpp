#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n,k,dp[100001];
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
    for(int i=0;i<n;i++){
        for(int j=0;j<=k;j++){
            if(j-books[i].first>=0){
                dp[j-books[i].first]=max(dp[j-books[i].first],dp[j]+books[i].second);
            }
        }
    }
    printf("%d",dp[0]);
}