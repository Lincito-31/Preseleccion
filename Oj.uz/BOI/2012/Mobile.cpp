#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef long double ld;
ll n,L,con,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> L;
    vector<pair<ll,ll>> point;
    cin >> a >> b;
    b=abs(b);
    point.push_back({a,b});
    for(int i=1;i<n;i++){
        cin >> a >> b;
        b=abs(b);
        if(a==point.back().first){
            point.back().second=min(point.back().second,b);
        }else{
            point.push_back({a,b});
        }
    }
    n=point.size();
    ll l=0,r=4e9;
    while(l<r){
        ll mid=(l+r)>>1;
        pair<ll,ll> last={0,0};
        for(int i=0;i<n;i++){
            ll dist=sqrt(mid*mid-(point[i].second*point[i].second));
            pair<ll,ll> now={point[i].first-dist,point[i].first+dist};
            if(last.second<now.first || now.second<last.first){
                continue;
            }
            last={min(last.first,now.first),max(last.second,now.second)};
        }
        if(last.second>=L){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    ld iz=l-2,de=l;
    while(con<15){
        ld mid=(iz+de)/2;
        pair<ld,ld> last={0,0};
        for(int i=0;i<n;i++){
            ld dist=sqrt(mid*mid-(point[i].second*point[i].second));
            pair<ld,ld> now={((ld)point[i].first)-dist,((ld)point[i].first)+dist};
            if(last.second<now.first || now.second<last.first){
                continue;
            }
            last={min(last.first,now.first),max(last.second,now.second)};
        }
        if(last.second>=(ld)L){
            de=mid;
        }else{
            iz=mid;
        }
        con++;
    }
    cout << fixed << setprecision(12) << iz;
}