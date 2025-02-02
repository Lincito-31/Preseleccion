#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
int t=1,n,s1,s2,m1,m2,a,b;
int main(){
    FASTIO;
    cin >> t;
    while(t--){
        cin >> n >> s1 >> s2;
        cin >> m1;
        vi graph1[n+1],graph2[n+1];
        vector<pair<int,int>> edges1(m1);
        vector<vi> res(n+1,vi(n+1,1e9));
        for(int i=0;i<m1;i++){
            cin >> a >> b;
            graph1[a].push_back(b);
            graph1[b].push_back(a);
            edges1[i]={min(a,b),max(a,b)};
        }
        cin >> m2;
        vector<pair<int,int>> edges2(m2);
        for(int i=0;i<m2;i++){
            cin >> a >> b;
            graph2[a].push_back(b);
            graph2[b].push_back(a);
            edges2[i]={min(a,b),max(a,b)};
        }
        sort(ALL(edges1));
        sort(ALL(edges2));
        vector<bool> posible(n+1,false);
        for(int i=0;i<m1;i++){
            if(binary_search(ALL(edges2),edges1[i])){
                posible[edges1[i].first]=true;
                posible[edges1[i].second]=true;
            }
        }
        priority_queue<vector<int>> cola;
        int respuesta=1e9;
        res[s1][s2]=0;
        cola.push({0,s1,s2});
        vector<vector<bool>> visited(n+1,vector<bool>(n+1,false));
        while(!cola.empty()){
            vector<int> top=cola.top();
            cola.pop();
            if(visited[top[1]][top[2]]){
                continue;
            }
            visited[top[1]][top[2]]=true;
            if(top[1]==top[2] && posible[top[1]]){
                respuesta=min(respuesta,res[top[1]][top[2]]);
            }
            for(auto u:graph1[top[1]]){
                for(auto v:graph2[top[2]]){
                    if(-top[0]+abs(u-v)<res[u][v]){
                        res[u][v]=-top[0]+abs(u-v);
                        cola.push({-res[u][v],u,v});
                    }
                }
            }
        }
        if(respuesta==1e9){
            cout << "-1\n";
        }else{
            cout << respuesta << "\n";
        }
    }
}
