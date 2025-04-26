#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int h,w,b,x,n,m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> h >> w >> b;
    while(b--){
        cin >> x;
        if(x+m<=w){
            m+=x;
        }else{
            cout << "NO";
            return 0;
        }
        if(m==w){
            m=0;
            n++;
        }
        if(n==h){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}