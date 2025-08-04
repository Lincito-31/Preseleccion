#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<ll> Point;
#define X real()
#define Y imag()
ll n,a,b,c,d,e,f;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a >> b >> c >> d >> e >> f;
        Point punto1={a,b};
        Point punto2={c,d};
        Point punto3={e,f};
        ll res=(conj(punto1-punto3)*(punto2-punto3)).Y;
        if(res==0){
            cout << "TOUCH\n";
        }else if(res>0){
            cout << "LEFT\n";
        }else{
            cout << "RIGHT\n";
        }
    }
}