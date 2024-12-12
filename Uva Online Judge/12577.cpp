#include <bits/stdc++.h>
using namespace std;
string s;
int n=0;
int main(){
    while(true){
        cin >> s;
        if(s=="*"){
            break;
        }
        n++;
        cout << "Case " << n << ": ";
        if(s=="Hajj"){
            cout << "Hajj-e-Akbar\n";
        }else{
            cout << "Hajj-e-Asghar\n";
        }
    }
}