#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int N,B,H,W,P,x,tot=1e9;;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N >> B >> H >> W;
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
        cout << tot;
    }else{
        cout << "stay home";
    }
}