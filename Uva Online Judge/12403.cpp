#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,a,sum;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> st;
        if(st=="report"){
            cout << sum << '\n';
        }else{
            cin >> a;
            sum+=a;
        }
    }
}