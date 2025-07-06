#include <bits/stdc++.h>
using namespace std;
int n,timee[1001],a,b,c;
int main(){
    ifstream in("blist.in");
    ofstream out("blist.out");
    in >> n;
    while(n--){
        in >> a >> b >> c;
        timee[--a]+=c;
        timee[b]-=c;
    }
    a=c=0;
    for(int i=0;i<=1000;i++){
        c=max(c,a=a+timee[i]);
    }
    out << c;
}