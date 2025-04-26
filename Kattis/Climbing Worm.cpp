#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int a,b,h;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> h;
    if(h<=a){
        cout << 1;
    }else{
        cout << 2+(h-a-1)/(a-b);
    }
}