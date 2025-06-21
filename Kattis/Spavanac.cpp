#include <bits/stdc++.h>
using namespace std;
int h,m,le=45;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> h >> m;
    if(m>=45){
        m-=45;
    }else{
        m=15+m;
        h=(h==0)?23:(h-1);
    }
    cout << h << ' ' << m;
}