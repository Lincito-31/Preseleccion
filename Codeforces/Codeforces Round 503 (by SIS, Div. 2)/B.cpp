#include <bits/stdc++.h>
using namespace std;
int n,to[1000],res[1000];
vector<int> revgraph[1000];
bool visited[1000];
void reve(int x,int val){
    res[x]=val;
    for(auto u:revgraph[x]){
        if(res[u]==-1){
            reve(u,val);
        }
    }
}
void floyd(int x){
    x=to[x];
    int y=to[x];
    while(x!=y){
        x=to[x];
        y=to[to[y]];
    }
    res[x]=x;
    x=to[x];
    while(x!=y){
        res[x]=x;
        x=to[x];
    }
    reve(x,x);
    x=to[x];
    while(x!=y){
        reve(x,x);
        x=to[x];
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> to[i];
        to[i]--;
        revgraph[to[i]].push_back(i);
        res[i]=-1;
    }
    for(int i=0;i<n;i++){
        if(res[i]==-1){
            floyd(i);
        }
        cout << res[i]+1 << ' ';
    }
}