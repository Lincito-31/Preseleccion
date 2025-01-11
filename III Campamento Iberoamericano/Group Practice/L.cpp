#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll dist=0,K,n,N=0,a,b;
char tip1,tip2;
int main(){
    scanf("%lld%lld",&K,&n);
    vector<pair<ll,ll>> nums;
    vector<ll> tot,iz,de;
    while(n--){
        scanf(" %c%lld %c%lld",&tip1,&a,&tip2,&b);
        dist+=abs(a-b);
        if(tip1!=tip2){
            dist++;
            if(a>b){
                swap(a,b);
            }
            nums.push_back({a,b});
            tot.push_back(a);
            iz.push_back(a);
            tot.push_back(b);
            de.push_back(b);
            N++;
        }
    }
    sort(ALL(nums));
    sort(ALL(tot));
    sort(ALL(iz));
    sort(ALL(de));
    vector<ll> psumde(N),psumiz(N);
    psumde[0]=de[0];
    psumiz[0]=iz[0];
    for(int i=2;i<N;i++){
        psumde[i]=psumde[i-1]+de[i];
        psumiz[i]=psumiz[i-1]+iz[i];
    }
    ll canti=1e18;
    if(K==1){
        for(auto u:tot){
            //cuantos estan al lado derecho?
            ll pos1=upper_bound(ALL(iz),u)-iz.begin();
            ll temp1=psumiz[N-1]-(pos1==0?0:psumiz[pos1-1]);
            temp1-=(N-pos1)*u;
            ll pos2=lower_bound(ALL(de),u)-de.begin();
            ll temp2=pos2*u-(pos2==0?0:psumde[pos2-1]);
            canti=min(canti,temp1+temp2);
        }
    }else{

    }
    dist+=canti;
    printf("%lld",dist);
}