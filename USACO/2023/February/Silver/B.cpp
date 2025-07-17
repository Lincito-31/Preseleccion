#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll n,g,a,b,c,ino;
ll mult(ll x, ll y){
    return x*x;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> g >> n;
    vector<vector<ll>> graze(g,vector<ll>(3));
    for(int i=0;i<g;i++){
        cin >> graze[i][1] >> graze[i][2] >> graze[i][0]; 
    }
    sort(ALL(graze));
    while(n--){
        cin >> a >> b >> c;
        vector<ll> bus={c,(ll)-1e18,(ll)-1e18};
        int pos=lower_bound(ALL(graze),bus)-graze.begin();
        if(pos>=1){
            if(mult(graze[pos-1][1]-a,2)+mult(graze[pos-1][2]-b,2)>mult(c-graze[pos-1][0],2)){
                ino++;
                continue;
            }
        }
        if(pos<g){
            if(mult(graze[pos][1]-a,2)+mult(graze[pos][2]-b,2)>mult(c-graze[pos][0],2)){
                ino++;
                continue;
            }
        }
    }
    cout << ino;
}