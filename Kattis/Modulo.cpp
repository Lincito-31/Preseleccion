#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
int a;
set<int> s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<10;i++){
        cin >> a;
        s.insert(a%42);
    }
    cout << s.size();
}