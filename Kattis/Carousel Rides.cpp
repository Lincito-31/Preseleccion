#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int a,b,bestx,besty,x,y;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> a >> b && (a+b)){
        xd=false;
        while(a--){
            cin >> x >> y;
            if(x>b){
                continue;
            }
            if(!xd){
                xd=true;
                bestx=x;
                besty=y;
            }else{
                if(besty*x>bestx*y){
                    bestx=x;
                    besty=y;
                }else if(besty*x==bestx*y){
                    if(x>bestx){
                        bestx=x;
                        besty=y;
                    }
                }
            }
        }
        if(xd){
            cout << "Buy "<< bestx << " tickets for $" << besty << '\n';
        }else{
            cout << "No suitable tickets offered\n";
        }
    }
}