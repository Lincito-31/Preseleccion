#include <bits/stdc++.h>
#define MOD 1000000007
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
        dp[x]+=solve(u);
        dp[x]%=MOD;
    }
    return dp[x];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
    }
    cout << solve(0);
} 