#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int a,b,c,d,e;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a >> b >> c >> d >> e;
    if(((e-(abs(a-c)+abs(b-d)))>=0)&&((e-abs(a-c)+abs(b-d))%2==0)){
        cout << "Y";
    }else{
        cout << 'N';
    }
}