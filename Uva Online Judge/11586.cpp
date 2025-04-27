#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t,MF,FF,MM;
string cas;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    cin.ignore();
    while(t--){
        MF=MM=FF=0;
        getline(cin,cas);
        stringstream line(cas);
        while(line >> cas){
            if(cas=="MF" || cas=="FM"){
                MF++;
            }else if(cas=="MM"){
                MM++;
            }else{
                FF++;
            }
        }
        if(MF+MM+FF==1){
            cout << "NO LOOP\n";
        }else if(MM==FF){
            cout << "LOOP\n";
        }else{
            cout << "NO LOOP\n";
        }
    }
}