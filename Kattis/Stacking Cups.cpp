#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
int n,numero;
string a;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    vector<pair<int,string>> ord(n);
    cin.ignore();
    while(n--){
        getline(cin,a);
        stringstream x(a);
        if(a[0]>='0' && a[0]<='9'){
            x>>numero;
            numero/=2;
            x>>a;
        }else{
            x>>a;
            x>>numero;
        }
        ord[n]={numero,a};
    }
    sort(ALL(ord));
    for(auto u:ord){
        cout << u.second << '\n';
    }
}