#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef __int128_t lll;
int n,m;
double now;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    vector<pair<int,int>> planet(n);
    for(int i=0;i<n;i++){
        cin >> planet[i].first;
    }
    for(int i=0;i<n;i++){
        cin >> planet[i].second;
        if(planet[i].first==1 || planet[i].second==1){
            cout << -1;
            return 0;
        }
    }
    now=(double)(now*planet[0].second+m)/(double)(planet[0].second-1);
    for(int i=n-1;i>0;i--){
        now=(double)(now*planet[i].first+m)/(double)(planet[i].first-1);
        now=(double)(now*planet[i].second+m)/(double)(planet[i].second-1);
    }
    now=(double)(now*planet[0].first+m)/(double)(planet[0].first-1);
    cout << fixed << setprecision(10) << now;
}