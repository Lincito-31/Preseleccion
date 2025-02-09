#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define RAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
int N,M,A,B;
vector<int> dsu;
set<int> componente_padre;
int find(int x){
    return (x==dsu[x])?x:dsu[x]=find(dsu[x]);
}
bool unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return false;
    }
    dsu[x]=y;
    componente_padre.erase(x);
    return true;
}
int main(){
    FASTIO;
    cin >> N >> M;
    dsu.resize(N+1);
    vector<vector<int>> cables_que_no_sirven;
    for(int i=1;i<=N;i++){
        dsu[i]=i;
        componente_padre.insert(i);
    }
    for(int i=0;i<M;i++){
        cin >> A >> B;
        if(!unite(A,B)){
            cables_que_no_sirven.push_back({A,B,i+1});
        }
    }
    int ini=0;
    vector<vector<int>> res;
    while(componente_padre.size()>1){
        if(*componente_padre.begin()==find(cables_que_no_sirven[ini][0])){
            auto p=componente_padre.begin();
            p++;
            unite(cables_que_no_sirven[ini][0],*p);
            res.push_back({cables_que_no_sirven[ini][2],cables_que_no_sirven[ini][0],*p});
        }else{
            auto p=componente_padre.begin();
            unite(cables_que_no_sirven[ini][0],*p);
            res.push_back({cables_que_no_sirven[ini][2],cables_que_no_sirven[ini][0],*p});
        }
        ini++;
    }
    cout << res.size() << "\n";
    for(auto u:res){
        for(auto k:u){
            cout << k << " ";
        }
        cout << "\n";
    }
}