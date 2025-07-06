#include <bits/stdc++.h>
using namespace std;
int n,a,b,g,points[3];
string state="012";
int main(){
    ifstream in("shell.in");
    ofstream out("shell.out");
    in >> n;
    while(n--){
        in >> a >> b >> g;
        swap(state[--a],state[--b]);
        points[state[--g]-'0']++;
    }
    out << max({points[0],points[1],points[2]});
}