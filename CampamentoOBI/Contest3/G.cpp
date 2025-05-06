#include <bits/stdc++.h>
using namespace std;
int n,a,b;
vector<vector<int>> graph;
vector<int> dp;
int maxi=0,con=0;
void dfsssss(int now,int ante){
    int op1=0,op2=0;
    dp[now]=graph[now].size()-1;
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        dfsssss(u,now);
        if(dp[u]>op1){
            op2=op1;
            op1=dp[u];
        }else if(dp[u]>op2){
            op2=dp[u];
        }
        dp[now]=max(dp[now],dp[u]+(int)graph[now].size()-2);

    }
    maxi=max(maxi,op1+(int)graph[now].size()-1);
    maxi=max(maxi,op1+op2+(int)graph[now].size()-2);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    if(n==1){
        cout << -1;
        return 0;
    }
    graph.resize(n);
    dp.resize(n);
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfsssss(0,-1);
    cout << maxi;
}
/*
8
1 2
2 3
4 2
5 2
6 5
5 7
7 8

5

12
1 2
1 3
2 4
2 5
3 6
3 7
7 8
8 10
8 9
8 11
8 12
*/