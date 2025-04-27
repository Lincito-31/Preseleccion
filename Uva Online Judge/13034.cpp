#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,x;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int i=1;i<=t;i++){
        xd=true;
        for(int j=0;j<13;j++){
            cin >> x;
            if(x==0){
                xd=false;
            }
        }
        cout << "Set #" << i << ':';
        if(xd){
            cout << " Yes\n";
        }else{
            cout << " No\n"; 
        }
    }
}