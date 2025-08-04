#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
typedef long long ll;
string s,t,r;
vector<ll> hashprefix,powpref,hashprefixtemp;
ll checker;
int main(){
    freopen("censor.in","r",stdin);
    freopen("censor.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll Constante=uniform_int_distribution<ll>(1,MOD-1)(rng);
    cin >> s >> t;
    hashprefix.resize(t.size());
    powpref.resize(s.size());
    powpref[0]=1;
    hashprefix[0]=t[0];
    for(int i=1;i<t.size();i++){
        hashprefix[i]=hashprefix[i-1]*Constante+t[i];
        hashprefix[i]%=MOD;
    }
    for(int i=1;i<=s.size();i++){
        powpref[i]=powpref[i-1]*Constante;
        powpref[i]%=MOD;
    }
    checker=hashprefix.back();
    //cout << checker << '\n';
    for(int i=0;i<s.size();i++){
        if(!hashprefixtemp.empty()){
            hashprefixtemp.push_back((hashprefixtemp.back()*Constante+s[i])%MOD);
        }else{
            hashprefixtemp.push_back(s[i]);
        }
        r.push_back(s[i]);
        while(true){
            if(r.size()<t.size()){
                break;
            }
            if(r.size()==t.size()){
                if(hashprefixtemp.back()==checker){
                    for(int j=0;j<t.size();j++){
                        r.pop_back();
                        hashprefixtemp.pop_back();
                    }
                }
                break;
            }
            ll temp=hashprefixtemp[r.size()-1]-hashprefixtemp[r.size()-t.size()-1]*powpref[t.size()];
            temp%=MOD;
            temp+=MOD;
            temp%=MOD;
            if(temp==checker){
                for(int j=0;j<t.size();j++){
                    hashprefixtemp.pop_back();
                    r.pop_back();
                }
            }else{
                break;
            }
        }
    }
    cout << r;
}