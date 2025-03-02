#include <bits/stdc++.h>
using namespace std;
int n;
string A;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> A;
    if(A.find("ABC")!=-1){
        cout <<A.find("ABC")+1;
    }else{
        cout << -1;
    }
}