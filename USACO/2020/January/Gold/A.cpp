#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c,dp[1005][1005],earn[1005],a,b,maxi;
vector<pair<int,int>> edges;
int main(){
    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);
    cin >> n >> m >> c;
    for(int i=0;i<n;i++){
        cin >> earn[i];
    }
    while(m--){
        cin >> a >> b;
        edges.push_back({--a,--b});
    }
    for(int i=0;i<1005;i++){
        for(int j=0;j<1005;j++){
            dp[i][j]=-1e18;
        }
    }
    dp[0][0]=0;
    for(int i=1;i<=1000;i++){
        for(auto u:edges){
            dp[u.second][i]=max(dp[u.second][i],dp[u.first][i-1]+earn[u.second]);
        }
        maxi=max(maxi,dp[0][i]-(ll)i*(ll)i*c);
    }
    cout << maxi;
}