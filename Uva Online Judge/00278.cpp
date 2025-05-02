#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int t,a,b;
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> c >> a >> b;
        if(c=='r' || c=='Q'){
            cout << min(a,b) << '\n';
        }else if(c=='K'){
            cout << (int)((a+1)/2)*(int)((b+1)/2) << '\n';
        }else{
            cout << (int)((b+1)/2)*(int)((a+1)/2)+(int)(b/2)*(int)(a/2) << '\n';
        }
    }
}