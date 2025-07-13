#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a;
map<ll,ll> mapa;
ll b,c;
int main(){
    cin >> n;
    while(n--){
        cin >> a;
        if(a){
            cin >> b;
            cout << mapa[b] << '\n';
        }else{
            cin >> b >> c;
            mapa[b]=c;
        }
    }
}