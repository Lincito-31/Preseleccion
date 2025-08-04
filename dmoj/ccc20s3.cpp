#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t lll;
const long long MOD=(1ll<<61)-1;
string N,H;
int con[26],con2[26];
vector<lll> hashprefix,powpref;
set<lll> distinct;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll Constante=uniform_int_distribution<ll>(1,MOD-1)(rng);
    cin >> N >> H;
    hashprefix.resize(H.size());
    powpref.resize(H.size());
    powpref[0]=1;
    hashprefix[0]=H[0];
    for(int i=1;i<H.size();i++){
        powpref[i]=powpref[i-1]*Constante;
        powpref[i]%=MOD;
        hashprefix[i]=hashprefix[i-1]*Constante+H[i];
        hashprefix[i]%=MOD;
    }
    if(N.size()>H.size()){
        cout << 0;
        return 0;
    }
    for(auto u:N){
        con[u-'a']++;
    }
    for(int i=0;i<N.size();i++){
        con2[H[i]-'a']++;
    }
    bool xd=true;
    for(int i=0;i<26;i++){
        if(con[i]!=con2[i]){
            xd=false;
            break;
        }
    }
    if(xd){
        distinct.insert(hashprefix[N.size()-1]);
    }
    for(int i=N.size();i<H.size();i++){
        con2[H[i]-'a']++;
        con2[H[i-N.size()]-'a']--;
        xd=true;
        for(int j=0;j<26;j++){
            if(con[j]!=con2[j]){
                xd=false;
                break;
            }
        }
        if(xd){
            distinct.insert((hashprefix[i]-(hashprefix[i-N.size()]*powpref[N.size()])%MOD+MOD)%MOD);
        }
    }
    cout << distinct.size();
}