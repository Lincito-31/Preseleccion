#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int a,b,c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> c;
    int now=c+abs(b-c);
    if(now>=a){
        now+=b;
    }else{
        if((a-now)%2==0){
            now=a+b;
        }else{
            now=a+b+1;
        }
    }
    cout << now;
}