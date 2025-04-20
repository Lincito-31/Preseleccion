#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,p,r,f;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> p >> r >> f;
        ll con=0;
        while(f-p>=0){
            con++;
            p*=r;
        }
        cout << con << '\n';
    }
}