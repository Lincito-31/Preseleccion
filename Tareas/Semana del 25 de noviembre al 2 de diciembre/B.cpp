// sol 1
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n,m,a,b;
vector<int> graph[2500];
int mini=1e9,limi=1e8;
int main(){
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&a,&b);
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        vector<int> lon(n,-1);
        queue<vi> bfs;
        bfs.push({i,0,1});
        while(!bfs.empty()){
            int now=bfs.front()[0];
            int ante=bfs.front()[1];
            int longit=bfs.front()[2];
            bfs.pop();
            if(lon[now]!=-1){
                mini=min(mini,lon[now]+longit-2);
                limi=mini/2+5;
                if(longit>limi){
                    break;
                }
                //break;
            }else{
                lon[now]=longit;
                for(auto u:graph[now]){
                    if(u==ante){
                        continue;
                    }
                    bfs.push({u,now,longit+1});
                }
            }
        }
    }
    if(mini==1e9){
        printf("-1");
    }else{
        printf("%d",mini);
    }
}
// sol 2
/*#include <bits/stdc++.h>
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
}*/
