#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int t,w,dif,a,b;
bool xd,lol;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        if(lol){
            cout << "\n";
        }
        lol=true;
        xd=true;
        cin >> w;
        cin >> a >> b;
        dif=a-b;
        while(--w){
            cin >> a >> b;
            if((a-b)!=dif){
                xd=false;
            }
        }
        if(xd){
            cout << "yes\n";
        }else{
            cout << "no\n";
        }
    }
}