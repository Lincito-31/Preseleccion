#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
    scanf("%d",&n);
    vector<pair<ll,ll>> friends(n);
    for(int i=0;i<n;i++){
        scanf("%lld",&friends[i].first);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&friends[i].second);
    }
    ll l=1,r=1e9,con=0;
    while(l<r){
        ll mid=(l+r)>>1;
        ll rang=friends[0].second*mid;
        ll limitiz=friends[0].first-rang;
        ll limide=friends[0].first+rang;
        for(int i=1;i<n;i++){
            limitiz=max(limitiz,friends[i].first-friends[i].second*mid);
            limide=min(limide,friends[i].first+friends[i].second*mid);
            if(limitiz>limide){
                break;
            }
        }
        if(limide>=limitiz){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    double ll=l-1;
    double rr=l;
    while(con<64){
        double mid=(ll+rr)/2;
        double rang=(double)friends[0].second*mid;
        double limitiz=(double)friends[0].first-rang;
        double limide=(double)friends[0].first+rang;
        for(int i=1;i<n;i++){
            limitiz=max(limitiz,(double)friends[i].first-(double)friends[i].second*mid);
            limide=min(limide,(double)friends[i].first+(double)friends[i].second*mid);
            if(limitiz>limide){
                break;
            }
        }
        if(limide>=limitiz){
            rr=mid;
        }else{
            ll=mid;
        }
        con++;
    }
    printf("%.12lf",ll);
}