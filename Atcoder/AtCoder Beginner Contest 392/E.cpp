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
set<int> queda;
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
    queda.erase(x);
    return true;
}
int main(){
    FASTIO;
    cin >> N >> M;
    dsu.resize(N);
    for(int i=0;i<N;i++){
        dsu[i]=i;
        queda.insert(i);
    }
    vector<vi> notused;
    for(int i=0;i<M;i++){
        cin >> A >> B;
        if(!unite(--A,--B)){
            notused.push_back({i,A,B});
        }
    }
    vector<vi> res;
    int ini=0;
    while(queda.size()>1){
        if(find(notused[ini][1])==*queda.begin()){
            auto p=queda.begin();
            p++;
            unite(notused[ini][1],*p);
            res.push_back({notused[ini][0],notused[ini][1],*p});
        }else{
            unite(notused[ini][1],*queda.begin());
            res.push_back({notused[ini][0],notused[ini][1],*queda.begin()});
        }
        ini++;
    }
    cout << res.size() << "\n";
    for(auto u:res){
        cout << u[0]+1 << " " << u[1]+1 << " " << u[2]+1 << "\n";
    }
}