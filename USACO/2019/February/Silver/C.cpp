#include <bits/stdc++.h>
using namespace std;
int n,m,dsu[100000],conta,color[100000],a,b;
char c;
vector<int> same[100000],dif[100000];
int find(int x){return x==dsu[x]?x:dsu[x]=find(dsu[x]);}
void unite(int x,int y){
    if((x=find(x))==(y=find(y))){
        return;
    }
    conta--;
    dsu[x]=y;
    return;
}
bool dfs(int x){
    for(auto u:same[x]){
        if(color[u]==0){
            color[u]=color[x];
            if(!dfs(u)){
                return false;
            }
        }else{
            if(color[u]!=color[x]){
                return false;
            }
        }
    }
    for(auto u:dif[x]){
        if(color[u]==0){
            if(color[x]==1){
                color[u]=2;
            }else{
                color[u]=1;
            }
            if(!dfs(u)){
                return false;
            }
        }else{
            if(color[u]==color[x]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<(conta=n);i++){
        dsu[i]=i;
    }
    while(m--){
        cin >> c >> a >> b;
        unite(--a,--b);
        if(c=='S'){
            same[a].push_back(b);
            same[b].push_back(a);
        }else{
            dif[a].push_back(b);
            dif[b].push_back(a);
        }
    }
    for(int i=0;i<n;i++){
        if(color[i]==0){
            color[i]=1;
            if(!dfs(i)){
                cout << 0;
                return 0;
            }
        }
    }
    cout << 1;
    for(int i=0;i<conta;i++){
        cout << 0;
    }
}