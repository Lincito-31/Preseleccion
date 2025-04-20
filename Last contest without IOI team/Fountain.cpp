#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> intset;
typedef long long ll;
int n,q,r,v;
int main(){
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    vector<pair<ll,ll>> fountain(n+1);
    vector<vector<ll>> padre(n+1,vector<ll>(20,-1));
    vector<vector<ll>> cap(n+1,vector<ll>(20,0));
    cap[0][0]=1e9;
    for(int i=1;i<=n;i++){
        cin >> fountain[i].first >> fountain[i].second;
        cap[i][0]=fountain[i].second;
    }
    padre[0][0]=0;
    stack<pair<int,int>> pila;
    pila.push({1e9+5,0});
    for(int i=n;i>=1;i--){
        while(fountain[i].first>=pila.top().first){
            pila.pop();
        }
        padre[i][0]=pila.top().second;
        pila.push({fountain[i].first,i});
    }
    for(int i=1;i<20;i++){
        for(int j=0;j<=n;j++){
            padre[j][i]=padre[padre[j][i-1]][i-1];
            cap[j][i]=cap[j][i-1]+cap[padre[j][i-1]][i-1];
            if(cap[j][i]>=(1e9)){
                cap[j][i]=1e9;
            }
        }
    }
    while(q--){
        cin >> r >> v;
        if(fountain[r].second>=v){
            cout << r << '\n';
        }else{
            for(int i=19;i>=0;i--){
                if(cap[r][i]<v){
                    v-=cap[r][i];
                    r=padre[r][i];    
                }
            }
            cout << r << '\n';
        }
    }
}