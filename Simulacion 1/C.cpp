#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,a,b,c;
vector<vector<vector<ll>>> graph(1e6);
ll contador=0,nodo=0,buscando=-1;
bool stop=true;
vector<bool> visitado(1e6);
vector<ll> tempel;
vector<bool> eliminado(1e6);
void dfs(ll x,ll camino){
    if(stop || eliminado[x]){
        return;
    }
    if(visitado[x]){
        buscando=x;
        cout << x << " ";
        tempel.push_back(x);
        eliminado[x]=true;
        stop=true;
        return;
    }
    visitado[x]=true;
    for(auto u: graph[x]){
        if(u[2]==camino || eliminado[u[0]]){
            continue;
        }
        dfs(u[0],u[2]);
        if(x==buscando){
            //detiene
            return;
        }
        if(buscando!=-1){
            eliminado[x]=true;
            tempel.push_back(x);
            return;
        }
        if(stop){
            visitado[x]=false;
            return;
        }
    }
    visitado[x]=false;
}
vector<ll> renovado;
vector<vector<ll>> nuevosedges;
void renovar(int x,int ante){
    for(auto u:graph[x]){
        if(u[0]==ante || eliminado[u[0]]){
            continue;
        }
        nuevosedges.push_back({x,u[0],u[1]});
        renovar(u[0],x);
    }
}
int main(){
    scanf("%lld%lld%lld",&n,&m,&t);
    /*graph.assign(n,{});
    visitado.assign(n,false);
    eliminado.assign(n,false);*/
    while(m--){
        scanf("%lld%lld%lld",&a,&b,&c);
        graph[a].push_back({b,c,contador});
        graph[b].push_back({a,c,contador});
        contador++;
    }
    nodo=n;
    //unir componentes
    while(true){
        stop=false;
        dfs(nodo-1,-1);
        if(buscando!=-1){
            buscando=-1;
            for(int i=tempel.size()-1;i>=0;i--){
                for(auto u:graph[i]){
                    if(eliminado[u[0]]){
                        continue;
                    }
                    graph[nodo].push_back({u[0],u[1],contador});
                    graph[u[0]].push_back({nodo,u[1],contador});
                    contador++;
                }
            }
            tempel.clear();
            nodo++;
        }else{
            break;
        }
    }
    /*for(int i=0;true;i++){
        if(!eliminado[i]){
            renovar(i,-1);
            break;
        }
    }*/
    /*ll tot=0;
    for(int i=0;i<nuevosedges.size();i++){
        cout << nuevosedges[i][0] << " " << nuevosedges[i][1] << " "<< nuevosedges[i][2] << endl;
    }*/
    /*for(ll i=0;i<n;i++){
        priority_queue<pair<ll,ll>> dijstra;
        vector<ll> longitud(n,1e18);
        longitud[i]=0;
        dijstra.push({0,i});
        ll con=0;
        while(!dijstra.empty()){
            ll top=dijstra.top().second;
            dijstra.pop();
            for(auto u:graph[top]){
                if(longitud[u.first]>longitud[top]+u.second){
                    longitud[u.first]=longitud[top]+u.second;
                    dijstra.push({-longitud[u.first],u.first});
                }
            }
        }
        for(ll j=0;j<n;j++){
            if(longitud[j]<=t){
                con++;
            }
        }
        con--;
        tot+=con;
    }
    tot/=2;
    printf("%lld",tot);*/
}