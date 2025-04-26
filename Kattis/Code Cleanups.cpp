#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,a,acum,last,con,canti;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a;
        acum+=canti*(a-last);
        last=a;
        if(acum>=20){
            con++;
            canti=0;
            acum=0;
        }
        canti++;
    }
    cout << con+1;
}