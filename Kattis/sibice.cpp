#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a,n,b,x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> a >> b;
    while(n--){
        cin >> x;
        if(x*x<=a*a+b*b){
            cout << "DA\n";
        }else{
            cout << "NE\n";
        }
    }
}