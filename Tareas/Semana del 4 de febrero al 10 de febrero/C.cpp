#include <bits/stdc++.h>
using namespace std;
string n;
int x=0,y=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(auto u:n){
        if(u=='4'){
            x++;
        }else if(u=='7'){
            y++;
        }
    }
    if(x||y){
        if(x>=y){
            cout << 4;
        }else{
            cout << 7;
        }
    }else{
        cout << -1;
    }
}