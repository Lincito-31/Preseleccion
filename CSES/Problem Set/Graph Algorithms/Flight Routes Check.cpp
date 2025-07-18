#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector<int> graph1[100000],graph2[100000];
bool visited1[100000],visited2[100000];
void dfs1(int x){
    for(auto u:graph1[x]){
        if(!visited1[u]){
            visited1[u]=true;
            dfs1(u);
        }
    }
}
void dfs2(int x){
    for(auto u:graph2[x]){
        if(!visited2[u]){
            visited2[u]=true;
            dfs2(u);
        }
    }
}
int main(){
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        graph1[--a].push_back(--b);
        graph2[b].push_back(a);
    }
    visited1[0]=true;
    dfs1(0);
    visited2[0]=true;
    dfs2(0);
    for(int i=0;i<n;i++){
        if(!visited1[i] || !visited2[i]){
            cout << "NO\n";
            if(!visited1[i]){
                cout << 1 << ' ' << i+1;
            }else{
                cout << i+1 << ' ' << 1;
            }
            return 0;
        }
    }
    cout << "YES\n";
}