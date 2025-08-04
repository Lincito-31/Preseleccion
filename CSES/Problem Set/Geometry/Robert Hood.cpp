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
int estado(Point x,Point y){
    ll res=cross(x,y);
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
    cin >> n;
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
        n=Convex.size();
        if(n==1){
            cout << 0;
            return 0;
        }
        if(n==2){
            cout << fixed << setprecision(12) << sqrt(dist(Convex[0]-Convex[1]));
            return 0;
        }
        vector<pair<int,int>> pares;
        int l=2;
        ll maxi=0;
        vector<bool> vis(n);
        int con=0;
        for(int i=0;i<n;i++){
            Point base=Convex[(i+1)%n]-Convex[i];
            con=0;
            while(con<=2*n && estado(base,Convex[(l+1)%n]-Convex[l])==estado(base,Convex[l]-Convex[(l-1+n)%n])){
                l++;
                l%=n;
                con++;
            }
            if(con>2*n){
                break;
            }
            if(vis[i]){
                continue;
            }
            vis[i]=true;
            pares.push_back({i,l});
            pares.push_back({(i+1)%n,l});
            if(estado(base,Convex[(l+1)%n]-Convex[l])==0){
                pares.push_back({i,(l+1)%n});
                pares.push_back({(i+1)%n,(l+1)%n});
                vis[l]=true;
            }
        }
        for(int i=0;i<pares.size();i++){
            maxi=max(maxi,dist(Convex[pares[i].first]-Convex[pares[i].second]));
        }
        cout << fixed << setprecision(12) << sqrt(maxi) << '\n';
    }