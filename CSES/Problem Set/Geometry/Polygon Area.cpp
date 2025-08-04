#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<ll> Point;
#define X real()
#define Y imag()
int n;
ll a,b,ar;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<Point> puntos(n);
    for(int i=0;i<n;i++){
        cin >> a >> b;
        puntos[i]={a,b};
    }
    for(int i=1;i<n;i++){
        ar+=puntos[i-1].X*puntos[i].Y-puntos[i-1].Y*puntos[i].X;
    }
    ar+=puntos[n-1].X*puntos[0].Y-puntos[n-1].Y*puntos[0].X;
    cout << abs(ar);
}