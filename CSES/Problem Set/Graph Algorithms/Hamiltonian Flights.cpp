#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n,m,a,b;
vector<int> graph[20];
ll suma,memo[1<<20][20];
int solve(int conjunto,int last){
    if(!(conjunto&1) && conjunto){
        memo[conjunto][last]=-1;
        return 0;
    }
    if(conjunto==0 && last==0){
        return 1;
    }
    if(memo[conjunto][last]!=0){
        if(memo[conjunto][last]==-1){
            return 0;
        }
        return memo[conjunto][last];
    }
    for(auto u:graph[last]){
        if(conjunto&(1<<u)){
            memo[conjunto][last]+=solve(conjunto-(1<<u),u);
            memo[conjunto][last]%=MOD;
        }
    }
    if(memo[conjunto][last]==0){
        memo[conjunto][last]=-1;
        return 0;
    }
    return memo[conjunto][last];
}
int main(){
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        graph[--b].push_back(--a);
    }
    cout << solve((1<<(n-1))-1,n-1);
}