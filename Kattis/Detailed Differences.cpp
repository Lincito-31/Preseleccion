#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n;
string a,b;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << a << '\n' << b << '\n';
        for(int i=0;i<a.size();i++){
            cout << "*."[a[i]==b[i]];
        }
        cout << "\n\n";
    }
}