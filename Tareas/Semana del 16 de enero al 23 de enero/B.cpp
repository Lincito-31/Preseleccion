#include <bits/stdc++.h>
using namespace std;
int n,a,b;
vector<vector<int>> graph;
int dfs(int now,int ante,int cant){
    int res=cant;
    for(auto u:graph[now]){
        if(u==ante){
            continue;
        }
        res+=dfs(u,now,cant)-1;
    }
    return min(0,res);
}
int main(){
    scanf("%d",&n);
    graph.resize(n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    int l=0,r=3e5;
    while(l<r){
        int mid=(l+r)>>1;
        if(dfs(0,-1,mid)>=0){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%d",l);
}