#include <bits/stdc++.h>
using namespace std;
string a="100",b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> b;
    for(char x:b){
        if(x=='A'){
            swap(a[0],a[1]);
        }else if(x=='B'){
            swap(a[1],a[2]);
        }else{
            swap(a[0],a[2]);
        }
    }
    for(int i=0;i<3;i++){
        if(a[i]=='1'){
            cout << i+1;
        }
    }
}