#include <bits/stdc++.h>
using namespace std;
int n;
string st,a;
map<string,bool> names;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> st >> a;
        if(st=="salida"){
            if(!names[a]){
                cout << a << " salio (ANOMALIA)\n";
            }else{
                names[a]=true;
                cout << a << " salio\n";
            }
        }else{
            if(!names[a]){
                cout << a << " entro\n";
                names[a]=true;
            }else{
                cout << a << " entro (ANOMALIA)\n";
            }
        }
    }
}