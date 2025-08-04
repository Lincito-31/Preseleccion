#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
typedef long long ll;
int n,c,q,aa,bb;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    vector<ll> a(n),b(n);
    vector<ll> prefa(n),prefb(n);
    map<int,ll> hash;
    map<ll,bool> usado1,usado2;
    for(int i=0;i<n;i++){
        cin >> c;
        if(hash.count(c)==0){
            hash[c]=uniform_int_distribution<ll>(1,MOD-1)(rng);
        }
        a[i]=hash[c];
    }
    for(int i=0;i<n;i++){
        cin >> c;
        if(hash.count(c)==0){
            hash[c]=uniform_int_distribution<ll>(1,MOD-1)(rng);
        }
        b[i]=hash[c];
    }
    prefa[0]=a[0];
    usado1[a[0]]=true;
    prefb[0]=b[0];
    usado2[b[0]]=true;
    for(int i=1;i<n;i++){
        if(!usado1[a[i]]){
            usado1[a[i]]=true;
            prefa[i]=prefa[i-1]^a[i];
        }else{
            prefa[i]=prefa[i-1];
        }
        if(!usado2[b[i]]){
            usado2[b[i]]=true;
            prefb[i]=prefb[i-1]^b[i];
        }else{
            prefb[i]=prefb[i-1];
        }
    }
    cin >> q;
    while(q--){
        cin >> aa >> bb;
        if(prefa[--aa]==prefb[--bb]){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
}