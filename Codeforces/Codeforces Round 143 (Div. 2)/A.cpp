#include <bits/stdc++.h>
using namespace std;
int x,a,b,c,con;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> x;
    while(x--){
        cin >> a >> b >> c;
        if(a+b+c>1){
            con++;
        }
    }
    cout << con;
}