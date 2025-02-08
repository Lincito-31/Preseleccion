#include <bits/stdc++.h>
#define lsOne(x) (x)&-(x)
using namespace std;
typedef long long ll;
ll n;
vector<ll> fenwick;
ll fsum(ll x){
    ll suma=0;
    while(x>0){
        suma+=fenwick[x];
        x-=lsOne(x);
    }
    return suma;
}
void update(ll x,ll val){
    while(x<=n+4){
        fenwick[x]+=val;
        x+=lsOne(x);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    vector<ll> pos(n+1),psum(n+1);
    vector<pair<ll,ll>> nega;
    ll sum=0,cantidad=0;
    set<ll> positivo;
    for(int i=1;i<=n;i++){
        cin >> pos[i];
        psum[i]=psum[i-1];
        if(pos[i]>0){
            psum[i]+=pos[i];
            cantidad++;
            positivo.insert(i);
        }else{
            nega.push_back({-pos[i],i});
        }
    }
    ll nuen=nega.size();
    sort(nega.begin(),nega.end());
    fenwick.resize(n+5);
    for(int i=0;i<nuen;i++){
        if(psum[nega[i].second]+fsum(nega[i].second)>=nega[i].first){
            cantidad++;
            //ll origi=nega[i].first;
            while(nega[i].first>0){
                auto p=positivo.lower_bound(nega[i].second);
                p--;
                ll mini=min(pos[*p],nega[i].first);
                pos[*p]-=mini;
                nega[i].first-=mini;
                update(*p,-mini);
                if(pos[*p]==0){
                    positivo.erase(p);
                }
            }
        }
    }
    cout << cantidad;
}