#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string S;
ll A,B;
map<ll,pair<ll,ll>> euclides;
ll algo(ll a,ll b){
    if(b==0){
        return a;
    }
    ll cociente=a/b;
    ll residuo=a%b;
    //residuo=a*1-b*cociente
    ll iz=0,de=0;
    pair<ll,ll> temp=euclides[a];
    euclides[residuo]={temp.first,temp.second};
    temp=euclides[b];
    euclides[residuo].first-=cociente*temp.first;
    euclides[residuo].second-=cociente*temp.second;
    return algo(b,residuo);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> A >> B;
    euclides[max(A,B)]={1,0};
    euclides[min(A,B)]={0,1};
    ll mcd=algo(max(A,B),min(A,B));
    cout << mcd << " ";
    cout << abs(euclides[mcd].first)+abs(euclides[mcd].second);
}