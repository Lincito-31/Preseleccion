#include <bits/stdc++.h>
using namespace std;
int x,y,a,b;
int main(){
    ifstream in("teleport.in");
    ofstream out("teleport.out");
    in >> a >> b >> x >> y;
    out << min({abs(b-a),abs(x-a)+abs(y-b),abs(x-b)+abs(y-a)});
}