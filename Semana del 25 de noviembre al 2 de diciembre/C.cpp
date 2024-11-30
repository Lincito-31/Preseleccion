#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<long long> vll;
ll n,m,a,b,c;
vector<pll> graph[100005];
vector<bool> visited(100005,false);
vector<vll> dp(100005,vll(4,0));
vll count(ll now,ll ante){
    if(now==n){
        dp[now][0]=0;
        dp[now][1]=1;
        dp[now][2]=0;
        dp[now][3]=0;
        return dp[now];
    }
    if(!(dp[now][0]==0 && dp[now][1]==0)){
        return dp[now];
    }
    visited[now]=true;
    ll con=0;
    ll mini=1e18,maxilon=0,minilon=1e18;
    for(auto u:graph[now]){
        if(visited[u.first]){
            continue;
        }
        vll x=count(u.first,now);
        if(mini<u.second+x[0]){
            continue;
        }else if(mini==u.second+x[0]){
            con+=x[1];
            maxilon=max(maxilon,1+x[3]);
            minilon=min(minilon,1+x[2]);
        }else{
            mini=u.second+x[0];
            con=x[1];
            maxilon=1+x[3];
            minilon=1+x[2];
        }
    }
    con%=1000000007;
    dp[now][0]=mini;
    dp[now][1]=con;
    dp[now][2]=minilon;
    dp[now][3]=maxilon;
    visited[now]=false;
    return dp[now];
}

int main(){
    scanf("%lld%lld",&n,&m);
    map<ll,map<ll,ll>> guard;
    for(int i=0;i<m;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        if(guard[a][b]==0){
            guard[a][b]=c;
        }else{
            guard[a][b]=min(guard[a][b],c);
        }
    }
    for(auto u:guard){
        for(auto j:u.second){
            graph[u.first].push_back(j);
        }
    }
    vll resp=count(1,0);
    printf("%lld %lld %lld %lld",resp[0],resp[1],resp[2],resp[3]);
}