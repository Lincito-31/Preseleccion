#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(cin >> st && st!="END"){
        if(st=="1"){
            cout << 1 << '\n';
            continue;
        }
        int con=1;
        int now=st.size();
        while(now!=1){
            now=1+log10(now);
            con++;
        }
        cout << con+1 << '\n';
    }
}