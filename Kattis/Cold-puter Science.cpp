#include <bits/stdc++.h>
using namespace std;
int t,n,con=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n<0){
            con++;
        }
    }
    cout << con;
}