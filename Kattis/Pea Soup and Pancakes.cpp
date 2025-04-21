#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
int n,t;
string name,menu;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        getline(cin,name);
        getline(cin,name);
        bool xd1=false,xd2=false;
        while(n--){
            getline(cin,menu);
            if(menu=="pea soup"){
                xd1=true;
            }
            if(menu=="pancakes"){
                xd2=true;
            }
        }
        if(xd1 && xd2){
            cout << name;
            return 0;
        }
    }
    cout << "Anywhere is fine I guess";
}