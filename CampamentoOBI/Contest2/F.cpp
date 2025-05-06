#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,Q,a,b;
vector<vector<int>> graph,padre;
vector<int> alt;
void dfs(int now,int ante){
    for(int i=1;i<20;i++){
        padre[now][i]=padre[padre[now][i-1]][i-1];
    }
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        alt[u]=alt[now]+1;
        padre[u][0]=now;
        dfs(u,now);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> Q;
    graph.resize(N);
    alt.resize(N);
    padre.assign(N,vector<int>(20));
    for(int i=0;i<N-1;i++){
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    dfs(0,-1);
    while(Q--){
        cin >> a >> b;
        int res=alt[--a]+alt[--b];
        if(alt[a]<alt[b]){
            swap(a,b);
        }
        int dif=alt[a]-alt[b];
        for(int i=20;i>=0;i--){
            if(dif&(1<<i)){
                a=padre[a][i];
            }
        }
        if(a==b){
            res-=2*alt[a];
        }else{
            for(int i=20;i>=0;i--){
                if(padre[a][i]!=padre[b][i]){
                    a=padre[a][i];
                    b=padre[b][i];
                }
            }
            a=padre[a][0];
            res-=2*alt[a];
        }
        cout << res << '\n';
    }
}
/*
5 3
1 2
1 3
3 4
3 5
1 3
2 5
1 4

1
3
2

*/