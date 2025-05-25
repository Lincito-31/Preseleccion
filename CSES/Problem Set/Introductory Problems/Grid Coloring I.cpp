#include <bits/stdc++.h>
using namespace std;
int n,m;
char c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> c;
            if(abs(i-j)%2){
                cout << "AB"[c=='A'];
            }else{
                cout << "CD"[c=='C'];
            }
        }
        cout << '\n';
    }
}