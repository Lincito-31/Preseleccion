#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,t;
int main(){
    scanf("%lld",&q);
    vector<pair<ll,ll>> snakes;
    ll con=0;
    snakes.push_back({-2,-1});
    ll cantidad2=0,tot=0;
    while(q--){
        scanf("%lld",&t);
        if(t==1){
            scanf("%lld",&t);
            snakes.push_back({snakes[tot].second+1,snakes[tot].second+t});
            tot++;
        }else if(t==2){
            con+=snakes[cantidad2+1].second-snakes[cantidad2+1].first+1;
            cantidad2++;
        }else{
            scanf("%lld",&t);
            printf("%lld\n",snakes[cantidad2+t].first-con);
        }
    }
}