#include <bits/stdc++.h>
using namespace std;
string a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b;
    if(b.size()<=a.size()){
        cout << "go";
    }else{
        cout << "no";
    }
}