#include <bits/stdc++.h>
using namespace std;
int n;
string x,z;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    cin >> x >> z;
    string y(x);
    for(int i=0;i<n;i++){
        if(x[i]==z[i]){
            y[i]='z';
        }else if(x[i]<z[i]){
            cout << -1;
            return 0;
        }else{
            y[i]=z[i];
        }
    }
    cout << y;
}