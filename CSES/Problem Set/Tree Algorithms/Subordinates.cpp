#include <bits/stdc++.h>
using namespace std;
int n,x;
vector<int> graph[200000];
int hij[200000];
void dfs(int x){
    for(auto u:graph[x]){
        dfs(u);
        hij[x]+=hij[u];
        hij[x]++;
    }
}
int main(){
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> x;
        graph[--x].push_back(i);
    }
    dfs(0);
    for(int i=0;i<n;i++){
        cout << hij[i] << ' ';
    }
}