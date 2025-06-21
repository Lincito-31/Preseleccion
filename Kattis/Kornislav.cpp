#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a[4];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<4;i++){
        cin >> a[i];
    }
    sort(a,a+4);
    cout << a[0]*a[2];
}