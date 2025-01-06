#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;
ll n,m;
ll dsu[100005],suma[100005];
vector<pll> haybale,ord;
ll find(ll a){
    if(a==dsu[a]){
        return a;
    }
    return dsu[a]=find(dsu[a]);
}
void unite(ll a,ll b){
    a=find(a);b=find(b);
    if(a==b){
        return;
    }
    dsu[b]=a;
    suma[a]+=suma[b];
    return;
}
int main(){
    freopen("hayfeast.in","r",stdin);
    freopen("hayfeast.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    haybale.resize(n+2);
    ord.resize(n);
    for(int i=0;i<n+5;i++){
        dsu[i]=i;
        suma[i]=0;
    }
    haybale[0]=haybale[n+1]={0,1e18};
    for(ll i=1;i<=n;i++){
        scanf("%lld%lld",&haybale[i].first,&haybale[i].second);
        suma[i]=haybale[i].first;
        ord[i-1]={haybale[i].second,i};
    }
    sort(ord.begin(),ord.end());
    for(int i=0;i<n;i++){
        ll xx=find(ord[i].second+1),yy=find(ord[i].second-1),zz=find(ord[i].second);
        if(haybale[xx].second<=haybale[zz].second){
            //unir
            unite(zz,xx);
        }
        if(haybale[yy].second<=haybale[zz].second){
            //unir
            unite(zz,yy);
        }
        if(suma[zz]>=m){
            printf("%lld",haybale[zz].second);
            break;
        }
    }
}