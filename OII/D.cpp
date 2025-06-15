#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b,c,con,restask0,restask1;
vector<pair<ll,ll>> graph[10005];
ll nivel[10005],contador[10005];
map<ll,ll> help;
void dfs1(ll now,ll ante,ll suma){
    if(suma==0 && ante!=-1){
        con+=help[0]-1;
    }else if(suma%2==0){
        con+=help[suma/2];
    }
    help[suma]++;
    for(auto u:graph[now]){
        if(u.first==ante){
            continue;
        }
        nivel[u.first]=nivel[now]+1;
        dfs1(u.first,now,suma+u.second);
    }
    help[suma]--;
}
void dfs2(ll now,ll ante,ll suma){
    if(suma==0 && ante!=-1){
        con+=help[0]-1;
    }else if(suma%2==0){
        con+=help[suma/2];
    }
    help[suma]++;
    for(auto u:graph[now]){
        if(u.first==ante || nivel[u.first]<nivel[now]){
            continue;
        }
        dfs2(u.first,now,suma+u.second);
    }
    help[suma]--;
}
bool task0=true,task1=true,task5=true;;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i=1;i<n;i++){
        cin >> a >> b >> c;
        if(c!=0){
            task0=false;
        }
        if(c!=1){
            task1=false;
        }
        graph[--a].push_back({--b,c});
        graph[b].push_back({a,c});
    }
    dfs1(0,-1,0);
    for(int i=0;i<n;i++){
        restask0+=nivel[i]*(nivel[i]-1)/2;
        restask1+=nivel[i]/2;
        if(graph[i].size()>=2){
            task5=false;
        }
    }
    if(task0){
        cout << restask0;
    }else if(task1){
        cout << restask1;
    }else if(task5){
        vector<int> res(n);
        int now=0,conta=1;
        while(graph[now].size()>0){
            res[conta]=res[conta-1]+graph[now][0].second;
            now=graph[now][0].first;
        }
        now=1;
        for(int i=0;i<n;i++){
            for(int j=i+2;j<n;j++){
                if((res[i]+res[j])%2==0){
                    
                }
            }
        }
    }else{
        nivel[0]=0;
        for(ll i=1;i<n;i++){
            dfs2(i,-1,0);
        }
        cout << con;
    }
}