#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    bitset<200001> detras;
    int con=0;
    // cada vez que pasa a alguien que esta delante, no pasa nada
    // cada vez que pasa a alguien que esta detras, da una vuelta
    // todos los que estan detras ahora esta delante
    while(m--){
        cin >> a;
        if(a>0){
            if(detras[a]){
                detras=0;
                detras[a]=1;
                con++;
            }else{
                detras[a]=1;
            }
        }else{
            if(detras[-a]){
                detras[-a]=0;
            }
        }
    }
    cout << con;
}