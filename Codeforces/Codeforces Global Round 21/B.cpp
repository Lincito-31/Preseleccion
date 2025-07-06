#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef __int128_t lll;
int n,a,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        bool xd=false,xd2=false,xd3=false;
        cin >> n;
        while(n--){
            cin >> a;
            if(a){
                xd=true;
            }
            if(xd && !a){
                xd2=true;
            }
            if(xd2 && a){
                xd3=true;
            }
        }
        if(xd3){
            cout << 2 << '\n';
        }else{
            if(xd){
                cout << 1 << '\n';
            }else{
                cout << 0 << '\n';
            }
        }
    }
}