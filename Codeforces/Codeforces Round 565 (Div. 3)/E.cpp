#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
int t,n,m,a,b;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        vector<vi> gra(n);
        while(m--){
            scanf("%d%d",&a,&b);
            a--;b--;
            gra[a].push_back(b);
            gra[b].push_back(a);
        }
        vi dist(n,0);
        vector<bool> visited(n,false);
        queue<pair<int,int>> cola;
        cola.push({0,0});
        while(!cola.empty()){
            pair<int,int> par=cola.front();
            cola.pop();
            if(visited[par.first]){
                continue;
            }
            visited[par.first]=true;
            dist[par.first]=par.second;
            for(auto u:gra[par.first]){
                cola.push({u,par.second+1});
            }
        }
        int pares=0,impares=0;
        for(int i=0;i<n;i++){
            dist[i]%=2;
            if(dist[i]==0){
                pares++;
            }else{
                impares++;
            }
        }
        if(pares<=impares){
            printf("%d\n",pares);
            for(int i=0;i<n;i++){
                if(dist[i]==0){
                    printf("%d ",i+1);
                }
            }
        }else{
            printf("%d\n",impares);
            for(int i=0;i<n;i++){
                if(dist[i]==1){
                    printf("%d ",i+1);
                }
            }
        }
        printf("\n");
    }
}