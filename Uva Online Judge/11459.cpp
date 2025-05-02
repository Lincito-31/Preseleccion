#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int t,n,a,b,p,mapa[100],player[1000000];
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        xd=false;
        cin >> n >> a >> b;
        memset(player,0,sizeof player);
        for(int i=0;i<100;i++){
            mapa[i]=i;
        }
        while(a--){
            cin >> p >> mapa[99];
            mapa[--p]=mapa[--mapa[99]];
        }
        mapa[99]=99;
        p=0;
        while(b--){
            cin >> a;
            if(!xd){
                player[p]=mapa[min(player[p]+a,99)];
                if(player[p]==99){
                    xd=true;
                }
                p++;
                if(p==n){
                    p=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout << "Position of player " << i+1 << " is " << player[i]+1 << ".\n";
        }
    }
}