#include <bits/stdc++.h>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,m,a,b,q,c;
vector<pair<int,ll>> graph[500];
ll dist[500][500];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=1e18;
        }
        dist[i][i]=0;
    }
    while(m--){
        cin >> a >> b >> c;
        a--;b--;
        if(dist[a][b]>c){
            dist[a][b]=dist[b][a]=c;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                dist[j][i]=dist[i][j];
            }
        }
    }
    while(q--){
        cin >> a >> b;
        a--;b--;
        if(dist[a][b]==1e18){
            cout << -1 << '\n';
        }else{
            cout << dist[a][b] << '\n';
        }
    }
} 