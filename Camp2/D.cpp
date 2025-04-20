#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K,N;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> K >> N;
    vector<pair<ll,ll>> choc(N),neg,pos;
    vector<ll> ssumneg,psumpos;
    for(int i=0;i<N;i++){
        cin >> choc[i].first;
    }
    for(int i=0;i<N;i++){
        cin >> choc[i].second;
    }
    sort(choc.begin(),choc.end());
    pos.push_back({0,0});
    for(int i=0;i<N;i++){
        if(choc[i].first<0){
            neg.push_back(choc[i]);
        }else{
            pos.push_back(choc[i]);
        }
    }
    neg.push_back({0,0});
    ll NEG=neg.size(),POS=pos.size();
    ssumneg.resize(NEG);
    psumpos.resize(POS);
    for(int i=NEG-2;i>=0;i--){
        ssumneg[i]=ssumneg[i+1]+neg[i].second;
    }
    for(int i=1;i<POS;i++){
        psumpos[i]=psumpos[i-1]+pos[i].second;
    }
    ll mini=1e18;
    for(int i=0;i<NEG;i++){
        ll nece=K-ssumneg[i];
        ll p=lower_bound(psumpos.begin(),psumpos.end(),nece)-psumpos.begin();
        if(p!=POS){
            ll iz=-neg[i].first;
            ll de=pos[p].first;
            mini=min(mini,iz+de+min(iz,de));
        }else{
            break;
        }
    }
    if(mini==1e18){
        cout << -1;
    }else{
        cout << mini;
    }
}
/*
10 5
1 2 3 4 5
1 1 1 1 1

100 3
-1 2 4
90 10 100
*/