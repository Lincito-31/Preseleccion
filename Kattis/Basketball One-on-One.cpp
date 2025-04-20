#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
string st;
int A,B;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> st;
    for(int i=0;i<st.size();i+=2){
        if(st[i]=='A'){
            A+=st[i+1]-'0';
        }else{
            B+=st[i+1]-'0';
        }
    }
    if(A>B){
        cout << 'A';
    }else{
        cout << 'B';
    }
}