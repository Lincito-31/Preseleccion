#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> gra;
vector<ll> ciclo;
vector<ll> tam;
vector<bool> visitado;
ll t,n,a,b,node,con;
bool xd;
void reset(){
    gra.assign(n,{});
    ciclo.clear();
    node=0;
    visitado.assign(n,false);
    xd=false;
    tam.assign(n,0);
}
void dfs(ll ahora, ll ante){
    if(visitado[ahora]){
        node=ahora;
        return;
    }
    visitado[ahora]=true;
    for(auto u: gra[ahora]){
        if(u==ante){
            continue;
        }
        dfs(u,ahora);
    }
}
void dfs2(ll ahora, ll ante){
    if(visitado[ahora]){
        xd=true;
        return;
    }
    ciclo.push_back(ahora);
    visitado[ahora]=true;
    for(auto u: gra[ahora]){
        if(xd){
            return;
        }
        if(u==ante){
            continue;
        }
        dfs2(u,ahora);
        if(xd){
            return;
        }
    }
    if(xd){
        return;
    }
    ciclo.pop_back();
}
void dfs3(ll ahora,ll ante){
    con++;
    for(auto u: gra[ahora]){
        if(u==ante || visitado[u]){
            continue;
        }
        dfs3(u,ahora);
    }
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        reset();
        ll res=n*(n-1)/2;
        for(int i=0;i<n;i++){
            scanf("%lld %lld",&a,&b);
            a--;b--;
            gra[a].push_back(b);
            gra[b].push_back(a);
        }
        // paso 1: detectar ciclo
        // encontrar un nodo del ciclo=node
        dfs(0,-1);
        // encontrar todos los nodos del ciclo=ciclo
        visitado.assign(n,false);
        dfs2(node,-1);
        // paso 2: encontrar el tamaño de cada arbol del nodo del ciclo como raiz;
        visitado.assign(n,false);
        ll m=ciclo.size();
        for(int i=0;i<m;i++){
            visitado[ciclo[i]]=true;
        }
        for(int i=0;i<m;i++){
            con=0;
            dfs3(ciclo[i],-1);
            tam[ciclo[i]]=con;
        }
        // paso 3: crear un prefixsum
        vector<ll> sum(m);
        sum[1]=tam[ciclo[1]];
        for(int i=2;i<m;i++){
            sum[i]=sum[i-1]+tam[ciclo[i]];
        }
        // paso 4: usar combi y sumar
        res+=tam[ciclo[0]]*sum[m-1];
        for(int i=m-1;i>=2;i--){
            res+=tam[ciclo[i]]*sum[i-1];
        }
        printf("%lld\n",res);
    }
}