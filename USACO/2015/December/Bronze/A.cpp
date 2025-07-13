#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
    ifstream in("paint.in");
    ofstream out("paint.out");
    in >> a >> b >> c >> d;
    if(b<c || d<a){
        out << b-a+d-c;
    }else{
        out << max(b,d)-min(a,c);
    }
}