#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a,b,c;
vector<vector<pair<int,int>>> graph;
vector<vector<int>> dp;
int mini=1e9;
void dfs(int now,int ante,int dist,int cantidad){
    if(dist==k){
        mini=min(mini,cantidad);
        return;
    }
    for(auto u:graph[now]){
        if(u.first==ante){
            continue;
        }
        dfs(u.first,now,dist+u.second,cantidad+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    graph.resize(n);
    dp.assign(n,vector<int>(101,1e9));
    for(int i=1;i<n;i++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    for(int i=0;i<n;i++){
        dfs(i,-1,0,0);
    }
}
/*
4 3
0 1 1
1 2 2
1 3 4

2

11 12
0 1 3
0 2 4
2 3 5
3 4 4
4 5 6
0 6 3
6 7 2
6 8 5
8 9 6
8 10 7

2

3 3
0 1 1
1 2 1

-1
*/