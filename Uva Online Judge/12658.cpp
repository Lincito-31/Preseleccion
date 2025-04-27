#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int t;
string x[5];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for(int i=0;i<5;i++){
        cin >> x[i];
    }
    for(int i=0;i<4*t;i+=4){
        if(x[0][i]=='.'){
            cout << 1;
        }else{
            if(x[3][i]=='*'){
                cout << 2;
            }else{
                cout << 3;
            }
        }
    }
    cout << '\n';
}