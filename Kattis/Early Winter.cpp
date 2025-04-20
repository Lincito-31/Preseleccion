#include <bits/stdc++.h>
using namespace std;
int t,k,a,con=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t >> k;
    while(t--){
        cin >> a;
        if(a>k){
            con++;
        }else{
            cout << "It hadn't snowed this early in " << con << " years!";
            return 0;
        }
    }
    cout << "It had never snowed this early!";
}