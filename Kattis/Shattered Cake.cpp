#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int W,s,t,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> W >> t;
    while(t--){
        cin >> a >> b;
        s+=a*b;
    }
    cout << s/W;
}