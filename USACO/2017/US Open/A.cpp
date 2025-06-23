#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int n,m,can,x=1,y,last;
int main(){
    ifstream in("lostcow.in");
    ofstream out("lostcow.out");
    in >> n >> m;
    last=n;
    if(m>n){
        while(n+x<m){
            can+=abs(n+x-last);
            last=n+x;
            x*=-2;
        }
        can+=abs(n+x-last);
        can-=n+x-m;
    }else{
        while(n+x>m){
            can+=abs(n+x-last);
            last=n+x;
            x*=-2;
        }
        can+=abs(n+x-last);
        can-=m-n-x;
    }
    out << can;
}