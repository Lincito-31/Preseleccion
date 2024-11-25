#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
vector<int> graph[2505];
vector<int> longitud(2505,1e9);
int djs[2505];
int tam[2505];
bool visitadodjs[2505];
//bool visited[2505][2505];
int now=0,mini=1e9;
//map<int,map<int,map<int,bool>>> visited;
void dfs(int x,int ante,int subante){
    if(mini==3){
        return;
    }
    /*if(visited[x][ante][subante]){
        return;
    }
    visited[x][ante][subante]=true;*/
    if(longitud[x]==1e9){
        longitud[x]=now;
        now++;
        for(auto u:graph[x]){
            if(u==ante){
                continue;
            }
            dfs(u,x,ante);
        }
        now--;
        longitud[x]=1e9;
    }else{
        mini=min(now-longitud[x],mini);
    }
}
int find(int x){
    if(djs[x]==x){
        return x;
    }
    return djs[x]=find(djs[x]);
}
void unir(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        mini=min(mini,tam[x]);
        return;
    }
    if(tam[x]>tam[y]){
        djs[y]=x;
        tam[x]+=tam[y];
    }else{
        djs[x]=y;
        tam[y]+=tam[x];
    }
}
int main(){
    for(int i=0;i<2505;i++){
        djs[i]=i;
        tam[i]=1;
        visitadodjs[i]=false;
    }
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        unir(a,b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(visitadodjs[find(i)]){
            continue;
        }
        visitadodjs[find(i)]=true;
        dfs(find(i),0,-1);
    }
    if(mini==1e9){
        printf("-1");
    }else{
        printf("%d",mini);
    }
}