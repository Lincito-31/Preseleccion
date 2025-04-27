#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,ante,now;
bool xd;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        xd=true;
        cin >> ante;
        for(int i=0;i<4;i++){
            cin >> now;
            if((now-ante)!=1){
                xd=false;
            }
            ante=now;
        }
        if(xd){
            cout << "Y\n";
        }else{
            cout << "N\n";
        }
    }
}