#include <bits/stdc++.h>
using namespace std;
int n,t;
set<string> s;
string x;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        s.clear();
        cin >> n;
        while(n--){
            cin >> x;
            s.insert(x);
        }
        cout << s.size() << '\n';
    }
}