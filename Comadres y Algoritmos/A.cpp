#include <bits/stdc++.h>
using namespace std;
int A,B,C;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> A >> B >> C;
    if(A%C==0){
        cout << A;
        return 0;
    }
    if(A-A%C+C<=B){
        cout << A-A%C+C;
    }else{
        cout << -1;
    }
}