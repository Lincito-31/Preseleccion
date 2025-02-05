#include <bits/stdc++.h>
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
ll N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    vector<ll> a(N),b(N);
    vector<vll> tot(2*N);
    map<ll,ll> contador;
    //1 vetical 0 horizontal
    for(ll i=0;i<N;i++){
        cin >> a[i];
        contador[a[i]]++;
        tot[i]={a[i],0,i};
    }
    for(ll i=0;i<N;i++){
        cin >> b[i];
        contador[b[i]]++;
        tot[i+N]={b[i],1,i};
    }
    contador[a[0]]--;
    sort(REV(tot));
    ll espaciohori=N-1,espacioverti=N-1;
    ll lasthori=N,lastver=N;
    for(ll i=0;i<2*N;i++){
        if(tot[i][2]==0){
            continue;
        }
        if(tot[i][1]){
            if(tot[i][2]<lastver){
                contador[tot[i][0]]+=(lastver-tot[i][2])*espacioverti;
                espaciohori-=(lastver-tot[i][2]);
                lastver=tot[i][2];
            }
        }else{
            if(tot[i][2]<lasthori){
                contador[tot[i][0]]+=(lasthori-tot[i][2])*espaciohori;
                espacioverti-=(lasthori-tot[i][2]);
                lasthori=tot[i][2];
            }
        }
    }
    ll maxi=0,numero=-1;
    for(auto u:contador){
        if(maxi<=u.second){
            maxi=u.second;
            numero=u.first;
        }
    }
    cout << numero << " " << maxi;
} 