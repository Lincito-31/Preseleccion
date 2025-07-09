#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a,b,c,dsu[200000],res[200000],sum=0,level[200000];
bool used[200000];
vector<vector<ll>> caminos;
vector<pair<ll,ll>> graph[200000];
pair<ll,ll> ancestor[200000][18],padre[200000];
ll find(ll x){
    return dsu[x]==x?x:dsu[x]=find(dsu[x]);
}
bool unir(ll x,ll y){
    x=find(x);
    y=find(y);
    if(x==y){
        return false;
    }
    dsu[x]=y;
    return true;
}
ll calc(ll x,ll y){
    ll maxi=0;
    if(level[x]<level[y]){
        swap(x,y);
    }
    ll need=level[x]-level[y];
    for(int i=0;i<18;i++){
        if(need&(1<<i)){
            maxi=max(maxi,ancestor[x][i].second);
            x=ancestor[x][i].first;
        }
    }
    if(x==y){
        return maxi;
    }
    for(int i=17;i>=0;i--){
        if(ancestor[x][i].first==ancestor[y][i].first){
            continue;
        }
        maxi=max(maxi,ancestor[x][i].second);
        maxi=max(maxi,ancestor[y][i].second);
        x=ancestor[x][i].first;
        y=ancestor[y][i].first;
    }
    maxi=max(maxi,padre[x].second);
    maxi=max(maxi,padre[y].second);
    return maxi;
}
void dfs(int now,int ante){
    for(auto u:graph[now]){
        if(u.first==ante){
            continue;
        }
        padre[u.first]={now,u.second};
        level[u.first]=level[now]+1;
        dfs(u.first,now);
    }
}
int main(){
    scanf("%lld%lld",&n,&m);
    caminos.resize(m);
    for(int i=0;i<n;i++){
        dsu[i]=i;
    }
    for(int i=0;i<m;i++){
        used[i]=false;
        for(int j=0;j<18;j++){
            ancestor[i][j]={0,0};
        }
        scanf("%lld%lld%lld",&a,&b,&c);
        caminos[i]={c,a-1,b-1,i};
    }
    sort(caminos.begin(),caminos.end());
    for(int i=0;i<m;i++){
        if(unir(caminos[i][1],caminos[i][2])){
            graph[caminos[i][1]].push_back({caminos[i][2],caminos[i][0]});
            graph[caminos[i][2]].push_back({caminos[i][1],caminos[i][0]});
            used[caminos[i][3]]=true;
            sum+=caminos[i][0];
        }
    }
    padre[0]={0,0};
    level[0]=0;
    dfs(0,-1);
    for(int i=0;i<n;i++){
        ancestor[i][0]=padre[i];
    }
    for(int j=1;j<18;j++){
        for(int i=0;i<n;i++){
            ancestor[i][j].first=ancestor[ancestor[i][j-1].first][j-1].first;
            ancestor[i][j].second=max(ancestor[ancestor[i][j-1].first][j-1].second,ancestor[i][j-1].second);
        }
    }
    for(int i=0;i<m;i++){
        if(used[caminos[i][3]]){
            continue;
        }
        res[caminos[i][3]]=sum+caminos[i][0]-calc(caminos[i][1],caminos[i][2]);
    }
    for(int i=0;i<m;i++){
        if(used[i]){
            printf("%lld\n",sum);
        }else{
            printf("%lld\n",res[i]);
        }
    }
}