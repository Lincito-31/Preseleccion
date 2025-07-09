#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a,b,c,d,e,f,g,h,x,y,z;
int main(){
    ifstream in("promote.in");
    ofstream out("promote.out");
    in >> a >> b >> c >> d >> e >> f >> g >> h;
    x=h-g;
    e-=x;
    y=f-e;
    c-=y;
    z=d-c;
    out << z << '\n' << y << '\n' << x;
}