#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
string a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> a;
    cout << a[0];
    for(int i=0;i<a.size();i++){
        if(a[i]=='-'){
            cout << a[i+1];
        }
    }
}