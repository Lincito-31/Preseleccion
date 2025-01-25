#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n;
int mat[1005][1005];
vector<int> graph[2005];
vector<int> ord;
vector<int> respu(2005,1e9);
vector<bool> visitado(2005);
vector<int> padre(2005);
bool arreglar(int x,int iniciclo,int cantidad){
    bool xd=false;
    if(x==iniciclo && cantidad!=1){
        for(auto u:ord){
            if(!visitado[u]){
                if(!arreglar(u,u,1)){
                    return false;
                }
            }
        }
        vector<int> temp(ord.size());
        for(auto u:ord){
            temp[u]=padre[u];
        }
        if(temp<respu){
            respu=temp;
        }
        return true;
    }
    if(visitado[x]){
        return false;
    }
    visitado[x]=true;
    for(auto u:graph[x]){
        padre[x]=u;
        if(arreglar(u,iniciclo,cantidad+1)){
            xd=true;
        }
    }
    padre[x]=x;
    visitado[x]=false;
    return xd;
}
int main(){
    scanf("%d",&n);
    vector<int> original(2*n+5),nuevo(2*n+5);
    vector<vector<int>> tiene(n+5); 
    vector<bool> visited(2*n+5);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            original[i+j]++;
            padre[i+j]=i+j;
            scanf("%d",&mat[i][j]);
            nuevo[mat[i][j]]++;
            if(visited[mat[i][j]]){
                continue;
            }
            visited[mat[i][j]]=true;
            ord.push_back(mat[i][j]);
        }
    }
    for(int i=2;i<=2*n;i++){
        tiene[original[i]].push_back(i);
    }
    for(int i=2;i<=2*n;i++){
        graph[i]=tiene[nuevo[i]];
    }
    respu.resize(ord.size());
    arreglar(ord[0],ord[0],1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",respu[mat[i][j]]);
        }
        printf("\n");
    }
}