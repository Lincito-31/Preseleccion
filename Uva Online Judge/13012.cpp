#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,a,b,c,d,con,e;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> t >> a >> b >> c >> d >> e){
        con=0;
        if(a==t){
            con++;
        }
        if(b==t){
            con++;
        }
        if(c==t){
            con++;
        }
        if(d==t){
            con++;
        }
        if(e==t){
            con++;
        }
        cout << con << '\n';
    }
}