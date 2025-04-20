#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,n,m,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        int god=0,meg=0;
        while(n--){
            cin >> a;
            god=max(god,a);
        }
        while(m--){
            cin >> a;
            meg=max(meg,a);
        }
        if(god>=meg){
            cout << "Godzilla\n";
        }else{
            cout << "MechaGodzilla\n";
        }
    }
}