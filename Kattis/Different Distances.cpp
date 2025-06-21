#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
typedef long double ld;
long double a,b,c,d,p;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> a >> b >> c >> d >> p){
        cout << fixed << setprecision(6) << (ld)pow((ld)pow((ld)abs(a-c),(ld)p)+(ld)pow((ld)abs(b-d),(ld)p),(ld)(1/p)) << '\n';
    }
}