#include <bits/stdc++.h>
using namespace std;
int n,tipo,monto;
string nombre;
map<string,bool> names;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    priority_queue<pair<int,string>> lista;
    while(n--){
        cin >> tipo;
        if(tipo==1){
            cin >> nombre >> monto;
            lista.push({monto,nombre});
        }else if(tipo==2){
            lista.pop();
        }else{
            pair<int,string> x=lista.top();
            cout << x.second << "\n";
        }
    }
}