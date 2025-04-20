#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,a,b;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> st;
        a+=-(st[0]+st[1])+2*'1';
        b+=-(st[2]+st[3])+2*'1';
    }
    int mini=min(a/2,b/2);
    a-=2*mini;
    b-=2*mini;
    cout << mini << ' ' << a << ' ' << b;
}