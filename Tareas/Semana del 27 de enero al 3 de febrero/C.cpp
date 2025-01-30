#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
char A[2005],B[2005];
set<vector<pair<ll,ll>>> dif;
string temp="";
void solve(ll x,ll y){
    if(x==n && y==n){
        //procesar
        vector<pair<ll,ll>> res;
        ll last=0;
        for(ll i=0;i<2*n;i++){
            if(temp[i]=='+'){
                res.push_back({last,1});
                last++;
            }else if(temp[i]=='0'){
                res.clear();
                //last=0;
            }else{
                for(ll j=0;j<res.size();j++){
                    res[j].second*=(ll)(temp[i]-48);
                }
            }
        }
        dif.insert(res);
        return;
    }
    if(x<n){
        temp.push_back(A[x]);
        solve(x+1,y);
        temp.pop_back();
    }
    if(y<n){
        temp.push_back(B[y]);
        solve(x,y+1);
        temp.pop_back();
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        dif.clear();
        scanf("%lld",&n);
        scanf("%s %s",A,B);
        solve(0,0);
        printf("%lld\n",dif.size());
    }
}