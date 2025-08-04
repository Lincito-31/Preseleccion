#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t lll;
typedef complex<lll> Point;
#define X real()
#define Y imag()
int n,m;
ll a,b;
int estado(Point x1,Point x2,Point y){
    lll res=(conj(x1-y)*(x2-y)).Y;
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
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    cin >> n >> m;
    vector<Point> puntos(n);
    for(int i=0;i<n;i++){
        cin >> a >> b;
        puntos[i]={a,b};
    }
    while(m--){
        cin >> a >> b;
        //checkear si estan sobre un segmento
        Point now={a,b},checker={(ll)(1e9),(ll)b+uniform_int_distribution<ll>(1,1e9)(rng)};
        bool lol=false;
        if(estado(puntos[n-1],puntos[0],now)==0 && intersecta(puntos[n-1],puntos[0],now,now)){
            lol=true;
            cout << "BOUNDARY\n";
            continue;
        }
        for(int i=1;i<n;i++){
            if(estado(puntos[i-1],puntos[i],now)==0 && intersecta(puntos[i-1],puntos[i],now,now)){
                lol=true;
                cout << "BOUNDARY\n";
                break;
            }
        }
        if(!lol){
            // checkear si de {a,b} al{1e9,b} corta una cantidad impar o par;
            int con=0;
            if(intersecta(now,checker,puntos[n-1],puntos[0])){
                con++;
                //cout << 0 << ' ';
            }
            for(int i=1;i<n;i++){
                if(intersecta(now,checker,puntos[i-1],puntos[i])){
                    con++;
                    //cout << i << ' ';
                }
            }
            if(con%2){
                cout << "INSIDE\n";
            }else{
                cout << "OUTSIDE\n";
            }
        }
    }
}