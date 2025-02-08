#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
string A,B;
set<vector<pair<ll,ll>>> dif;
vector<pair<ll,ll>> temp={{-1,0}};
void solve(ll x,ll y){
    if(x==n && y==n){
        //procesar
        dif.insert(temp);
    }
    if(x<n){
        if(A[x]=='+'){
            temp.push_back({x,1});
            solve(x+1,y);
            temp.pop_back();
        }else{
            for(ll j=0;j<temp.size();j++){
                temp[j].second*=(ll)(A[x]-48);
            }
            solve(x+1,y);
            for(ll j=0;j<temp.size();j++){
                temp[j].second/=(ll)(A[x]-48);
            }
        }
    }
    if(y<n){
        if(B[y]=='+'){
            temp.push_back({6+y,1});
            solve(x,y+1);
            temp.pop_back();
        }else{
            for(ll j=0;j<temp.size();j++){
                temp[j].second*=(ll)(B[y]-48);
            }
            solve(x,y+1);
            for(ll j=0;j<temp.size();j++){
                temp[j].second/=(ll)(B[y]-48);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        dif.clear();
        cin >> n;
        cin >> A >> B;
        solve(0,0);
        cout << dif.size() << "\n";
    }
}