#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
int t,n,a,b;
vector<vector<int>> graph;
vector<int> resp;
priority_queue<vll> posibilidades;
vector<bool> used;
pair<int,int> dfs(int now,int ante){
    if(now==-1){
        return {-1,-1};
    }
    pair<int,int> res={now,1};
    for(auto u:graph[now]){
        if(u==ante || u==-1){
            continue;
        }
        pair<int,int> temp=dfs(u,now);
        if(temp.second+1>res.second){
            res.second=temp.second+1;
            res.first=temp.first;
        }else if(temp.second+1==res.second){
            res.first=max(res.first,temp.first);
        }
    }
    return res;
}
bool dfs2(int now,int ante,int target){
    if(now==-1){
        return false;
    }
    if(now==target){
        return used[now]=true;
    }
    for(int i=0;i<graph[now].size();i++){
        if(graph[now][i]==ante || graph[now][i]==-1){
            continue;
        }
        if(dfs2(graph[now][i],now,target)){
            used[now]=true;
            graph[now][i]=-1;
            break;
        }
    }
    if(used[now]){
        for(auto u:graph[now]){
            if(u==ante || u==-1){
                continue;
            }
            for(int i=0;i<graph[u].size();i++){
                if(graph[u][i]==now){
                    graph[u][i]=-1;
                }
            }
            //cout << u+1 << ' ';
            pair<int,int> paso1=dfs(u,-1);
            int w=paso1.first;
            pair<int,int> paso2=dfs(paso1.first,-1);
            int v=paso2.first;
            posibilidades.push({paso2.second,max(w,v),min(w,v)});
        }
    }
    return used[now];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        resp.clear();
        while(!posibilidades.empty()){
            posibilidades.pop();
        }
        cin >> n;
        used.assign(n,false);
        graph.clear();
        graph.resize(n);
        for(int i=0;i<n-1;i++){
            cin >> a >> b;
            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }
        pair<int,int> paso1=dfs(0,-1);
        int u=paso1.first;
        pair<int,int> paso2=dfs(paso1.first,-1);
        int v=paso2.first;
        posibilidades.push({paso2.second,max(u,v),min(u,v)});
        while(!posibilidades.empty()){
            vll top=posibilidades.top();
            posibilidades.pop();
            resp.push_back(top[0]);
            resp.push_back(top[1]+1);
            resp.push_back(top[2]+1);
            dfs2(top[1],-1,top[2]);
        }
        for(auto u:resp){
            cout << u << ' ';
        }
        cout << '\n';
    }
}