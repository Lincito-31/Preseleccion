#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int N,B,H,W,P,x,tot;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> N >> B >> H >> W){
        tot=1e9;
        while(H--){
            cin >> P;
            for(int i=0;i<W;i++){
                cin >> x;
                if(x>=N){
                    tot=min(tot,N*P);
                }
            }
        }
        if(tot<=B){
            cout << tot << '\n';
        }else{
            cout << "stay home\n";
        }
    }
}