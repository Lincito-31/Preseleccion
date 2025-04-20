#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string ord;
int ar[3];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> ar[0] >> ar[1] >> ar[2];
    cin >> ord;
    sort(ar,ar+3);
    cout << ar[ord[0]-'A'] << ' ' << ar[ord[1]-'A'] << ' ' << ar[ord[2]-'A'];
}