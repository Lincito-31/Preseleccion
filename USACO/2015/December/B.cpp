#include <bits/stdc++.h>
using namespace std;
int n,m,c,x,now,maxi,maxispeed[100];;
int main(){
    ifstream in("speeding.in");
    ofstream out("speeding.out");
    in >> n >> m;
    while(n--){
        in >> c >> x;
        while(c--){
            maxispeed[now++]=x;
        }
    }
    now=0;
    while(m--){
        in >> c >> x;
        while(c--){
            maxi=max(maxi,x-maxispeed[now++]);
        }
    }
    out << maxi;
}