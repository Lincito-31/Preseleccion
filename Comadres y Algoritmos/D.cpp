#include <bits/stdc++.h>
using namespace std;
int n;
string A;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> A;
        if(A.size()>10){
            cout << A[0] << A.size()-2 << A.back() << '\n';
        }else{
            cout << A << '\n';
        }
    }
}