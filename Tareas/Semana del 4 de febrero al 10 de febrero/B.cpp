#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    while(n--){
        if(n%4==0 || n%4==1){
            cout << "a";
        }else{
            cout << "b";
        }
    }
}