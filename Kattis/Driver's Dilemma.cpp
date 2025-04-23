#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
double X,C,M,speed[6],x[6];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> C >> X >> M;
    C/=2;
    C-=0.000001;
    for(int i=0;i<6;i++){
        cin >> speed[i] >> x[i];
    }
    for(int i=5;i>=0;i--){
        double tiempo=M/speed[i];
        double Galon=M/x[i];
        Galon=C-Galon;
        if(tiempo*X<=Galon){
            cout << "YES " << speed[i];
            return 0;
        }
    }
    cout << "NO";
}