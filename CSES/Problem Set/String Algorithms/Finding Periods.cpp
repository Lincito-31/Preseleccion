#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t lll;
const long long MOD=1e9+7;
string st;
vector<ll> hashprefix,powpref;
vector<ll> res;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll Constante=uniform_int_distribution<ll>(1,MOD-1)(rng);
    cin >> st;
    hashprefix.resize(st.size());
    powpref.resize(st.size());
    powpref[0]=1;
    hashprefix[0]=st[0];
    for(int i=1;i<st.size();i++){
        powpref[i]=powpref[i-1]*Constante;
        powpref[i]%=MOD;
        hashprefix[i]=hashprefix[i-1]*Constante+st[i];
        hashprefix[i]%=MOD;
    }
    for(int i=0;i<st.size();i++){
        ll lengh=i+1;
        ll val=hashprefix[i],temp;
        bool xd=true;
        for(int j=lengh;j<st.size();j+=lengh){
            if(j+lengh-1>=st.size()){
                temp=hashprefix[st.size()-1]-hashprefix[j-1]*powpref[st.size()-j];
                temp%=MOD;
                temp+=MOD;
                temp%=MOD;
                if(temp!=hashprefix[st.size()-j-1]){
                    xd=false;
                    break;
                }
            }else{
                temp=hashprefix[j+lengh-1]-hashprefix[j-1]*powpref[lengh];
                temp%=MOD;
                temp+=MOD;
                temp%=MOD;
                if(val!=temp){
                    xd=false;
                    break;
                }
            }
        }
        if(xd){
            res.push_back(i+1);
        }
    }
    for(auto u:res){
        cout << u << ' ';
    }
}