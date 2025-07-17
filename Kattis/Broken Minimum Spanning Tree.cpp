#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
int n,m;
ll peso,a,b,c;
vector<vector<int>> graph;
vector<int> dsu;
int find(int x){return (x==dsu[x])?x:dsu[x]=find(dsu[x]);}
bool unite(int x,int y){
    if((x=find(x))==(y=find(y))){
        return false;
    }
    dsu[x]=y;
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<vector<ll>> edges(m);
    vector<bool> edges_usados(n);
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        if(i<n-1){
            peso+=c;
            edges_usados[i]=true;
        }
        edges[i]={c,--a,--b,i};
    }
    sort(ALL(edges));
    vector<pair<int,int>> res;
    for(int i=m-1;i>=0;i--){
        if(!edges_usados[edges[i][3]]){
            continue;
        }
        //si quito el edge_i qué pasa?
        ll pesodeseado=0;
        dsu.clear();
        dsu.resize(n);
        for(int j=0;j<n;j++){
            dsu[j]=j;
        }
        for(int j=0;j<m;j++){
            if(j==i){
                continue;
            }
            if(edges_usados[edges[j][3]]){
                unite(edges[j][1],edges[j][2]);
                pesodeseado+=edges[j][0];
            }
        }
        int edge_espe=-1;
        for(int j=0;j<m;j++){
            if(unite(edges[j][1],edges[j][2])){
                pesodeseado+=edges[j][0];
                edge_espe=edges[j][3];
                break;
            }
        }
        if(edge_espe==-1 || pesodeseado>=peso){
            continue;
        }
        //cambio;
        peso=pesodeseado;
        edges_usados[edges[i][3]]=false;
        edges_usados[edge_espe]=true;
        res.push_back({edges[i][3]+1,edge_espe+1});
    }
    cout << res.size() << '\n';
    for(auto u:res){
        cout << u.first << ' ' << u.second << '\n';
    }
}