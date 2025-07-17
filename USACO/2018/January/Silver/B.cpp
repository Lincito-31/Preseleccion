#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
ll n,m,r,a,b,maxi;
int main(){
    freopen("rental.in","r",stdin);
    freopen("rental.out","w",stdout);
    cin >> n >> m >> r;
    vector<ll> cows(n),ssum(n),rent(r),psum(r);
    vector<pair<ll,ll>> fact(m),psumcant(m);
    for(int i=0;i<n;i++){
        cin >> cows[i];
    }
    sort(ALL(cows));
    ssum[n-1]=cows[n-1];
    for(int i=n-2;i>=0;i--){
        ssum[i]=ssum[i+1]+cows[i];
    }
    for(int i=0;i<m;i++){
        cin >> fact[i].second >> fact[i].first;
    }
    sort(REV(fact));
    for(int i=0;i<m;i++){
        swap(fact[i].first,fact[i].second);
    }
    psumcant[0].first=fact[0].first;
    psumcant[0].second=fact[0].first*fact[0].second;
    for(int i=1;i<m;i++){
        psumcant[i].first=psumcant[i-1].first+fact[i].first;
        psumcant[i].second=psumcant[i-1].second+fact[i].first*fact[i].second;
    }
    for(int i=0;i<r;i++){
        cin >> rent[i];
    }
    sort(REV(rent));
    psum[0]=rent[0];
    for(int i=1;i<r;i++){
        psum[i]=psum[i-1]+rent[i];
    }
    //sin rentar
    ll extra=ssum[0];
    ll pos=upper_bound(ALL(psumcant),make_pair(extra,0ll))-psumcant.begin()-1;
    if(pos>=0){
        maxi=psumcant[pos].second;
        extra-=psumcant[pos].first;
    }
    if(pos+1<m){
        maxi+=extra*fact[pos+1].second;
    }
    for(ll i=1;i<n;i++){
        //rentar i cows
        extra=ssum[i];
        pos=upper_bound(ALL(psumcant),make_pair(extra,0ll))-psumcant.begin()-1;
        ll temp=0;
        if(pos>=0){
            temp=psumcant[pos].second;
            extra-=psumcant[pos].first;
        }
        if(pos+1<m){
            temp+=extra*fact[pos+1].second;
        }
        maxi=max(maxi,psum[min(i-1,r-1)]+temp);
    }
    // rentar todo
    maxi=max(maxi,psum[min(r-1,n-1)]);
    cout << maxi;
}