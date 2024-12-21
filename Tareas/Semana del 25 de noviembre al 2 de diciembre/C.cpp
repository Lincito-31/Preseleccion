#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<long long> vll;
ll n,m,a,b,c;
vector<pll> graph[100005];
vector<bool> visited(100005,false);
vector<vll> valores(100005,vll(4,1e18));
void count(){
    ll x;
    priority_queue<pair<ll,ll>> cola;
    cola.push({0,1});
    valores[1]={0,1,0,0};
    while(!cola.empty()){
        x=cola.top().second;
        cola.pop();
        if(visited[x]){
            continue;
        }
        visited[x]=true;
        for(auto u:graph[x]){
            ll y=u.first,w=u.second;
            if(valores[x][0]+w<valores[y][0]){
                valores[y][0]=valores[x][0]+w;
                valores[y][1]=valores[x][1];
                valores[y][1]%=MOD;
                valores[y][2]=valores[x][2]+1;
                valores[y][3]=valores[x][3]+1;
                cola.push({-valores[y][0],y});
            }else if(valores[x][0]+w==valores[y][0]){
                valores[y][1]+=valores[x][1];
                valores[y][1]%=MOD;
                valores[y][2]=min(valores[y][2],valores[x][2]+1);
                valores[y][3]=max(valores[y][3],valores[x][3]+1);
            }
        }
    }
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        graph[a].push_back({b,c});
    }
    count();
    printf("%lld %lld %lld %lld",valores[n][0],valores[n][1],valores[n][2],valores[n][3]);
}