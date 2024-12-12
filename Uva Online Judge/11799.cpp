#include <bits/stdc++.h>
using namespace std;
int t,a;
string st,in;
int main(){
    cin >> t;
    getline(cin,st);
    for(int i=1;i<=t;i++){
        int maxi=0;
        getline(cin,st);
        stringstream in(st);
        while(in>>a){
            maxi=max(maxi,a);
        }
        cout << "Case " << i << ": " << maxi << "\n"; 
    }
}