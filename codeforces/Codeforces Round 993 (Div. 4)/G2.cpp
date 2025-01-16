#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend();
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
vi parent,dsu,tam,tamano;
vector<bool> visited,visitedcomp,pertenececiclo;
vector<vi> graph;
int t=1,n,a,res;
int find(int x){
    if(x==dsu[x]){
        return x;
    }
    return dsu[x]=find(dsu[x]);
}
void unir(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return;
    }
    if(tam[x]>tam[y]){
        swap(x,y);
    }
    dsu[x]=y;
    tam[y]+=tam[x];
    return;
}
int solve(int x){
    if(tamano[x]!=1){
        return tamano[x];
    }
    for(auto u:graph[x]){
        if(pertenececiclo[u]){
            continue;
        }
        tamano[x]+=solve(u);
    }
    res=max(res,tamano[x]);
    return tamano[x];
}
void calc(int x){
    while(!visited[x]){
        visited[x]=true;
        x=parent[x];
    }
    //x pertenece al ciclo
    int y=parent[x];
    pertenececiclo[x]=true;
    while(y!=x){
        pertenececiclo[y]=true;
        y=parent[y];
    }
    y=parent[x];
    for(auto u:graph[x]){
        if(pertenececiclo[u]){
            continue;
        }
        solve(u);
    }
    while(y!=x){
        for(auto u:graph[y]){
            if(pertenececiclo[u]){
                continue;
            }
            solve(u);
        }
        y=parent[y];
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        res=0;
        scanf("%d",&n);
        visited.assign(n,false);
        parent.assign(n,0);
        dsu.assign(n,0);
        tam.assign(n,1);
        tamano.assign(n,1);
        pertenececiclo.assign(n,false);
        visitedcomp.assign(n,false);
        graph.clear();
        graph.resize(n);
        for(int i=0;i<n;i++){
            dsu[i]=i;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            a--;
            parent[i]=a;
            graph[a].push_back(i);
            unir(i,a);
        }
        for(int i=0;i<n;i++){
            int temp=find(i);
            if(visitedcomp[temp]){
                continue;
            }
            visitedcomp[temp]=true;
            calc(temp);
        }
        printf("%d\n",res+2);
    }
}