#include <bits/stdc++.h>
using namespace std;
bool visitado[300000],visitado_comp[300000],existe_ciclo=false,visited[300000];
int n,m,a,b,maxi=0,maxiletra[300000][26],maxicanti[300000];
vector<int> alrevgraph[300000];
char cade[300000];
void findciclo(int x){
    if(visitado[x] || existe_ciclo){
        existe_ciclo=true;
        return;
    }
    if(visitado_comp[x]){
        return;
    }
    visitado[x]=visitado_comp[x]=true;
    for(auto u:alrevgraph[x]){
        findciclo(u);
    }
    visitado[x]=false;
}
int dfs(int x){
    if(maxicanti[x]){
        return maxicanti[x];
    }
    for(auto u:alrevgraph[x]){
        dfs(u);
        for(int i=0;i<26;i++){
            maxiletra[x][i]=max(maxiletra[x][i],maxiletra[u][i]);
        }
    }
    maxiletra[x][cade[x]-97]++;
    for(int i=0;i<26;i++){
        maxicanti[x]=max(maxiletra[x][i],maxicanti[x]);
    }
    return maxicanti[x];
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",cade);
    for(int i=0;i<n;i++){
        visitado_comp[i]=visited[i]=visitado[i]=maxicanti[i]=false;
        for(int j=0;j<26;j++){
            maxiletra[i][j]=0;
        }
    }
    while(m--){
        scanf("%d%d",&a,&b);
        a--;b--;
        alrevgraph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(visitado_comp[i]){
            continue;
        }
        findciclo(i);
        if(existe_ciclo){
            printf("-1");
            return 0;
        }
    }

    for(int i=0;i<n;i++){
        maxi=max(maxi,dfs(i));
    }
    printf("%d",maxi);
}