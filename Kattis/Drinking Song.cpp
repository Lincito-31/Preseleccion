#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int t;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t >> st;
    while(t>=3){
        cout << t << " bottles of "<< st << " on the wall, " << t << " bottles of "<< st << ".\nTake one down, pass it around, " << --t << " bottles of "<< st << " on the wall.\n\n";
    }
    if(t==2){
        cout << t << " bottles of "<< st << " on the wall, " << t << " bottles of "<< st << ".\nTake one down, pass it around, " << --t << " bottle of "<< st << " on the wall.\n\n";
    }
    cout << t << " bottle of "<< st << " on the wall, " << t << " bottle of "<< st << ".\nTake it down, pass it around, no more bottles of " << st << ".";
}