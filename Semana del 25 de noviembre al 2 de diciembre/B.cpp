// sol 1
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,m,a,b;
vector<int> graph[2505];
int padre[2505];
int mini=1e9;
vector<int> comp[2505];
int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        vector<int> lon(n+5,1e9);
        queue<vi> bfs;
        lon[i]=1;
        bfs.push({1,0,1});
        while(!bfs.empty()){
            int now=bfs.front()[0];
            int ante=bfs.front()[1];
            int longit=bfs.front()[2];
            bfs.pop();
            if(lon[])
            for(auto u:graph[now]){
                if(u==ante)
            }
        }
    }
}