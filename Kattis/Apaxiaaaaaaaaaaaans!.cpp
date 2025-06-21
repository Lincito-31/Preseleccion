#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define REV(x) x.rbegin(),x.rend()
using namespace std;
typedef long long ll;
string st;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    cout << st[0];
    for(int i=1;i<st.size();i++){
        if(st[i]!=st[i-1]){
            cout << st[i];
        }
    }
}