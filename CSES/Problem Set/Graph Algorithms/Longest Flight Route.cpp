#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,m,a,b,dp[100000],pad[100000];
vector<int> graph[100000];
bool visited[100000];
int solve(int x){
    if(x==n-1){
        return 1;
    }
    if(visited[x]){
        return dp[x];
    }
    visited[x]=true;
    for(auto u:graph[x]){
        if(solve(u)==-1e9){
            continue;
        }
        if(solve(u)+1>dp[x]){
            dp[x]=solve(u)+1;
            pad[x]=u;
        }
    }
    if(dp[x]<=0){
        return dp[x]=-1e9;
    }
    return dp[x];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        dp[i]=-1e9;
    }
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
    }
    solve(0);
    if(dp[0]!=-1e9){
        cout << dp[0] << '\n';
        int now=0;
        while(now!=n-1){
            cout << now+1 << ' ';
            now=pad[now];
        }
        cout << now+1;
    }else{
        cout << "IMPOSSIBLE";
    }
} 