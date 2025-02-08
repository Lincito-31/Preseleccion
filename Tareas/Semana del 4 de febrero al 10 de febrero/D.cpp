#include <bits/stdc++.h>
using namespace std;
int t,n,m,con;
string x;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> m;
        con=0;
        while(--n){
            cin >> x;
            if(x.back()=='R'){
                con++;
            }
        }
        cin >> x;
        for(auto u:x){
            if(u=='D'){
                con++;
            }
        }
        cout << con << "\n";
    }
}