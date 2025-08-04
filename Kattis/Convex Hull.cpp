#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
typedef long long ll;
typedef complex<ll> Point;
#define X real()
#define Y imag()
#define eps 1e-9
ll n,a,b;
int indice;
Point pivot;
bool operator<(Point x,Point y){
    if(x.X==y.X){
        return x.Y<y.Y;
    }
    return x.X<y.X;
}
ll cross(Point x,Point y){
    return x.X*y.Y-x.Y*y.X;
}
int estado(Point x1,Point x2,Point y){
    ll res=cross(x1-y,x2-y);
    if(res>0){
        return 1;
    }else if(res==0){
        return 0;
    }else{
        return -1;
    }
}
ll dist(Point x){
    return x.X*x.X+x.Y*x.Y;
}
bool cmp(Point x,Point y){
    if(cross(x-pivot,y-pivot)==0){
        //with max dist;
        return dist(x-pivot)<dist(y-pivot);
    }
    return cross(x-pivot,y-pivot)>0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> n && n){
        vector<Point> Convex,puntos(n),nuevo;
        indice=0;
        for(int i=0;i<n;i++){
            cin >> a >> b;
            puntos[i]={a,b};
            if(puntos[i]<puntos[indice]){
                indice=i;
            }
        }
        pivot=puntos[indice];
        for(int i=0;i<n;i++){
            if(puntos[i]==pivot){
                continue;
            }
            nuevo.push_back(puntos[i]);
        }
        puntos=nuevo;
        n=puntos.size();
        sort(ALL(puntos),cmp);
        Convex.push_back(pivot);
        for(int i=0;i<n;i++){
            while(Convex.size()>=2){
                if(estado(Convex[Convex.size()-2],Convex[Convex.size()-1],puntos[i])<=0){
                    Convex.pop_back();
                }else{
                    break;
                }
            }
            Convex.push_back(puntos[i]);
        }
        cout << Convex.size() << '\n';
        for(auto u:Convex){
            cout << u.X << ' ' << u.Y << '\n';
        }
    }
}