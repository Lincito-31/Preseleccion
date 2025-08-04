#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<ll> Point;
#define X real()
#define Y imag()
ll n,a,b,c,d,e,f,g,h;
int estado(Point x1,Point x2,Point y){
    ll res=(conj(x1-y)*(x2-y)).Y;
    if(res>0){
        return 1;
    }else if(res==0){
        return 0;
    }else{
        return -1;
    }
}
bool operator<(Point x,Point y){
    if(x.X==y.X){
        return x.Y<y.Y;
    }
    return x.X<y.X;
}
bool intersecta(Point punto1,Point punto2,Point punto3,Point punto4){
    if(punto1==punto3 || punto1==punto4 || punto2==punto3 || punto2==punto4){
        return true;
    }
    int estado1,estado2,estado3,estado4;
    estado1=estado(punto1,punto2,punto3);
    estado2=estado(punto1,punto2,punto4);
    estado3=estado(punto3,punto4,punto1);
    estado4=estado(punto3,punto4,punto2);
    if(estado1==0 && estado2==0 && estado3==0 && estado4==0){
        if(punto2<punto1){
            swap(punto1,punto2);
        }
        if(punto4<punto3){
            swap(punto3,punto4);
        }
        if(punto2<punto3 || punto4<punto1){
            return false;
        }else{
            return true;
        }
    }else if(estado1!=estado2 && estado3!=estado4){
        return true;
    }else{
        return false;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        if(intersecta({a,b},{c,d},{e,f},{g,h})){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}