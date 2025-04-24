#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
double a,b,c,d,e,f;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> c >> d >> e >> f;
    if(a*e<=b*d && a*f<=d*c){
        cout << fixed << setprecision(6) << a-d*a/d << " " << b-e*a/d << " " << c-f*a/d;
    }else if(b*d<=e*a && b*f<=e*c){
        cout << fixed << setprecision(6) << a-d*b/e << " " << b-e*b/e << " " << c-f*b/e;
    }else{
        cout << fixed << setprecision(6) << a-d*c/f << " " << b-e*c/f << " " << c-f*c/f;
    }
}