#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,g,h;
int main(){
    ifstream in("billboard.in");
    ofstream out("billboard.out");
    in >> a >> b >> c >> d;
    in >> e >> f >> g >> h;
    if((e<=a && c<=g)&&(f<=b && d<=h)){
        out << 0;
    }else if((e<=a && c<=g)){
        if(f<=b || d<=h){
            out << (c-a)*(d-b)-(c-a)*max(min(d,h)-max(b,f),0);
        }else{
            out << (c-a)*(d-b);
        }
    }else if((f<=b && d<=h)){
        if(e<=a || c<=g){
            out << (c-a)*(d-b)-(d-b)*max(min(c,g)-max(a,e),0);
        }else{
            out << (c-a)*(d-b);
        }
    }else{
        out << (c-a)*(d-b);
    }
}