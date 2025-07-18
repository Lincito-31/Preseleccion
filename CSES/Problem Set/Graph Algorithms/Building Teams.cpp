#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,m,a,b;
vector<int> graph[100000];
vector<int> rep(100000);
bool dfs(int x){
    for(auto u:graph[x]){
        if(rep[u]==0){
            if(rep[x]==1){
                rep[u]=2;
            }else{
                rep[u]=1;
            }
            if(!dfs(u)){
                return false;
            }
        }else{
            if(rep[x]==rep[u]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(rep[i]==0){
            rep[i]=1;
            if(!dfs(i)){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << rep[i] << ' ';
    }
}