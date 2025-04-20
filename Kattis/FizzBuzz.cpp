#include <bits/stdc++.h>
using namespace std;
int x,y,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> x >> y >> n;
    for(int i=1;i<=n;i++){
        if(i%x && i%y){
            cout << i << "\n";
            continue;
        }
        if(i%x==0){
            cout << "Fizz";
        }
        if(i%y==0){
            cout << "Buzz";
        }
        cout << "\n";
    }
}