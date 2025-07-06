#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef __int128_t lll;
int n,ind=1,ind2,a,b;
lll mini=4e20;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<pair<lll,lll>> points(n);
    for(int i=0;i<n;i++){
        cin >> a >> b;
        points[i].first=a;
        points[i].second=b;
    }
    for(int i=2;i<n;i++){
        lll ar=(lll)points[0].first*(points[ind].second-points[i].second)+(lll)(points[i].first-points[ind].first)*points[0].second+(lll)points[ind].first*points[i].second-(lll)points[ind].second*points[i].first;
        if(ar==0){
            if(points[0].first<points[i].first && points[i].first<points[ind].first){
                ind=i;
            }else if(points[0].first>points[i].first && points[i].first>points[ind].first){
                ind=i;
            }else if(points[0].second<points[i].second && points[i].second<points[ind].second){
                ind=i;
            }else if(points[0].second>points[i].second && points[i].second>points[ind].second){
                ind=i;
            }
        }
    }
    for(int i=1;i<n;i++){
        if(i==ind){
            continue;
        }
        lll ar=(lll)points[0].first*(points[ind].second-points[i].second)+(lll)(points[i].first-points[ind].first)*points[0].second+(lll)points[ind].first*points[i].second-(lll)points[ind].second*points[i].first;
        if(ar<0){
            ar*=-1;
        }
        if(ar!=0 && ar-mini<0){
            mini=ar;
            ind2=i;
        }
        ll x=ar;
    }
    cout << 1 << ' ' << ind2+1 << ' ' << ind+1;
}