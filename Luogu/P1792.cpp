#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
vector<ll> arb;
pair<ll,ll> solve(ll x){
    // 0=no use arb[0] / 1=si use arb[0];
    pair<ll,ll> sol[n][2];
    sol[0][0]={0,0};
    sol[0][1]=max(make_pair(arb[0]-x,1),{0ll,0ll});
    sol[1][0]=max(sol[0][0],make_pair(arb[1]-x,1ll));
    sol[1][1]=max(sol[0][1],make_pair(arb[1]-x,1ll));
    for(ll i=2;i<n-1;i++){
        sol[i][0]=max(sol[i-1][0],{sol[i-2][0].first+arb[i]-x,sol[i-2][0].second+1});
        sol[i][1]=max(sol[i-1][1],{sol[i-2][1].first+arb[i]-x,sol[i-2][1].second+1});
    }
    sol[n-1][0]=max(sol[n-1-1][0],{sol[n-1-2][0].first+arb[n-1]-x,sol[n-1-2][0].second+1});
    sol[n-1][1]=sol[n-2][1];
    return max(sol[n-1][0],sol[n-1][1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    arb.resize(n);
    for(ll i=0;i<n;i++){
        cin >> arb[i];
    }
    ll l=-1e9,r=1e9;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(solve(mid).second>=k){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    pair<ll,ll> res=solve(l);
    if(res.second<k){
        cout << "Error!";
    }else{
        cout << res.first+k*l;
    }
}