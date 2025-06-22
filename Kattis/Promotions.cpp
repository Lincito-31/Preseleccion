#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef long double ld;
int a,b,n,m,x,y,certa,certb,noposi,canti;
vector<int> graph[5000],revgraph[5000];
bitset<5000> visited;
void dfs(int x){
    visited[x]=true;
    canti++;
    for(auto u:graph[x]){
        if(!visited[u]){
            dfs(u);
        }
    }
}
void dfs2(int x){
    visited[x]=true;
    canti++;
    for(auto u:revgraph[x]){
        if(!visited[u]){
            dfs2(u);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> n >> m;
    while(m--){
        cin >> x >> y;
        graph[x].push_back(y);
        revgraph[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        visited=0;
        canti=0;
        dfs(i);
        if(b>n-canti){
            certb++;
            if(a>n-canti){
                certa++;
            }
        }
        visited=0;
        canti=0;
        dfs2(i);
        if(canti-1>=b){
            noposi++;
        }
    }
    cout << certa << '\n' << certb << '\n' << noposi;
}