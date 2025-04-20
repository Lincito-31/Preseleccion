#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,a,speed,timee;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    cout << t << ":\n";
    for(int i=2;(2*i-1)<=t;i++){
        
        int x=i,y=i-1;
        if(t%(x+y)==0 || t%(x+y)==x){
            cout << x << ',' << y << "\n";
        }
        y++;
        if(t%(x+y)==0 || t%(x+y)==x){
            cout << x << ',' << y << "\n";
        }
    }
}