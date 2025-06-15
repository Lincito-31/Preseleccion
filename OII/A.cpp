#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,dsu[200000],nivel[200000],m,a,b,c,d,bj[200000][20];
vector<ll> graph[200000];
pair<ll,ll> pares[200000];
ll res=1;
ll bigmod(ll b,ll e){
    ll p=1;
    while(e>0){
        if(e%2){
            p*=b;
            p%=MOD;
        }
        e/=2;
        b*=b;
        b%=MOD;
    }
    return p;
}
ll inversemod(ll x){
    return bigmod(x,MOD-2);
}
void dfs(ll x,ll ante){
    for(auto u:graph[x]){
        if(u==ante){
            continue;
        }
        nivel[u]=nivel[x]+1;
        dfs(u,x);
    }
}
ll find(ll x){
    if(x==dsu[x]){
        return x;
    }
    return dsu[x]=find(dsu[x]);
}
void unite(ll x,ll y){
    x=find(x);
    y=find(y);
    if(x==y){
        return;
    }
    dsu[y]=x;
    res*=inversemod(pares[x].second-pares[x].first+1);
    res%=MOD;
    res*=inversemod(pares[y].second-pares[y].first+1);
    res%=MOD;
    pares[x].first=max(pares[x].first,pares[y].first);
    pares[x].second=min(pares[x].second,pares[y].second);
    res*=max(pares[x].second-pares[x].first+1,0ll);
    res%=MOD;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    bj[0][0]=0;
    dsu[0]=0;
    nivel[0]=0;
    for(ll i=1;i<n;i++){
        dsu[i]=i;
        cin >> bj[i][0];
        bj[i][0]--;
        graph[bj[i][0]].push_back(i);
    }
    dfs(0,-1);
    /*for(ll i=1;i<20;i++){
        for(ll j=0;j<n;j++){
            bj[j][i]=bj[bj[j][i-1]][i-1];
        }
    }*/
    for(ll i=0;i<n;i++){
        cin >> pares[i].first >> pares[i].second;
        res*=pares[i].second-pares[i].first+1;
        res%=MOD;
    }
    cin >> m;
    while(m--){
        cin >> a >> b >> c >> d;
        if(res==0){
            cout << 0 << '\n';
            continue;
        }
        a--;b--;c--;d--;
        vector<ll> n1,n2,principal1,principal2;
        bool xd=false;
        while(a!=b){
            if(nivel[a]<nivel[b]){
                swap(a,b);
                xd=!xd;
            }
            if(!xd){
                n1.push_back(a);
            }else{
                n2.push_back(a);
            }
            a=bj[a][0];
        }
        if(!n2.empty()){
            reverse(ALL(n2));
        }
        for(ll i=0;i<n1.size();i++){
            principal1.push_back(n1[i]);
        }
        principal1.push_back(a);
        for(ll i=0;i<n2.size();i++){
            principal1.push_back(n2[i]);
        }
        n2.clear();n1.clear();
        xd=false;
        while(c!=d){
            if(nivel[c]<nivel[d]){
                swap(c,d);
                xd=!xd;
            }
            if(!xd){
                n1.push_back(c);
            }else{
                n2.push_back(c);
            }
            c=bj[c][0];
        }
        if(!n2.empty()){
            reverse(ALL(n2));
        }
        for(ll i=0;i<n1.size();i++){
            principal2.push_back(n1[i]);
        }
        principal2.push_back(c);
        for(ll i=0;i<n2.size();i++){
            principal2.push_back(n2[i]);
        }
        for(ll i=0;i<principal1.size();i++){
            unite(principal1[i],principal2[i]);
        }
        cout << res << '\n';
    }
}