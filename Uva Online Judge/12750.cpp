#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int t,n,can,res;
char a;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int i=1;i<=t;i++){
        xd=true;
        cout << "Case " << i << ": ";
        cin >> n;
        can=0;
        for(int j=1;j<=n;j++){
            cin >> a;
            if(a=='W'){
                can=0;
            }else{
                can++;
            }
            if(can>=3 && xd){
                xd=false;
                res=j;
            }
        }
        if(xd){
            cout << "Yay! Mighty Rafa persists!\n";
        }else{
            cout << res << '\n';
        }
    }
}