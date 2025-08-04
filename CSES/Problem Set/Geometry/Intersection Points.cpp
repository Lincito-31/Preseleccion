#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b,c,d;
#define M 1000001
vector<ll> fenwick;
#define lson(x) (x)&(-x)
void update(ll x,ll val){
    while(x<=2*M){
        fenwick[x]+=val;
        x+=lson(x);
    }
}
ll sum(ll x){
    ll suma=0;
    while(x>0){
        suma+=fenwick[x];
        x-=lson(x);
    }
    return suma;
}
ll res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<vector<ll>> lines;
    for(ll i=0;i<n;i++){
        cin >> a >> b >> c >> d;
        if(b==d){
            lines.push_back({b,0,a+M,c+M});
        }else{
            lines.push_back({b,1,a+M,c+M});
            lines.push_back({d,2,a+M,c+M});
        }
    }
    fenwick.resize(2*M+1);
    sort(lines.begin(),lines.end());
    for(auto u:lines){
        if(u[1]==0){
            res+=sum(u[3])-sum(u[2]-1);
        }else if(u[1]==1){
            update(u[2],1);
        }else{
            update(u[2],-1);
        }
    }
    cout << res;
}