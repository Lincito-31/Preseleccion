#include <bits/stdc++.h>
using namespace std;
int N,a,ante;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> N;
    cin >> a;
    cout << a << " ";
    ante=a;
    while(N--){
        cin >> a;
        if(a==ante){
            continue;
        }
        cout << a << ' ';
        ante=a;
    }
}