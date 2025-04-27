#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,x,y,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> t && t){
        cin >> x >> y;
        while(t--){
            cin >> a >> b;
            if(a==x || y==b){
                cout << "divisa\n";
            }else if(a>x){
                if(b>y){
                    cout << "NE\n";
                }else{
                    cout << "SE\n";
                }
            }else{
                if(b>y){
                    cout << "NO\n";
                }else{
                    cout << "SO\n";
                }
            }
        }
    }
}