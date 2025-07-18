#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
int main(){
    cin >> n >> m;
    vector<int> graph[n],dist(n),par(n);
    queue<int> bfs;
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    bfs.push(0);
    dist[0]=0;
    while(!bfs.empty()){
        int top=bfs.front();
        bfs.pop();
        for(auto u:graph[top]){
            if(dist[u]==0){
                dist[u]=dist[top]+1;
                par[u]=top;
                bfs.push(u);
            }
        }
    }
    if(dist[n-1]){
        cout << dist[n-1]+1 << '\n';
        vector<int> res;
        a=n-1;
        while(a!=0){
            res.push_back(a);
            a=par[a];
        }
        res.push_back(a);
        for(int i=res.size()-1;i>=0;i--){
            cout << res[i]+1 << ' ';
        }
    }else{
        cout << "IMPOSSIBLE";
    }
}