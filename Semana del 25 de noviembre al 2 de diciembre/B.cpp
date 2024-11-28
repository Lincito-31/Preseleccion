// sol 1
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,m,a,b;
vector<int> graph[2505];
int padre[2505];
int longitud[2505];
bool visitadoedges[2505][2505];
int mini=1e9;
int djs[2505];
int tam[2505];
vector<int> comp[2505];
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

int ances(int x,int y){
    if(longitud[x]<longitud[y]){
        return ances(x,padre[y]);
    }
    if(longitud[x]>longitud[y]){
        return ances(padre[x],y);
    }
    if(x==y){
        return x;
    }
    return ances(padre[x],padre[y]);
}
int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i=0;i<2505;i++){
        longitud[i]=1e9;
        djs[i]=i;
        for(int j=0;j<2505;j++){
            visitadoedges[i][j]=false;
        }
    }
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
        unir(a,b);
    }
    queue<vi> bfs;
    for(int i=1;i<=n;i++){
        comp[find(i)].push_back(i);
    }
    int reap=2;
    do{
        for(int i=0;i<2505;i++){
            longitud[i]=1e9;
            padre[i]=0;
            for(int j=0;j<2505;j++){
                visitadoedges[i][j]=false;
            }
        }
        vector<int> checkear;
        for(int i=1;i<2505;i++){
            if(comp[i].size()<=2){
                continue;
            }
            int aaa=uniform_int_distribution<int>(0,comp[i].size()-1)(rng);
            checkear.push_back(comp[i][aaa]);
        }
        for(auto i:checkear){
            bfs.push({i,0,1});
            while(!bfs.empty()){
                vi temp=bfs.front();
                bfs.pop();
                int now=temp[0],ante=temp[1],lon=temp[2];
                if(longitud[now]!=1e9){
                    int res=longitud[now]+longitud[ante];
                    res-=2*longitud[ances(now,ante)];
                    res++;
                    if(res<=2){
                        //nada
                    }else{
                        mini=min(mini,res);
                    }
                }
                longitud[now]=lon;
                padre[now]=ante;
                for(auto u:graph[now]){
                    if(visitadoedges[min(u,now)][max(u,now)]){
                        continue;
                    }
                    visitadoedges[min(u,now)][max(u,now)]=true;
                    bfs.push({u,now,lon+1});
                }
            }
        }
    }while(reap--);
    if(mini==1e9){
        printf("-1");
    }else{
        printf("%d",mini);
    }
}
// sol2 no da:(
/*#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,m,a,b;
vector<int> graph[2505];
vector<int> longitud(2505,1e9);
int djs[2505];
int tam[2505];
vi comp[2505];
int now=0,mini=1e9;
double tiempo=0;
void dfs1(int x,int ante,int subante){
    if(mini==3){
        return;
    }
    if(longitud[x]==1e9){
        longitud[x]=now;
        now++;
        for(auto u:graph[x]){
            if(u==ante){
                continue;
            }
            dfs1(u,x,ante);
        }
        now--;
        longitud[x]=1e9;
    }else{
        mini=min(now-longitud[x],mini);
    }
}
void dfs(int x,int ante,int subante){
    if(clock()/(double) CLOCKS_PER_SEC-tiempo>=0.10){
        return;
    }
    if(clock()/(double) CLOCKS_PER_SEC>=0.98){
        return;
    }
    if(mini==3){
        return;
    }
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
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i=0;i<2505;i++){
        djs[i]=i;
        tam[i]=1;
    }
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        unir(a,b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        comp[find(i)].push_back(i);
    }
    vi posible,muyposi;
    for(int i=0;i<=n;i++){
        if(comp[i].size()<=2){
            continue;
        }
        if(comp[i].size()<=100){
            muyposi.push_back(i);
        }else{
            posible.push_back(i);
        }
    }
    while(true && !posible.empty()){
        if(clock()/(double) CLOCKS_PER_SEC>=0.98){
            break;
        }
        for(int i=0;i<n+1;i++){
            longitud[i]=1e9;
        }
        int bbb=uniform_int_distribution<int>(0,posible.size()-1)(rng);
        int aaa=uniform_int_distribution<int>(0,comp[posible[bbb]].size()-1)(rng);
        dfs(comp[posible[bbb]][aaa],0,-1);
        if(clock()/(double) CLOCKS_PER_SEC-tiempo>=0.10){
            tiempo=clock()/(double) CLOCKS_PER_SEC;
            continue;
        }
    }
    for(auto j:muyposi){
        for(int i=0;i<n+1;i++){
            longitud[i]=1e9;
        }
        dfs1(comp[j][0],0,-1);
    }
    if(mini==1e9){
        printf("-1");
    }else{
        printf("%d",mini);
    }
}*/