#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c,d;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> a >> b >> c >> d && (a+b+c+d)>0){
        if(10*max(a,b)+min(a,b)==21){
            if(10*max(c,d)+min(c,d)==21){
                cout << "Tie.";
            }else{
                cout << "Player 1 wins.";
            }
        }else if(a==b){
            if(10*max(c,d)+min(c,d)==21){
                cout << "Player 2 wins.";
            }else if(c==d){
                if(a>c){
                    cout << "Player 1 wins.";
                }else if(a==c){
                    cout << "Tie.";
                }else{
                    cout << "Player 2 wins.";
                }
            }else{
                cout << "Player 1 wins.";
            }
        }else{
            if(10*max(c,d)+min(c,d)==21 || c==d){
                cout << "Player 2 wins.";
            }else if(10*max(a,b)+min(a,b)>10*max(c,d)+min(c,d)){
                cout << "Player 1 wins.";
            }else if(10*max(a,b)+min(a,b)==10*max(c,d)+min(c,d)){
                cout << "Tie.";
            }else{
                cout << "Player 2 wins.";
            }
        }
        cout << '\n';
    }
}