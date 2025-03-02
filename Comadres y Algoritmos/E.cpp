#include <bits/stdc++.h>
using namespace std;
int n,x,y,z,A=0,B=0,C=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> x >> y >> z;
        A+=x;B+=y;C+=z;
    }
    if(A==0 && B==0 && C==0){
        cout << "YES";
    }else{
        cout << "NO";
    }
}