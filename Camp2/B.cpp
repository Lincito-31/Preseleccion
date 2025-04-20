#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x,y,a,b;
char C;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> x >> y;
    x%=2;
    x+=2;
    x%=2;
    y%=2;
    y+=2;
    y%=2;
    while(n--){
        cin >> a >> b >> C;
        a%=2;
        a+=2;
        a%=2;
        b%=2;
        b+=2;
        b%=2;
        if(C=='N' && ((x+y)%2)==((a+b)%2)){
            cout << "NO\n";
        }else if(C=='B' && ((x+y)%2)!=((a+b)%2)){
            cout << "NO\n";
        }else{
            cout << "SI\n";
        }
    }
}