#include <bits/stdc++.h>
using namespace std;
double h,c,f,fa,day,facons,now;
int main(){
    while(cin >> h >> c >> f >> fa,h>0){
        day=1;
        now=0;
        facons=c*fa/100;
        while(true){
            now+=c;
            c=max(c-facons,(double)0);
            if(now>h){
                cout << "success on day " << day << '\n';
                break;
            }
            now-=f;
            if(now<0){
                cout << "failure on day " << day << '\n';
                break;
            }
            day++;
        }
    }
}