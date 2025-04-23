#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string typ;
double prom;
int canti,a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(true){
        cin >> typ;
        if(typ=="buy"){
            cin >> a >> b;
            prom=(double)(canti*prom+a*b)/(double)(canti+a);
            canti+=a;
        }else if(typ=="sell"){
            cin >> a >> b;
            canti-=a;
        }else if(typ=="split"){
            cin >> a;
            canti*=a;
            prom/=a;
        }else if(typ=="merge"){
            cin >> a;
            canti/=a;
            prom*=a;
        }else{
            cin >> a;
            if(a-prom<=0){
                cout << fixed << setprecision(6) << canti*(a);
            }else{
                cout << fixed << setprecision(6) << canti*(a-(a-prom)*0.3);
            }
            break;
        }
    }
}