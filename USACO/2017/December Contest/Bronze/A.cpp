#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,h,i,j,k,l;
int main(){
    ifstream in("billboard.in");
    ofstream out("billboard.out");
    in >> a >> b >> c >> d;
    in >> e >> f >> g >> h;
    in >> i >> j >> k >> l;
    int to=(c-a)*(d-b)+(g-e)*(h-f)-max(min(c,g)-max(a,e),0)*max(min(h,d)-max(b,f),0);
    to-=max(min(c,k)-max(a,i),0)*max(min(l,d)-max(b,j),0);
    to-=max(min(g,k)-max(e,i),0)*max(min(l,h)-max(f,j),0);
    to+=max(min({g,k,c})-max({e,i,a}),0)*max(min({l,h,d})-max({f,j,b}),0);
    out << to;
}