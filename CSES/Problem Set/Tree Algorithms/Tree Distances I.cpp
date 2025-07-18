#include <bits/stdc++.h>
using namespace std;
int n,a,b;
vector<int> graph[200000];
pair<int,int> alt[200000];
int res[200000];
void dfs(int now,int ante){
    alt[now]={0,0};
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        dfs(u,now);
        if(alt[u].first+1>alt[now].first){
            alt[now].second=alt[now].first;
            alt[now].first=alt[u].first+1;
        }else if(alt[u].first+1>alt[now].second){
            alt[now].second=alt[u].first+1;
        }
    }
}
void reroot(int now,int ante){
    res[now]=alt[now].first;
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        pair<int,int> tempnow=alt[now];
        pair<int,int> tempu=alt[u];
        if(alt[now].first==alt[u].first+1){
            alt[now].first=0;
        }else if(alt[now].second==alt[u].first+1){
            alt[now].second=0;
        }
        int maxi=max(alt[now].first,alt[now].second);
        if(maxi+1>alt[u].first){
            alt[u].second=alt[u].first;
            alt[u].first=maxi+1;
        }else if(maxi+1>alt[u].second){
            alt[u].second=maxi+1;
        }
        reroot(u,now);
        alt[now]=tempnow;
        alt[u]=tempu;
    }
}
int main(){
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    reroot(0,-1);
    for(int i=0;i<n;i++){
        cout << res[i] << ' ';
    }
}