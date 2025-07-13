#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100];
int con[100],n,a,b;
void dfs(int now,int ante){
    con[now]++;
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        dfs(u,now);
    }
}
int main(){
    ifstream in("factory.in");
    ofstream out("factory.out");
    in >> n;
    for(int i=1;i<n;i++){
        in >> a >> b;
        graph[--a].push_back(--b);
    }
    for(int i=0;i<n;i++){
        dfs(i,-1);
    }
    for(int i=0;i<n;i++){
        if(con[i]==n){
            out << i+1;
            return 0;
        }
    }
    out << -1;
}