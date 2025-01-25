#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,D,X;
int main(){
    scanf("%lld%lld%lld",&n,&D,&X);
    vector<pair<ll,ll>> restaurants(n);
    for(int i=0;i<n;i++){
        scanf("%lld",&restaurants[i].first);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&restaurants[i].second);
    }
    restaurants.push_back({X,0});
    sort(ALL(restaurants));
    priority_queue<ll> energysavailable;
    ll lastadist=0,con=0;
    for(int i=0;i<=n;i++){
        if(lastadist>=X){
            break;
        }
        while(restaurants[i].first-lastadist>D){
            if(energysavailable.empty()){
                printf("-1");
                return 0;
            }
            D+=energysavailable.top();
            energysavailable.pop();
            con++;
        }
        D-=restaurants[i].first-lastadist;
        lastadist=restaurants[i].first;
        energysavailable.push(restaurants[i].second);
    }
    printf("%lld",con);
}